-- Question 1
-- ==========

create or replace procedure display_hello is
begin
    dbms_output.put_line('Good day to you.');
end;
/

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
/

begin
    dept_info('&department');
end;
/

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
/

begin
    for r in (select * from department) loop
        course_popular(r.dept_name);
    end loop;
end;
/

-- Question 4
-- ==========

-- SAME AS QUESTION 2!

-- Question 5
-- ==========

create or replace function square(x number) return number is
begin
    return x * x;
end;
/

begin
    dbms_output.put_line(square(5));
end;
/

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
/

declare
    cursor dept_cursor is 
        select distinct dept_name from department;
begin
    for r in dept_cursor loop
        dbms_output.put_line(r.dept_name || ': ' || department_highest(r.dept_name));
    end loop;
end;
/

-- Question 7
-- ==========
create or replace package department_operations is
    procedure list_instructors(v_dept_name department.dept_name%type);
    function max_salary(v_dept_name department.dept_name%type) return number;
end department_operations;
/

create or replace package body department_operations is 
    procedure list_instructors(v_dept_name department.dept_name%type) is
        cursor instructor_cursor is
            select name from instructor where dept_name like v_dept_name;
    begin
        dbms_output.put_line('== ' || v_dept_name || ' instructors ==');
        for i in instructor_cursor loop
            dbms_output.put_line(i.name);
        end loop;
    end;

    function max_salary(v_dept_name department.dept_name%type) return number is
        cursor salary_cursor is
            select salary from instructor where dept_name like v_dept_name;
        v_max_salary number := 0;
    begin
        for i in salary_cursor loop
            if i.salary > v_max_salary then
                v_max_salary := i.salary;
            end if;
        end loop;
        return v_max_salary;
    end;
end department_operations;
/

begin
    department_operations.list_instructors('Comp. Sci.');
    dbms_output.put_line('Highest salary: ' ||
        department_operations.max_salary('Comp. Sci.'));
end;
/
-- Question 8
-- ==========

create or replace procedure compute_interest(
    principal number, roi number, years pls_integer,
    total_sum IN OUT number, 
    simple_interest OUT number, compound_interest OUT number
) is
begin
    total_sum := principal;
    for i in 1..years loop 
        total_sum := total_sum * (1 + roi);
    end loop;
    
    compound_interest := total_sum - principal;
    simple_interest := roi * years * principal;
end;
/

declare
    -- inputs
    principal number := 100;
    roi number := 0.09;
    years pls_integer := 8;

    -- outputs
    total_sum number;
    simple_interest number;
    compound_interest number;
begin
    compute_interest(principal, roi, years, 
        total_sum, simple_interest, compound_interest);

    dbms_output.put_line('Total sum: ' || total_sum);
    dbms_output.put_line('Simple interest: ' || simple_interest);
    dbms_output.put_line('Compound interest: ' || compound_interest);
end;
/