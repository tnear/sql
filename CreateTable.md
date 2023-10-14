# Create Table

https://www.sqlitetutorial.net/sqlite-create-table/

### Create table (simple)
```sql
sqlite> create table t (date text);
```

### Create table with multiple columns, primary key, not null, and unique modifiers

```sql
create table contacts (
    contact_id integer primary key,
    first_name text not null,
    last_name  text not null,
    email      text not null unique,
    phone      text not null unique
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
