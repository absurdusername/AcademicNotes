### Views

```sql
create view v as <query>;
create view v(name1, name2) as <query>;
```

Now the view `v` can be used as if it was a relation. One that is lazily computed at run-time. 