# Null

`null` in SQL is special because `null != null`. Instead, one must use `is null` or `is not null` to check for `null` values.

```sql
select * from table
where Property is null
```
