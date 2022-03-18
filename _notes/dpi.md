


状态防火墙监视网络连接的“状态”，比如TCP流、UDP数据和ICMP消息可能被分为LISTEN,
ESTABLISHED,

或者CLOSING状态[2]。按照相应的安全策略，状态防火墙在状态表中为各TCP流或者UDP数据创建记录。凡在表中的session，所有相关封包都被允许通过，不再检测，因此比一般的检测使用更少CPU。

维持一个session的状态取决于其传输层协议。比如TCP是面向连接的协议[3]，其session是由三路握手的SYN消息建立，由FIN消息终止。[4]状态防火墙由此可以知道何时从表中移除session，而不必等待超时再移除。UDP是无连接的协议[3]，它不会发送特别的连接消息，因此一个UDP的session只有等待超时才会被移除，UDP打洞就利用了这一特性设立隧道。[5] ICMP消息与TCP和UDP不同，它传递网络本身的控制信息，比如ping命令。[6]ICMP回复一般会被允许。有时UDP通信会使用ICMP来提供session的状态信息，因此和某UDP session有关的ICMP回复也是允许的。


缺點[编辑]
無法處理應用層協定


應用防火牆（英語：Application
firewall），一種防火牆，經由應用程式或服務來控制網路封包的流入、流出與系統調用，因為運作在OSI模型中的應用層而得名。它能夠監控網路封包，阻擋不符合防火牆設定規則的封包進入、離開以及呼叫系統調用（system
calls）。這類防火牆，通常又可以分成以網路為基礎的應用防火牆（network-based
application firewalls）與以主機為基礎的應用防火牆（host-based application
firewalls）二者。


跳到导航跳到搜索
次世代防火墙，一般称呼为：下一代防火牆（英語：Next-Generation Firewall，縮寫為NGFW），一種整合式的網路平台，將多種功能整合在其上：除了傳統的防火牆功能之外，還包括線上深度封包檢測（DPI），入侵預防系統（IPS），應用層偵測與控制，SSL/SSH檢測，網站過濾，以及QoS/頻寬管理等功能，使得這個系統能夠應對複雜而高智慧的網路攻擊行動。其他技術還可以被採用，例如TLS / SSL加密流量檢查，網站過濾，QoS /帶寬管理，防病毒檢測和第三方身份管理集成（即LDAP，RADIUS，Active Directory）[1]。

