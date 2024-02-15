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

### Question 3

```sql
declare
    l_issue_date date;
    l_return_date date;
    l_days number;
    l_fine number;
begin
    l_issue_date := to_date('&issue_date', 'DD/MM/YYYY');
    l_return_date := to_date('&return_date', 'DD/MM/YYYY');

    l_days := l_return_date - l_issue_date;
    
    case
    when l_days <= 7 then
        l_fine := 0;
    when l_days >= 8 and l_days <= 15 then
        l_fine := l_days * 1;
    when l_days >= 16 and l_days <= 30 then
        l_fine := l_days * 2;
    else
        l_fine := l_days * 5;
    end case;

    dbms_output.put_line('Fine: ' || l_fine);
end;
/
```
```
