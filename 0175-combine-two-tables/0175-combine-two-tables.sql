# Write your MySQL query statement below

select firstName, lastName,city,state from Person p left outer join address a on p.personId= a.personId;