# FN T3: Physical Layer (OSI Model)

## Q1

1. What are the functions of the physical layer?
   1.  The physical layer's function is to **transport data using electrical, mechanical, or procedural interfaces**.
   2. The physical layer is responsible for **sending computer bits from one device to another** along the network.
   3. The physical layer is also responsible to **define how bits are converted from bits to signals**, data rate, synchronization, transmission mode, and interface.
2. With reference to the diagram, describe encapsulation process from source node to destination node.
   1. The user data is segmented by the transport layer, placed into packets by the network layer, and further encapsulated as frames by the data link layer.
   2. The physical layer encodes the frames and creates the electrical, optical, or radio wave signals that represent the bits in each frame.
   3. These signals are then sent on the media one at a time.
   4. The destination node physical layer retrieves these individual signals from the media, restores them to their bit representations, and passes the bits up to the data link layer as a complete frame.
3. There are three basic forms of network media. The physical layer produces the representation and groupings of bits for each type of media as: (3 marks) 
   1. Copper cable: The signals are patterns of  electrical pulses.
   2. Fiber-optic cable: The signals are patterns of light.
   3. Wireless: The signals are patterns of microwave transmissions.
4. The physical layer standards address three functional areas which is physical components, encoding and signaling. Discuss each of the functional areas
   1. **Physical components**:  The physical components are the electronic hardware devices, media, and other connectors  that transmit and carry the signals to represent the bits.
   2. **Encoding:** Encoding or line encoding is a method of converting a stream of data bits into a predefined "code". Codes are groupings of bits used to provide a predictable pattern that can be recognized by both the sender and the received. In the case of networking, encoding is a pattern of voltage or current used to represent bits; the 0s and 1s.
   3. **Signaling:** The physical layer must generate the electrical, optical, or wireless signals that represent the "1" and "0" on the media. The method of representing the its is called the signaling method.

## Q2

1. Fill in the blank： (5 marks) 

| Term                | Physical Layer Description                                   |
| ------------------- | ------------------------------------------------------------ |
| Synchronous         | Data signals are sent along with a clock signals which occurs at evenly spaced time durations referred to as the bit time. |
| Signaling method    | The method to represent the bits.                            |
| Frame encoding      | The method a network frame is converted into signals for transmission |
| Asynchronous        | Data signals are transmitted without an associated clock signal. |
| Physical components | The electronic hardware devices, media, and other connects that transmit and carry the signals to represent the bits. |

2. Distinguish between bandwidth and throughput 
   1. **Bandwidth**: The capacity of a medium to carry data. Digital bandwidth measures the amount of data that can flow from one place to another in a given time. Bandwidth refers to the maximum amount under ideal conditions. Bandwidth is equal or higher than throughput.
   2. **Throughput:** The measure of the transfer of bits across the media over a given period of time. Throughput refers to the actual amount, under the influence of the amount and type of traffic, and latency. Therefore, throughput is often lower than bandwidth.

3.  Identify the type of the copper cable and briefly describe the cable.  

   1. | Cable Type                          | Description                                                  |
      | ----------------------------------- | ------------------------------------------------------------ |
      | Unshielded Twisted Pair (UTP) cable | Consists of four pairs of color-coded wires that have been twisted together and then encased in a flexible plastic sheath that protects from minor physical damage. The twisting of wires helps protect against signal interference from other wires. |
      | Shielded Twisted Pair (STP) cable   | STP cables combine the techniques of shielding to counter EMI and RFI, and wire twisting to counter crosstalk. |
      | Coaxial cable                       | There are two conductors that share the same axis.           |

4.  Discuss the application of each of the following UTP cable types. 

   1. | Cable Type             | Cable Use / Applications                                     |
      | ---------------------- | ------------------------------------------------------------ |
      | Straight-through cable | Commonly used to interconnect a host to a switch and a switch to a router. |
      | Crossover cable        | Cable used to interconnect similar devices.                  |
      | Rollover cable         | Connect workstation to a router or switch console port       |

5.  When is a wired connection preferred to a wireless connection by an end-user device? 

   1. When security is very important. Packets transmitted through wired connection cannot be easily intercepted.
   2. When connection stability is important. Wired connections are less susceptible to interference, more stable and consistent compared to wireless connection.
   3. Direct data transfer. Wired connections offers direct connection to data transfer compared to wireless connections which requires an intermediary device to broadcast wireless signals. Wired connections are faster.  