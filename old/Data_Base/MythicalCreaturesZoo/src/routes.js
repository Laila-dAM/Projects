import express from 'express';
import pool from './db.js';

const router = express.Router();

router.get('/creatures/:habitat', async (req, res) => {
    const { habitat } = req.params;
    const result = await pool.query(
        `SELECT * FROM Creature WHERE habitat_id = (SELECT id FROM Habitat WHERE name = $1)`,
        [habitat]
    );
    res.json(result.rows);
});

router.get('/caretakers/ranking', async (_, res) => {
    const result = await pool.query(
        `SELECT caretaker_id, COUNT(*) AS creature_count FROM CreatureCaretaker GROUP BY caretaker_id ORDER BY creature_count DESC`
    );
    res.json(result.rows);
});

router.get('/food/monthly', async (_, res) => {
    const result = await pool.query(
        `SELECT food_type, COUNT(*) * 30 AS monthly_food FROM Creature GROUP BY food_type`
    );
    res.json(result.rows);
});

export default router;
