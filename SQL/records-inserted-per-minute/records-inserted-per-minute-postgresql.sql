SELECT
  date_trunc('minute', first_seen_dt) as time,
  count(*) inserts_per_minute
FROM
  dsrc_record
GROUP BY
  time
ORDER BY
  time desc;