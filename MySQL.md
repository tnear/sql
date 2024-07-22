# MySQL

MySQL is a relational database using a client-server model. It is open-source, owned by Oracle, and written in C++. PostgreSQL is suited for web applications, enterprise solutions, and data warehousing where scalability and concurrency control are needed.

MariaDB was created as a fork when Oracle acquired Sun in 2010.

## Concurrency
Concurrency works similarly as [PostgreSQL](PostgreSQL.md). MySQL uses the InnoDB engine.

## Replication
Replication is done through a binary log (*binlog*). The primary server logs all changes to the binlog, then the replicas read this log and apply the same changes.

Unlike PostgreSQL, MySQL does not support logical replication (which are `update`, `delete`, etc statements which are replayed).
