# Write your MySQL query statement below
select E.employee_id 
from Employees E left join Salaries S on E.employee_id = S.employee_id 
where salary is null
union 
select S.employee_id 
from Employees E right join Salaries S on E.employee_id = S.employee_id 
where name is null 

order by employee_id 
