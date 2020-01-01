# SBA Tips

- Bring your own one piece of paper, A4 size, double sided
- ONLY Handwritten, CONFIGURATION command
- No description, no formula
  - No description:
    - Can write `show run`  and so on
    - CANNOT "this command is used to show running configuration"

## Part C, P4 & P5

## Theory Part

- Similar to the practice questions. Only difference are the values.
- Pay very close attention to the class, very high chance to GG there.

## Practical Part

- Again, very similar to practice questions
- Refer to [Lazily Prepared Cheatsheet](./lazily-prepared-cheatsheet-that-will-get-teared-off.rtf) inside the same folder. Remove all the "headings", write it out, and you have a working cheatsheet.
- The subpoints are pretty much depreciated, but are kept for archival purpose (just like our History textbook)
  - Configure the router
  - Enter config mode
  - Assign device name `hostname R1`
  - Assign password, secret, all password
  - Encrypt clear text password
  - Clock command
  - Banner command
  - IP Address & Mask, `no shutdown`
  - `show ip int brief` `show interfaces` `show running-config`

### Miscellaneous Tips

Make sure don't accidentally unplug cable

- If accidentally unplug, go back to question and check

Configuring interfaces

- First step, go into interface, configure IP
- Second step, ensure all interfaces are up `no shutdown`
- Default gateway: `ip default-gateway [DEFAULT GATEWAY]`
- Remember to `copy run start`