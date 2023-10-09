# Order By

Databases store data in an unspecified order. The `Order By` clause tells the database to return ordered data.

https://www.sqlitetutorial.net/sqlite-order-by/

### Complete syntax
```sql
SELECT
   select_list
FROM
   table
ORDER BY
    column_1 ASC,
    column_2 DESC;
```

If `asc` or `desc` are left off, the default order is *ascending*.

### Get longest tracks
`> sqlite3 tutorial/media.db`
```sql
sqlite> select * from tracks order by Milliseconds desc limit 4;
TrackId  Name                         Milliseconds  Bytes       Price
-------  ---------------------------  ------------  ----------  -----
2820     Occupation / Precipice       5286953       1054423946  1.99
3224     Through a Looking Glass      5088838       1059546140  1.99
3244     Greetings from Earth, Pt. 1  2960293       536824558   1.99
3242     The Man With Nine Lives      2956998       577829804   1.99
```

### NULL values
By default `NULL` values are considered to be less than any other value. To change this behavior, specify `nulls first` or `nulls last`:

```sql
select * from tracks order by Composer nulls last limit 4;
```
