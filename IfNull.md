# ifnull

SQLite's `ifnull` function accepts two arguments and returns the first non-null argument.

`ifnull` is similar to [coalesce](Coalesce.md) with two arguments.

### Basic usage
```sql
select ifnull(null, 10);

ifnull(null, 10)
----------------
10
```

### Left join example
`left join` introduces `null` values when data is in the left table but not the right. The example below has one `null` title:

```sql
select artists.Name, albums.Title from artists
left join albums on artists.ArtistId = albums.ArtistId
order by Name desc limit 15;

Name             Title
---------------  ----------------------
Zeca Pagodinho   Ao Vivo [IMPORT]
Youssou N'Dour
Yo-Yo Ma         Bach: The Cello Suites
```

One way to replace `null` values is to use `ifnull`:
```sql
select artists.Name, ifnull(albums.Title, '<no title>')
from artists
left join albums on artists.ArtistId = albums.ArtistId
order by Name desc;

Name             Title
---------------  ----------------------
Zeca Pagodinho   Ao Vivo [IMPORT]
Youssou N'Dour   <no title>
Yo-Yo Ma         Bach: The Cello Suites
```
