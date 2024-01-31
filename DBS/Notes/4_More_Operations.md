# More Operations

#### String matching, where clause predicates, ordering

```%``` matches any substring, ```_``` matches one character. ```\``` is the escape character. 

#### Set operations

- ```union```
- ```intersect```
- ```minus``` 

#### Null values

In the `where` clause, comparisions like `1 > null` or `0 > null` evaluate to "unknown." `where` only selects the tuples where the predicate evaluates to `true`.

- `true` `or` unknown is `true`
- `false` `or` unknown is unkown
- `true` `and` unknown is unknown
- `false` `and` uknown is `false`
- unknown `and`/`or` unknown is uknown


Aggregate functions like `sum()` ignore null values.

#### Inequality

`<>` is the equivalent of `!=`. It can also be used with `some()`.

#### Aliasing

```sql
select distinct T.name
from instructor T, instructor S where T.salary > S.salary and S.dept
name = ’Biology’;
```