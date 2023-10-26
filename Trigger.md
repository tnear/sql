# Trigger

https://www.sqlitetutorial.net/sqlite-trigger/

A SQLite `trigger` is a named database object that is executed automatically when an `insert`, `update`, or `delete` statement is issued against the associated table. Triggers are useful for logging changes to sensitive information such as salaries.

### Syntax
```sql
create trigger [if not exists] trigger_name
    [before|after|instead of] [insert|update|delete]
    on table_name
    [when condition]
begin
    statements;
end;
```

### Example
First, create a table for all business leads in a company.
```sql
create table leads (
    id integer primary key,
    first_name text not null,
    last_name text not null,
    phone text not null,
    email text not null,
    source text not null
);
```

Next, create a trigger.
```sql
create trigger validate_email_before_insert_leads
    before insert on leads
begin
    select
        case
            when new.email not like '%_@__%.__%' then
                raise (abort, 'invalid email address')
            end;
end;
```

Lastly, insert an invalid email address.
```sql
insert into leads (first_name,last_name,email,phone)
values('john', 'doe', 'jjj', '4089009334');

Runtime error: invalid email address (19)
```

### Drop trigger
Syntax: `drop trigger [if exists] trigger_name;`
