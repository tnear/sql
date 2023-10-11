# Round

https://www.sqlite.org/lang_corefunc.html

The `round(X,Y)` function returns a floating-point value `X` rounded to `Y` digits to the right of the decimal point. If the `Y` argument is omitted or negative, it is taken to be 0.

```sql
select round(4.5); -- rounds to nearest int, 5.0
```

```sql
select round(1.2345, 2); -- rounds to 2 digits, 1.23
```
