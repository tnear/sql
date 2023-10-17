# Group Concat

The `group_concat()` function is an aggregate function that concatenates all non-null values in a column. The default separator is comma (',').

### Syntax
`group_concat(expression [,separator])`

### Example
Create a table and insert a few records.

```sql
create table t (id integer primary key, val text);
insert into t (val) values ('a'), ('b'), (NULL), ('c');

select group_concat(val) from t;
group_concat(val)
-----------------
a,b,c
```

### Change separator
```sql
select group_concat(val, '-') as '' from t;
-----
a-b-c
```
