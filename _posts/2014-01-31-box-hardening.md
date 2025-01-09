---
date: "2013-08-01"
title: box hardening
---

- Default password changes in each release.
    - Document the change in release notes, and in user manual.
    - Explicitly point out that the password will change in each release

- Force users to change password on install, as most systems do.

- Do NOT put plain text passwords in releases.

- Check VERY seriously of code, especially in plain text scripts.

- Carefully assign file permissions.

- Audit code for security. At least block
    - Remote code execution
    - Arbitrary code execution
    - Take good care with inputs




    exec('/usr/bin/logger -p lpr.info -t Acc_Printer -- "Printer ' . $ip . ' ' . $buffer . ' ' . $msg . '"', $out, $ret);

