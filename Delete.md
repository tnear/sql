# Delete

The `delete` statement in SQL removes records from a table.

### Syntax
```sql
delete from <table>
where <search_condition>
```

### Example
```sql
create table t (val1 int, val2 int);
insert into t values (1, 2), (3, 4);

delete from t
where val1 > 2;

select * from t;

val1  val2
----  ----
1     2
```

### Delete all records from a table (without deleting the table)

To delete all records, remove the `where` clause from the query:

`delete from <table>;`

Note: this deletes all records but preserves the table. To delete the table itself, use `drop table <table>;`.
