# Lab Four

### Group by

#### 1
```sql
select course_id, count(*)
from takes
group by course_id;
```

#### 2
```sql
select dept_name
from student
group by dept_name
having count(*) >= 10;
```

#### 3
```sql
select dept_name, count(*) 
from course
group by dept_name;
```

#### 4
```sql
select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary) > 42000;
```

#### 5
```sql
select course_id,sec_id, count(*)
from takes
group by (course_id,sec_id, semester, year)
having semester = 'Spring' and year = 2009;
```

### Ordering

#### 6

```sql
select *
from prereq
order by course_id asc;
```

#### 7
```sql
select *
from instructor
order by salary desc;
```

#### 8
```sql
select max(tot_salary)
from (
    select dept_name, sum(salary) as tot_salary
	from instructor
	group by dept_name
);
```

#### 9
```sql
select dept_name, avg_salary
from (
    select dept_name, avg(salary) as avg_salary
    from instructor
    group by dept_name
) where avg_salary > 42000;
```

#### 10
```sql
select course_id, sec_id, enrolment
from (
    select course_id, sec_id, semester, year, count(*) as enrolment
    from takes
    group by (course_id, sec_id, semester, year)
) where semester = 'Spring' and year = 2010;
```







