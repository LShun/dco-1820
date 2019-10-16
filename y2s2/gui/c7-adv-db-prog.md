# GUI C7: Advanced DB Prog.

## LO1: Retrieve DB Metadata

- **DB Metadata:** Information that describe database
- `DatabaseMetaData` interface: Obtain DB-wide info.
- `ResultSetMetaData` interface: Obtain `ResultSet` info.

### `DatabaseMetaData`

- Types of methods:
  - Retrieving info
  - Finding DB capabilities (if support ALTER TABLE...etc)
  - Getting object descriptions (Tables, Views, Procedures)

### ResultSet parameters

- In Chapter 5, `ResultSet` without backtracking is implemented.
- Syntax: 
  - Statement
    - `Statement s = c.createStatement(int resultSetType, int resultSetConcurrency);`
  - PreparedStatement
    - `PreparedStatement s = c.preparedStatement(String sql, int resultType, int resultSetConcurrency);`
  - Parameters
    - `resultSetType`: `TYPE_FORWARD_ONLY`, `YPE_SCROLL_INSENSITIVE, `TYPE_SCROLL_SENSITIVE``
    - `resultSetConcurrency`: `CONCUR_READ_ONLY`, `CONCUR_UPDATABLE`

## AP1: MVC

- Separates data storage and handling from design.
- **Model:** Store & handle data
- **View:** Display data
- **Controller:** Obtain data
- Benefits:
  - Multiple views possible. Data sharing through same model.
  - Simplifies complex application. 
    - Modularize, scalable, maintenance.
    - Changes to frontend without affecting backend
  - Synchronization
    - Consistency, view displays updates in model immediately.
    - **Source**: Model
    - **Listener**: View

### MVC Variations

- 

## LO2: Fill Combo Box with Table



## LO3: Display DB query results

## LO4: Store/retrieve image in JDBC

