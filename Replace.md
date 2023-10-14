# Replace

(Note: less frequent command)

https://www.sqlitetutorial.net/sqlite-replace-statement/

The `replace` command will replace an existing row or insert a new row in a table.

## Syntax
```sql
replace into table (column_list)
values (value_list);
```

## Example

### Create a positions table
```sql
create table positions (id int primary key, title text not null, min_salary numeric);
```

### Insert data into positions table
```sql
insert into positions (title, min_salary)
values ('DBA', 120000), ('Developer', 100000), ('Architect, 150000);
```

### Create a unique index so that 'title' is unique
```sql
create unique index idx_positions_title
on positions (title);
```

### Add new title using `replace`
`replace` will add a new row if one does not already exist.

```sql
replace into positions (title, min_salary)
values ('Full Stack Developer', 140000);
```

### Replace existing title using `replace`

'DBA' already exists. Because 'title' has a unique index, this command updates the existing record instead of adding a new one.

```sql
replace into positions (title, min_salary)
values ('DBA', 170000);
```

