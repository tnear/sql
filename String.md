# String

## Concatenation
SQLite supports concatenation via the `||` operator. There is no `concat` function in SQLite.

```sql
sqlite> select 'hello' || ' world' as '';

-----------
hello world
```

## Substr

Syntax: `substr(string, start, length)`

The `start` parameter is 1-indexed.

```sql
select substr('hello world', 7, 3);

---
wor
```
