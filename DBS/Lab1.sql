create table employees(
	emp_no		number(10),
    emp_name	varchar(40),
    emp_address	varchar(40)
);

insert into employees values(1, 'A', 'Manipal');
insert into employees values(2, 'B', 'Mangalore');
insert into employees values(3, 'C', 'Manipal');
insert into employees values(4, 'D', 'Mangalore');
insert into employees values(5, 'E', 'Mars');

select emp_name from employees;

select * from employees where emp_address='Manipal';

alter table employees add(salary number(12));

update employees set salary=0;

desc employees;

delete from employees where emp_address='Mangalore';

rename employees to employees1;

drop table employees1;