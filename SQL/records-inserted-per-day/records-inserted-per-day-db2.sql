SELECT
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD') as time,
  count(*) as inserts_per_minute
FROM
  DSRC_RECORD
GROUP BY
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD')
ORDER BY
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD') desc;