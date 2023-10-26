# Dump

The `dump` command in SQLite transforms the database records into a plaintext file.

By default, `dump` outputs contents to the screen. To set a file, use the `output` command.

### Dump to file
`> sqlite3 tutorial/media.db`
```sql
.output data.dmp
.dump
```
```shell
$ cat data.dmp

PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "albums"
(
    [AlbumId] INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    [Title] NVARCHAR(160)  NOT NULL,
    [ArtistId] INTEGER  NOT NULL,
    FOREIGN KEY ([ArtistId]) REFERENCES "artists" ([ArtistId])
		ON DELETE NO ACTION ON UPDATE NO ACTION
);
INSERT INTO albums VALUES(1,'...',1);
...
```

### Dump specific table
```sql
.dump [table]
```

