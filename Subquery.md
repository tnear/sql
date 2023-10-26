# Subquery

https://www.sqlitetutorial.net/sqlite-subquery/

A subquery is a nested query inside an outer query. Subqueries are enclosed in parentheses.

## Syntax

```sql
select column_1
from table_1
where column_1 = (
   select column_1
   from table_2
);
```

## The `=` operator when there is one result

The `=` operator is used when the subquery returns one result. For 1+ results, use `in` (see example in next section).

### Get all tracks from the album 'Greatest Hits II'

The `tracks` and `albums` are joined by `albumId`. The nested query first gets the `albumId`. The outer query then uses that to query the tracks table for tracks which belong to that album.

`> sqlite3 tutorial/media.db`
```sql
select trackId, name, albumId
from tracks
where albumId =
    (select albumId from albums where title = 'Greatest Hits II');

TrackId  Name                       AlbumId
-------  -------------------------  -------
419      A Kind Of Magic            36
420      Under Pressure             36
421      Radio GA GA                36
422      I Want It All              36
```

## The `in` operator for 1+ results

The `in` operator checks for the existence of a single value within a set of values.

### Return customers whose sale representatives are in Canada

The `customers` and `employees` tables are linked by the `SupportRepId` (customers) and `EmployeeId` (employees) fields.

`> sqlite3 tutorial/media.db`
```sql
select customerId, firstName from customers
where SupportRepId in
    (select employeeId from employees where Country = 'Canada');

CustomerId  FirstName
----------  ---------
1           Luis
2           Leon
3           Francois
4           Helena
```

### Return albums less than 10 MB

The subquery groups by `albumId` so that tracks of that album are grouped together. `having` applies criteria to these groups so that only records > 10 MB are left. Lastly, the outer query uses the subqueries albumId to get the title of the albums.

`> sqlite3 tutorial/media.db`
```sql
select albumId, title from albums
where albumId in
    (select albumId from tracks
     group by albumId
     having sum(bytes) < 10000000)
order by title;
```

### Named subquery + `left join`
This query gets a list of all teachers and how many students they teach.

The subquery gets the number of students for all teachers who have a non-zero number of students. The subquery also has a name, `StudentSize` because its values will be referenced by the outer query.

The outer query uses `left join` with the Teachers table because we need *all* teachers (including ones with zero student count). The `ifnull` function translates `null` values coming from `left join` into zeros. The outer query joins the TeacherID from the Teacher table with the TeacherID from the inner query which comes from the Courses table.

```sql
select Teachers.TeacherID, Teachers.TeacherName, ifnull(StudentSize.Number, 0) as StudentCount
from Teachers left join
    (
        select TeacherID, count(Courses.TeacherID) as Number from Courses, StudentCourses
where Courses.CourseID = StudentCourses.CourseID
group by Courses.TeacherID
    ) StudentSize
on Teachers.TeacherID = StudentSize.TeacherID;

TeacherID  TeacherName  StudentCount
---------  -----------  ------------
1          Chen         3
2          Jones        4
3          Smith        0
4          Wang         0
```

<!--
Full data and schema:

SQLite:
```sql
create table Courses (CourseID integer primary key, CourseName text, TeacherID integer);
create table Teachers (TeacherID integer primary key, TeacherName text);
create table Students (StudentID integer primary key, StudentName text);
create table StudentCourses (CourseID integer, StudentID integer, primary key (CourseID, StudentID));

insert into Teachers (TeacherName) values ('Chen');
insert into Teachers (TeacherName) values ('Jones');
insert into Teachers (TeacherName) values ('Smith');
insert into Teachers (TeacherName) values ('Wang');

insert into Students (StudentName) values ('Adam');
insert into Students (StudentName) values ('Chris');
insert into Students (StudentName) values ('Michael');
insert into Students (StudentName) values ('Robert');
insert into Students (StudentName) values ('Zachary');

insert into Courses (CourseName, TeacherID) values ('Security', 1);
insert into Courses (CourseName, TeacherID) values ('Networking', 2);
insert into Courses (CourseName, TeacherID) values ('Cryptography', 3);
insert into Courses (CourseName, TeacherID) values ('Operating Systems', 1);

insert into StudentCourses values (1, 1);
insert into StudentCourses values (1, 2);
insert into StudentCourses values (2, 1);
insert into StudentCourses values (2, 2);
insert into StudentCourses values (2, 3);
insert into StudentCourses values (2, 4);
insert into StudentCourses values (4, 1);
```
-->
