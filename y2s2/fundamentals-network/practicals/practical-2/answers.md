## 2.2.3.4 Answers

Answer the following questions 

Note: 

- for Q1-2, its answer is located before you enter the `show running-config`
- for Q3, remember to press "Enter" when the console write `-More-` , pressing other buttons will cancel output :

1)     How many FastEthernet interfaces does the switch have?

- 24

2)     How many Gigabit Ethernet interfaces does the switch have?

- 2

3)     What is the range of values shown for the `vty` lines?

- 0-4
- 5-15

4)     Which command will display the current contents of non-volatile random-access memory (NVRAM)?

- `show startup-config`

5)     Why does the switch respond with startup-config is not present?

- Because nothing is configured in the NVRAM

Step 2:     Secure access to the console line.

- Why is the `login` command required?
  - The `login` command enables the prompt for the password. Its similar to "require password on log-in".

## Part 3 : Configure an MOTD

1)     When will this banner be displayed?

- When you first start the CLI of the switch. Or, when you exit to the login screen using `exit`.

2)     Why should every switch have a MOTD banner? (ASK)

- To inform users of important details of the switch

## Part 4: Save configuration files to NVRAM

What is the shortest, abbreviated version of the copy running-config startup-config command? (TODO)

- `copy running startup` 

### Step 3:     Examine the startup configuration file.

Which command will display the contents of NVRAM?

- `show startup`

Are all the changes that were entered recorded in the file?

- Yes, because we copied the `running-config` to `startup-config` earlier.

## 2.3.2.5 Answers

### Step 3:   Verify the password configurations for S1.

How can you verify that both passwords were configured correctly?

- Exit the switch and then re-enter the interface in global config mode. 

## Part 2:     Configure the PCs

### Step 2:   Test connectivity to switches.

Were you successful? Why or why not?

- No, because the switch have not been configured yet.

## Part 3:     Configure the Switch Management Interface

### Step 1:   Configure S1 with an IP address.

- `no shutdown` is used to 'power on'.

