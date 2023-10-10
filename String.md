# String

### Concatenation
SQLite supports concatenation via the `||` operator. There is no `concat` function in SQLite.

```sql
sqlite> select 'hello' || ' world' as '';

-----------
hello world
```
