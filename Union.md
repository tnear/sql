# Union

https://en.wikipedia.org/wiki/Set_operations_(SQL)

The `union` operator combines the results of two SQL queries into a single table of all matching rows. The two queries must result in the same number of columns and compatible data types. Duplicate records are removed unless `union all` is used.

## Example

Create two tables with the same structure but different values:
```sql
create table t1 (v1 int);
insert into t1 values (1), (2), (3);

create table t2 (v2 int);
insert into t2 values (2), (3), (4);
```

Now, use a `union` query to combine and remove duplicates:
```sql
select * from t1
union
select * from t2;

v1
--
1
2
3
4
```

^Note that duplicates (2, 3) are removed the field name of the result set is from the first table.

## `Union all`
`union all` does *not* remove duplicate records and therefore runs faster than `union`.

This example uses the same tables from above. With `union all`, we now see duplicate rows in the result set:

```sql
select * from t1
union all
select * from t2;

v1
--
1
2
3
2
3
4
```
