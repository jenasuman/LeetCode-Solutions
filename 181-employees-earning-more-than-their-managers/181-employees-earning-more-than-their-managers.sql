select t.name as employee from employee t where t.managerId is not null and t.salary >(select t1.salary from employee t1 where t1.id=t.managerId )

-- select 
-- 	t.name as employee  
-- from employee t 
-- 	where t.managerid is not null 
-- 	and t.salary > (select t1.salary from employee t1 where t.managerId = t1.id)