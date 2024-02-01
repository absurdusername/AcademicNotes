## Set Operations

```sql
create view fall2009 as
select course_id, title from course natural join section where (semester='Fall' and year=2009);

create view spring2010 as
select course_id, title from course natural join section where (semester='Spring' and year=2010);
```

#### Union: Find courses that ran in Fall 2009 OR Spring 2010
```sql
select * from fall2009 
union
select * from spring2010;
```

#### Intersection: AND
```sql
select * from fall2009 
intersect
select * from spring2010;
```

#### Minus
```sql
select * from fall2009 
minus
select * from spring2010;
```

#### Zero-student courses
```sql
select title from course
minus
select title from course natural join takes;
```


### Nested Queries

```sql
select * from fall2009
where course_id in (
    select course_id
    from section
    where semester = 'Spring' and year = 2010
);
```

```sql
select count(distinct takes.ID)
from takes
where course_id in (
    select course_id
    from teaches
    where teaches.ID = 10101
);
```

```sql
select * from fall2009 
where course_id not in (
    select course_id
    from section
    where semester = 'Spring' and year = 2010
);
```

```sql
select name
from student 
where name in (
    select name
    from instructor
);
```

### Set comparision

```sql
select name
from instructor
where salary > some (
    select salary
    from instructor
    where dept_name = 'Biology'
);
```

```sql
select name
from instructor
where salary > all (
    select salary
    from instructor
    where dept_name = 'Biology'
);
```

```sql
select dept_name, avg(salary) dept_avg_salary
from instructor
group by dept_name
having avg(salary) >= all (
    select avg(salary)
    from instructor
    group by dept_name
);
```

```sql
select dept_name
from department
where budget < (
    select avg(salary)
    from instructor
);
```

### Test for empty relations

```sql
select * from fall2009
where exists (
    select *
    from course natural join section
    where semester = 'Spring' and year = 2010
);
```

```sql
select S.ID, S.name
from student S
where not exists (
    select course_id from course C where C.dept_name = 'Biology'
    minus
    select course_id from takes T where T.ID = S.ID
);
```

### Test for absence of duplicates

```sql
select C.course_id
from course C
where 1 >= (
    select count(*)
    from section S
    where S.year = 2009 and S.course_id = C.course_id
);
```

```sql
select S.ID, S.name
from student S
where 2 >= (
    select count(*)
    from takes T
    where T.ID = S.ID
);
```

### Subqueries in the from clause

```sql
select dept_name, avg_salary
from (
    select dept_name, avg(salary) as avg_salary
    from instructor
    group by dept_name
) having avg_salary > 42000;
```

### Views

```sql
create view all_courses as 
select building, room_number
from section
where semester = 'Fall' and year = 2009
and course_id in (
    select course_id
    from course
    where dept_name = 'Physics'
);
```

```sql
select * from all_courses;
```

### Question twenty

`lateral`
```sql
create view department_total_salary as
select D.dept_name, total_salary
from department D, lateral (
    select sum(I.salary) as total_salary
    from instructor I
    where D.dept_name = I.dept_name
);
```

`with`
```sql
with department_salaries(dept_name, value) as (
    select dept_name, sum(salary) as value
    from instructor
    group by dept_name
) select department.dept_name, value
from department, department_salaries
where department.dept_name = department_salaries.dept_name;
```