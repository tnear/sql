# Changes

The `changes` function returns a count of the number of records modified.

### Insert

```sql
create table t (value text);
insert into t values ('hello'), ('world');
select changes();

changes()
---------
2
```

### Update
```sql
update t
set value = 'text'
where value = 'hello';

changes()
---------
1
```
