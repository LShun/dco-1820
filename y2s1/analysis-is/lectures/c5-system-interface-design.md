# C5: System Interface and Design

## What is system design?

- A design that shows how the system will do its job
- Overall plan or model, consisting of all the specifications for system
- Person: Designer details system specifications
- One IS can have many design

## Importance of Design

- **Maintenance.** Provides 'roadmap' and documentation required.
- **Quality.** Provides criteria to assess software.
- **Testing.** Make testing easier.
- **Communication.** Communication medium between designers of subsystems.
- **Implementation.** Translate customer requirements to finished products.

## Overview Areas of Design

- Picture

## Analysis and Design Models

- **Architectural design**
  - Define the relationship among major modules of the system
  - DFD serves as the basis for modular or functional design

- **Procedural design**
  - Transform structural elements of program architecture into a procedural description of software components.
  - Process spec provides basic information for procedural design.

- **Interface design**
  - Describe how software communicates within itself, to system that interoperates with it, and with humans who use it.
  - DFD provides the information required for interface design

- **Data design**
  - Transforms the information domain model created during analysis into the data structures that will be required to implement the software.
  - ERD and data dictionary provide the basis for the data design activity.

## Physical and Logical Design

- **Logical Design**
  - Developed during the system analysis phase.
  - Describe the functions and features of the system (eg. input, output, process) that must be performed by the system.
  - Defines what must take place, not how it is accomplished physically.
  - Example - Customer records system - logical design describes what data that must be entered for each customer. E.g. name, address, etc.

- **Physical Design**
  - Developed during the system design phase.
  - Describes the actual processes of entering, verifying, and storing data.
  - Defines how the system will be implemented physically.
  - Example - Customer records system - physical design describes how the data will be entered for each customer e.g. input screen layout etc.

| Differences | Logical Design                           | Physical Design                         |
| ----------- | ---------------------------------------- | --------------------------------------- |
| Phase       | System Analysis                          | System Design                           |
| Areas       | Describe the functions & features        | Describe actual physical processes      |
| Focus       | Define what must be done in the system   | Describe how system will be implemented |
| Example     | Describes what data that must be entered | Describes how the data will be entered  |

## Exercise for Student

| Differences | Logical Design                    | Physical Design                    |
| ----------- | --------------------------------- | ---------------------------------- |
| Phase       | System Analysis                   | System Design                      |
| Areas       | Describe the functions & features | Describe actual physical processes |
| Focus       | Define what must be done          | Define how must be done            |
| Example     | Describe what data entered        | Describe how data will be entered  |

## Architectural Design

- **Meaning:** 
  - Gives big picture of objective, show the modules & relationships.
- **Purpose:**
  - Derive big picture to improve development & quality before software design.
  - To develop modular program structure & control relationships in-between.
  - To merge program and data structure, define interfaces to enable data to flow.

## System Structure

- Shows relationship between modules of system, and how information flow between them.

## Functional Decomposition Diagram(Structure Chart)

**Definition:** Top-down view of function. Shows system structured into sub-systems. 

**Creating:** Start from DFD to create FDD. 

- Diagram 0 = **Whole system.** 
- Diagram 1 = **whole module**.
- Identify communications between subsystems

## Benefits of Functional Decomposition

- Functions and processes broken down, more manageable.
- Modules more cohesive, loosely coupled. Systems more stable, errors localized, system faults minimized.
- Can concentrate on one area
- Allow independent development of different subsystem, easier multitasking

## User Interface Design

### User Interface

- **Meaning:** How user interact with system
- Can be hardware or software.

### Types (Just remember a few)

- CLI (Command-line Interface)
- Menu-Driven Interface
- Improved Menu Interface
  - Pop-up menu
  - Pull-down & cascading menu
- Toolbar & icon-based interface
- Form-based Interface
- Natural Language Interaction

### Menu Building Tools

- **Definition:** Allows programmer to design menu structure easily

### HW Devices

- Well, the usual stuff, just use your imagination if you can't figure.

### User Interface Design Principles

| Principles             | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Consistent design      | Similar operations should be activated same way.             |
| Familiarize users      | Use terms and concepts that users anticipate from past experiences. |
| Guide users            | User guidance depending on situation.                        |
| Reduce surprise        | Behavior of system shouldn't surprise user.                  |
| Enhance recoverability | Allow user to recover from errors.                           |

