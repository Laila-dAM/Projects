const mysql = require('mysql2/promise');

const pool = mysql.createPool({
  host: '127.0.0.1',
  user: 'todo_user',
  password: 'senha123!',
  database: 'todolist',
  waitForConnections: true,
  connectionLimit: 10,
  queueLimit: 0,
});

module.exports = {
  query: async (sql, params) => {
    const [results] = await pool.execute(sql, params);
    return results;
  },
  getConnection: () => pool.getConnection(),
};