# C7 - DB Admin & Sec

## Weak Data Admin -> Bad data quality :star:

- **Missing data elements**
  - Reduction in data value
- **Poor response time**
- **Damaged, sabotaged, stolen data**
- **Unauthorized access**

## Traditional Administration Def.

- **Data administration**: high-level function, responsible for overall management of data resources in organization.
- **Database administration.** A technical function that is responsible for physical database design and for dealing with technical issues.

## Functions

### Traditional Data Administration Functions (remember at least 2)

- **Planning**
- **Internal marketing of DA concepts**
- Data conflict (ownership) resolution
- Managing information repository
- Data policies, procedures, standards

### Traditional Database Administration Functions (remember at least 2)

- Analyze & design database
- **Selecting DBMS and software tools**
- **Installing/Upgrading DBMS**
- Tuning database performance
- Improving query processing performance
- **Manage data security, privacy, integrity**
- **Data backup and recovery**

### Data Warehouse Administration

- Emphasis on integration and coordination of data across different sources
- Specific roles
  - Support decision-making applications
  - Manage data warehouse growth
  - Establish service level agreements

## Open Source DB Management

- Alternative to proprietary packages
- Pros: 
  - Less expensive
  - Source code available for modification
- Cons:
  - Not as feature-rich as proprietary DBMS
  - May not have certification programs
  - Ambiguous licensing concerns

## IT Operations

- Policies & procedures to manage infrastructure, apps, and DB in organization.
- For DB:
  - Backup and recovery
  - Availability

### DB Recovery :star:

- Mechanisms to restore data efficiently after loss/damage
- Recovery facilities (remember at least 2):
  - Backup facilities
  - Journalizing facilities
  - Checkpoint facilities
  - Recovery manager

#### Back-up facilities

- The utilization of DBMS copy utility to produce full/incremental copy of database.
- Periodic backup
  - **Cold backup**: Shut down ENTIRE DB during backup
  - **Hot backup:** Shut down specific portion of DB for backup
- Stored in secure, off-site location.

#### Journalizing facilities

- **Produce audit trail** of transactions & database updates
- Types of logs
  - **Transaction log**: Records of essential data
  - **Database change log**: Images of updated database
    - **Before-image:** Copy before update
    - **After-image:** Copy after update

#### Checkpoint facilities

- Allows recovery manager to resume processing from short period (rollback to last checkpoint), instead of having to restart entire day (using periodic backups).

## Recovery and Restart Procedures

- **Disk mirroring**: 
  - If you play Path of Exile (PoE): ![Mirror of Kalandra](../img/mirror-of-kalandra.png)
  - If you don't play PoE: switching between identical copies of database
- **Restore/Rerun**: Reprocess transaction against backup
- **Transactional Integrity:** Commit/abort all transaction changes
- **Backward Recovery (Rollback):** - Apply before images
- **Forward recovery (Rollforward):** Apply after images (preferable to restore/rerun)

## Typical Types of Failures

- **Aborted transaction**
  - Rollback (preferred)
- **Incorrect data (update inaccurate)**
  - Rollback (preferred)
- **System failure (database intact)**
  - Switch to duplicate database
- **Database destruction**
  - Switch to duplicate database

## Data Availability

- Ensure database always available
  - **Hardware failures**: Backup systems
  - **Loss of data:** Database mirroring
  - **Human Error:** Standard operating procedures
  - **Natural damage:** Build in places without natural disaster

## Data Security

- Database security: Protection of data against loss, destruction, misuse

### Physical protection

- Glass windows and surrounding

### Threats to data security

- Accidental damage
- Theft and fraud
- Loss of privacy / confidentiality
- Loss of data integrity
  - Entity (PK cannot duplicate)
  - Referential (FK -> PK or NULL)
  - Domain (Range)
- Loss of data availability
  - Sabotage (eg. DDoS)

### Defenses

#### Firewall

#### Static HTML

- Easy to secure

#### Dynamic HTML

- Session security
  - Timer to timeout
- Encryption
- Restrict users and open ports
- Remove unnecessary programs

### W3C Web Privacy Standard

- HTTPS/HTTP
- Address following:
  - Who collect data
  - Purpose of data
  - ...

## Database Software Security

- Create views or subschemas
- Integrity controls
- Authorization rules (privileges)
- **Backup, journalizing, checkpoint, recovery (8m)**

## Views and Integrity Controls

- Views
  - Let user view without direct access to underlying table.
- Integrity controls
  - Protect from unauthorized use
  - Domains - set allowable values
  - Assertions - enforce database conditions
    - Set min/max
    - control input pattern, regex
  - Triggers - prevent inappropriate actions

## Authorization rules

- Controls in DBMS
- Restrict
  - Data access
  - Actions available
- Authorization matrix table (very important)
  - Subjects
  - Objects
  - Actions
  - Constraints

## Authentication Schemes

- Obtain positive identification of user
- Password
- Strong authentication, ask you to add in special symbols

## Logical Access to Data

- Personnel controls
  - No one know whole picture, separation of duty. 
- Physical access controls
  - Swipe cards, laptop protection

## 