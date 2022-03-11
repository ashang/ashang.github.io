

store the password with the industry standard bcryptjs or bcrypt to protect them.

bcrypt uses a form of encryption to convert your password into a very large number that's easy to confirm, but difficult to reverse engineer with only the number. When you give my server your password I run it through the same encryption and if it comes equal to what I have in the database (more or less), then I know you gave me the correct one.

What makes bcrypt secure is someone with this large number has to spend a lot of time feeding bad passwords through bcrypt--requiring expensive CPU usage--


https://codahale.com/how-to-safely-store-a-password/


MDx 与 SHAx 系列散列，都是 为尽快摘要大量数据设计的通用算法，对于保证完整性是高效的。
对于防御字典攻击或暴力攻击，为速度要求设计的通用加密散列，加盐与否以及盐的强弱都无关紧要。

It uses a variant of the Blowfish encryption algorithm’s keying schedule, and introduces a work factor, which allows you to determine how expensive the hash function will be. Because of this, bcrypt can keep up with Moore’s law. As computers get faster you can increase the work factor and the hash will get slower.

bcrypt 根據Blowfish加密演算法所設計的密碼雜湊函式，

實作中bcrypt會使用一個加鹽的流程以防禦彩虹表攻擊，同時bcrypt還是適應性函式，它可以藉由增加疊代之次數來抵禦日益增進的電腦運算能力透過暴力法破解。

口令必须是8至56个字符，并将在内部被轉化为448位的密钥。然而，所提供的所有字符都具有十分重要的意义。密码越强大，数据就越安全。

除了对数据进行加密，默认情况下，bcrypt在删除数据之前将使用随机数据三次覆盖原始输入文件，以阻挠可能会获得计算机数据的人恢复数据的尝试。


bcrypt allows you to choose your balance of speed and security.


bcrypt is an adaptive password hashing algorithm which uses the Blowfish keying schedule, not a symmetric encryption algorithm.


 bcrypt has salts built-in to prevent rainbow table attacks.


Security Issues And Concerns

Per bcrypt implementation, only the first 72 bytes of a string are used. Any extra bytes are ignored when matching passwords. Note that this is not the first 72 characters. It is possible for a string to contain less than 72 characters, while taking up more than 72 bytes (e.g. a UTF-8 encoded string containing emojis).



##

https://www.npmjs.com/package/bcrypt



```
import re

# Simplified version of a regex to match bcrypt passwords
regular_expression = "^[$]2[abxy]?[$](?:0[4-9]|[12][0-9]|3[01])[$][./0-9a-zA-Z]{53}$"

# A bcrypt password encoded with version "2y" and cost 12
encoded_password = "$2y$12$PEmxrth.vjPDazPWQcLs6u9GRFLJvneUkcf/vcXn8L.bzaBUKeX4W"

matches = re.search(regular_expression, encoded_password)

if matches:
  print("YES! We have a match!")
else:
  print("No match")
```











