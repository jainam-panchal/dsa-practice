 # Write your MySQL query statement below
 
 # The COUNT (*) function returns the number of rows that satisfy the WHERE clause of a SELECT statement. 
 
SELECT customer_id,
       Count(*) AS count_no_trans
FROM   (SELECT V.customer_id
        FROM   visits AS V
        WHERE  V.visit_id NOT IN (SELECT visit_id
                                  FROM   transactions)) AS T
GROUP  BY customer_id;  