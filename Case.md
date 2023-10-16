# Case

https://www.sqlitetutorial.net/sqlite-case/

The `case` expression evaluates a list of conditions then returns an expression based on the evaluation.

`case` is similar to `if-then-else` in other programming languages.

`case` can be used within `where`, `order by`, `having`, `select`, `update`, and `delete`.

### Syntax
```sql
case case_expression
     when when_expression_1 then result_1
     when when_expression_2 then result_2
     ...
     [ else result_else ]
end
```

### Show 'Domestic' or 'Foreign' (based in USA) for customers

The `country` field contains the country for each customer. If this equals 'USA', set to 'Domestic'. Otherwise, set to 'Foreign'.

`> sqlite3 tutorial/media.db`
```sql
select firstName,
       lastName,
       case country
           when 'USA' then 'Domestic'
           else 'Foreign'
       end
from customers;
```

### Classify tracks as short/medium/long
```sql
select trackId, name,
    case
        when milliseconds < 60000 then 'short'
        when milliseconds between 60000 and 300000 then 'medium'
        else 'long'
    end
from tracks;
```
