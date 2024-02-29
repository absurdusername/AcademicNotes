-- Question 1
-- ==========

create or replace procedure display_hello is
begin
	dbms_output.put_line('Good day to you.');
end;

exec display_hello; -- run this separately

-- Question 2
-- ==========

create or replace procedure dept_info(v_dept_name department.dept_name%type) isc
    cursor instructor_cursor is 
    	select name 
    	from department natural left join instructor
    	where dept_name like v_dept_name;

	cursor course_cursor is
        select course_id, title
        from department natural left join course
        where dept_name like v_dept_name;
begin
    dbms_output.put_line('== Instructors ==');
	for i in instructor_cursor loop
    	dbms_output.put_line(i.name);
    end loop;

	dbms_output.put_line('== Courses ==');
	for c in course_cursor loop
		dbms_output.put_line(c.course_id || ' ' || c.title);
    end loop;
end;

begin
	dept_info('Comp. Sci.');
end;
