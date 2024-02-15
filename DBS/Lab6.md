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

### Question 1 and 2

```sql
declare 
	l_roll_number student.roll_number%type;
	l_gpa student.gpa%type;
	l_letter_grade varchar(2);
begin
    l_roll_number := '&roll_number';

	select gpa
	into l_gpa
	from student
	where roll_number = l_roll_number;

    if l_gpa >= 9 then
        l_letter_grade := 'A+';
    elsif l_gpa >= 8 then
        l_letter_grade := 'A';
    elsif l_gpa >= 7 then
        l_letter_grade := 'B';
    elsif l_gpa >= 6 then
        l_letter_grade := 'C';
    elsif l_gpa >= 5 then
        l_letter_grade := 'D';
    else
        l_letter_grade := 'F';
    end if;

    dbms_output.put_line('GPA: ' || l_gpa);
    dbms_output.put_line('Letter grade: ' || l_letter_grade);
end;
```
