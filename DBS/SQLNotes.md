# SQL Notes

## Lab One

#### Creating a table
```sql
create table employees(
    name			varchar(40),
    dob				date,
    compensation	number(12, 2),
    productivity    number(3, 1)
);
```

#### Adding, modifying, and dropping columns
```sql
alter table employees add(department char(3));
alter table employees modify(department varchar(3));
alter table employees drop column department;
```

#### Inserting values
```sql
insert into employees values('Anon', '01-Jan-1990', 1, 1);
insert into employees(name, compensation) values('John Doe', 9999999);
```

#### Selecting
```sql
select * from employees;
select compensation as employee_compensation from employees;
select productivity / compensation from employees;
```

#### Updating
```sql
update employees set productivity=0;
update employees set productivity=1, compensation=1 where name='John Doe';
```

#### Deleting
```sql
delete from employees where name='Anon';
delete from employees;
```

#### Renaming, truncating, and deleting
```sql
rename employees to slaves;
truncate table slaves;
drop table slaves;
```

## Lab Two

#### Creating tables with constraints

```sql
create table employees(
    id				int             primary key,
    another_id		int             unique,
    name			varchar(40)     not null,
    department      char(3)         default('DEF') check(department in ('ABC', 'DEF'))
);

create table slaves(
    slave_id	int,
    primary key(slave_id),
    foreign key(slave_id) references employees,
    foreign key(slave_id) references another_table on delete cascade
);

create table another_way(
    id  int references employees(id) on delete cascade
);
```

#### Externally adding named constraints

```sql
alter table slaves
add constraint constraint_name
check (id != 0);

alter table slaves
drop constraint constraint_name;
```

#### Externally adding unnamed constraints
These could have easily been named constrained, by the way.

```sql
alter table slaves
add check(id != 0);

alter table slaves
add primary key(id);

alter table slaves
add foreign key(id) references some_other_table;
```

#### To externally add a not null or default constraint
```sql
alter table slaves
modify id not null;

alter table slaves 
modify salary default 1000;
```

#### Joins 

[SQL Bolt Lesson 6: Multi-table queries with joins](https://sqlbolt.com/lesson/select_queries_with_joins) (inner joins)

[SQL Bolt Lesson 7: Outer Joins](https://sqlbolt.com/lesson/select_queries_with_outer_joins) (left, right, and full joins)

This [StackOverflow answer](https://stackoverflow.com/questions/8696383/difference-between-natural-join-and-inner-join/8696397#8696397) illuminates the details of natural joins. 

TLDR: Joins are "cross product + selection." Natural joins are like inner joins, but they help you be lazy.

## Lab Three

#### Set operations
```sql
[select query]
union/intersect/minus
[another select query]
```

#### Create view
```sql
create view view_name as
[select query]
```

## Resources

[LiveSQL](https://livesql.oracle.com) by Oracle, run SQL queries here

[SQLBolt](https://sqlbolt.com/) for basics

[Oracle-specific SQL tutorial](https://www.oracletutorial.com/) for intermediate reference


#### To list all tables
```sql
select table_name from user_tables;
```
