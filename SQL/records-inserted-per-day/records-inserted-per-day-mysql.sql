SELECT
  DATE_FORMAT(first_seen_dt, "%Y-%m-%d") as time,
  count(*) inserts_per_day
FROM
  DSRC_RECORD
GROUP BY
  time
ORDER BY
  time desc;