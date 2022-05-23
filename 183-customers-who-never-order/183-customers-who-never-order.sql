/* Write your PL/SQL query statement below */

-- select name as Customers from Customers where Customers.id NOT IN (select customerId from Orders) 

select name as Customers from Customers LEFT JOIN Orders on Customers.id=Orders.customerId where Orders.customerId IS NULL