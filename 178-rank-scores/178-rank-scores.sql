SELECT t.score
     , (SELECT COUNT(DISTINCT s.score)  FROM scores s WHERE s.score >=t.score)  AS rank 
  FROM scores t
 ORDER BY t.score DESC