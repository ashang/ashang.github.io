---
title: rbenv
date: 2017-09-03
--- 

Using rbenv will provide you with a well-controlled and robust environment for
developing your Ruby on Rails applications, allowing you to easily switch the
version of Ruby for your entire team when needed.

rbenv provides support for specifying application-specific versions of Ruby,
lets you change the global Ruby for each user, and allows you to use an
environment variable to override the Ruby version.

```
gem install --user-install rbenv
```

```
rbenv init
```

Verify that rbenv is properly set up using this rbenv-doctor script:

```
curl -fsSL https://github.com/rbenv/rbenv-installer/raw/main/bin/rbenv-doctor | bash
```

```
$ gem install --user-install rbenv
WARNING:  You don't have /home/aaron/.gem/ruby/3.0.0/bin in your PATH,
          gem executables will not run.
Successfully installed rbenv-9001
1 gem installed
```

## Trouble shooting

