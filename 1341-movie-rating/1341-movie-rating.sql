
-- CTE to count the number of ratings per user
WITH userTotalRating AS (
    SELECT 
        u.user_id, 
        u.name, 
        COUNT(*) AS totalRating
    FROM 
        Users u
    JOIN 
        MovieRating m ON u.user_id = m.user_id
    GROUP BY 
        u.user_id
),

-- CTE to calculate the average rating per movie for February 2020
movieMaxRating AS (
    SELECT 
        m.movie_id, 
        mv.title, 
        AVG(m.rating) AS averageRating
    FROM 
        MovieRating m
    JOIN 
        Movies mv ON m.movie_id = mv.movie_id
    WHERE 
        m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY 
        m.movie_id
)

-- Select the user with the greatest number of ratings
(
    SELECT 
    name AS results
    FROM 
        userTotalRating
    ORDER BY 
        totalRating DESC, 
        name ASC
    LIMIT 1
)
UNION all
(  
    SELECT 
        title AS results
    FROM 
        movieMaxRating
    ORDER BY 
        averageRating DESC, 
        title ASC
    LIMIT 1
)
