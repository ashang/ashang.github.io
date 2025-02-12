
$ sudo iptables -L --line-numbers
Chain INPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain FORWARD (policy DROP)
num  target     prot opt source               destination         
1    DOCKER-USER  all  --  anywhere             anywhere            
2    DOCKER-ISOLATION  all  --  anywhere             anywhere            
3    ACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED
4    DOCKER     all  --  anywhere             anywhere            
5    ACCEPT     all  --  anywhere             anywhere            
6    ACCEPT     all  --  anywhere             anywhere            

Chain OUTPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain DOCKER (1 references)
num  target     prot opt source               destination         
1    ACCEPT     tcp  --  anywhere             172.17.0.2           tcp dpt:5000

Chain DOCKER-ISOLATION (1 references)
num  target     prot opt source               destination         
1    RETURN     all  --  anywhere             anywhere            

Chain DOCKER-USER (1 references)
num  target     prot opt source               destination         
1    RETURN     all  --  anywhere             anywhere            



W01.5 0103 11:08:37 aaron@dev24:~/
$ sudo iptables -L --line-numbers
Chain INPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain FORWARD (policy DROP)
num  target     prot opt source               destination         
1    DOCKER-ISOLATION  all  --  anywhere             anywhere            
2    ACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED
3    DOCKER     all  --  anywhere             anywhere            
4    ACCEPT     all  --  anywhere             anywhere            
5    ACCEPT     all  --  anywhere             anywhere            

Chain OUTPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain DOCKER (1 references)
num  target     prot opt source               destination         
1    ACCEPT     tcp  --  anywhere             172.17.0.2           tcp dpt:2375
2    ACCEPT     tcp  --  anywhere             172.17.0.5           tcp dpt:5000
3    ACCEPT     tcp  --  anywhere             172.17.0.3           tcp dpt:afs3-callback
4    ACCEPT     tcp  --  anywhere             172.17.0.3           tcp dpt:4001

Chain DOCKER-ISOLATION (1 references)
num  target     prot opt source               destination         
1    RETURN     all  --  anywhere             anywhere            





W01.5 0103 10:55:41 aaron@dev16:~/
$ sudo iptables -L --line-numbers
Chain INPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain FORWARD (policy DROP)
num  target     prot opt source               destination         
1    DOCKER-ISOLATION  all  --  anywhere             anywhere            
2    ACCEPT     all  --  anywhere             anywhere             ctstate RELATED,ESTABLISHED
3    DOCKER     all  --  anywhere             anywhere            
4    ACCEPT     all  --  anywhere             anywhere            
5    ACCEPT     all  --  anywhere             anywhere            

Chain OUTPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain DOCKER (1 references)
num  target     prot opt source               destination         
1    ACCEPT     tcp  --  anywhere             172.17.0.2           tcp dpt:9443

Chain DOCKER-ISOLATION (1 references)
num  target     prot opt source               destination         
1    RETURN     all  --  anywhere             anywhere            

