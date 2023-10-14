# Exists

The `exists` operator checks if a subquery returns any rows. If the subquery returns 1+ rows, exists returns `true`. Otherwise, it returns `false` or `null`.

The `in` operator can often be used instead of `exists`.

### Find all customers who have an invoice

The `customers` and `invoices` tables are linked by `customerId`. The subquery returns `true` via `select 1` when it finds a match between the two tables. This causes the outer query to select that row for that customerId.

`> sqlite3 tutorial/media.db`
```sql
select customerId, firstName, lastName from customers
where
    exists
    (
        select 1 from invoices
        where invoices.customerId = customers.customerId
    );
```

Note: this can also be done with the `in` operator:

```sql
select customerId, firstName, lastName from customers
where customerId in
    (select invoices.customerId from invoices);
```
