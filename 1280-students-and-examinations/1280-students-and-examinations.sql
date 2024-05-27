# Write your MySQL query statement below

WITH cte AS
    (SELECT *
    FROM Students
    CROSS JOIN Subjects)

# 1 Alice Math
# 1 Alice Physics
# ..

# 2 bob Math
# 2 bob Physics (this will need a special treatment)

, cte2 AS
    (SELECT student_id, subject_name, COUNT(subject_name) AS attended_exams
    FROM Examinations
    GROUP BY student_id, subject_name)
    
# 1 Math 3
# 1 Physics 2
# ..

# 2 Programming 1
# 2 Math 1
# bob didn't give physics exam

SELECT cte.student_id, 
    cte.student_name, 
    cte.subject_name , 
    CASE WHEN attended_exams IS NOT NULL THEN attended_exams ELSE 0 END AS attended_exams
FROM cte
LEFT JOIN cte2
ON cte.student_id = cte2.student_id AND cte.subject_name = cte2.subject_name
ORDER BY cte.student_id, cte.subject_name;


# 1 Alice Math 3
# 1 Alice Physics 2
# ..

# 2 Bob Programming 1
# 2 Bob Physics NULL (BRUH) Issue

