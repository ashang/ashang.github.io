


$ grep -H '' /sys/devices/system/cpu/vulnerabilities/*

/sys/devices/system/cpu/vulnerabilities/itlb_multihit:KVM: Mitigation: VMX disabled
/sys/devices/system/cpu/vulnerabilities/l1tf:Mitigation: PTE Inversion; VMX: conditional cache flushes, SMT disabled
/sys/devices/system/cpu/vulnerabilities/mds:Mitigation: Clear CPU buffers; SMT disabled
/sys/devices/system/cpu/vulnerabilities/meltdown:Mitigation: PTI
/sys/devices/system/cpu/vulnerabilities/spec_store_bypass:Mitigation: Speculative Store Bypass disabled via prctl and seccomp
/sys/devices/system/cpu/vulnerabilities/spectre_v1:Mitigation: usercopy/swapgs barriers and __user pointer sanitization
/sys/devices/system/cpu/vulnerabilities/spectre_v2:Mitigation: Full generic retpoline, IBPB: conditional, IBRS_FW, STIBP: disabled, RSB filling
/sys/devices/system/cpu/vulnerabilities/srbds:Mitigation: Microcode
/sys/devices/system/cpu/vulnerabilities/tsx_async_abort:Mitigation: Clear CPU buffers; SMT disabled

$ awk 'FNR==1{print "==>"FILENAME"\n"}1' /sys/devices/system/cpu/vulnerabilities/*

==>/sys/devices/system/cpu/vulnerabilities/itlb_multihit

KVM: Mitigation: VMX disabled
==>/sys/devices/system/cpu/vulnerabilities/l1tf

Mitigation: PTE Inversion; VMX: conditional cache flushes, SMT disabled
==>/sys/devices/system/cpu/vulnerabilities/mds

Mitigation: Clear CPU buffers; SMT disabled
==>/sys/devices/system/cpu/vulnerabilities/meltdown

Mitigation: PTI
==>/sys/devices/system/cpu/vulnerabilities/spec_store_bypass

Mitigation: Speculative Store Bypass disabled via prctl and seccomp
==>/sys/devices/system/cpu/vulnerabilities/spectre_v1

Mitigation: usercopy/swapgs barriers and __user pointer sanitization
==>/sys/devices/system/cpu/vulnerabilities/spectre_v2

Mitigation: Full generic retpoline, IBPB: conditional, IBRS_FW, STIBP: disabled, RSB filling
==>/sys/devices/system/cpu/vulnerabilities/srbds

Mitigation: Microcode
==>/sys/devices/system/cpu/vulnerabilities/tsx_async_abort

Mitigation: Clear CPU buffers; SMT disabled

