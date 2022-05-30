/* Write your PL/SQL query statement below */
-- SELECT event_day AS day, emp_id,SUM((out_time-in_time)) AS total_time 
-- FROM Employees 
-- GROUP BY event_day,emp_id;


SELECT 
to_char(event_day,'YYYY-MM-DD') AS day, emp_id, SUM((out_time - in_time)) AS total_time
FROM Employees
GROUP BY to_char(event_day,'YYYY-MM-DD'), emp_id;