# Cursors

Look up things like `SQL%notfound` in the lab manual.

### Implicit and explicit cursors

Implicit cursor
```sql
begin
    for i in (select * from instructor) loop
		dbms_output.put_line(i.name);
    end loop;
end;
```

Explicit cursor

```sql
declare 
    cursor c is 
    	select * from instructor;
begin
	for i in c loop
		dbms_output.put_line(i.name);
    end loop;
end;
```

### Another example 

```sql
declare
	cs constant student.dept_name%type := 'Comp. Sci.';
	cursor iterator is 
        select name from student where dept_name = cs;
	name student.name%type;
begin
	open iterator;
	loop
        fetch iterator into name;
		exit when iterator%notfound;
		dbms_output.put_line(name);
    end loop;
	close iterator;
end;
```

### For loops

```sql
declare
	cursor dept_iterator is
    	select * from department;
	v_name department.dept_name%type;
    v_budget department.budget%type := 0;
begin
	-- for loops automatically open and close the cursor
	for dept in dept_iterator loop 
		if dept.budget > v_budget then
			v_name := dept.dept_name;
			v_budget := dept.budget;
    	end if;
    end loop;
	dbms_output.put_line(v_name || ': ' || v_budget);
end;
```

### Updating with for loops

Also known as **"while current of" loops**

```sql
declare
	cursor dept_iterator is
    	select * from department for update; -- "for update"
	v_factor float;
begin
    for dept in dept_iterator loop
    	if dept.budget <= 70000 then
    		v_factor := 1.2;
		elsif dept.budget <= 10000 then
            v_factor := 1.15;
		else
            v_factor := 1.1;
		end if;

		-- updating current row
		update department set budget = budget * v_factor 
			where current of dept_iterator;
    end loop;
end;
```

### Parametrized cursors

```sql
declare
	cursor instructor_iterator(v_name instructor.dept_name%type) is
    	select * from instructor where dept_name like v_name;
begin
	for i in instructor_iterator('Comp. Sci.') loop
		dbms_output.put_line(i.id || ' ' || i.name);
    end loop;
end;
```