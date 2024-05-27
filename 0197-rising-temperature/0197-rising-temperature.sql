# Cartesian Cross Product with itself.
# Filter with Conditions

SELECT 
    Weather.id AS 'Id'
FROM
    Weather
        JOIN 
    Weather w ON DATEDIFF(Weather.recordDate, w.recordDate) = 1
        AND
    Weather.temperature > w.temperature;