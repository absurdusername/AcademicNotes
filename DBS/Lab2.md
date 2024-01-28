## Questions 1 to 8

#### Creating table employees
```sql
create table employees(
	emp_id		int				primary key,
    emp_name	varchar(40)		not null,
    gender		char(1)			not null,
    salary		number(12, 2)	not null,
    address		varchar(40)		not null,
    dept_id		int,
    check(gender in ('M', 'F'))
);
```

#### Creating table departments
```sql
create table departments(
    dept_id		int				primary key,
    dept_name	varchar(40)		unique,
    location	varchar(40)
);
```

#### Adding foreign key to employees
```sql
alter table employees
add constraint dept_id_const
foreign key(dept_id) 
references departments(dept_id);
```

#### Inserting tuples into employees and departments
```sql
insert into employees values(1, 'A', 'M', 99999, 'A address', 1);
insert into departments values(1, 'alphabet', 'alphabet address');
insert into employees values(2, '-1', 'M', 99999, '-1 address', 2);
insert into departments values(2, 'numbers', 'numbers address');
```

#### Inserting invalid tuples
```sql
insert into employees values(1, NULL, 'Invalid Gender', NULL, NULL, 12);
insert into departments values(12, 'alphabet', 'sad location');
```

#### Modifications violating a constraint
```sql
update departments 
set dept_id=3 
where dept_name='alphabet';

update employees 
set dept_id=3 
where dept_id=1;
```

#### Dropping old constraint, adding new one
```sql
alter table employees
drop constraint dept_id_const;

alter table employees
add constraint dept_id_const
	foreign key(dept_id) 
    references departments(dept_id)
	on delete cascade;
```

#### Modifying default
```sql
alter table employees 
modify salary default 1000;
```

#### Cleaning up
```sql
drop table employees;
drop table departments;
```

## Questions 9 to 25

#### Retrieving records from a table
```sql
select name, dept_name from student;

select name from instructor where dept_name='Comp. Sci.';

select title from course where credits=3;

select course.course_id as course_id, course.title as course_title
from takes
left join course
	on takes.course_id = course.course_id
where id = '12345';

select name from instructor where salary 
between 40000 and 90000;
```

#### Retrieving records from multiple tables
```sql
select name
from instructor 
left join teaches
	on teaches.id = instructor.id
where teaches.course_id is NULL;

select name, course_id, year
from student natural join takes natural join section
where room_number='514';
```

#### 16 and 17
```sql
select name, course_id as "c-name" 
from student natural join takes 
where year = 2015;

select name, salary as "inst-salary"
from instructor
where salary > (
    select min(salary)
    from instructor
    where dept_name = 'Comp. Sci.'
);
```

#### 18
```sql
select * from instructor where dept_name like '%ch';
```

#### 19 to 23
```sql
select name, length(name) from instructor;
select dept_name, substr(dept_name, 3, 3) from department;
select upper(name) from instructor;
update instructor set dept_name='Unassigned' where dept_name is null;
select salary, round(salary/3, 2) from instructor;
```

#### 24 and 25
```sql
select to_char(to_date(dob, 'DDMMYYYY'), 'Mon DD, YYYY');
select name, to_char(to_date(dob, 'DDMMYYYY'), 'YEAR');
```