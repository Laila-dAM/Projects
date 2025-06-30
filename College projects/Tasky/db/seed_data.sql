USE todolist;

INSERT INTO users (name, email, password) VALUES
('Teste', 'teste@email.com', '123456');

INSERT INTO tasks (user_id, description, completed) VALUES
(1, 'Primeira tarefa de teste', false),
(1, 'Segunda tarefa de teste', true);
