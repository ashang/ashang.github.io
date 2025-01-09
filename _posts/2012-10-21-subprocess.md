

## subprocess


process = subprocess.Popen(
   cmd,
   stdout=subprocess.PIPE,
   stderr=subprocess.PIPE,
   shell=True,
   encoding='utf-8',
   errors='strict',   # could be ignore or replace too, `strict` is the default
)



import subprocess

p1 = subprocess.Popen('dir', shell=True, stdin=None, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
p2 = subprocess.Popen('sort /R', shell=True, stdin=p1.stdout)

p1.stdout.close()
out, err = p2.communicate()
In order to combine both commands, we create two subprocesses, one for the dir command and another for the sort command. Since we want to sort in reverse order, we add /R option to the sort call.

We define the stdout of process 1 as PIPE, which allows us to use the output of process 1 as the input for process 2. Then we need to close the stdout of process 1, so it can be used as input by process 2. The communication between process is achieved via the communicate method.


## str vs bytes

@CraigAnderson: unicode_text = str(bytestring, character_encoding) works as expected on Python 3. Though unicode_text = bytestring.decode(character_encoding) is more preferable to avoid confusion with just str(bytes_obj) that produces a text representation for bytes_obj instead of decoding it to text: str(b'\xb6', 'cp1252') == b'\xb6'.decode('cp1252') == '¶' and str(b'\xb6') == "b'\\xb6'" == repr(b'\xb6') != '¶'


str(bytes_string, 'utf-8', 'ignore') Errors can be ignored by passing the third parameter.


## Output



In Python 3, sys.stdout is always str-typed, with an encoding chosen by the PYTHONIOENCODING environment variable (and/or PYTHONUTF8 on Windows).

sys.stdout.buffer (i.e. a TextIOBase::buffer) is the underlying bytestream for the text-encoded stdout stream.

Since you're reading bytes from the subprocess, you'll need to also write to the byte-typed stream.

for c in iter(lambda: process.stdout.read(1), b''):
    sys.stdout.buffer.write(c)

    If, on the other hand, you do expect to be working with text, you may wish to configure the subprocess object to decode output to strings.


## Logging

Here's how I do it with logging and argparse:

import argparse
import logging

parser = argparse.ArgumentParser()
parser.add_argument(
    '-d', '--debug',
    help="Print lots of debugging statements",
    action="store_const", dest="loglevel", const=logging.DEBUG,
    default=logging.WARNING,
)
parser.add_argument(
    '-v', '--verbose',
    help="Be verbose",
    action="store_const", dest="loglevel", const=logging.INFO,
)
args = parser.parse_args()
logging.basicConfig(level=args.loglevel)

So if --debug is set, the logging level is set to DEBUG. If --verbose, logging is set to INFO. If neither, the lack of --debug sets the logging level to the default of WARNING.


 @MatthewLeingang When the output is a console/terminal it's usually better to send all messages to stderr. Sending them to stdout typically makes it more difficult to use your program in a unix pipeline. The rule of thumb for me is stdout -> program output, stderr -> program messages.

https://docs.python.org/2/howto/logging.html#handlers


 Creating a filter class is actually not necessary. You can also pass a callable: h1.addFilter(lambda record: record.levelno <= logging.INFO)

https://docs.python.org/3.7/howto/logging.html

https://docs.python.org/zh-cn/3.12/howto/argparse.html

https://docs.python.org/3/library/trace.html


