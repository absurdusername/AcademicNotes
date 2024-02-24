
-- Question 1
-- ==========

create table salary_raise(
    id	varchar2(5),
    raise_date date,
    raise_amount number(8, 2)
);

declare
	cursor instructor_iterator(v_name instructor.dept_name%type) is
    	select * from instructor 
    		where dept_name like v_name 
    		for update;

	v_raise constant instructor.salary%type := 500;
begin
	for i in instructor_iterator('Comp. Sci.') loop
		update instructor set salary = salary + v_raise
    		where current of instructor_iterator;

		insert into salary_raise values(i.id, current_date, v_raise);
    end loop;
end;

-- Question 2
-- ==========

declare
	cursor c is 
    	select * from student order by tot_cred;
begin
	for s in c loop
    	dbms_output.put_line(s.name || ', ' || s.tot_cred);
		exit when c%rowcount = 10;
    end loop;
end;

-- Question 3
-- ==========

/*
-- for a complete solution, use
select distinct course_id, title, C.dept_name, credits, name, building, room_number, time_slot_id,
    (select count(*) as total_students from takes T where T.course_id = course_id) as total_students
    from course C
    left join section using(course_id)
    left join (teaches natural join instructor) using(course_id);
*/


declare
	cursor c is
		select *
    	from course C, lateral(
    		select count(*) as total_students
    		from takes T
    		where T.course_id = C.course_id
        );
begin
	for r in c loop
		dbms_output.put_line(r.course_id || ' ' || r.title || ' ' || r.total_students);
    end loop;
end;

-- Question 4
-- ==========

-- "where current of" can't be used here. Iterated table is different from modified table.
declare 
    cursor c is
    select * from student S
        where exists(select * from takes T where T.course_id like 'CS-101')
    for update;
begin
    for s in c loop
		if s.tot_cred < 30 then
			delete from takes
    		where s.id = takes.id;
    	end if;
    end loop;
end;

-- Question 5
-- ==========

-- creating the table
create table student2(
    roll_number number primary key,
    gpa number(4, 2)
);

insert into student2 values(1, 5.8);
insert into student2 values(2, 6.5);
insert into student2 values(3, 3.4);
insert into student2 values(4, 7.8);
insert into student2 values(5, 9.5);

alter table student2 add letter_grade varchar2(2);

-- now the actual solution
declare 
	cursor c is select * from student2 for update;
	v_grade student2.letter_grade%type;
begin
	for s in c loop
		if s.gpa >= 9 then
    		v_grade := 'A';
		elsif s.gpa >= 8 then
            v_grade := 'A';
		else 
			v_grade := 'F';
        end if;

		update student2
        set letter_grade = v_grade
        where current of c;
    end loop;
end;

-- Question 6
-- ==========

declare
	cursor c(v_course_id teaches.course_id%type) is
    select * from teaches natural left join instructor
    where course_id like v_course_id;
begin
	for i in c('CS-101') loop
		dbms_output.put_line(i.name);
    end loop;
end;

-- Question 7
-- ==========

declare
	cursor c is
        select s_id, name from advisor A 
    	left join student on A.s_id = student.id
        where exists (
            select * from takes T
            where T.id = A.s_id and T.course_id in (
                select course_id from teaches 
                where teaches.id = A.i_id
            )
        );
	v_name student.name%type;
begin
	for s in c loop
		dbms_output.put_line(s.s_id || ' ' || s.name);
    end loop;
end;
