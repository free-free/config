#!/bin/sh

# tell you whether the adapter has an ip address allocated
sudo ifconfig 

# check booting log
dmesg | tail

# shed some light on what caused the connection to drop
sudo dhclient -v wlan0 # or (wlp3s0)

# restart NetworkManager
sudo systemctl restart NetworkManager

# restart networking 
nmcli networking off
nmcli networking on

# restart wifi
nmcli radio wifi off && sleep && nmcli radio wifi on
# reload the kernel wifi module
# The Module name will depend on the wifi hardware installed.To
# find out the module name try eithrt of these commands:
# $ lspci | grep -i network
# or 
# $ sudo lshw -C network
# and look for a line containing driver=something

sudo rmmod iwlwifi
sudo modprobe iwlwifi



