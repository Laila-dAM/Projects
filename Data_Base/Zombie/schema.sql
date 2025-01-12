CREATE DATABASE ZombieApocalypse;
USE ZombieApocalypse;
CREATE TABLE Survivors (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT,
    gender VARCHAR(10),
    health INT,
    refuge_id INT,
    FOREIGN KEY (refuge_id) REFERENCES Refuges(id)
);

CREATE TABLE Zombies (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    type VARCHAR(50),
    health INT,
    defeated_by INT,
    FOREIGN KEY (defeated_by) REFERENCES Survivors(id)
);

CREATE TABLE Refuges (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    location VARCHAR(200),
    supplies_duration INT,
);

CREATE TABLE Supplies (
    id INT AUTO_INCREMENT PRIMARY KEY,
    refuge_id INT,
    item_name VARCHAR(100),
    quantity INT,
    expiration_date DATE,
    FOREIGN KEY (refuge_id) REFERENCES Refuges(id)
);