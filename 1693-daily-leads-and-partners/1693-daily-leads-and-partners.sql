/* Write your PL/SQL query statement below */
SELECT 
to_char(date_id,'YYYY-MM-DD') AS date_id,make_name,
COUNT(DISTINCT(lead_id)) AS unique_leads,
COUNT(DISTINCT(partner_id)) AS unique_partners
FROM DailySales 
GROUP BY to_char(date_id,'YYYY-MM-DD'),make_name;