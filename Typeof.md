# Typeof

The `typeof` in SQLite returns a string that indicates the data type of the expression.

### Examples
```sql
select typeof(100), typeof(10.0), typeof('abc'), typeof(x'1000'), typeof(null);

typeof(100)  typeof(10.0)  typeof('abc')  typeof(x'1000')  typeof(null)
-----------  ------------  -------------  ---------------  ------------
integer      real          text           blob             null
```

Note: `x'1000'` creates a hex literal, which must be an even length.
