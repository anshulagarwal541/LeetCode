# Write your MySQL query statement below


with weighted_queue as (
    select *, sum(weight) over (order by turn) as totalWeight
    from Queue
)

select person_name
from weighted_queue
where totalWeight<=1000
order by totalWeight desc
limit 1;