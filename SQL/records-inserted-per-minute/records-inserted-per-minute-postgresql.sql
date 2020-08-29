SELECT
  date_trunc('minute', first_seen_dt) as time,
  count(*) inserts_per_minute
FROM
  dsrc_record
WHERE
  first_seen_dt > NOW() - INTERVAL '1 HOURS'
GROUP BY
  time
ORDER BY
  time desc;
