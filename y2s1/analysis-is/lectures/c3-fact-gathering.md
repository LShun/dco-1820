# Chapter 3 - System Analysis, Fact Gathering

## SDLC

## Definition

- AKA requirement analysis
- Defines the required functionality of the new system, collate them in **requirements specification** by utilizing fact-gathering & fact recording techniques.
  - *Fact gathering*: Gather facts using techniques such as interviewing
  - *Fact recording*: Document facts using modelling techniques such as DFD.

## Fact Gathering in System Development

- From who? *Users of system*, i.e.: End users
- Requirements? *Analyst with knowledge and experience* in business area involved
- Gathering materials? 
  - Business rules, 
  - processes, 
  - locations of work, 
  - activities of users, 
  - system interface with other systems

## Technique of Fact Gathering

### Interviews

- Widely used, most productive
- Face-to-face
- Formal meaning
- Document feedback to user (confirmation)

#### Advantages

- **Overcome resistance**: Obtains cooperation of people involved
- **Body language:** Can see visual cues, extra information
- **Clarification of facts:** Unclear information can be clarified on-the-spot
- **Build rapport:** Develop rapport, build cooperation
- **Intimate & frank:** More chance to obtain controversial/critical information

#### Disadvantages

- **Costly, time consuming:** Requires dedicated time
- **Skill-dependent:** Interviewer's skill is a significant factor of success.
- **Require personal contacts:** Required to obtain good cooperation.

### Questionnaires

- List of questions, sent to users to answer when free
- Contains *closed questions* (to ascertain facts) & *open questions* (to understand feelings/opinions)
- Can be tested
- Good representation of **first stage** of data collection.

#### Suitability

Good choice when:

- **Large population.** Insufficient time.

- **Geographically distributed users.** Too costly in terms of time and money.

- **Anonymity.** When anonymity is important for info. provider.

- **Factual information.** Difficult to be answered instantly.

   

#### Advantages

- **Recipient can answer at convenience.** No time block required.
- **Respond anonymously.** More likely to obtain accurate answers.
- **Respondents given time.** Given time to obtain information.
- **Information from large group.** Obtain information from geographically distributed users.

#### Disadvantages

- **Difficult to design.** Hard to design question without misinterpretation and bias possible.
- **Cannot clarify question.** Unlike interviews, hard to explain to user.
- **Poor response.** Many people will delay/forget.

### Observation

- Analyst monitor interrelations, interactions, procedures, and data flow inside a department
- Requires prior arrangement & make everyone aware of purpose
- **Participatory observation.** An analyst temporarily joins group activity while observing.

#### Advantages

- **Additional perspective.** Gives another perspective & supplemental information for fact gathering.

- **Cross-check and verify.** Allows verification with information previously received (through interview).

- **Acquire know-how.** Understand how to implement system.

- **Better acceptance.** More acquainted with intended implementation audience.

- **Environmental conditions.** Able to understand environmental factors that can affect implementation (dirt, dust). 

#### Disadvantages of Observation

- **Time consuming**. 
- **Need prior understanding of procedure.**
- **Subconscious observation**. Observation might be biased due to local environment and past experiences.
- **Hawthorne Effect**. Workers nervous under observation

### Analysis of Existing Documents

1. Collect documents from current system
2. Make relevant copies
3. Make analysis on them

#### Advantages

- **Detailed description of procedures.** More accurate and verbose compared to interviewing or questionnaire.
- **Better understanding of procedures.**
- **Guide to current practice.** 

#### Disadvantages

- **Not up to date.** System documentation might have implicit changes overtime.
- **Document procedures modified**. Some procedures might have been changed/modified over the course of time.
- **Current practice not following documentation.**
- **Need careful selection of documents.** Requires good selection.

### Joint Application Development (JAD)

- **Definition**: A workshop for users to explore requirements, issues, and problems.
- **Purpose:** Allow IT personnel to work with users to learn about requirements.
- **Participants**: Headed by project leader
- **Documentation:** Proceedings recorded

### Background Research

- Review journals, periodicals, and books with information relevant to task
- Attend meetings & seminars
- Formal and informal discussion
- Visits to similar sites

### Prototyping Approach

- **Definition**. A model containing key features of the project, create using a 4GL or CASE tool.
- **Purpose.** Allows user testing & feedback to know if requirements are met.
- **Advantage: Speed**. Can be modified quickly.
- **Advantage 2: Productivity.** Can be quickly developed into working program
- **Steps**
  1. Define Requirements
  2. Build/modify prototype
  3. Use & Test prototype
  4. Check if user is okay with prototype
     - If YES, continue
     - otherwise, go to beginning
  5. System Requirement Specification
  6. System Design
- Steps 1-4 is aka **System Analysis**

## Functional Requirements

- Describe functionality or services expected from the system.
- Depends on:
  - Software used
  - Requirements
- Examples:
  - **Storage requirements**. Fast retrieval & entry.
  - **User interface requirements** Automatic entry of data.
  - **Processing requirements.** Automatic calculation.
  - **Control requirements.** Input safeguards.

## Non-functional requirements

- Not directly related to a function.
- Describes features, constraints, and characteristics of system.

### Examples

#### Interface with other systems

- Receive & send information between systems.

#### Audit Requirements

- **Audit trail**. Records significant information on transactions.
- Content must be agreed and defined in non-functional requirements. (Formatting is part of non-functional requirements).

#### Legal issues

- Support industry-wide legislation (e.g.: Data Protection Act)
- Legislation might require users to satisfy requirements
- The capability of the software to handle such needs is also part of non-functional requirements.

#### Archiving, backup, and recovery

- Backup and recovery routines
  - Make copy in anticipation of future failure.
  - Also part of non-functional requirements, as:
    - it is not specific to any part of the system
    - the method, and interval needs to be specified by the user
- Archiving facilities
  - Moving data from primary storage to long-term storage
  - Purpose: to provide legally acceptable business history without filling up usable space.
  - Length of retention depends on legal obligations and business needs

#### Usability

- **Definition**: How easy it is for the user to use the system and perform a task.
- **Measuring/Describing Usability:**
  - Learnability
  - Efficiency
  - Memorability
  - Errors
  - Satisfaction

#### Reliability

- Definition: A measure to know a system's ability to perform without failure.
- Important because failures bring hardships to users

