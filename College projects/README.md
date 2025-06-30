# Tasky

**Tasky** é uma aplicação web simples de lista de tarefas (To-Do List) com backend em Node.js e frontend em HTML, CSS e JavaScript. Ideal para aprender como conectar uma interface web com uma API RESTful.

## Funcionalidades

- Adicionar tarefas
- Listar tarefas existentes
- Marcar tarefas como concluídas
- Deletar tarefas
- Interface web simples e funcional

## Estrutura do Projeto

- **backend/**: código do servidor (API com Node.js)
  - `server.js`: inicia o servidor
  - `routes.js`, `controllers.js`, `models.js`: controlam as tarefas
  - `db.js`: conexão com o banco de dados
- **public/**: interface do usuário
  - `index.html`, `todo.html`: páginas web
  - `style.css`: estilos visuais
  - `script.js`, `todo.js`: comportamentos da interface
- `README.md`: este arquivo de explicação
