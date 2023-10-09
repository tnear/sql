# Date/time

SQLite does not have a date/time class. Instead it supports:
- text: ex: ('YYYY-MM-DD HH:MM:SS.SSS')
- real: (floating-point): the number of days since November 24, 4714 B.C (Julian date)
- integer: the number of seconds since January 1st, 1970

## Example: get all 2022 years

### Date as text example
```sql
sqlite> create table t (date text);
insert into t values ('2023-10-08');
insert into t values ('2022-01-01');
insert into t values ('2021-01-01');
select * from t where date like '2022%';

date
----------
2022-01-01
```

### Date as integer example
```sql

sqlite> create table t (date integer);
insert into t values (strftime('%s', '2023-01-01'));
insert into t values (strftime('%s', '2022-01-01'));
insert into t values (strftime('%s', '2021-01-01'));
select datetime(date, 'auto') from t where date >= strftime('%s', '2022-01-01') and date < strftime('%s', '2023-01-01');

datetime(date, 'auto')
---------------------------
2022-01-01 00:00:00
```

### Date as real example (less common)

```sql

sqlite> create table t (date real);
insert into t values (julianday('2023-01-01'));
insert into t values (julianday('2022-01-01'));
insert into t values (julianday('2021-01-01'));

-- use datetime() to format output as a date
select datetime(date) from t where date >= julianday('2022-01-01') and date < julianday('2023-01-01');

datetime(date)
-------------------
2022-01-01 00:00:00
```
