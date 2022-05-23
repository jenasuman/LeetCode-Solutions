/* Write your PL/SQL query statement below */

select t1.id from Weather t1,Weather t2 where (t1.recordDate-1)=(t2.recordDate) and (t1.temperature > t2.temperature);

-- select w1.id from Weather w1, Weather w2
-- where w1.recordDate-w2.recordDate=1
-- and w1.temperature > w2.temperature