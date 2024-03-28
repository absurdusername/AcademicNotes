-- Question 1

create table log_change_takes(
	time_of_change 	date,
    id				varchar2(5),
    course_id		varchar2(8),
    sec_id			varchar2(8),
    semester		varchar2(6),
    year			number(4, 0),
    grade			varchar2(2)
);

create or replace trigger takes_logger
before insert or update or delete on takes
for each row
begin
	insert into log_change_takes values(sysdate, :OLD.id, :OLD.course_id, 
    	:OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
end;

-- to demonstrate
delete from takes;
select * from log_change_takes;

-- Question 2

create table old_data_instructor(
    id			varchar2(5),
    name		varchar2(20),
    dept_name	varchar2(20),
    salary		number(8, 2)
);

create or replace trigger instructor_logger
before update of salary on instructor
for each row
begin
	insert into old_data_instructor values(:OLD.id, :OLD.name, 
    	:OLD.dept_name, :OLD.salary);
end;

-- to demonstrate
update instructor set salary = 100000 where dept_name like 'Comp. Sci.';
select * from old_data_instructor;

-- Question 3

create or replace trigger instructor_validator
before insert or update on instructor
for each row
declare
    v_dept_budget number;
begin
    select budget into v_dept_budget from department where :NEW.dept_name like dept_name;

    if :NEW.name not like '%' then -- fix this regex
		raise_application_error(-20100, 'Invalid instructor name');
    end if;

	if :NEW.salary <= 0 then
		raise_application_error(-20100, 'Instructor salary is not a positive number');
    end if;

	if :NEW.salary > v_dept_budget then
		raise_application_error(-20100, 'Instructor salary exceeds department budget');
    end if;
end;

-- to demonstrate an error
insert into instructor values(52343, 'Krishanu', 'Comp. Sci.', 999999);