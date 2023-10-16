# Select

https://www.sqlitetutorial.net/sqlite-select/

The `select` statement in SQL allows querying of data.

### Complete syntax
```sql
select distinct column_list
from table_list
  join table on join_condition
where row_filter
order by column
limit count offset offset
group by column
having group_filter;
```

### Select distinct
`> sqlite3 tutorial/media.db`
```sql
select distinct city
from customers
order by city;
```

#### NULL values with distinct
If there are `NULL` values, a `distinct` query will only return exactly one of them. In other words, `NULL` values are treated like any other value for `select distinct`.
