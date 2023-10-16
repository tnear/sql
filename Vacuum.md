# Vacuum

https://www.sqlite.org/lang_vacuum.html

The `vacuum` command rebuilds the database file, packing it into a minimal amount of disk space. This is necessary because for a variety of reasons:

- Dropping objects does not change the size of the database file. Rather, these objects are merely *marked* for deletion. As a result, the database file only grows in size unless `vacuum` is run.
- Inserting or deleting data can cause tables and indexes to become fragmented.

`vacuum` first copies data to a temporary database file. Then, SQLite copies the content of the temporary file temporary file back to the original database file.

The `vacuum` command may change `rowid` values for tables which do not have an explicit `integer primary key`.

### Running `vacuum` in SQLite
```sql
sqlite> vacuum;
```

### `vacuum` to create a database copy

The `vacuum` command is a useful way to create a backup copy of the database. It is transactional-safe.

```sql
$ sqlite3 myDb.db
create table t (val integer);
insert into t values (2), (3);
vacuum main into 'backup.db';

$ ls *.db

    Directory: C:\temp

Mode             LastWriteTime       Length Name
----             -------------       ------ ----
-a---      10/16/2023 12:28 PM         8192 backup.db
-a---      10/16/2023 12:28 PM         8192 myDb.db
```