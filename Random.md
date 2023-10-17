# Random

https://www.sqlitetutorial.net/sqlite-functions/sqlite-random/

The SQLite `random()` function returns a random integer between -9223372036854775808 and +9223372036854775807. `random()` accepts zero function arguments.

### Basic usage
```
select random();

random()
-------------------
-200597320284455111
```

### Get 5 random tracks
When `random()` is used in `order by`, the result set contains a random ordering.

`> sqlite3 tutorial/media.db`
```sql
select name from tracks
order by random()
limit 5;
```
