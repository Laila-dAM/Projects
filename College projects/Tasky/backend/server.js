const path = require('path');
const express = require('express');
const cors = require('cors');

const routes = require('./routes');

const app = express();
const port = 3000;

// Middlewares
app.use(cors());
app.use(express.json());

// Rotas da API
app.use('/', routes);

// Servir arquivos estáticos do frontend
app.use(express.static(path.join(__dirname, '..', 'public')));

// Redirecionar outras rotas para o frontend
app.get('*', (req, res) => {
  res.sendFile(path.join(__dirname, '..', 'public', 'index.html'));
});

// Inicializar servidor
app.listen(port, () => {
  console.log(`✅ Servidor rodando em: http://localhost:${port}`);
});