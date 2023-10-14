# Like

The SQL `like` operator allows for searching strings which match simple patterns.

### Wildcards
| Character | Behavior                |
|-----------|-------------------------|
| `%`       | Matches 0 or more chars |
| `_`       | Matches one character   |

### Get all genres beginning with 'S'
`> sqlite3 tutorial/media.db`
```sql
select * from genres
where Name like 'S%';

GenreId  Name
-------  ----------------
10       Soundtrack
18       Science Fiction
20       Sci Fi & Fantasy
```

### Get all genres with 'a' as the second character
`> sqlite3 tutorial/media.db`
```sql
select * from genres
where Name like '_a%';

GenreId  Name
-------  --------------
2        Jazz
7        Latin
12       Easy Listening
```

### Case insensitive
`like` queries are case insensitive. This query matches `finish` both lowercase and capitalized:

`> sqlite3 tutorial/media.db`
```sql
select Name from tracks
where Name like '%finish%';

Name
---------------------
Nice Guys Finish Last
Unfinished Business
```

### Without wildcard
An SQL query without a wildcard character does an exact match:

`select * from genres where Name like 'Opera';`

### Escape clause
Get all songs with '%' in the name. This requires escaping '%' with '\%' then using the `escape` clause to tell SQLite the escape char, `\`.

`> sqlite3 tutorial/media.db`
```sql
sqlite> select Name from tracks where Name like '%\%%' escape '\';

Name
-------------
100% HardCore
.07%
```
