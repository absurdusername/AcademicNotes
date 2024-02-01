# Lab Four

### Group by

#### 1
```sql
select course_id, count(*) as n_students
from (course natural join takes)
group by course_id;
```

#### 2
```sql
select dept_name, count(*) as n_students
from (department natural join student) 
group by dept_name
having count(*) > 10;
```

#### 3
```sql
select dept_name, count(*) as n_courses
from (department natural join course)
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
select course_id,sec_id, count(*) as enrollment
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

### Derived relations

These can typically be rewritten with `with`.

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
with section_enrollment as (
    select course_id, sec_id, count(*) as enrollment
    from takes
    where semester = 'Spring' and year = 2010
    group by (course_id, sec_id)
)
select * 
from section_enrollment
where enrollment = (
    select max(enrollment)
    from section_enrollment
);
```

#### 11
```sql
with pairs(instructor_id, student_id) as (
    select teaches.ID, takes.ID
    from takes join teaches using(course_id, sec_id, semester, year)
)
select name
from instructor I
where not exists (
	select student.ID
    from student
    where student.dept_name = 'Comp. Sci.' and 
    	(I.ID, student.ID) not in (select * from pairs)
);
```

Alternatively

```sql
select I.name from instructor I 
where not exists (
    select *
    from student S
    where S.dept_name = 'Comp. Sci.' and 
        not exists (
    		select * 
    		from takes join teaches using(course_id, sec_id, semester, year)
    		where takes.ID = S.ID and teaches.ID = I.ID
        )
);
```

#### 12

```sql
select dept_name
from department natural join instructor
group by dept_name
having avg(salary) > 50000 and count(*) > 5;
```

### With clause

#### 13

```sql
with max_budget(value) as (
    select max(budget) from department
)
select dept_name, budget
from department, max_budget
where department.budget = max_budget.value;
```

#### 14

```sql
with dept_total (dept_name, value) as (
    select dept_name, sum(salary)
    from instructor
    group by dept_name
), 
dept_total_avg(value) as (
    select avg(value) from dept_total
)
select dept_name, dept_total.value
from dept_total, dept_total_avg
where dept_total.value >= dept_total_avg.value;
```

