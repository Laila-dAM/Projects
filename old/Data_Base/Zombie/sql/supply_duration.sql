SELECT r.name AS RefugeName, r.supplies_duration, 
       SUM(DATEDIFF(s.expiration_date, CURDATE())) AS DaysUntilSuppliesExpire
FROM Refuges r
JOIN Supplies s ON r.id = s.refuge_id
GROUP BY r.id;
