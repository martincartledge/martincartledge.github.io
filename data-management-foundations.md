### Data management and foundations

#### Study resources

- LinkedIn Learning Course: https://www.linkedin.com/learning/learning-sql-programming-8382385/learning-sql-programming?autoplay=true&u=2045532
- Solo Learn: https://www.sololearn.com/learning/1060
- Caleb Curry Database Design Series: https://www.youtube.com/watch?v=e7Pr1VgPK4w&list=PL_c9BZzLwBRK0Pc28IdvPQizD2mJlgoID&ab_channel=CalebCurry
- Business Intelligence and Data Mining (Ch 10 & 14)
- Dr. Super Database Series: https://www.youtube.com/watch?v=4Z9KEBexzcM&ab_channel=Dr.DanielSoper

#### Topics to focus on

- Structured vs unstructured data
- SQL statements
- 1:1, 1:N, N:M relationships
- Unary, binary, and ternary relationships
- Basic defintions
- Normalization (and three forms)
- ER diagrams
- Business intelligence and data mining

SQL structured query language
> formulate questions a database can respond to

Used as data manpulation language, DML
- CRUD

Used as a data definition language, DDL
- Edit structure (schema)

SQL statements:
- Whitespace independent
- Composed of clauses
- Keywords tell database to take action

`LIKE`
- Match a charcter within a field
- The beginning, middle, or end
- Use the `%` operator, i.e. `LIKE 'M%'`, `LIKE '%A%'`, `LIKE '%N'`

Use `LENGTH` to return number of characters within a given field i.e. (`SELECT LENGTH(first_name) FROM people;`)

Return unique values by using `DISTINCT` keyword i.e. (`SELECT DISTINCT(first_name) FROM people;`)

Use `COUNT` to return number of matching records within a specified criteria i.e. (`SELECT COUNT(first_name) FROM people WHERE first_name='Martin';`)

```sql
SELECT name, team, score, prize
FROM people
ORDER BY prize, team;
```

`JOIN` (inner join)

> Ask for records across two tables that are associated with each other based on a common piece of information

```sql
SELECT people.first_name, people.state_code, states.division
FROM people
JOIN states ON people.state_code=states.state_abbrev;
```

`Implicit (inner) JOIN`

```sql
SELECT people.first_name, states.state_name
FROM people, states
WHERE people.state_code, states.state_abbrev
```

`LEFT JOIN`

```sql
SELECT people.first_name, state.state_name
FROM states
LEFT JOIN people ON people.state_code=states.state_abbrev;
```

`GROUP BY`

> Run query for each field name that is specified i.e. `SELECT state_code, COUNT(state_code) FROM people GROUP BY state_code;`

```sql
SELECT states.state_name, COUNT(people.shirt_or_hat)
FROM states
JOIN people ON states.state_abbrev=people.state_code
WHERE people.shirt_or_hat='hat
GROUP BY people.shirt_or_hat, states.state_name;
```

```sql
SELECT states.division, people.team, COUNT(people.team)
FROM states
JOIN people ON states.state_abbrev=people.state_code
GROUP BY states.division, people.team;
```
