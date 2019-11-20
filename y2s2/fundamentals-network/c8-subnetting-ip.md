# C8: Subnetting IP Net.

## Broadcast Domains

- **Broadcast Domain**: A domain where broadcast are propagated, connected through router interface.
- **Problems with Large Broadcast Domains**
  - **Slow network**: Large broadcast traffic
  - **Slow device operation**: All devices must process broadcast

- **Solutions**
  - Reduce size through subnetting
  - **Subnets**: smaller networks
- **Reasons for subnetting**
  - Device grouping by
    - Location
    - Organizational unit
    - Device type

## Subnetting

### Ways to subnet

#### Class / Octet Boundary Subnetting

- IPv4 is divided into 4 blocks, basically fill those blocks with predefined numbers. The more blocks filled with 1s, the larger the number of subnets, but the smaller each subnet is.
- **Prefix length**: /8, /16, /24 (basically number of bits filled)

#### Classless Subnetting

- Subnets above /24, max is /30 (allows 2 hosts)
- Range: 24-30

- Number of hosts: 2^bitsRemaining^ - 2.
  - Reason: First bit of host region must be 0 to differentiate mask and hosts.
- Number of subnets: 2^bitsBorrowed^

#### Splitting Subnets

- Borrow 1 extra bit. For first subnet, make it `0`, for second, make it `1`.

## Subnets with /16 & /8 prefix

- Basically same as above, except you start with 16 bits & 8 bits reserved. The more bits you borrow, the more subnets, the less hosts. Formula all same.



## Subnetting Based on Host Requirements

### Consideration

- Number of hosts

- Number of individual subnets

- Organizational structure

## Benefits of Variable Length Subnetting Masking

- Traditional subnetting wastes addresses. Not all addresses used per subnet.

### Basic VLSM Subnetting Scheme

- Basically, subnetting a subnet. Borrow "borrowed" bits to make into smaller subnets.

## Structured Design

### Network Address Planning

- Planning IP Address Assignment
  - Size
  - Number of hosts per subnet
  - How hosts addressed
- Considerations
  - Prevent address duplication
  - Control access
  - Security & Performance



   