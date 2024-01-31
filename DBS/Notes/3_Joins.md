# Joins

#### Natural join using only specific columns

```sql
select * from r1 join r2 using (A1, A2);
```

### Using joins correctly

To select from  ```(instructor natural join teaches)``` x `course`

```sql
select name, title
from instructor natural join teaches, course
where teaches.course_id = course.course_id;
```

Because ```natural join``` works like ```inner join```, the following snippet would not produce the same result. 
```sql
select name, title
from instructor natural join teaches natural join course
```

## References

- [SQL Bolt Lesson 6: Multi-table queries with joins](https://sqlbolt.com/lesson/select_queries_with_joins) (```inner join```)

- [SQL Bolt Lesson 7: Outer Joins](https://sqlbolt.com/lesson/select_queries_with_outer_joins) (```left join```, ```right join```, and ```full join```)

- [StackOverflow answer](https://stackoverflow.com/questions/8696383/difference-between-natural-join-and-inner-join/8696397#8696397) about natural join relates to inner joins

TLDR. Joins are "cross product + selection." ```natural join``` works like ```inner join```, except that columns with matching names are equated.

