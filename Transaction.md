# Transaction

A database transaction is a unit of work which either entirely is committed or none is committed. A transaction is atomic, consistent, isolated, and durable. Databases use transactions to ensure data integrity.

By default, SQLite is in *auto-commit* mode. This means that SQLite starts and commits a transaction with each command.

### Explicit transaction

Wrap work between `begin transaction` and `commit` to tell SQLite the scope of the transactional unit:

```sql
begin transaction;
<do work>
commit; -- or 'commit transaction'
```

### Rollback transaction

To cancel changes, use the `rollback` keyword to cancel the transaction. Work is not committed to the database upon `rollback`.

```sql
begin transaction;
<do work>
rollback; -- or 'rollback transaction'
```
