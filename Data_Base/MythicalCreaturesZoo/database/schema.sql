CREATE TABLE Habitat (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE Creature (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    species VARCHAR(100) NOT NULL,
    habitat id INT REFERENCES Habitat(id),
    food_type varchar(100) not null
);

create table caretaker (
    id serial primary key,
    name varchar(100) not null
);

create table creaturecaretaker (
    creature_id int references creature(id),
    caretaker_id int references caretaker(id),
    primary key (creature_id, caretaker_id)
);

