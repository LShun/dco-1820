# C5 - Ethernet

## Mid Term Coverage

- Switch MAC Address Table

## 5.1 Ethernet Protocol - LLC & MAC Sublayers

### Ethernet

- Most widely used LAN technology
- Operates in data link layer & physical layer
- Defined in IEEE 802.2 & 802.3 standards

### Ethernet Standards

- Define L2 & L1 technologies
- Two layers
  - Logical Link Control (LLC)
  - Media Access Control (MAC)

#### LLC

- Handles communication between upper & lower layers
- Adds control information to network protocol data
  - Help packet delivery

#### MAC

- Lower sublayer of data link layer
- Implemented by HW, in computer NIC
- Responsibilities:
  - Data encapsulation
    - **Frame delimiting**: Identify group of bits that makes up a frame. Synchronize transmitting & receiving nodes.
    - **Addressing**: Add MAC address to Ethernet header for delivery
    - **Error detection**: Add Cyclic Redundancy Check (CRC) trailer  of contents to Ethernet frame
  - Media access control
    - Control frame placement on media
    - Media recovery

#### MAC - Carrier Sense Multiple Access (CSMA) process

- Detect if media is carrying signal
- If no carrier signal, transmit data
- Else, DO NOT transmit, otherwise data collision

- **Method**: Contention-based access
- **Characteristics:** 
  - Transmit anytime
  - Collisions exists, have resolve mechanism
  - Mechanisms:
    - CSMA/CD for Ethernet
    - CSMA/CA for 802.11 Wireless networks

##### CSMA/Collision Detection

- If **signal** is **idle**, device transmit data
- If signal is "**busy**", all device stop sending and try later
- With today's intermediary devices, **collisions** do not occur on Ethernet, CSMA/CD unnecessary

##### CSMA/Collision Avoidance (CSMA/CA)

- Check if have signal, if free, send **notification** to declare intent to use.
- Device sends data

### Ethernet Encapsulation

- Ethernet frame structure add headers & trailers around Layer 3 PDU to encapsulate

- Ethernet Frame Structure

  - | Bytes   | 7                             | 1                                      | 6                   | 6              | 2                                          | 46-1500                              | 4                      |
    | ------- | ----------------------------- | -------------------------------------- | ------------------- | -------------- | ------------------------------------------ | ------------------------------------ | ---------------------- |
    | Content | Preamble                      | Start of Frame Delimiter               | Destination address | Source address | Length                                     | 802.2 Header & Data                  | Frame Check Sequence   |
    | Details | Notify destination new frame. | Synchronize sending & receiving device |                     |                | Length of frame data field & protocol used | Pad frame field to at least 64 bytes | Detect errors with CRC |

  - **Min size**: 64 bytes (Less = "collision/runt frame")

  - **Max size**: 1518 bytes

- Less/More = drop frame

### MAC Address: Ethernet Identity

- 48-bit binary, 12 hex digits
- Must use vendor Organizationally Unique Identifier (OUI) as first 3 bytes
  - If same, must use unique value in last 3 bytes

### Frame Processing

- Packets contain source & destination MAC address
- Each NIC check if destination MAC same as device's MAC in RAM. 
  - If same, pass up OSI layers & decapsulate
  - Else, discard

## Ethernet MAC

### Types of MAC address

|                 | Unicast    | Broadcast         | Multicast                 |
| --------------- | ---------- | ----------------- | ------------------------- |
| Destination MAC | Unique MAC | FF-FF-FF-FF-FF-FF | Starts with 01-00-5E      |
| IP              | Unique IP  | XXX.XXX.X.255     | 224.0.0.1-239.255.255.255 |

## MAC & IP

| MAC                        | Address     | IP                           |
| -------------------------- | ----------- | ---------------------------- |
| Don't change               | Mutability  | Change depending on location |
| Names                      | Similar to  | House addresses              |
| Physical address           | AKA         | Logical address              |
| Host NIC                   | Assigned by | Network Admin                |
| Layer 2 devices (Switches) | Examined by | Layer 3 devices (Routers)    |

## Intro to ARP

### Purpose

- Find MAC address of destination in Ethernet

### Functions

- Resolve IPv4 to MAC addresses
- Maintain table of mappings

### ARP Table

- Find MAC address of destination IPv4 address
- Intermediary node to store IP & MAC address
- Can have static map entries

### ARP Request

- Layer 2 broadcast to all 

- Node matching IP address will reply
- If no device respond, packet is dropped because frame cannot be created

### ARP Process

- Check if ARP entry present
- If not present
  - Broadcast ARP request for IP
  - Receiver with same IP reply with MAC address
  - Host add IP & MAC pair to ARP cache
- Host send data directly to destination

### ARP - Remote Communication

#### Destination IPv4 Host

| Local Network             | NOT on local network       | Gateway entry NOT in table                    |
| ------------------------- | -------------------------- | --------------------------------------------- |
| Use MAC address of device | Use MAC address of gateway | Use ARP request to get MAC address of gateway |

## Switch Port Fundamentals

### Layer 2 LAN switch

- Connect end device to intermediary device
- Perform switching & filtering based on MAC address
- Build MAC address table for forwarding decisions
- Depend on router to pass data between IP subnetworks

### Switch MAC Address Table

- Switch receives broadcast frame (ARP)
- Switch enter source MAC & port number into address table
- Flood frame to all ports except sender
- Destination reply with unicast frame to sender
- Switch enter destination MAC & port number into address table.
- Switch transfers frame between source & destination without flooding using address table ports.

### Duplex Settings

#### Half Duplex (CSMA/CD)

- Use Hub
- Unidirectional
- Data collision can occur

#### Full Duplex

- Use switch
- Point-to-point
- Attach to dedicated switched port
- Collision-free
- CD circuit disabled

### AutoMDIX

- Auto detect connection & configure interface