# Key

A *key* in a relational database is a unique identifier for a record in a table. Keys are often used to [Join](Join.md) tables in queries.

## Primary key
Each table in SQLite may have at most one primary key. They are denoted by the keywords `primary key`.

### Basic usage
```sql
create table t (val integer primary key, val2 integer);
insert into t values (1, 2);

insert into t values (1, 3); -- duplicate primary key throws error
*Runtime error: UNIQUE constraint failed: t.val (19)*
```

### Primary key table constraint
To create a multi-column primary key, use the table constraint `primary key(col1, col2, ...)`. This syntax also works for a single primary key.

```sql
create table t (val1 integer, val2 integer, val3 integer, primary key (val1, val2));
insert into t values (1, 2, 3), (1, 4, 5);

select rowid, * from t;
rowid  val1  val2  val3
-----  ----  ----  ----
1      1     2     3
2      1     4     5
```

See [RowID](RowID.md) for more information on the `rowid` column.

## Foreign key

