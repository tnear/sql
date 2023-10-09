# Glob

`glob` in SQL is similar to `like` but are case sensitive. Additionally,, glob patterns use UNIX wildcards.

### Wildcards
| Character | Behavior                  |
|-----------|---------------------------|
| `*`       | Matches 0 or more chars   |
| `?`       | Matches one character     |
| `[]`      | Matches one char in range |

### Match prefix using `*`
`> sqlite3 tutorial/media.db`
```sql
sqlite> select name from tracks where name glob 'Wherever*';

Name
---------------------
Wherever I May Roam
Wherever You May Go
Wherever I Lay My Hat
Wherever I May Roam
```

### Match one char using `?`
`> sqlite3 tutorial/media.db`
```sql
sqlite> select name from tracks where name glob '?ere*';

Name
-----------------------
Serenity
Were Do We Go From Here
Jeremy
Here I Go Again
```

### Match songs beginning with three digits using `[]`
`> sqlite3 tutorial/media.db`
```sql
select name from tracks where name glob '[0-9][0-9][0-9]*';

Name
-------------
200 Years Old
100% HardCore
2112 Overture
1979
```
