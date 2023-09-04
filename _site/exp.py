#!/usr/bin/python3
import sys
#from pexpect import spawn
import pexpect

p = pexpect.spawn('cat') # Echo is on by default.
p.sendline('1234') # We expect see this twice from the child...
p.expect(['1234']) # ... once from the tty echo...
p.expect(['1234']) # ... and again from cat itself.
p.setecho(False) # Turn off tty echo
p.sendline('abcd') # We will set this only once (echoed by cat).
p.sendline('wxyz') # We will set this only once (echoed by cat)
p.expect(['abcd'])
p.expect(['wxyz'])

#r = ssh.expect(['$ '])
#
#if r == 0:
    #ssh.sendline('ls; pwd')

pexpect.run("uname -prov")
#handler = pexpect.spawn("ssh dev22", encoding='utf-8', logfile=sys.stdout)
handler = pexpect.spawn("ssh 10.10.50.168", encoding='utf-8')
handler = pexpect.spawn("ssh 10.10.50.168", encoding='utf-8', logfile=sys.stdout, echo=False)
handler = pexpect.spawn("ssh 10.10.50.168", encoding='utf-8')

## NOT to echo secrets
#handler.logfile=sys.stdout
## 'echo=False' only disables 'read', the 'send' still outputs
## setecho(False) + waitnoecho() make no sense
handler.logfile_read=sys.stdout

#i = handler.expect(["password"])
#if i == 0:
    #handler.sendline("pwd")

#handler.expect(["$ "])
#handler.sendline("pwd")
#handler.expect(["$ "])
##handler.sendline("exit")

handler.expect(["assword:"])
handler.waitnoecho()
handler.sendline("shang")
#handler.setecho(True)

handler.expect(["@localhost:"])
handler.sendline("uname -prov")
handler.expect(["@localhost:"])
handler.sendline("exit")

#handler.logfile = None
#handler.interact()

handler.expect(pexpect.EOF)

pexpect.run("uname -prov")

# $ python -m trace --trace exp.py

#handler = pexpect.spawn('/bin/ls /tmp')
#handler.expect(pexpect.EOF)
print()
print(handler.before)


c = pexpect.spawnu('/usr/bin/env python')

c.expect('>>>')
print('And now for something completely different...')
print(''.join(reversed((c.before))))
print('Yes, it\'s python, but it\'s backwards.')
print()
print('Escape character is \'^]\'.')
print(c.after, end=' ')
c.interact()
c.kill(1)
print('is alive:', c.isalive())