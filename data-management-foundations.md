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

Data

> numeric, textual, visual, or audio information that describes real-world systems

- Scope: amount of data produced and collected can vary
- Format: can be produced as numbers, text, images, audio, or video
- Access: private and public

Database

> collection of data in a structured format

Database system

> (database management system, DBMS) software that reads and writes data in a database

Query

> a request to retrieve or change data in a database

Query language

> A specialize programming language designed specifically for database systems

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

#### Primary keys

> a field in a table that uniquely identifies the table records

- Must contain a unique value for each row
- It cannot contain `null` values

`SHOW`

> displays info contained in the database and its tables

`SHOW TABLES`

> command used to display all tables within the current MySQL database

`SHOW COLUMNS`

> displays information about the columns within a table

```sql
SHOW COLUMNS FROM tableName
```

#### Transactions

> group of queries that must be completed or rejected as a whole

- ensure all transactions are processed completely or not at all
- prevent conflicts between concurrent transactions
- ensure transaction results are never lost

#### Architecture

> describes the internal components and the relationships between components

Query processor

> interprets queries, creates a plan to modify the database or retrieve datam and returns query results to the application

Storage manager

> translates the query processor instructions into low-level file system commands that modify or retrieve data

Transaction manager

> ensures transactions are properly executed

Log

> a file containing a complete record of all inserts, updates, and deletes processed by the database

Catalog (data dictionary)

> directory of tables, columns, indexes, and other database objects

#### Column data types

`INT` stores integer values

`DECIMAL` store fractional numeric values

`VARCHAR` stores textual values

`DATE` stores year, month, and day

#### Database design

> specification of database objects, tables, columns, data types, and indexes

Entity

> a person, place, activity, or thing

Relationship

> a link between entities

Attribute

> a descriptive property of an entity

Entities, relationships, and attributes are depicted in *ER diagrams*

- Rectangles represent entities, entity names appear at the top of the rectanges
- Lines between rectangles represent relationships
- Text inside rectangles and below entity names represent attributes

Three phases:
- Analysis, specifies database requirements without regard to a database system
- Logical design, 
- Physical design

#### Logical design

> phase that implements database requirements in a specific database system

Key 

> a colum used to identify individual rows of a table

Logical design is depicted in a *table diagram*

- Rectangles represent tables, table names appear at the top of rectangles
- Text within rectangles and below table names represent columns
- Solid bullets • indicate key columns
- Empty bullets and arrows -> <- indicate columns that refer to *keys*

Schema

> the logical design, specified in SQL and depicted in a table diagram

#### Physical design

> Phase that adds indexes and specifies how tables are organized on storage media

Data independence

> the principle that physical design never affects query results

- allows designers to tune query performance without changes to the application program
- when designers modify indexes or row order, applications run slower or faster

### API, Application Programming Interface

> library of procedures or classes that link a hosts programming language to a database
