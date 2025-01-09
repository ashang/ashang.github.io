---
title: jupyter notebook
date: 2018-01-21
---

## notebook password

```
$ jupyter notebook password
Enter password:
Verify password:
[NotebookPasswordApp] Wrote hashed password to /home/aaron/.jupyter/jupyter_notebook_config.json
```

## HTTPS

Generate a self-signatured certificate using SSLby.

    $ cd $HOME/.jupyter; sscg

```
$ sscg
Wrote service certificate key to /home/aaron/.jupyter/service-key.pem
Wrote service certificate to /home/aaron/.jupyter/service.pem
Wrote CA certificate to /home/aaron/.jupyter/ca.crt
```
