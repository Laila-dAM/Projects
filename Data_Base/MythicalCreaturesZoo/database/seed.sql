insert into habitat (name) values
('Mountain 🏔️'), 
('Forest 🌲'), 
('Desert 🌵');

insert into creature (name, species, habitat_id, food_type) values
('Smaug', 'Dragon 🐉', 1, 'Meat 🍖'),
('Fawkes', 'Phoenix 🔥', 2, 'Fruits 🍎'),
('Griff', 'Griffin 🦅', 3, 'Meat 🍖');

insert into caretaker (name) values ('Alice 🧑‍🌾'), ('Bob 🦸‍♂️'), ('Charlie 🧑‍🚀');

insert into creaturecaretaker (creature_id, caretaker_id) values (1, 1), (2, 1), (2, 2), (3, 3);