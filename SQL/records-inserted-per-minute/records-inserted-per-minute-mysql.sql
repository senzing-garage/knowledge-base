SELECT
  DATE_FORMAT(first_seen_dt, "%Y-%m-%d %H:%i") as time,
  count(*) inserts_per_minute
FROM
  DSRC_RECORD
GROUP BY
  time
ORDER BY
  time desc;