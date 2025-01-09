---
date: 2017-07-20
update: 2016-11-11 11:00:00 CST
---

while true; do nc -l -p 80 < index.html; done

One downside of this is that many implementations of netcat can only do one connection at once, so it won't serve a file the second time until the first connection is properly closed or times out. Some variants (the most common is the BSD one) have a -k option that will solve this nicely; the bash script using nc mentioned in Nick Lothian's answer tries to solve this problem with some vanilla netcat.

