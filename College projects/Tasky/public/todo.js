const taskForm = document.getElementById('task-form');
const taskDateInput = document.getElementById('task-date');
const taskTitleInput = document.getElementById('task-title');
const taskDescriptionInput = document.getElementById('task-description');
const taskList = document.getElementById('task-list');
const logoutBtn = document.getElementById('logout-btn');


function createTaskElement(task) {
    const li = document.createElement('li');
    li.className = 'task-item';

    const title = document.createElement('strong');
    title.textContent = task.title;

    const date = document.createElement('small');
    date.textContent = new Date(task.due_date).toLocaleDateString();

    const description = document.createElement('p');
    description.textContent = task.description;

    const doneBtn = document.createElement('button');
    doneBtn.textContent = '✔';
    doneBtn.title = 'Marcar como concluída';
    doneBtn.className = 'done-btn';

    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = '✖';
    deleteBtn.title = 'Excluir tarefa';
    deleteBtn.className = 'delete-btn';

    doneBtn.addEventListener('click', async () => {
        try {
            const response = await fetch(`/tasks/${task.id}`, {
                method: 'PUT',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ completed: !task.completed }),
            });

            if (!response.ok) {
                const errorData = await response.json();
                throw new Error(errorData.error || 'Falha ao atualizar status.');
            }

            li.classList.toggle('done');
            task.completed = !task.completed;
        } catch (err) {
            console.error('Erro ao atualizar tarefa:', err);
            alert(`Erro ao atualizar tarefa: ${err.message}`);
        }
    });

    deleteBtn.addEventListener('click', async () => {
        try {
            const response = await fetch(`/tasks/${task.id}`, {
                method: 'DELETE',
            });

            if (!response.ok) {
                const errorData = await response.json();
                throw new Error(errorData.error || 'Falha ao excluir tarefa.');
            }

            taskList.removeChild(li);
        } catch (err) {
            console.error('Erro ao excluir tarefa:', err);
            alert(`Erro ao excluir tarefa: ${err.message}`);
        }
    });

    if (task.completed) li.classList.add('done');

    li.appendChild(title);
    li.appendChild(date);
    li.appendChild(description);
    li.appendChild(doneBtn);
    li.appendChild(deleteBtn);

    return li;
}

function sortTasksByDate(tasks) {
    return tasks.sort((a, b) => new Date(a.due_date) - new Date(b.due_date));
}

async function loadTasks() {
    try {
        const userId = localStorage.getItem('userId');
        if (!userId) {
            alert('Você precisa estar logado para acessar suas tarefas.');
            window.location.href = 'index.html';
            return;
        }

        const response = await fetch(`/tasks/${userId}`);
        if (!response.ok) {
            const errorData = await response.json();
            throw new Error(errorData.error || 'Falha ao carregar tarefas.');
        }

        let tasks = await response.json();
        tasks = sortTasksByDate(tasks);

        taskList.innerHTML = '';
        tasks.forEach(task => {
            const taskItem = createTaskElement(task);
            taskList.appendChild(taskItem);
        });
    } catch (err) {
        console.error('Erro ao carregar tarefas:', err);
        alert(`Erro ao carregar tarefas: ${err.message}`);
    }
}

taskForm.addEventListener('submit', async (e) => {
    e.preventDefault();

    const due_date = taskDateInput.value;
    const title = taskTitleInput.value.trim();
    const description = taskDescriptionInput.value.trim();

    if (!due_date || !title || !description) {
        alert('Por favor, preencha todos os campos para adicionar uma tarefa.');
        return;
    }

    try {
        const userId = localStorage.getItem('userId');
        if (!userId) {
            alert('Usuário não autenticado. Faça login novamente.');
            window.location.href = 'index.html';
            return;
        }

        const response = await fetch('/tasks', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ userId, title, description, due_date }),
        });

        if (!response.ok) {
            const errorData = await response.json();
            throw new Error(errorData.error || 'Erro ao adicionar tarefa.');
        }

        const { taskId } = await response.json();
        const newTask = {
            id: taskId,
            title,
            description,
            due_date,
            completed: false
        };

        const taskItem = createTaskElement(newTask);
        taskList.appendChild(taskItem);

        taskForm.reset();
        taskDateInput.focus();
    } catch (err) {
        console.error('Erro ao adicionar tarefa:', err);
        alert(`Erro ao adicionar tarefa: ${err.message}`);
    }
});

logoutBtn.addEventListener('click', () => {
    localStorage.removeItem('userId');
    localStorage.removeItem('userName'); // se usado
    window.location.href = 'index.html';
});

loadTasks();