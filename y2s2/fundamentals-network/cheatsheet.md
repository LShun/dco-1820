## CLI

### Switch

`show running-config`: Displays running configuration

Change switch host name:

```bash
enable
conf t
h S1
exit
```

- Notes
  - `conf` = `configure`
  - `t` = `terminal`

#### Access Control

- Set terminal password

  ```bash
  enable
  configure terminal
  line console 0
  password [yourPW]
  login
  exit
  ```

- Set `enable`/ privileged mode password

  ```bash
  enable
  configure terminal
  enable password c1$c0
  exit
  ```

- Set `enable` secret password (overrides `enable` password)

  ```bash
  config t
  enable secret itsasecret
  exit
  ```

- Set VTY password

  ```
line vty 0 15
  password [yourPw]
  login
  ```
  
  

- Encrypt unencrypted passwords

  - Note: `config t` = `configure terminal` 

  ```bash
  config t
  service password-encryption
  exit
  ```

- Message of the day banner

  ```bash
  config t
  banner motd "This is a secure system. Authorized Access Only!"
  exit
  ```

- Saving config file

  - Note: [Enter] key is on the keyboard

  ```bash
  copy running-config startup-config
  [Enter]
  ```

### Administration

- Configure IP address for switches

  ```bash
  configure terminal
  interface vlan 1
  ip address 192.168.1.253 255.255.255.0
  no shutdown
  exit
  ```

  - `no shutdown` is used to 'power on'.

- Reset router

  - ```bash
    enable
    erase startup-config
    delete vlan.dat
    reload
    no
    no
    yes
    ```

- Show status of IP address, ports, interfaces

  - `show ip interface brief`
  - `show running-config`

- 

## SPA

- Ask you to secure switch