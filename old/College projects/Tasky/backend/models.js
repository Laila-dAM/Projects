const db = require('./db');

async function findUserByEmail(email) {
  const [rows] = await db.execute(
    'SELECT * FROM users WHERE email = ?',
    [email]
  );
  return rows[0];
}

async function createUser(name, email, hashedPassword) {
  const [result] = await db.execute(
    'INSERT INTO users (name, email, password) VALUES (?, ?, ?)',
    [name, email, hashedPassword]
  );
  return result.insertId;
}

async function getTasksByUserId(userId) {
  const [rows] = await db.execute(
    'SELECT * FROM tasks WHERE user_id = ? ORDER BY due_date ASC',
    [userId]
  );
  return rows;
}

async function addTask(userId, title, description, due_date) {
  const [result] = await db.execute(
    'INSERT INTO tasks (user_id, title, description, due_date) VALUES (?, ?, ?, ?)',
    [userId, title, description, due_date]
  );
  return result.insertId;
}

async function updateTaskStatus(taskId, completed) {
  await db.execute(
    'UPDATE tasks SET completed = ? WHERE id = ?',
    [completed ? 1 : 0, taskId]
  );
}

async function deleteTask(taskId) {
  await db.execute(
    'DELETE FROM tasks WHERE id = ?',
    [taskId]
  );
}

async function getTarefasPendentes(userId) {
  const [rows] = await db.execute(
    'SELECT * FROM tarefas WHERE usuario_id = ? AND concluida = 0',
    [userId]
  );
  return rows;
}

module.exports = {
  findUserByEmail,
  createUser,
  getTasksByUserId,
  addTask,
  updateTaskStatus,
  deleteTask,
  getTarefasPendentes
};