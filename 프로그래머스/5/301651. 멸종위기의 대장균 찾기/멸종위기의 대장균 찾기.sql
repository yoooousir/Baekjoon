with recursive generations as(
    select id, parent_id, 1 as generation
    from ECOLI_DATA
    where parent_id IS NULL
    UNION ALL
    select c.id, c.parent_id, 1+p.generation
    from ECOLI_DATA as c
    join generations p on c.parent_id=p.id
)
select count(*) as COUNT, g.generation as GENERATION 
FROM generations g
WHERE g.id NOT IN (
    SELECT DISTINCT parent_id FROM ECOLI_DATA WHERE parent_id IS NOT NULL
)
GROUP BY g.generation
ORDER BY g.generation;