# Pragma

https://www.sqlite.org/pragma.html

The `pragma` statement is an SQL extension specific to SQLite. It is used to modify the SQLite library without recompilation.

## `foreign_keys`

A foreign key constraint enforces the "exists" relationship between tables. For legacy reasons, foreign key constraints are not enabled by default:

```sql
sqlite> pragma foreign_keys;

foreign_keys
------------
0
```

To enable: `sqlite> pragma foreign_keys = 1;`

To disable: `sqlite> pragma foreign_keys = 0;`

## table_info
The `table_info` pragma shows basic information for a database table.

`> sqlite3 tutorial/media.db`
```sql
pragma table_info('artists');

cid  name      type           notnull  dflt_value  pk
---  --------  -------------  -------  ----------  --
0    ArtistId  INTEGER        1                    1
1    Name      NVARCHAR(120)  0                    0
```

## index_list
`index_list` shows detailed metadata on the indexes in the specified table.

```sql
create table table1 (id int, name text);
create index table1_index on table1 (id);
pragma index_list('table1');

seq  name          unique  origin  partial
---  ------------  ------  ------  -------
0    table1_index  0       c       0
```

## index_info
`index_info` shows what columns are in a specified index.

```sql
create table table1 (id int, name text, val real);
create index table1_index on table1 (id, val, name);

pragma index_info('table1_index');
seqno  cid  name
-----  ---  ----
0      0    id
1      2    val
2      1    name
```
