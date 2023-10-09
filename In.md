# In

https://www.w3schools.com/sql/sql_in.asp

The `in` operator allows you to specify multiple values in a `where` clause.

```sql
select * from customers
where Country in ('Germany', 'France', 'UK');
```

### `not in`
`not in` inverts the operation. It will return all records which are NOT equal to any of the values in the list.

```sql
select * from customers
where Country not in ('Germany', 'France', 'UK');
```
