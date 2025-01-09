---
title: fly.io
date: 2018-08-13
--- 


    ~  mkdir flyio                                                                                                                                                                                                                                                                                                      ✔
    ~  cd flyio                                                                                                                                                                                                                                                                                                         ✔
    ~/flyio  curl -L https://fly.io/install.sh | sh                                                                                                                                                                                                                                                                     ✔
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  1412    0  1412    0     0   1235      0 --:--:--  0:00:01 --:--:--  1236
curl: (28) Failed to connect to github.com port 443 after 130198 ms: Connection timed out

    ~/flyio                                                                                                                                                                                                                                                                                             0|28 ✘  2m 14s 
    ~/flyio  curl -L -O https://fly.io/install.sh                                                                                                                                                                                                                                                                  0|28 ✘
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  1412    0  1412    0     0    996      0 --:--:--  0:00:01 --:--:--   996
    ~/flyio  ls -ltr                                                                                                                                                                                                                                                                                                    ✔
total 4
-rw-r--r-- 1 aaron aaron 1412 Dec 17 13:43 install.sh
    ~/flyio  vi install.sh                                                                                                                                                                                                                                                                                              ✔
    ~/flyio  sh install.sh                                                                                                                                                                                                                                                                                       ✔  4s 
#=#=-  #       #                                                                                                                                                                                                                                               #=O#-     #        #                                                                                                                                                                                                                                           -#O=- #      #          #                                                                                                         ######################################################################################################################################################################################################################################################### 100.0%-=O#-   #        #           #                                                                                                                                                                                                                                  -=O=#      #        #            #                                                                                                                                                                                                                             -=O=- #       #          #             #                                                                                                                                                         ######################################################################################################################################################################################################################################################### 100.0%
WARN no config file found at /home/aaron/.fly/config.yml
set channel to shell
flyctl was installed successfully to /home/aaron/.fly/bin/flyctl
Manually add the directory to your $HOME/.zshrc (or similar)
  export FLYCTL_INSTALL="/home/aaron/.fly"
  export PATH="$FLYCTL_INSTALL/bin:$PATH"
Run '/home/aaron/.fly/bin/flyctl --help' to get started
    ~/flyio   



