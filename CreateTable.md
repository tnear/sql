# Create Table

https://www.sqlitetutorial.net/sqlite-create-table/

### Create table (simple)
```sql
sqlite> create table t (date text);
```

### Create table with multiple columns, primary key, not null, and unique modifiers

```sql
CREATE TABLE contacts (
	contact_id INTEGER PRIMARY KEY,
	first_name TEXT NOT NULL,
	last_name  TEXT NOT NULL,
	email      TEXT NOT NULL UNIQUE,
	phone      TEXT NOT NULL UNIQUE
);
```

### Create index
```sql
sqlite> create table table1 (id int, name text);
sqlite> create index table1_index on table1 (id);

-- show indexes
sqlite> .indexes
table1_index
```
