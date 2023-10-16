# Write your MySQL query statement below
SELECT DISTINCT MAX(salary) as SecondHighestSalary
FROM Employee a
WHERE salary < (SELECT MAX(salary) FROM Employee b WHERE b.salary > a.salary)