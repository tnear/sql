# Having

A `having` clause dictates that only rows should be returned when they meet the specified criteria.

`having` is enforced after `group by` groups results into buckets. `having` filters out rows which do not meet the specified constraints.

### Get albums with more than 25 songs

First, this query must group by albumId so that all songs belonging to that ID are grouped together. Then, use `having` to filter for albums with more than 25 songs.

`> sqlite3 tutorial/media.db`
```sql
select albumId, count(albumId)
from tracks
group by albumId
having count(albumId) > 25;

AlbumId  count(albumId)
-------  --------------
23       34
73       30
141      57
229      26
```
