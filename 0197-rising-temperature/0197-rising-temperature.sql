# Write your MySQL query statement below
select d1.id from weather d1,weather d2 where DATEDIFF(d1.recordDate,d2.recordDate) =1 and d1.temperature> d2.temperature