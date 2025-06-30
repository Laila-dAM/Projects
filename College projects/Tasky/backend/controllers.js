const bcrypt = require('bcrypt');
const models = require('./models');

async function registerUser(req, res) {
  const { name, email, password } = req.body;
  if (!name || !email || !password) {
    return res.status(400).json({ error: 'Preencha todos os campos' });
  }

  try {
    const existingUser = await models.findUserByEmail(email);
    if (existingUser) {
      return res.status(400).json({ error: 'Email já cadastrado' });
    }

    const hashedPassword = await bcrypt.hash(password, 10);
    const userId = await models.createUser(name, email, hashedPassword);

    res.json({ message: 'Cadastro realizado com sucesso', userId });
  } catch (err) {
    res.status(500).json({ error: 'Erro no servidor' });
  }
}

async function loginUser(req, res) {
  const { email, password } = req.body;
  if (!email || !password) {
    return res.status(400).json({ error: 'Preencha todos os campos' });
  }

  try {
    const user = await models.findUserByEmail(email);
    if (!user) {
      return res.status(401).json({ error: 'Email ou senha incorretos' });
    }

    const passwordMatch = await bcrypt.compare(password, user.password);
    if (!passwordMatch) {
      return res.status(401).json({ error: 'Email ou senha incorretos' });
    }

    res.json({
      message: 'Login efetuado com sucesso',
      user: { id: user.id, name: user.name, email: user.email }
    });
  } catch (err) {
    res.status(500).json({ error: 'Erro no servidor' });
  }
}

async function getTasks(req, res) {
  const userId = req.params.userId;
  try {
    const tasks = await models.getTasksByUserId(userId);
    res.json(tasks);
  } catch (err) {
    res.status(500).json({ error: 'Erro ao buscar tarefas' });
  }
}

async function getPendingTasks(req, res) {
  const userId = req.params.userId;
  try {
    const tarefas = await models.getTarefasPendentes(userId);
    res.json(tarefas);
  } catch (err) {
    console.error('Erro ao buscar tarefas pendentes:', err);
    res.status(500).json({ error: 'Erro interno do servidor' });
  }
}

async function addTask(req, res) {
  const { userId, title, description, due_date } = req.body;

  if (!userId || !title || !description || !due_date) {
    return res.status(400).json({ error: 'Campos incompletos' });
  }

  try {
    const taskId = await models.addTask(userId, title, description, due_date);
    res.json({ message: 'Tarefa adicionada', taskId });
  } catch (err) {
    res.status(500).json({ error: 'Erro ao adicionar tarefa' });
  }
}

async function updateTask(req, res) {
  const { id } = req.params;
  const { completed } = req.body;

  try {
    await models.updateTaskStatus(id, completed);
    res.json({ message: 'Tarefa atualizada' });
  } catch (err) {
    res.status(500).json({ error: 'Erro ao atualizar tarefa' });
  }
}


async function deleteTask(req, res) {
  const { id } = req.params;

  try {
    await models.deleteTask(id);
    res.json({ message: 'Tarefa deletada' });
  } catch (err) {
    res.status(500).json({ error: 'Erro ao deletar tarefa' });
  }
}

module.exports = {
  registerUser,
  loginUser,
  getTasks,
  getPendingTasks,   // ✅ incluída
  addTask,
  updateTask,
  deleteTask,
};