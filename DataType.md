# Data Type

### SQLite data types
| Data type | Description                                               |
|-----------|-----------------------------------------------------------|
| INTEGER   | Signed integer stored in 0-8 bytes depending on magnitude |
| REAL      | 8-byte IEEE floating-point number                        |
| TEXT      | String, encoded as UTF-8 or UTF-16                        |
| BLOB      | Binary large object (BLOB)                                |  
| NULL      | A missing value                                           |

### Unsupported data types
- Boolean (use integer instead). TRUE/FALSE are defined as 1/0, respectively.
- date/time (use text, integer, or real instead).
