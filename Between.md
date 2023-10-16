# Between

The `between` operator selects values within a given range. The values can be numbers, text, or dates.

`between` is inclusive on *both* ends.

### Numeric example: return prices between [10, 20] (inclusive)
```sql
select * from Products
where Price between 10 and 20;
```

### Text example: return products between 'car' and 'truck' alphabetically
```sql
select * from Products
where ProductName between 'car' and 'truck';
```

### Date example: return dates between Jan 1, 2010 and February 28, 2010
This works with textual dates when the schema saves dates in the format `yyyy-mm-dd`.

`> sqlite3 tutorial/media.db`
```sql
select * from invoices where InvoiceDate between '2010-01-01' and '2010-02-28';
```

### Not between
`not between` inverts the `between` operation. This query gets all prices less than 10 or greater than 20:
```sql
select * from Products
where Price not between 10 and 20;
```
