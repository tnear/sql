# SQLite3

sqlite3 is a command line interface for SQLite version 3.

Syntax: `sqlite3 [options] [databaseFile] [SQL]`

### Create in-memory database
`$ sqlite3`

### Create file database
`$ sqlite3 data.db`

### Exit sqlite3 CLI
`sqlite> .exit  # or .quit or Ctrl+D`

### .tables: = list tables
```sql
sqlite> .tables
table1 table2
```

### Run commands from terminal
```sql
$ sqlite3 data.db 'select * from table1;'
id  name
--  -----
1   hello
2   world
```

### .schema: show the complete structure of the database
```sql
sqlite> .schema
CREATE TABLE table1(id int, name text);
CREATE TABLE table2(name text);
```

### .index: show indexes:
```sql
sqlite> .indexes
table1_index
```

### .headers: toggle headers (column name) for tables
```sql
sqlite> .headers on  # 'off' to disable
sqlite> select * from table1;
name
hello
```

### .mode: toggle mode for tables ('list' is default)
```sql
sqlite> .mode list
id|name
1|hello
2|world

sqlite> .mode column
id  name
--  -----
1   hello
2   world
```

### .read: read external plaintext sql file
`sqlite> .read file.sql`

OR, from terminal:

`$ sqlite3 db.db '.read file.sql'`