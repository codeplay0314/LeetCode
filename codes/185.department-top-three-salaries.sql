--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--

-- @lc code=start
# Write your MySQL query statement below
select
    D.name as Department,
    E.name as Employee,
    salary as Salary
from
    Employee as E
    join Department as D on E.departmentID = D.id
where
    3 >= (
        select
            count(distinct salary)
        from
            Employee
        where
            departmentID = E.departmentID
            and salary >= E.salary
    )
-- @lc code=end

