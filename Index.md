# Index
An SQL index is used to improve the performance of querying a database.

### Create index
```sql
create table table1 (id int, name text);
create index table1_index on table1 (id);
```

### List indexes
```
sqlite> .indexes
table1_index
```

### Index metadata
```
sqlite> pragma index_list('table1');

seq  name          unique  origin  partial
---  ------------  ------  ------  -------
0    table1_index  0       c       0
```

### Unique index
A unique index enforces unique values in the index. Unique indexes function similarly as unique constraints.

```sql
create table table1 (id int, name text);
create unique index table1_index_unique on table1 (id);

insert into table1 values (1, 'hello');
insert into table1 values (1, 'world'); -- duplicate index
Runtime error: UNIQUE constraint failed: table1.id (19)
```

### Multiple column index
Multiple columns indexes are comma separated when creating the index.

```sql
create table table1 (id int, name text, val real);
create index table1_index on table1 (id, val, name);
```

The index order is important. SQLite maintains a sorted list. The example above provides efficient lookup on these queries:
- `id`
- `id`, `val`
- `id`, `val`, `name`

### Drop index
`drop index [if exists] index_name;`

### Index expression

```sql
create index customers_length_company 
on customers(length(company));
```

See [Explain](Explain.md) for a full example.
