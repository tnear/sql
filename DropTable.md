# Drop Table

`drop` removes a table from the database.

### Syntax
```sql
drop table [if exists] [schema_name.]table_name;
```

### Example
```sql
sqlite> drop table t;
```

### Removing multiple tables
This requires running multiple `drop` statements, one for each table.

```sql
drop table a;
drop table b;
...
```