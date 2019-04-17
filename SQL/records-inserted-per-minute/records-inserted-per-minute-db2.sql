SELECT
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD HH24:MI') as time,
  count(*) as inserts_per_minute
FROM
  DSRC_RECORD
GROUP BY
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD HH24:MI')
ORDER BY
  TO_CHAR(first_seen_dt, 'YYYY-MM-DD HH24:MI') desc;