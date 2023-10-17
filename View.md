# View

https://www.sqlitetutorial.net/sqlite-create-view/

A view is a virtual table based on the result set of an SQL statement. A view can be a useful abstraction layer where you can add or remove columns without touching the schema. Additionally, a view can be used to encapsulate complex queries to simplify data access.

An SQL view is read-only. You cannot `insert`, `delete`, or `update` into a view table.

## Syntax
```sql
create [temp] view [if not exists] view_name[(column-name-list)]
as 
   select-statement;
```

## Create view
First, create a query that you want to assign a view. Then prefix that query with `create view <name> as <query>`:

`> sqlite3 tutorial/media.db`
```sql
create view v_tracks 
as 
select
    trackid,
    tracks.name,
    albums.title as album,
    media_types.name as media,
    genres.name as genres
from
tracks
inner join albums on albums.albumid = tracks.albumid
inner join media_types on media_types.mediatypeid = tracks.mediatypeid
inner join genres on genres.genreid = tracks.genreid;
```

From now on, you can view this data using the `v_tracks` view:
```sql
select * from v_tracks
limit 1;
```

## Drop view

### Syntax
```sql
drop view [if exists] [schema_name.]view_name;
```

### Example
```sql
drop view v_tracks;
```
