// backend/server.js
const path = require('path');
const express = require('express');
const cors = require('cors');
const cron = require('node-cron');
const enviarEmail = require('./emailService');
const routes = require('./routes');

const app = express();
const port = 3000;

app.use(cors());
app.use(express.json());

app.use('/', routes);

app.use(express.static(path.join(__dirname, '..', 'public')));

app.get('*', (req, res) => {
  res.sendFile(path.join(__dirname, '..', 'public', 'index.html'));
});

const tarefas = [
  { titulo: "Comprar leite", concluida: false },
  { titulo: "Estudar Node.js", concluida: true },
  { titulo: "Gravar vídeo", concluida: false },
];

const emailDoUsuario = "usuario@gmail.com";

cron.schedule("0 9 * * *", () => {
  const pendentes = tarefas.filter((t) => !t.concluida);
  if (pendentes.length > 0) {
    enviarEmail(emailDoUsuario, pendentes);
  } else {
    console.log("Nenhuma tarefa pendente para enviar.");
  }
});

app.listen(port, () => {
  console.log(`✅ Servidor rodando em: http://localhost:${port}`);
});
