# Write your MySQL query statement below
select email as Email from Person GROUP BY EMAIL HAVING count(*)>1;