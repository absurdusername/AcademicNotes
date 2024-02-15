# Lab 6

### Creating the table
```sql
create table student(
    roll_number number primary key,
    gpa number(4, 2)
);

insert into student values(1, 5.8);
insert into student values(2, 6.5);
insert into student values(3, 3.4);
insert into student values(4, 7.8);
insert into student values(5, 9.5);
```

### Question 1

```sql
declare 
	l_roll_number student.roll_number%type;
	l_gpa student.gpa%type;
begin
    l_roll_number := '&roll_number';

	select gpa
	into l_gpa
	from student
	where roll_number = l_roll_number;

	dbms_output.put_line(l_gpa);
end;
```