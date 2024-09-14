# Write your MySQL query statement below

with daySum as (
    select 
        visited_on,
        sum(amount) as amount
    from Customer
    group by visited_on
)

select 
    a.visited_on, 
    round(sum(b.amount), 2) as amount,
    round(avg(b.amount), 2) as average_amount
from daySum a, daySum b
where datediff(a.visited_on, b.visited_on) between 0 and 6
group by a.visited_on
having count(*) > 6