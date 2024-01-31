# Aggregate functions

Refer [SQLBolt](https://sqlbolt.com/) for practice.

`avg()`, `min()`, `max()`, `sum()`, `count()`

#### Counting distinct instances
```sql
select count (distinct ID)
from teaches
where semester = ’Spring’ and year = 2010;
```

#### Group by and having

```sql
select dept_name, avg(salary) avg_salary
from instructor
group by dept_name
having avg(salary) > 42000;
```

An attribute can appear exclusively inside aggregates, or exclusively outside aggregates. Nothing in between.
