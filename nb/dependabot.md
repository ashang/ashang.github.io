## Local Code Execution through Argument Injection via dash leading git url parameter in Gemfile. #195

In bundler versions before 2.2.33, when working with untrusted and apparently harmless Gemfile's, it is not expected that they lead to execution of external code, unless that's explicit in the ruby code inside the Gemfile itself. However, if the Gemfile includes gem entries that use the git option with invalid, but seemingly harmless, values with a leading dash, this can be false.

To handle dependencies that come from a Git repository instead of a registry, Bundler uses various commands, such as git clone. These commands are being constructed using user input (e.g. the repository URL). When building the
commands, Bundler versions before 2.2.33 correctly avoid Command Injection vulnerabilities by passing an array of arguments instead of a command string. However, there is the possibility that a user input starts with a dash (-) and is therefore treated as an optional argument instead of a positional one. This can lead to Code Execution because some of the commands have options that can be leveraged to run arbitrary executables.

Since this value comes from the Gemfile file, it can contain any character, including a leading dash.

### Exploitation

To exploit this vulnerability, an attacker has to craft a directory containing a Gemfile file that declares a dependency that is located in a Git repository. This dependency has to have a Git URL in the form of -u./payload. This URL
will be used to construct a Git clone command but will be interpreted as the upload-pack argument. Then this directory needs to be shared with the victim, who then needs to run a command that evaluates the Gemfile, such as bundle lock, inside.

### Impact

This vulnerability can lead to Arbitrary Code Execution, which could potentially lead to the takeover of the system. However, as explained above, the exploitability is very low, because it requires a lot of user interaction. It still could put developers at risk when dealing with untrusted files in a way they think is safe, because the exploit still works when the victim tries to make sure nothing can happen, e.g. by manually reviewing the Gemfile (although they would need the weird URL with a leading dash to not raise any flags).

This kind of attack vector has been used in the past to target security researchers by sending them projects to collaborate on.

### Patches

Bundler 2.2.33 has patched this problem by inserting -- as an argument before any positional arguments to those Git commands that were affected by this issue.
Workarounds

Regardless of whether users can upgrade or not, they should review any untrustred Gemfile's before running any bundler commands that may read them, since they can contain arbitrary ruby code.

### References

- <https://nvd.nist.gov/vuln/detail/CVE-2021-43809>
- <https://cwe.mitre.org/data/definitions/88.html>
- https://www.cnbc.com/2021/01/26/north-korean-hackers-targeting-security-researchers-on-twitter.html
- https://blog.google/threat-analysis-group/new-campaign-targeting-security-researchers/

## OS Command Injection in Rake #192

There is an OS command injection vulnerability in Ruby Rake before 12.3.3 in Rake::FileList when supplying a filename that begins with the pipe character |.

```rb
spec.add_dependency "rake", ">= 12.3.3"
spec.add_development_dependency "rake", ">= 12.3.3"

```

## Insecure path handling in Bundler #193


Bundler prior to 2.1.0 uses a predictable path in /tmp/, created with insecure permissions as a storage location for gems, if locations under the user's home directory are not available. If Bundler is used in a scenario where the user does not have a writable home directory, an attacker could place malicious code in this directory that would be later loaded and executed.



