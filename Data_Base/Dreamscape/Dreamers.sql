CREATE TABLE Dreamers (
    DreamerID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Age INT NOT NULL CHECK (Age >= 0),
    DreamVividnessLevel INT NOT NULL CHECK (DreamVividnessLevel BETWEEN 1 AND 10),
    TotalDreams INT DEFAULT 0
);

CREATE TABLE Categories (
    CategoryID INT AUTO_INCREMENT PRIMARY KEY,
    CategoryName VARCHAR(50) UNIQUE NOT NULL
);

CREATE TABLE Themes (
    ThemeID INT AUTO_INCREMENT PRIMARY KEY,
    ThemeName VARCHAR(50) UNIQUE NOT NULL
);

CREATE TABLE Dreams (
    DreamID INT AUTO_INCREMENT PRIMARY KEY,
    DreamerID INT NOT NULL,
    CategoryID INT NOT NULL,
    ThemeID INT NOT NULL,
    DreamDate DATE NOT NULL,
    Description TEXT,
    FOREIGN KEY (DreamerID) REFERENCES Dreamers (DreamerID) ON DELETE CASCADE,
    FOREIGN KEY (CategoryID) REFERENCES Categories (CategoryID) ON DELETE CASCADE,
        FOREIGN KEY (ThemeID) REFERENCES Themes(ThemeID) ON DELETE CASCADE
);

INSERT INTO Dreamers (Name, Age, DreamVividnessLevel)
VALUES
('Alice', 25, 8),
('Bob', 30, 6),
('Cindy', 22, 9),
('David', 40, 5);

INSERT INTO Categories (CategoryName)
VALUES
('Nightmare'),
('Adventure'),
('Surreal');

INSERT INTO Themes (ThemeName)
VALUES
('Flying'),
('Falling'),
('Chase'),
('Talking to Animals'),
('Time Travel');

INSERT INTO Dreams (DreamerID, CategoryID, ThemeID, DreamDate, Description)
VALUES
(1, 1, 2, '2025-01-01', 'Falling endlessly though a dark void.'),
(2, 2, 1, '2025-01-02', 'Flying over mountains and oceans.'),
(3, 3, 3, '2025-01-03', 'Being chased by a giant talking clock.'),
(1, 1, 3, '2025-01-04', 'Chased by shadows in a forest.'),
(3, 2, 4, '2025-01-05', 'Talking to a lion about philosophy.'),
(4, 1, 2, '2025-01-06', 'Falling from a skyscraper repeatedly.');

UPDATE Dreamers d
SET TotalDreams = (SELECT COUNT(*) FROM Dreams WHERE DreamerID = d.DreamerID);

SELECT t.ThemeName, COUNT(d.DreamID) AS ThemeCount
FROM Themes t
JOIN Dreams d ON t.ThemeID = d.ThemeID
GROUP BY t.ThemeName
ORDER BY ThemeCount DESC;

SELECT Name, DreamVividnessLevel, TotalDreams
FROM Dreamers
WHERE DreamVividnessLevel > 7
ORDER BY TotalDreams DESC;

SELECT (COUNT(DreamID) * 100.0 / (SELECT COUNT(*) FROM Dreams)) AS NightmarePercentage
FROM Dreams
WHERE CategoryID = (SELECT CategoryID FROM Categories WHERE CategoryName = 'Nightmare');

SELECT Name, TotalDreams
FROM Dreamers
ORDER BY TotalDreams DESC;

SELECT d.DreamDate, dr.Name AS Dreamer, c.CategoryName, t.ThemeName, d.Description
FROM Dreams d
JOIN Dreamers dr ON d.DreamerID = dr.DreamerID
JOIN Categories c ON d.CategoryID = c.CategoryID
JOIN Themes t ON d.ThemeID = t.ThemeID
ORDER BY d.DreamDate DESC;

SELECT c.CategoryName, t.ThemeName
FROM Categories c
JOIN Dreams d ON c.CategoryID = d.CategoryID
JOIN Themes t ON d.ThemeID = t.ThemeID
GROUP BY c.CategoryName, t.ThemeName
HAVING COUNT(DISTINCT d.DreamerID) = 1;

SELECT dr.Name, COUNT(DISTINCT d.CategoryID) AS UniqueCategories
FROM Dreamers dr
JOIN Dreams d ON dr.DreamerID = d.DreamerID
GROUP BY dr.Name
HAVING UniqueCategories > 1
ORDER BY UniqueCategories DESC;

SELECT dr.Name, t.ThemeName, COUNT(d.DreamID) AS Frequency
FROM Dreamers dr
JOIN Dreams d ON dr.DreamerID = d.DreamerID
JOIN Themes t ON d.ThemeID = t.ThemeID
GROUP BY dr.Name, t.ThemeName
ORDER BY dr.Name, Frequency DESC;