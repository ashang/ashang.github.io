

### on mail server

$ for i in ferry.fan; do sudo useradd -m -d /home/$i -s /bin/false $i; echo $i:$i|sudo chpasswd; done

$ sudo vi /etc/aliases

$ sudo newaliases

### on other servers

$ for i in ferry.fan; do sudo useradd -m -d /home/$i -s /bin/bash $i; echo $i:$i|sudo chpasswd; done

### samba

for i in [a-z]*; do echo -e "$i\n$i\n"|sudo pdbedit -a -u $i -t;done


## Resources

- Webmail https://outlook.office.com/
