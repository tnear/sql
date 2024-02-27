# Write-Ahead Logging (WAL)

Write-ahead logging is a technique for providing atomicity and durability in database systems. In SQLite, WAL is newer than the *rollback journal*, which is a different mechanism for achieving atomicity and durability.

A WAL is an *append-only* disk structure used for crash and transaction recovery. Changes are first recorded in the log before they are written to the database.

### Comparison of WAL to rollback journal
A rollback journal copies the *old* version of changes to another file so that they can be copied back to the main database when rolling back.

WAL takes the opposite approach: new versions of changes are written to another file and the original database remains unchanged. Periodically, the database performs a *checkpoint* where all pending changes in the WAL are written to the database and the WAL is cleared.

### Change journal_mode setting
The default journal_mode is *delete* which uses a rollback journal. To switch to WAL, run this command

`sqlite> pragma journal_mode=wal;`

### How failures are handled
A system may crash at any point in writing data to a database. Upon restarting, the system checks the log to learn if the last operation finished completely. The system consults the WAL and compares the current database state against the log. Based on this comparison, the program can decide to undo operations or continue to achieve a "safe" state.

### Advantages of WAL over rollback journal
- Faster for most scenarios.
- Provides more concurrency because writers do not block readers.
- Disk I/O operations are more sequential and therefore faster.

### Disadvantages of WAL over rollback journal
- WAL does not work over a network file system (NFS).
- WAL is slightly slower (~2%) for read-heavy applications where writes are rare.
