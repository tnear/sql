# Having

A `having` clause returns rows only when they meet a specified criteria.

`having` is enforced *after* the `group by` clause groups results into buckets. `having` filters out rows which do not meet the constraints.

### Get albums with between 26 and 60 songs

First, this query must group by `albumId` so that all songs belonging to that ID are grouped together. Then, use `having` to filter for albums with between 26 and 60 songs.

`> sqlite3 tutorial/media.db`
```sql
select albumId, count(trackId)
from tracks
group by albumId
having count(trackId) between 26 and 60;

AlbumId  count(trackId)
-------  --------------
23       34
73       30
141      57
229      26

AlbumId  count(albumId)
-------  --------------
23       34
73       30
141      57
229      26
```
