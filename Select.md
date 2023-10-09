# Select

https://www.sqlitetutorial.net/sqlite-select/

### Complete syntax
```sql
SELECT DISTINCT column_list
FROM table_list
  JOIN table ON join_condition
WHERE row_filter
ORDER BY column
LIMIT count OFFSET offset
GROUP BY column
HAVING group_filter;
```

### Select distinct
`> sqlite3 tutorial/media.db`
```sql
select distinct city
from customers
order by city;
```

#### NULL values with distinct
If there are `NULL` values, a `distinct` query will only return one of them. In other words, `NULL` values are treated like any other for `select distinct`.
