---
title: bundler
date: 2019-06-06
--- 

# bundler install

```
$ bundle install
Warning: the running version of Bundler (2.2.5) is older than the version that created the lockfile (2.2.33). We suggest you to upgrade to the version that created the lockfile by running `gem install bundler:2.2.33`.
```

# mirrors for bundler or Gemfile

```
$ bundle config mirror.https://rubygems.org https://mirrors.ustc.edu.cn/rubygems/

$ cat ~/.bundle/config
---
BUNDLE_MIRROR__HTTPS://RUBYGEMS__ORG/: "https://mirrors.ustc.edu.cn/rubygems/"

$ bundle config mirror.https://rubygems.org https://mirrors.tuna.tsinghua.edu.cn/rubygems

You are replacing the current global value of mirror.https://rubygems.org, which is
currently "https://mirrors.ustc.edu.cn/rubygems/"

$ bundle config mirror.https://rubygems.org
Settings for `mirror.https://rubygems.org` in order of priority. The top value will be used
Set for the current user (/home/aaron/.bundle/config): "https://mirrors.tuna.tsinghua.edu.cn/rubygems"

$ cat ~/.bundle/config
---
BUNDLE_MIRROR__HTTPS://RUBYGEMS__ORG/: "https://mirrors.tuna.tsinghua.edu.cn/rubygems"
```

```
$ bundle-2.7 update
 Warning: the running version of Bundler (2.1.4) is older than the version that
 created the lockfile (2.2.33). We suggest you to upgrade to the version that
 created the lockfile by running `gem install bundler:2.2.33`.
 The dependency tzinfo (~> 1.2) will be unused by any of the platforms Bundler
 is installing for. Bundler is installing for ruby but the dependency is only
 for x86-mingw32, x64-mingw32, x86-mswin32, java. To add those platforms to the
 bundle, run `bundle lock --add-platform x86-mingw32 x64-mingw32 x86-mswin32
 java`.
 The dependency tzinfo-data (>= 0) will be unused by any of the platforms
 Bundler is installing for. Bundler is installing for ruby but the dependency
 is only for x86-mingw32, x64-mingw32, x86-mswin32, java. To add those
 platforms to the bundle, run `bundle lock --add-platform x86-mingw32
 x64-mingw32 x86-mswin32 java`.
 The dependency wdm (~> 0.1.1) will be unused by any of the platforms Bundler
 is installing for. Bundler is installing for ruby but the dependency is only
 for x86-mingw32, x64-mingw32, x86-mswin32. To add those platforms to the
 bundle, run `bundle lock --add-platform x86-mingw32 x64-mingw32 x86-mswin32`.
 Fetching source index from https://mirrors.tuna.tsinghua.edu.cn/rubygems/
 Resolving dependencies.....

$ gem install --user-install bundler:2.2.33
WARNING:  You don't have /home/aaron/.gem/ruby/3.0.0/bin in your PATH,
          gem executables will not run.
Successfully installed bundler-2.2.33
1 gem installed

$ gem install --user-install bundler:2.2.33
Fetching bundler-2.2.33.gem
WARNING:  You don't have /home/aaron/.gem/ruby/2.7.0/bin in your PATH,
          gem executables will not run.
Successfully installed bundler-2.2.33
Parsing documentation for bundler-2.2.33
Installing ri documentation for bundler-2.2.33
Done installing documentation for bundler after 1 seconds
1 gem installed

$ bundle-2.7 config set --local path ~/.gem 
```
