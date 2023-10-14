# Update

The `update` SQL statement modifies existing records in a table.

### Syntax
```sql
update table_name
set column1 = value1, column2 = value2, ...
where condition; 
```

Note: if the `where` clause is omitted, then *all* records will be updated.

### Example
```sql
create table t (val1 int);
insert into t values (1), (2), (4);
-- update value '4' to '3'
update t set val1 = 3 where val1 = 4;

select * from t;

val1
----
1
2
3
```
