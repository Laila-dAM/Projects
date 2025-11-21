SELECT r.name AS RefugeName, COUNT(s.id) AS SurvivorCount
FROM Refuges r
JOIN Survivors s ON r.id = s.refuge_id
GROUP BY r.id
ORDER BY SurvivorCount DESC;
