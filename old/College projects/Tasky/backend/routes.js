const express = require('express');
const router = express.Router();
const controllers = require('./controllers');

router.post('/register', controllers.registerUser);
router.post('/login', controllers.loginUser);

router.get('/tasks/:userId', controllers.getTasks);               
router.get('/tasks/pendentes/:userId', controllers.getPendingTasks); 

router.post('/tasks', controllers.addTask);
router.put('/tasks/:id', controllers.updateTask);
router.delete('/tasks/:id', controllers.deleteTask);

module.exports = router;