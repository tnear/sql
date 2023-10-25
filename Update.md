# Update

The `update` SQL statement modifies existing records in a table.

### Syntax
```sql
update table_name
set column1 = value1, column2 = value2, ...
where condition;
```

Note: if the `where` clause is omitted, then *all* records will be updated.

### Update one column

Update value '3' to '2'

```sql
create table t (val1 int);
insert into t values (1), (3);

update t
set val1 = 2
where val1 = 3;

select * from t;

val1
----
1
2
```

### Update multiple columns
```sql
create table t (val1 int, val2 int);
insert into t values (1, 2);

update t
set val1 = 10, val2 = 11
where val1 = 1;

select * from t;

val1  val2
----  ----
10    11
```