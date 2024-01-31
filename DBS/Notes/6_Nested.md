# Nested Queries

### Set membership

```sql
select ...
where col in (select ...);
```

### Set comparision

#### Some

To find instructors with salary greater than that of at least one instructor in the Biology department.

```sql
select name
from instructor
where salary > some (
    select salary
    from instructor
    where dept_name = 'Biology'
);
```
Also supported with `some()` are `>=`, `<`, `<=`, `<>`, and `=`.

`= some()` is identical to `in` and `<> some()` is identical to `not in`.

#### Any

To find the department with the highest average salary

```sql
select dept_name 
from instructor
group by dept_name
having avg(salary) > all(
    select avg(salary) 
    from instructor
    group by dept_name
);
```

### Test for empty relations

```sql
select course
from section S
where semester = 'Fall' and year = 2009 and
    exists(
        select * 
        from section T
        where semester = 'Spring' and year = 2010 and
            S.course_id = T.course_id
    );
```

This is a correlation subquery, because `S` from the outer query is used in the subquery.