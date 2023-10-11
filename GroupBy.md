# Group By

`group by` tells SQL `select` to partition results into groups. The result of a `group by` query contains one row for each group. Aggregate functions can operate on these groups.

SQLite supports these aggregate functions: `avg, count, group_concat, max, min, sum`.

## Count
`count(X)` returns a count of the number of times that `X` is not null in a group.

`count(*)` returns the total number of rows in a group.

### Get albums which have the highest number of tracks

Use `group by` to group tracks by albums then use `count(trackId)` to get the number of tracks in each group. Lastly, use `order by` on `count` to get the highest number.

`> sqlite3 tutorial/media.db`
```sql
select albumId, count(trackId)
from tracks
group by albumId
order by count(trackId) desc limit 5;

AlbumId  count(trackId)
-------  --------------
141      57
23       34
73       30
229      26
230      25
```

### Get the album name and track count
This requires joining the `tracks` and `albums` tables on `AlbumId`.

`group by` is added to the albumId to group all songs from an album together. Then, it counts the tracks.

`> sqlite3 tutorial/media.db`
```sql
select albums.albumId, albums.title, count(tracks.trackId)
from albums, tracks
where tracks.albumId = albums.albumId
group by tracks.albumId;

AlbumId  Title              TrackCount
-------  -----------------  ----------
1        Restless and Wild  3
2        Let There Be Rock  8
3        Big Ones           15
```

## Sum
The sum function adds values from each group.

### Get the longest albums

There is a `Milliseconds` field which can be summed to find the total duration of each album.

`> sqlite3 tutorial/media.db`
```sql
select albumId, sum(Milliseconds)
from tracks
group by albumId
order by sum(Milliseconds) desc;

AlbumId  sum(Milliseconds)
-------  -----------------
229      70665582         
253      70213784         
230      64854936         
231      63289631         
228      59780268         
```
