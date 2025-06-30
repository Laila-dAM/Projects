const taskForm = document.getElementById('task-form');
const taskDateInput = document.getElementById('task-date');
const taskTitleInput = document.getElementById('task-title');
const taskDescriptionInput = document.getElementById('task-description');
const taskList = document.getElementById('task-list');

function createTaskElement(task) {
  const li = document.createElement('li');
  li.className = 'task-item';

  const title = document.createElement('strong');
  title.textContent = task.title;

  const date = document.createElement('small');
  date.textContent = new Date(task.due_date || task.date).toLocaleDateString();

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

  doneBtn.addEventListener('click', () => {
    li.classList.toggle('done');
    // TODO: implementar atualização do status no backend
  });

  deleteBtn.addEventListener('click', () => {
    taskList.removeChild(li);
    // TODO: implementar exclusão no backend
  });

  li.appendChild(title);
  li.appendChild(date);
  li.appendChild(description);
  li.appendChild(doneBtn);
  li.appendChild(deleteBtn);

  return li;
}

function sortTasksByDate(tasks) {
  return tasks.sort((a, b) => new Date(a.due_date || a.date) - new Date(b.due_date || b.date));
}

async function loadTasks() {
  try {
    const userId = localStorage.getItem('userId');
    const response = await fetch(`/tasks/${userId}`);
    if (!response.ok) throw new Error('Falha ao carregar tarefas');
    let tasks = await response.json();
    tasks = sortTasksByDate(tasks);

    taskList.innerHTML = '';
    tasks.forEach(task => {
      const taskItem = createTaskElement(task);
      taskList.appendChild(taskItem);
    });
  } catch (err) {
    console.error(err);
    alert('Erro ao carregar tarefas');
  }
}

taskForm.addEventListener('submit', async (e) => {
  e.preventDefault();

  const due_date = taskDateInput.value;
  const title = taskTitleInput.value.trim();
  const description = taskDescriptionInput.value.trim();

  if (!due_date || !title || !description) {
    alert('Por favor, preencha todos os campos.');
    return;
  }

  try {
    const userId = localStorage.getItem('userId');
    const response = await fetch('/tasks', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ userId, title, description, due_date }),
    });

    if (!response.ok) throw new Error('Erro ao adicionar tarefa');

    const newTask = await response.json();
    const taskItem = createTaskElement(newTask);
    taskList.appendChild(taskItem);

    taskForm.reset();
    taskDateInput.focus();
  } catch (err) {
    alert(err.message);
  }
});

loadTasks();