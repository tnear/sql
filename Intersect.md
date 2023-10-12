# Intersect

The `intersect` operator returns distinct rows that are in both queries.

## Example

Create two tables with the same structure but different values:
```sql
create table t1 (v1 int);
insert into t1 values (1), (2), (3);

create table t2 (v2 int);
insert into t2 values (2), (3), (4);
```

Now, use an `intersect` query to list records common to both:
```sql
select * from t1
intersect
select * from t2;

v1
--
2
3
```