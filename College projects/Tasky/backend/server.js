const path = require('path');
const express = require('express');
const mysql = require('mysql2/promise');
const cors = require('cors');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(cors());
app.use(bodyParser.json());

const dbConfig = {
  host: '127.0.0.1',
  user: 'todo_user',
  password: 'senha123!',
  database: 'todolist',
};

app.use(async (req, res, next) => {
  try {
    req.db = await mysql.createConnection(dbConfig);
    next();
  } catch (err) {
    console.error('Erro ao conectar ao banco:', err);
    res.status(500).json({ error: 'Erro ao conectar ao banco' });
  }
});

app.post('/register', async (req, res) => {
  const { name, email, password } = req.body;
  if (!name || !email || !password) {
    return res.status(400).json({ error: 'Preencha todos os campos' });
  }

  try {
    const [existing] = await req.db.execute('SELECT id FROM users WHERE email = ?', [email]);
    if (existing.length > 0) {
      return res.status(400).json({ error: 'Email já cadastrado' });
    }

    await req.db.execute(
      'INSERT INTO users (name, email, password) VALUES (?, ?, ?)',
      [name, email, password]
    );

    res.json({ message: 'Cadastro realizado com sucesso' });
  } catch (err) {
    console.error('Erro no cadastro:', err);
    res.status(500).json({ error: 'Erro no servidor' });
  } finally {
    await req.db.end();
  }
});

app.post('/login', async (req, res) => {
  const { email, password } = req.body;
  if (!email || !password) return res.status(400).json({ error: 'Preencha todos os campos' });

  try {
    const [rows] = await req.db.execute('SELECT * FROM users WHERE email = ? AND password = ?', [email, password]);
    if (rows.length === 0) return res.status(401).json({ error: 'Email ou senha incorretos' });

    const user = rows[0];
    res.json({ message: 'Login efetuado com sucesso', user: { id: user.id, name: user.name, email: user.email } });
  } catch (err) {
    console.error('Erro no login:', err);
    res.status(500).json({ error: 'Erro no servidor' });
  } finally {
    await req.db.end();
  }
});

app.get('/tasks/:userId', async (req, res) => {
  const { userId } = req.params;
  try {
    const [tasks] = await req.db.execute('SELECT * FROM tasks WHERE user_id = ?', [userId]);
    res.json(tasks);
  } catch (err) {
    console.error('Erro ao buscar tarefas:', err);
    res.status(500).json({ error: 'Erro ao buscar tarefas' });
  } finally {
    await req.db.end();
  }
});

app.post('/tasks', async (req, res) => {
  const { userId, description } = req.body;
  if (!userId || !description) return res.status(400).json({ error: 'Campos incompletos' });

  try {
    await req.db.execute(
      'INSERT INTO tasks (user_id, description) VALUES (?, ?)',
      [userId, description]
    );
    res.json({ message: 'Tarefa adicionada' });
  } catch (err) {
    console.error('Erro ao adicionar tarefa:', err);
    res.status(500).json({ error: 'Erro ao adicionar tarefa' });
  } finally {
    await req.db.end();
  }
});

app.put('/tasks/:id', async (req, res) => {
  const { id } = req.params;
  const { completed } = req.body;
  try {
    await req.db.execute('UPDATE tasks SET completed = ? WHERE id = ?', [completed ? 1 : 0, id]);
    res.json({ message: 'Tarefa atualizada' });
  } catch (err) {
    console.error('Erro ao atualizar tarefa:', err);
    res.status(500).json({ error: 'Erro ao atualizar tarefa' });
  } finally {
    await req.db.end();
  }
});

app.delete('/tasks/:id', async (req, res) => {
  const { id } = req.params;
  try {
    await req.db.execute('DELETE FROM tasks WHERE id = ?', [id]);
    res.json({ message: 'Tarefa deletada' });
  } catch (err) {
    console.error('Erro ao deletar tarefa:', err);
    res.status(500).json({ error: 'Erro ao deletar tarefa' });
  } finally {
    await req.db.end();
  }
});

app.use(express.static(path.join(__dirname, '..', 'public')));

app.get('*', (req, res) => {
  res.sendFile(path.join(__dirname, '..', 'public', 'index.html'));
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});