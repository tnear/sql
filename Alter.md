# Alter

The `alter table` statement changes the structure of an existing table.

`alter` can do any of the following operations:
- Rename a table
- Add a new column to a table
- Rename a column

### Rename a table (`rename to`)
```sql
create table t (val integer);
alter table t
rename to tt;
```

### Add new column to table (`add column`)
```sql
create table t (val integer);
insert into t values (1);
alter table t
add column name text;

select * from t;

val  name
---  ----
1
```

### Rename column (`rename column`)
```sql
create table t (val integer);
alter table t
rename column val to value;

select * from t;

value
-----
1
```
