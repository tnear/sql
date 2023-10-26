# Dense Rank

https://www.sqlitetutorial.net/sqlite-window-functions/sqlite-dense_rank/

`dense_rank` is a window function that computes the rank of a row, returned an integer.

### Syntax
```sql
dense_rank() over
(
    partition by expression1, expression2,...
    order by expression1 [asc | desc], expression2,..
)
```

### Get rank (order) of text (no partitions)
```sql
create table DenseRankDemo (val text);
insert into DenseRankDemo values ('a'),('b'),('c'),('d'),('e');

select val, dense_rank() over
(
    order by val
) as Rank
from DenseRankDemo;

val  Rank
---  ----
a    1
b    2
c    3
d    4
e    5
```

### Rank all songs within an album (partition example)
This uses `partition by` `albumId` so that `dense_rank` ranks all song lengths within an album.

```sql
select
    albumId,
    name,
    milliseconds,
    dense_rank () over
    (
        partition by albumId
        order by milliseconds
    ) as LengthRank
from tracks;

AlbumId  Name                   Milliseconds  LengthRank
-------  ---------------------  ------------  ----------
1        Dog Eat Dog            215196        1
1        Breaking the Rules     254380        2
1        Bad Boy Boogie         267728        3
2        Deuces Are Wild        215875        1
2        Blind Man              240718        2
3        Right Through You      176117        1
3        Perfect                188133        2
3        Hand In My Pocket      221570        3
3        Not The Doctor         227631        4
```

Each song within an album is ranked according to Milliseconds.
