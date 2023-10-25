# Unique
The `unique` constraint ensures all values in a column are unique.

```sql
create table t (id integer unique);
insert into t values (1); -- okay

insert into t values (1); -- error, duplicate value
*Runtime error: UNIQUE constraint failed: t.id (19)*
```

Multiple unique constraints:
```sql
create table table_name(
    ...,
    unique(column_name1, column_name2, ...)
);
```
