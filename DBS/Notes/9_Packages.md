# Packages

### Package specification

```sql
create package asdfghjkl is
    procedure foo;
    procedure bar(arg1 int);
    died_of_laughter exception;
end asdfghjkl;
```

### Package body
```sql
create or replace package body asdfghjkl is
    procedure foo is
    begin
        dbms_output.put_line('foo');
    end;

    procedure bar(arg1 int) is
    begin
        dbms_output.put_line(arg1);
    end;
end asdfghjkl;
```

### Accessing package members
```sql
exec asdfghjkl.foo;
exec asdfghjkl.bar(1);

begin
    asdfghjkl.foo;
end;
```

### IN, OUT, and IN OUT
All procedure and function parameters are marked as `IN` by default. These parameters cannot be modified. Treat them like constants.

`OUT` parameters cannot be read or accessed (not sure), they can only be assigned values to. Assigning values to them modifies the original variable used in the function call. Think of them like pointers.

`IN OUT` is almost like `OUT` but the parameter can be read.
