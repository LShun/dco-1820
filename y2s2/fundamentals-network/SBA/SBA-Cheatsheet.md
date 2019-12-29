# SBA - Cheatsheet

## Change HostName

en

conf t

h[ost] [hostName]

## Disable DNS Lookup

en

conf t

no ip domain-lookup

## EXEC Secret password

en

conf t

ena[ble] s[ecret] pas$word

## EXEC Literal password

en

conf t

enable password pas$word

## Console Password

en

conf t

line console 0

password CISCO

login

## VTY Password enable login

en

conf t

line vty 0 4

password CISCO123

login

## Encrypt clear text password

conf t

service password-encryption







