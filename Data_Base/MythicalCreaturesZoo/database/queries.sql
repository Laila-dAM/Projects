select * from creature where habitat_id = (select id from habitat where name = 'forest 🌲');

select caretaker_id, count(*) as creature_count from creaturecaretaker group by caretaker_id order by creature_count desc;

select food_type, count(*) * 30 as monthly_food from creature group by food_type;