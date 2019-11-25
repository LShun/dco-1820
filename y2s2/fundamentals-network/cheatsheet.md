# CLI

### Show MAC table

- `show mac-address-table`

### ARP

- Delete ARP: `arp -d`
- Show ALL ARP: `arp -a`

### Configuration

`show running-config`: Displays running configuration

`show startup-config`: Show startup configuration

- Change host name:

```bash
enable
conf t
h S1
exit
```

- Notes
  - `conf` = `configure`
  - `t` = `terminal`

### IPv6

#### Router: Enable IPv6 forwarding

```bash
enable
conf t
ipv6 unicast-routing
```

#### Router: Config IPv6 address

```bash
en
conf t
interface [interfaceName, eg: GigabitEthernet0/0]
ipv6 address [address, eg: 2001:DB8:1:1::1/64]
no shutd
ex
```

- For link local: `ipv6 address FE80::1 link-local`

#### ServersL Conf IPv6

- Use Desktop > IP Config

#### Flash

- `show flash`: Show contents of flash
- Save startup config to flash
  - `copy startup-config flash`

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

- Save config to NVRAM/file

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