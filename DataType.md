# Data Type

### Dynamic typing

SQLite uses a *dynamic* type system. This is in contract to MySQL and PostgreSQL which use *static* typing. Dynamic typing is when the value(s) in the column determine its data type.

### SQLite data types

SQLite supports five primitive data types known as *storage classes*:

| Data type | Description                                               |
|-----------|-----------------------------------------------------------|
| integer   | Signed integer stored in 0-8 bytes depending on magnitude |
| real      | 8-byte IEEE floating-point number                         |
| text      | String, encoded as UTF-8 or UTF-16                        |
| blob      | Binary large object (BLOB)                                |
| null      | A missing value                                           |

### Unsupported data types
- Boolean (use integer instead). TRUE/FALSE are defined as 1/0, respectively.
- date/time (use text, integer, or real instead).

### `typeof`
The `typeof` function shows you what data type a value is interpreted as by SQLite. See [