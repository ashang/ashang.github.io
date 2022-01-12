---
date: 2019-02-10
---

# Error for userdel/user/add/groupadd/groupdel: 


# PAM authentication failed
    
    Solution: Add pam file.
    
    e.g. for userdel:
    
    add a file /etc/pam.d/userdel
    
```
auth	sufficient	pam_rootok.so
auth	required	pam_unix.so

account	required	pam_unix.so

session	required	pam_unix.so

password required	pam_permit.so
```
