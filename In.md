# In

https://www.w3schools.com/sql/sql_in.asp

The `in` operator allows you to specify multiple values in a `where` clause.

```sql
select * from customers
where Country in ('Germany', 'France', 'UK');
```

### Subquery

`> sqlite3 tutorial/media.db`

#### Get the albums for a particular artist
```sql
select AlbumID from Albums where ArtistId = 248;

AlbumId
-------
316
320
```

To find the tracks in albums 316 or 320, use the `in` operator with a subquery:

```sql
select * from Tracks
where AlbumId in
    (select AlbumId from Albums where ArtistId = 248);

TrackId  Name                         AlbumId  Composer
-------  ---------------------------  -------  ---------------
3450     Peer Gynt Suite No.1, Op.46  316      Edvard Grieg
3454     Symphony No. 41 in C Major   320      Mozart
3491     Le Sacre Du Printemps: I.iv  320      Igor Stravinsky
```

### `not in`
`not in` inverts the operation. It will return all records which are NOT equal to any of the values in the list.

```sql
select * from customers
where Country not in ('Germany', 'France', 'UK');
```
