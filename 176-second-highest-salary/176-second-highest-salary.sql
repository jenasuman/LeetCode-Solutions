/* Write your PL/SQL query statement below */



SELECT MAX(DISTINCT(salary)) as SecondHighestSalary 
FROM Employee 
WHERE salary <> (SELECT MAX(salary) FROM Employee);