# Explain

## Explain query plan
https://www.sqlitetutorial.net/sqlite-index-expression/

`explain query plan` describes a high-level description of the plan that SQLite uses to implement specific SQL query. This command can be useful for seeing if SQLite uses an index.

### Determine is SQLite is performing an indexed query
`> sqlite3 tutorial/media.db`
```sql
explain query plan
select customerId,
       company
  from customers
 where length(company) > 10
 order by length(company) desc;
```

```
QUERY PLAN
|--SCAN customers
`--USE TEMP B-TREE FOR ORDER BY
```

From the output above, you can see that it scans the entire `customers` table to order by length. To improve this, index `length(company)` then repeat the query:

```sql
create index customers_length_company
on customers(length(company));

explain query plan
(same query)
```

```
QUERY PLAN
`--SEARCH customers USING INDEX customers_length_company (<expr>>?)
```

Now the output shows that the query is using the table index `customers_length_company`.
