# C8: Network Basics

## 8.1 Application Layer Protocols

Upon completion of this section, you should be able to:

Explain how the functions of the application layer, session layer, and presentation layer work together to provide network services to end user applications.

### Application Layer

- Closest to end user
- Enable users to send & receive data
- Interface between application & network
- Common: HTTP, FTP, DNS
- **Exam Tips:** Explain/List down 2 or 3 protocols in the application layer

### Presentation & Session Layer

#### Presentation Layer

- 3 primary functions, **FEC**
  - Format, compress & encrypt data
- Common: 
  - **Video**: QuickTime, MPEG
  - **Graphics:** GIF, JPEG, PNG

#### Session Layer

- Create & maintain dialogs between source & destination applications
- Handle information exchange, keep connection alive

## 8.1.2 How application protocols interact with applications

Explain how common application layer protocols interact with end user applications.

### Client-Server Model

- **Client:** Device requesting info
- **Server:** Device responding to request
- In **application layer**
- Process:
  - Client request data from server
  - Server send data back

### Peer-to-Peer (P2P) Networks

- Data accessed without dedicated server
- Every end-device (**peer**) can function as server & client
- Role determined on request basis

- **Hybrid system**: Decentralized resource sharing, index (like Yellow Pages) stored in centralized directory. 
  - Access index to get location on another peer.

- Common: BitTorrent, Bitcoin

#### BitTorrent technology

- **Torrent file:** Location of peers + trackers
- **Trackers:** Computer keeping track of files hosted by users

## 8.2: Well-Known Application Layer Protocols & Services

Upon completion of this section, you should be able to:

Explain how web and email protocols operate.

Explain how the IP addressing protocols operate.

Explain how file transfer protocols operate.

### HTTP & HTML

- **URL:** Web address, reference to web server. Allows web browser to connect to web server.
  - Parts: Protocol, server name, filename
  - Eg: http://www.cisco.com/index.html
  - DNS translates server name portion
  - **Exam:** Give example or URL, and explain/identify 3 parts.
- **URI:** Uniform Resource Identifier. Superset of URL (but URI may/may not help in locating)
- **Exam:** Remember full name of HTTP & HTTPS

#### Steps in locating web pages

1. DNS translate server name :arrow_right: IP Address
2. Browser send GET request to server IP, ask for file
3. Server send back file, in HTML code
4. Browser process, formats, display

#### HTTP & HTTPS

- **HTTP**: request/response protocol.
  - Common message types: GET, POST, PUT
  - Not secure
- **HTTPS**: HTTP + Auth & Encryption to secure data

### Email Protocols

- **Store-and-forward** method to send messages
- Stored in databases on **mail servers**
- **Email clients** send/receive email through mail servers
- Mail server communicate with other mail servers
- Three operational protocols: SMTP (sending), POP/IMAP (retrieving)

#### SMTP Operation

- Require header + body
- **Header:** Properly formatted, recipient + sender address
- **Body:** Anything
- Operation:
  - SMTP client send email to SMTP server
  - Server receive message, either store or send to another mail server
  - User use email clients (through IMAP/POP) to get messages.

#### POP Operation

- **Download** message from server :arrow_right: client
- POP client & server exchange commands
  - Allow email downloading & deleting
  - No centralized location for emails
  - Downloaded message on client

#### IMAP Operation

- Protocol for email address
- Allow message **display** (NOT download)

- Message on server until deleted
- User view copies of messages
- User can create folders & organize mails
- When message deleted, action synced to server

# Topic 8.2.2: IP Addressing

### DNS - Domain Name Server

- Dynamic translation of domain name to IP address
- Format: DNS message format

### DNS Message Format

#### Record Types:

| Record Type | Description     |
| ----------- | --------------- |
| A           | End-device IPV4 |
| NS          | Name server     |
| AAAA        | End-device IPv6 |
| MX          | Mail exchange   |

- DNS server look at own records first, if not found, check with other DNS servers.

### DNS Hierarchy

- Use hierarchical system, broken down into manageable zones.

- Each DNS server manage a portion of DNS structure, forwards the rest.
- **Top-level domains**: Represent type or country of origin

### NSLookup

- Allow manual DNS queries

## 8.2.3 File Sharing Services

### DHCP - Dynamic Host Configuration Protocol

- Distributes addresses, leased for fixed time
- Returned to pool when no longer used
- Improve scalability, easier to configure (auto-include crucial information).

#### DHCP Operation (HOT TOPIC 12m last exam :star:)

1. Client broadcast DHCP**D**iscover
2. DHCP reply with DHCP**O**ffer
3. Client send DHCP**R**equest
4. Server send back DHCP**A**ck to finalize
   1. OR, sever send back DHCP**N**Ak (Not acknowledged) if no longer valid
5. Client renew with DHCP**R**equest
6. Mnemonic, **DORA** and **BUBU**. Pair them up (DB, OU, RB, AU)
   1. B = Broadcast
   2. U = unicast

### FTP Transfer Protocol

- File transfer over network
- FTP **Client** push/pull data from FTP **server**
- Require 2 connection. One for control, one for data transfer

#### Process

- Client link to server at TCP port 21 (control)
- Client push/pull data at TCP port 20 (data transfer)

### Server Message Block

- Client/server file sharing protocol
- All share a common format
- Once connected, client can access remote resources as if they are a local resources

