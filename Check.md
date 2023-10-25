# Check

https://www.sqlitetutorial.net/sqlite-check-constraint/

SQLite's `check` constraints allow you to define expressions to test values when they are inserted or updated within a column. If values do not meet the criteria, SQLite will issue a constraint violation and abort the statement.

### Syntax

```sql
create table table_name(
    ...,
    column_name data_type check(expression),
    ...
);
```

### Column-level check: ensure value has 4 digits
```sql
create table contact (val integer check (length(val) = 4));
insert into contact values (1234); -- okay
insert into contact values (123); -- errors (3 digits)
*Runtime error: CHECK constraint failed: length(val) = 4 (19)*
```

### Table-level check
Table-level checks allow for multi-property constraints.

```sql
create table products (
    product_id   integer         primary key,
    product_name text            not null,
    list_price   decimal (10, 2) not null,
    discount     decimal (10, 2) not null default 0,
    check (list_price >= discount and 
        discount >= 0 and 
        list_price >= 0) 
);
```

