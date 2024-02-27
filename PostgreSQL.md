# PostgreSQL

PostgreSQL is a relational database using a client-server model. It is open-source and written in C. PostgreSQL is suited for web applications, enterprise solutions, and data warehousing where scalability and concurrency control are needed.

## Concurrency
PostgreSQL supports locking and concurrency control, making it appropriate for applications with high concurrency and transactional requirements.

### Multiversion concurrency control (MVCC)
MVCC allows multiple transactions to access the same data simultaneously without blocking each other. MVCC ensures that each transaction sees a *snapshot* of the database. When a transaction modifies data, it does not overwrite the existing data. Instead, it creates a new version of the data.

MVCC follows this process:

- Snapshots: When a transaction reads data, it sees a consistent snapshot of the database as it existed at the start of the transaction. This means that reading transactions do not block writing transactions and vice versa.
- Versioning: Each row version has transaction IDs for creation and expiration. A transaction can see a row version if it was created before the transaction started and has not expired (been overwritten or deleted) by the time the transaction began.
- Vacuum: Over time, the creation of multiple versions of data can lead to bloat. PostgreSQL runs a process called "vacuum" to clean up old row versions that are no longer visible to any transactions.

### Locking
- Row-level locking: while a row is being updated or deleted, other transactions can still read the last committed value.
- Table-level locking (less common): typically reserved for dropping and truncating tables.

## Replication
Replication in PostgreSQL copies data from a primary database to standby databases for redundancy, high availability, and load balancing.

### Types of Replication
- Physical Replication: Copies binary data to standby servers, ensuring an exact copy of the primary. It supports both synchronous and asynchronous modes.
- Logical Replication: Transmits data changes at the statement level (ex: `insert`, `update`, and `delete` statements).

### Process
- Physical Replication uses Write-Ahead Logging (WAL) files. Changes are first logged in WAL files on the primary, then shipped and replayed on standby servers.
- Logical Replication operates on a publication and subscription model, where the primary publishes changes, and standbys subscribe to receive only specified data.
