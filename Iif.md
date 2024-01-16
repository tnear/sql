# iif

The `iif()` function allows adding if-else logic go queries.

### Syntax
`iif(expression, true_expression, false_expression);`

### Example
```sql
select iif(1 < 2, 'Yes', 'No');

iif(1 < 2, 'Yes', 'No')
-----------------------
Yes
```
