# Create Table

https://www.sqlitetutorial.net/sqlite-create-table/

### Syntax
```sql
create table [if not exists] [schema_name].table_name (
	column_1 data_type primary key,
   	column_2 data_type not null,
	column_3 data_type default 0,
	table_constraints
);
```

### Create table (basic)
```sql
create table t (date text);
```

### Create table with multiple columns, primary key, not null, and unique modifiers

```sql
create table contacts (
    contact_id integer primary key,
    first_name text not null,
    email      text not null unique,
    phone      text not null unique
);
```

### Unique constraint
The `unique` constraint ensures all values in a column are unique.

```sql
create table t (id int unique);
insert into t values (1); -- okay

insert into t values (1); -- error, duplicate value
*Runtime error: UNIQUE constraint failed: t.id (19)*
```

Multiple unique constraints:
```sql
create table table_name(
    ...,
    unique(column_name1, column_name2, ...)
);
```
