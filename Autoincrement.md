# Autoincrement

https://www.sqlite.org/autoinc.html

The `autoincrement` keyword is not recommended by SQLite because it imposes extra CPU, memory, disk space, and disk I/O overhead. Instead, SQLite recommends its implicit [RowID](RowID.md) column to create a default integer identifier for a row in table.

### Example
```sql
create table t (val integer primary key autoincrement, val2 integer);
insert into t (val2) values (10), (11), (12);
select * from t;
val  val2
---  ----
1    10
2    11
3    12
```

### Disk full error
If you insert a value with a maximum integer value (9223372036854775807), the next insertion will throw a database full error:

```sql
create table t (val integer primary key autoincrement, val2 integer);
insert into t values (9223372036854775807, 0);
insert into t (val2) values (12345);

*Runtime error: database or disk is full (13)*
```
