# Coalesce

The `coalesce()` function accepts two or more arguments and returns the first non-null value. If all inputs are null, it returns null.

Coalesce is useful to substitute a default value for a null value.

### Basic usage
```sql
select coalesce(null, null, 10, 20); -- returns 10
select coalesce(null, null);   -- returns null
```

### Practical example

This query returns numerous null values:

`> sqlite3 tutorial/media.db`
```sql
select firstName, company
from customers
limit 5;

FirstName  Company
---------  ------------------------------------------------
Louis      SA
Leon
François
Fran       JB
```

To replace `null` with the string '`<null>`', use the `coalesce` function:

```sql
select firstName,
       coalesce(company, '<null>')
  from customers
 limit 5;

FirstName  Company
---------  ------------------------------------------------
Louis      SA
Leon       <null>
François   <null>
Fran       JB
```
