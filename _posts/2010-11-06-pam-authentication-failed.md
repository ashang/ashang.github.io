---
author: aaronshang
comments: true
date: 2010-11-06 09:13:18+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/11/06/pam-authentication-failed/
slug: pam-authentication-failed
title: PAM authentication failed
wordpress_id: 54
---

# Error for userdel/user/add/groupadd/groupdel: 





# PAM authentication failed
    
    Solution: Add pam file.
    
    e.g. for userdel:
    
    add a file /etc/pam.d/userdel
    
    

auth	sufficient	pam_rootok.so
auth	required	pam_unix.so

account	required	pam_unix.so

session	required	pam_unix.so

password required	pam_permit.so
