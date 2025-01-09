#!/usr/bin/env expect

# ltp_efx500.exp
# For chassis EFX500 

proc Pdu_Reboot { port } {

set pduIp_90 10.10.50.90
set pduIp_91 10.10.50.91
set pduIp_92 10.10.50.92
set pduIp_93 10.10.50.93

switch $port {
       1 {
         spawn telnet $pduIp_92
         }

       2 {
         spawn telnet $pduIp_92
         }

       3 {
         spawn telnet $pduIp_92
         }

       4 {
         spawn telnet $pduIp_92
         }

       5 {
         spawn telnet $pduIp_92
         }

       6 {
         spawn telnet $pduIp_92
         }

       7 {
         spawn telnet $pduIp_91
         }

       8 {
         spawn telnet $pduIp_91
         }

       12 {
         spawn telnet $pduIp_91
         }

       13 {
         spawn telnet $pduIp_91
         }

       14 {
         spawn telnet $pduIp_93
         }

       15 {
         spawn telnet $pduIp_93
         }
       
       17 {
         spawn telnet $pduIp_90
         }

       18 {
         spawn telnet $pduIp_90
         }

       19 {
         spawn telnet $pduIp_90
         }

       20 {
         spawn telnet $pduIp_90
         }

       21 {
         spawn telnet $pduIp_90
         }

       22 {
         spawn telnet $pduIp_91
         }

       23 {
         spawn telnet $pduIp_91
         }

       24 {
         spawn telnet $pduIp_90
         }

       25 {
         spawn telnet $pduIp_90
         }

       26 {
         spawn telnet $pduIp_90
         }

       27 {
         spawn telnet $pduIp_90
         }

       28 {
         spawn telnet $pduIp_90
         }

  }

send "\r"

expect "Name"
send "apc\r"

expect "Password"
send "apc\r"

expect "Control Console"
send "1\r"

expect "Device Manager"

# if { $port>=1 && $port<=15 } {
if { $port>=1 && $port<=15 } {
  send "2\r"
  expect "Outlet Management"
  send "1\r"
 } elseif { $port>=17 && $port<=28 } {
# send "3\r"
   send "2\r"
  expect "Outlet Management"
  send "1\r"
 }

while 1 {
expect { 
   "Press <ENTER> to continue" {
         send "\r"
     }
   "Master Control/Configuration" {
         break
    }
 }
}

expect ">"

switch $port {
       1 {
         send "1\r"
         }

       2 {
         send "1\r"
         }

       3 {
         send "5\r"
         }

       4 {
         send "5\r"
         }

       5 {
         send "2\r"
         }

       6 {
         send "2\r"
         }

       7 {
         send "1\r"
         }

       8 {
         send "1\r"
         }

       12 {
         send "7\r"
         }

       13 {
         send "7\r"
         }

       14 {
         send "1\r"
         }

       15 {
         send "1\r"
         }

       17 {
         send "15\r"
         }

       18 {
         send "16\r"
         } 

       19 {
         send "18\r"
         }

       20 {
         send "19\r"
         }

       21 {
         send "21\r"
         }

       22 {
         send "5\r"
#     * EFX-500-6 (Rainier Development)
#          o Chassis - Rack 4 - 1
#           o Serial - 10.10.50.123 2022
#           o Remote PDU - 10.10.50.91 outlets 5 (apc/apc)
#           o Service-port Fixed address 10.10.50.76


         } 
     
       23 {
         send "7\r"
         }

       24 {
         send "4\r"
         }
 
       25 {
         send "5\r"
         }

       26 {
         send "6\r"
         }

       27 {
         send "7\r"
         }

       28 {
         send "8\r"
         }

  }

expect "Outlet"
send "1\r"

expect "Control Outlet"
# send "2\r"
send "3\r"

expect "Enter 'YES' to continue or <ENTER> to cancel :"
send "yes\r"

expect "Press <ENTER> to continue..."
send "\r"

while 1 {expect {
 	"<ESC>- Back" {send \033; exp_continue}
 	"Press <ENTER> to continue..." {send "\r"; exp_continue}
	"<ESC>- Main Menu" {send "4\r";break}
 }
}

puts "\n\r===================END====================\n\r"
}

set port [lindex $argv 0]
set pduIp 10.10.50.90

Pdu_Reboot $port

