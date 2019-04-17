SELECT
  day(first_seen_dt) log_day,
  hour(first_seen_dt) log_hr,
  minute(first_seen_dt) log_min,
  count(*) olpm
FROM
  dsrc_record
GROUP BY
  day(first_seen_dt),
  hour(first_seen_dt),
  minute(first_seen_dt)
ORDER BY
  log_day,
  log_hr,
  log_min asc;