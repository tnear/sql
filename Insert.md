# Insert

An SQL `insert` statement adds records to a table in the database.

### Syntax
```sql
insert into table (col1, col2, ...)
values (value1, value2, ...);
```

### Insert all columns
```sql
create table t (val1 int, val2 int);
insert into t values (1,2), (3,4), (5,6);
select * from t;

val1  val2
----  ----
1     2
3     4
5     6
```

### Insert subset of columns
For missing data, default values are inserted (`null` in this case).

```sql
create table t (val1 int, val2 int);
insert into t (val1) values (1);
select * from t;

val1  val2
----  ----
1
```

### Default values
To insert a new record with all default values, use:
```sql
insert into t default values;
```
