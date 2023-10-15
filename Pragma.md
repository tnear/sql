# Pragma

https://www.sqlite.org/pragma.html

The `pragma` statement is an SQL extension specific to SQLite. It is used to modify the SQLite library without recompilation.

### Foreign key constraints: `foreign_keys`

A foreign key constraint enforces the "exists" relationship between tables. For legacy reasons, foreign key constraints are not enabled by default:

```sql
sqlite> pragma foreign_keys;

foreign_keys
------------
0
```

To enable: `sqlite> pragma foreign_keys = 1;`

To disable: `sqlite> pragma foreign_keys = 0;`