與傳統防火牆的比較[编辑]
NGFW包括傳統防火牆的典型功能，如封包過濾[2]，網絡和端口地址轉換（NAT），狀態檢查和虛擬私人網路（VPN）支持[3]。 下一代防火牆的目標是包含OSI模型的更多層次，改進了依賴於數據包內容的網絡流量過濾[



get the brief information about your motherboard:

 sudo dmidecode -t2                                                                                     ✔
# dmidecode 3.3
Getting SMBIOS data from sysfs.
SMBIOS 3.2.1 present.

Handle 0x0002, DMI type 2, 15 bytes
Base Board Information
        Manufacturer: Dell Inc.
        Product Name: 0V251J
        Version: A03
        Serial Number: /F6JRZN2/CNWSC0002D0CFJ/
        Asset Tag: Not Specified
        Features:
                Board is a hosting board
                Board is replaceable
        Location In Chassis: Not Specified
        Chassis Handle: 0x0003
        Type: Motherboard
        Contained Object Handles: 0

# dmidecode -t baseboard                                                                            ✔
# dmidecode 3.3
Getting SMBIOS data from sysfs.
SMBIOS 3.2.1 present.

Handle 0x0002, DMI type 2, 15 bytes
Base Board Information
        Manufacturer: Dell Inc.
        Product Name: 0V251J
        Version: A03
        Serial Number: /F6JRZN2/CNWSC0002D0CFJ/
        Asset Tag: Not Specified
        Features:
                Board is a hosting board
                Board is replaceable
        Location In Chassis: Not Specified
        Chassis Handle: 0x0003
        Type: Motherboard
        Contained Object Handles: 0

Handle 0x0009, DMI type 10, 6 bytes
On Board Device Information
        Type: Video
        Status: Enabled
        Description: "Intel HD Graphics"

Handle 0xF02E, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 1
        Bus Address: 0000:00:00.0

Handle 0xF02F, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Video
        Type: Video
        Status: Enabled
        Type Instance: 1
        Bus Address: 0000:00:02.0

Handle 0xF030, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 2
        Bus Address: 0000:00:04.0

Handle 0xF031, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 3
        Bus Address: 0000:00:08.0

Handle 0xF032, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 4
        Bus Address: 0000:00:12.0

Handle 0xF033, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 5
        Bus Address: 0000:00:14.0

Handle 0xF034, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 6
        Bus Address: 0000:00:14.2

Handle 0xF035, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Ethernet
        Type: Ethernet
        Status: Enabled
        Type Instance: 1
        Bus Address: 0000:00:14.3

Handle 0xF036, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 7
        Bus Address: 0000:00:15.0

Handle 0xF037, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 8
        Bus Address: 0000:00:15.1

Handle 0xF038, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 9
        Bus Address: 0000:00:16.0

Handle 0xF039, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - SATA
        Type: SATA Controller
        Status: Enabled
        Type Instance: 1
        Bus Address: 0000:00:17.0

Handle 0xF03A, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 10
        Bus Address: 0000:00:1f.0

Handle 0xF03B, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Sound
        Type: Sound
        Status: Enabled
        Type Instance: 1
        Bus Address: 0000:00:1f.3

Handle 0xF03C, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 11
        Bus Address: 0000:00:1f.4

Handle 0xF03D, DMI type 41, 11 bytes
Onboard Device
        Reference Designation: Onboard - Other
        Type: Other
        Status: Enabled
        Type Instance: 12
        Bus Address: 0000:00:1f.5

    ~  sudo dmidecode -t system                                                                               ✔
# dmidecode 3.3
Getting SMBIOS data from sysfs.
SMBIOS 3.2.1 present.

Handle 0x0001, DMI type 1, 27 bytes
System Information
        Manufacturer: Dell Inc.
        Product Name: Inspiron 5488
        Version: Not Specified
        Serial Number: F6JRZN2
        UUID: 4c4c4544-0036-4a10-8052-c6c04f5a4e32
        Wake-up Type: Power Switch
        SKU Number: 089C
        Family: Inspiron

Handle 0x000B, DMI type 12, 5 bytes
System Configuration Options
        Option 1: Default string

Handle 0x000C, DMI type 15, 35 bytes
System Event Log
        Area Length: 4 bytes
        Header Start Offset: 0x0000
        Header Length: 2 bytes
        Data Start Offset: 0x0002
        Access Method: Indexed I/O, one 16-bit index port, one 8-bit data port
        Access Address: Index 0x046A, Data 0x046C
        Status: Invalid, Not Full
        Change Token: 0x00000000
        Header Format: No Header
        Supported Log Type Descriptors: 6
        Descriptor 1: End of log
        Data Format 1: OEM-specific
        Descriptor 2: End of log
        Data Format 2: OEM-specific
        Descriptor 3: End of log
        Data Format 3: OEM-specific
        Descriptor 4: End of log
        Data Format 4: OEM-specific
        Descriptor 5: End of log
        Data Format 5: OEM-specific
        Descriptor 6: End of log
        Data Format 6: OEM-specific

Handle 0x0013, DMI type 32, 20 bytes
System Boot Information
        Status: No errors detected



                                                                                                       ✔
    ~  cat /sys/devices/virtual/dmi/id/board_{vendor,name,version}                                            ✔
Dell Inc.
0V251J
A03
    ~ 


                                                                                                     2 ✘
    ~  sudo dmidecode -s                                                                                    2 ✘
dmidecode: option requires an argument -- 's'
String keyword expected
Valid string keywords are:
  bios-vendor
  bios-version
  bios-release-date
  bios-revision
  firmware-revision
  system-manufacturer
  system-product-name
  system-version
  system-serial-number
  system-uuid
  system-sku-number
  system-family
  baseboard-manufacturer
  baseboard-product-name
  baseboard-version
  baseboard-serial-number
  baseboard-asset-tag
  chassis-manufacturer
  chassis-type
  chassis-version
  chassis-serial-number
  chassis-asset-tag
  processor-family
  processor-manufacturer
  processor-version
  processor-frequency
    ~ 



                                                                                                       ✔
    ~  sudo dmidecode -s system-serial-number                                                                 ✔
F6JRZN2
    ~ 



