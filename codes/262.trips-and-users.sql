--
-- @lc app=leetcode id=262 lang=mysql
--
-- [262] Trips and Users
--

-- @lc code=start
# Write your MySQL query statement below
select
    request_at as "Day",
    round(count(if(status != "completed", status, null)) / count(*), 2) as "Cancellation Rate"
from
    Trips
    join Users as U1 on client_id = U1.users_id and U1.banned = "No"
    join Users as U2 on driver_id = U2.users_id and U2.banned = "No"
where
    "2013-10-01" <= request_at 
    and request_at <= "2013-10-03"
group by
    1
-- @lc code=end

