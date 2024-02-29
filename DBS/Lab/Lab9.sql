-- Question 1
-- ==========

create or replace procedure display_hello is
begin
	dbms_output.put_line('Good day to you.');
end;

exec display_hello; -- run this separately

-- Question 2
-- ==========

create or replace procedure dept_info(v_dept_name department.dept_name%type) is
    cursor student_cursor is 
    	select * from student where dept_name like v_dept_name;

	cursor course_cursor is
        select * from course where dept_name like v_dept_name;
begin
    dbms_output.put_line('== Department students ==');
	for s in student_cursor loop
		dbms_output.put_line(s.id || ' ' || s.name);
    end loop;

	dbms_output.put_line('== Department courses ==');
	for c in course_cursor loop
		dbms_output.put_line(c.course_id || ' ' || c.title);
    end loop;
end;

begin
	dept_info('&department');
end;

-- Question 3
-- ==========

create or replace procedure course_popular(v_dept_name department.dept_name%type) is
	cursor course_frequency is
    	select course_id, title, count(*) as enrollment
        from course
        where course.dept_name = v_dept_name
        group by course_id, title;

	v_max_enrollment int := 0;
begin
	for c in course_frequency loop
		if c.enrollment > v_max_enrollment then
    		v_max_enrollment := c.enrollment;
		end if;
    end loop;

	dbms_output.put_line('Most popular courses for ' || v_dept_name);
    for c in course_frequency loop
		if c.enrollment = v_max_enrollment then
			dbms_output.put_line(c.course_id || ' ' || c.title);
        end if;
    end loop;
end;

begin
    for r in (select * from department) loop
		course_popular(r.dept_name);
    end loop;
end;

-- Question 4
-- ==========

-- SAME AS QUESTION 2!

-- Question 5
-- ==========

create or replace function square(x number) return number is
begin
    return x * x;
end;

begin
    dbms_output.put_line(square(5));
end;

-- Question 6
-- ==========

create or replace function department_highest(v_dept_name department.dept_name%type) 
    return instructor.name%type is

    cursor instructor_cursor is
    	select * from instructor where dept_name like v_dept_name;

	v_highest_salary instructor.salary%type := 0;
	v_name instructor.name%type;
begin
	for i in instructor_cursor loop
		if i.salary > v_highest_salary then
			v_name := i.name;
			v_highest_salary := i.salary;
    	end if;
    end loop;

	return v_name;
end;

declare
	cursor dept_cursor is 
		select distinct dept_name from department;
begin
	for r in dept_cursor loop
		dbms_output.put_line(r.dept_name || ': ' || department_highest(r.dept_name));
	end loop;
end;
