

http://0pointer.de/blog/projects/os-release


https://www.freedesktop.org/software/systemd/man/os-release.html



http://0pointer.de/blog/projects/the-new-configuration-files.html







test -e /etc/os-release && os_release='/etc/os-release' || os_release='/usr/lib/os-release'
. "${os_release}"

echo "Running on ${PRETTY_NAME:-Linux}"





#!/usr/bin/python
# SPDX-License-Identifier: CC0-1.0

import platform
os_release = platform.freedesktop_os_release()

pretty_name = os_release.get('PRETTY_NAME', 'Linux')
print(f'Running on {pretty_name!r}')

if 'fedora' in [os_release.get('ID', 'linux'),
                *os_release.get('ID_LIKE', '').split()]:
    print('Looks like Fedora!')







----



Example 5. Reading os-release in python(1) (any version)

#!/usr/bin/python
# SPDX-License-Identifier: CC0-1.0

import ast
import re
import sys

def read_os_release():
    try:
        filename = '/etc/os-release'
        f = open(filename)
    except FileNotFoundError:
        filename = '/usr/lib/os-release'
        f = open(filename)

    for line_number, line in enumerate(f, start=1):
        line = line.rstrip()
        if not line or line.startswith('#'):
            continue
        if m := re.match(r'([A-Z][A-Z_0-9]+)=(.*)', line):
            name, val = m.groups()
            if val and val[0] in '"\'':
                val = ast.literal_eval(val)
            yield name, val
        else:
            print(f'{filename}:{line_number}: bad line {line!r}',
                  file=sys.stderr)

os_release = dict(read_os_release())

pretty_name = os_release.get('PRETTY_NAME', 'Linux')
print(f'Running on {pretty_name!r}')

if 'debian' in [os_release.get('ID', 'linux'),
                *os_release.get('ID_LIKE', '').split()]:
    print('Looks like Debian!')
Note that the above version that uses the built-in implementation is preferred in most cases, and the open-coded version here is provided for reference.


----



