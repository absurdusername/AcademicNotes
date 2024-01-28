#### Union: Find courses that ran in Fall 2009 OR Spring 2010
```sql
select course_id, title from course natural join section where (semester='Fall' and year=2009) 
union
select course_id, title from course natural join section where (semester='Spring' and year=2010);
```

#### Intersection: AND
```sql
select course_id, title from course natural join section where (semester='Fall' and year=2009) 
intersect
select course_id, title from course natural join section where (semester='Spring' and year=2010);
```

#### Minus
```sql
select course_id, title from course natural join section where (semester='Fall' and year=2009) 
minus
select course_id, title from course natural join section where (semester='Spring' and year=2010);
```

#### Zero-student courses
```sql
select title from course
minus
select title from course natural join takes;
```