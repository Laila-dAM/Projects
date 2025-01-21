SELECT s.name AS SurvivorName, COUNT(z.id) AS ZombiesDefeated
FROM Survivors s
JOIN Zombies z ON s.id = z.defeated_by
GROUP BY s.id;
