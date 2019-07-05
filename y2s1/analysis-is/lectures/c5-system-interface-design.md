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

- Architectural design
  - Define the relationship among major modules of the system
  - DFD serves as the basis for modular or functional design

- Procedural design
  - Transform structural elements of program architecture into a procedural description of software components.
  - Process spec provides basic information for procedural design.

- Interface design
  - Describe how software communicates within itself, to system that interoperates with it, and with humans who use it.
  - DFD provides the information required for interface design

- Data design
  - Transforms the information domain model created during analysis into the data structures that will be required to implement the software.
  - ERD and data dictionary provide the basis for the data design activity.

## Physical and Logical Design

- Logical Design
  - Developed during the system analysis phase.
  - Describe the functions and features of the system (eg. input, output, process) that must be performed by the system.
  - Defines what must take place, not how it is accomplished physically.
  - Example - Customer records system - logical design describes what data that must be entered for each customer. E.g. name, address, etc.

- Physical Design
  - Developed during the system design phase.
  - Describes the actual processes of entering, verifying, and storing data.
  - Defines how the system will be implemented physically.
  - Example - Customer records system - physical design describes how the data will be entered for each customer e.g. input screen layout etc.

| Differences | Logical Design                           | Physical Design                         |
|-------------|------------------------------------------|-----------------------------------------|
| Phase       | System Analysis                          | System Design                           |
| Areas       | Describe the functions & features        | Describe actual physical processes      |
| Focus       | Define what must be done in the system   | Describe how system will be implemented |
| Exampple    | Describes what data that must be entered | Describes how the data will be entered  |