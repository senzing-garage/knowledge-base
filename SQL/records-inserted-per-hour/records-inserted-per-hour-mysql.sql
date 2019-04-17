SELECT
  DATE_FORMAT(first_seen_dt, "%Y-%m-%d %H") as time,
  count(*) inserts_per_hour
FROM
  DSRC_RECORD
GROUP BY
  time
ORDER BY
  time desc;