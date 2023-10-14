# Date/time

https://www.sqlite.org/lang_datefunc.html

SQLite does not have a dedicated date/time data type. Instead, it supports:
- Text: ex: `('YYYY-MM-DD HH:MM:SS.SSS')`
- Real: (floating-point): the number of days since November 24, 4714 B.C (Julian date)
- Integer: the number of seconds since January 1st, 1970

## Specifiers

| Specifier | Meaning                        |
|-----------|--------------------------------|
| %d        | day of month: 00               |
| %f        | fractional seconds: SS.SSS     |
| %H        | hour: 00-24                    |
| %j        | day of year: 001-366           |
| %J        | Julian day number (fractional) |
| %m        | month: 01-12                   |
| %M        | minute: 00-59                  |
| %s        | seconds since 1970-01-01       |
| %S        | seconds: 00-59                 |
| %w        | day of week 0-6 with Sunday==0 |
| %W        | week of year: 00-53            |
| %Y        | year: 0000-9999                |
| %%        | % (escape)                     |

### Format current date as `YYYY-MM/DD`
`%Y` is year, `%m` is month, `%d` is day:

```sql
sqlite> select strftime('%Y-%m/%d');

strftime('%Y-%m/%d')
--------------------
2023-10/11
```

## Get all 2022 years

### Date as `text`
```sql
sqlite> create table t (date text);
insert into t values ('2023-10-08'), ('2022-01-01'), ('2021-01-01');
select * from t where date like '2022%';

date
----------
2022-01-01
```

### Date as `integer`
```sql

sqlite> create table t (date integer);
insert into t values (strftime('%s', '2023-01-01')),
                     (strftime('%s', '2022-01-01')),
                     (strftime('%s', '2021-01-01'));
select datetime(date, 'auto') from t where date >= strftime('%s', '2022-01-01') and date < strftime('%s', '2023-01-01');

datetime(date, 'auto')
---------------------------
2022-01-01 00:00:00
```

### Date as `real` (less common)

```sql

sqlite> create table t (date real);
insert into t values (julianday('2023-01-01')),
                     (julianday('2022-01-01')),
                     (julianday('2021-01-01'));

-- use datetime() to format output as a date
select datetime(date) from t where date >= julianday('2022-01-01') and date < julianday('2023-01-01');

datetime(date)
-------------------
2022-01-01 00:00:00
```
