# Join

A join in SQL combines columns from one or more tables.

SQLite supports three join types:
1. Inner join
1. Left join
1. Cross join

https://www.sqlitetutorial.net/sqlite-join/

## Inner join

An inner join selects records that have matching values in both tables.

In a Venn diagram, an inner join is the *intersection* portion.

### Example using "implicit join" notation (no `join` keyword)
`> sqlite3 tutorial/media.db`

```sql
sqlite> select artists.Name, albums.Title from albums, artists where artists.ArtistId = albums.ArtistId;

Name    Title
------  -------------------
AC/DC   For Those About
Accept  Balls to the Wall
Accept  Restless and Wild
AC/DC   Let There Be Rock
```

### Example with three tables
Get every song, album, and artist.

The `tracks` and `albums` tables are linked by `AlbumId`. The `albums` and `artists` table are linked by `ArtistId`.

```sql
select tracks.trackid, tracks.name, albums.title, artists.name
from tracks, albums, artists
where tracks.albumid = albums.albumid and albums.artistid = artists.artistid;

TrackId  Track            Album                      Artist
-------  ---------------  -------------------------  ----------
1441     Blow Your Mind   Emergency On Planet Earth  Jamiroquai
1442     Revolution 1993  Emergency On Planet Earth  Jamiroquai
1443     Didgin' Out      Emergency On Planet Earth  Jamiroquai
1444     Canned Heat      Synkronized                Jamiroquai
1445     Planet Home      Synkronized                Jamiroquai
```

## Left join

A left outer join selects data starting in the left table and matching rows in the right table. If a row from the left table does not have a matching row in the right table, SQL inserts `NULL` values in the result. *All* rows from the left table will appear in the result set.

In a Venn diagram, a left join is the left portion plus the intersecting portion.

`> sqlite3 tutorial/media.db`
```sql
sqlite>  select artists.Name, albums.Title from artists left join albums on artists.ArtistId = albums.ArtistId order by Name;

Name           Title
-------------  -------------------
A Cor Do Som
AC/DC          For Those About
AC/DC          Let There Be Rock
```

### Find all artists who have zero albums
The artists and albums tables are linked by `ArtistId`. A left join of the two (`artists` on the left) will show albums for all artists and insert `NULL` when there is no match.

This query uses `is null` to filter the results.

```sql
select
   artists.ArtistId,
   AlbumId
from
   artists
left join albums on
   albums.ArtistId = artists.ArtistId
where
   AlbumId is null;
```

## Cartesian product
The Cartesian product is the set of all ordered pairs (*a*, *b*) where *a* is in A and *b* is in *B*.

### Set-builder notation
`A x B = {(a, b) | a ∈ A, b ∈ B}`

### Example

Find the Cartesian product of: `A = {1, 2} B = {a, b, c}`

`A x B = { (1,a),(1,b),(1,c),(2,a),(2,b),(2,c) }`

Note that `A x B != B x A`. For example, `B x A` would include (*a*, *1*) which is not in `A x B`.

### Cardinality
The number of elements in the Cartesian product equals the number of elements in each set multiplied by each other.
```
|A x B| = |A|*|B|
|A x B| = |{1,2}| * |{a,b,c}| = 2 * 3 = 6
```

## Cross join
A cross join is a Cartesian product of rows from the joined tables. A `cross join` combines every row from the first table with every row from the second table. Unlike `inner join` and `left join`, a `cross join` does not have a join condition.

Cross join cannot be visualized by a Venn diagram.

`> sqlite3 tutorial/media.db`
```sql
select * from albums
cross join artists;

AlbumId  Title            ArtistId  ArtistId  Name
-------  ---------------  --------  --------  -----------------
1        For Those About  1         1         AC/DC
1        For Those About  1         2         Accept
1        For Those About  1         3         Aerosmith
1        For Those About  1         4         Alanis Morissette
1        For Those About  1         5         Alice In Chains
```

### Implicit `cross join` syntax
```sql
select * from albums, artists;
```

### Generate a deck of cards

Rank has A, 2-10, J, Q, K (13 rows)

Suit has Clubs, Diamonds, Hearts, Spades (4 rows)

This query produces a 52-card deck:
```sql
select rank,
       suit
  from ranks
       cross join
       suits
order by suit;
```

## Self-join
A self-join is when a table is joined with itself using either `inner join` or `left join`. Doing a self join requires two table aliases for the same table.

Self-join is useful for querying parent/child relationships.

### Get all direct reports for all managers

The employees table has ReportsTo column if they have a manager:

`> sqlite3 tutorial/media.db`
```sql
sqlite> select * from employees limit 1;
Id  LastName  FirstName  Title            ReportsTo
--  --------  ---------  ---------------  ----------
1   Adams     Andrew     General Manager  <null>
2   Edwards   Nancy      Sales Manager    1
3   Peacock   Jane       Sales Agent      2
```

To get this information, create two aliases for the same table then join EmployeeId with ReportsTo:

```sql
sqlite> select m.firstname, m.lastname, r.firstname, r.lastname
from employees m, employees r
where m.employeeid = r.reportsto;

Manager        Report
-------------  ----------------
Andrew Adams   Nancy Edwards
Nancy Edwards  Jane Peacock
Nancy Edwards  Margaret Park
Nancy Edwards  Steve Johnson
```
