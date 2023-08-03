# Write your MySQL query statement below
SELECT a.id 
FROM Weather a, Weather b
WHERE a.temperature > b.temperature && DATEDIFF(a.recordDate, b.recordDate) = 1