# RowID

By default, SQLite implicitly creates a 64-bit incrementing field called `rowid` for tables. `rowid` is always indexed and fast to query.

```sql
create table t (val integer);
insert into t values (2), (3);

select rowid, val from t;
rowid  val
-----  ---
1      2
2      3
```

### Integer primary key
When creating a table with an `integer primary key`, that column becomes an alias of `rowid`:

```sql
create table t (val integer primary key, val2 integer);
insert into t (val2) values (3), (4);

select rowid, * from t;
val  val  val2
---  ---  ----
1    1    3
2    2    4
```

*Note: `int primary key` does not seem to work. Needs full `integer` word.*

