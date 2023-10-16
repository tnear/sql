# Subquery

https://www.sqlitetutorial.net/sqlite-subquery/

A subquery is a nested query inside an outer query. Subqueries are enclosed in parentheses.

## Syntax

```sql
select column_1
from table_1
where column_1 = (
   select column_1
   from table_2
);
```

## The `=` operator when there is one result

The `=` operator is used when the subquery returns one result. For 1+ results, use `in` (see example in next section).

### Get all tracks from the album 'Greatest Hits II'

The `tracks` and `albums` are joined by `albumId`. The nested query first gets the albumId. The outer query then uses that to query the tracks table for tracks which belong to that album.

`> sqlite3 tutorial/media.db`
```sql
select trackId, name, albumId
from tracks
where albumId =
    (select albumId from albums where title = 'Greatest Hits II');

TrackId  Name                       AlbumId
-------  -------------------------  -------
419      A Kind Of Magic            36
420      Under Pressure             36
421      Radio GA GA                36
422      I Want It All              36
```

## The `in` operator for 1+ results

The `in` operator checks for the existence of a single value within a set of values.

### Return  customers whose sale representatives are in Canada

The `customers` and `employees` tables are linked by the `SupportRepId` (customers) and `EmployeeId` (employees) fields.

`> sqlite3 tutorial/media.db`
```sql
select customerId, firstName from customers
where SupportRepId in
    (select employeeId from employees where Country = 'Canada');

CustomerId  FirstName
----------  ---------
1           Luis
2           Leon
3           Francois
4           Helena
```

### Return albums less than 10 MB

The subquery groups by `albumId` so that tracks of that album are grouped together. `having` applies criteria to these groups so that only records > 10 MB are left. Lastly, the outer query uses the subqueries albumId to get the title of the albums.

`> sqlite3 tutorial/media.db`
```sql
select albumId, title from albums
where albumId in
    (select albumId from tracks
     group by albumId
     having sum(bytes) < 10000000)
order by title;
```
