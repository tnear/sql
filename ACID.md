# ACID

https://en.wikipedia.org/wiki/ACID

ACID (atomicity, consistency, isolation, durability) is a set of properties of database transactions intended to guarantee data validity despite errors, crashes, or other issues. The most popular relational databases are typically ACID-compliant.

### Atomicity
Atomicity ensures each transaction is either fully completed or entirely failed, leaving no partial state.

### Consistency
Consistency guarantees that the database moves from one valid state to another, maintaining its rules and constraints.

### Isolation
Isolation ensures multiple transactions can occur concurrently without leading to inconsistencies.

### Durability
Durability guarantees that once a transaction is committed, it will remain in the system even in case of system failures.
