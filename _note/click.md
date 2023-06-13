---
title: Click the Command Line Interface Creation Kit
date: 2014-12-20
---

Click is a Python package for creating beautiful command line interfaces in a composable way with as little code as necessary.

It’s the “Command Line Interface Creation Kit”. It’s highly configurable but comes with sensible defaults out of the box.

It aims to make the process of writing command line tools quick and fun while also preventing any frustration caused by the inability to implement an intended CLI API.

Click in three points:

- arbitrary nesting of commands
- automatic help page generation
- supports lazy loading of subcommands at runtime

```py
import click

@click.command()
@click.option('--count', default=1, help='Number of greetings.')
@click.option('--name', prompt='Your name',
              help='The person to greet.')
def hello(count, name):
    """Simple program that greets NAME for a total of COUNT times."""
    for x in range(count):
        click.echo('Hello %s!' % name)

if __name__ == '__main__':
    hello()
```

$ python hello.py --count=3
Your name: John
Hello John!
Hello John!
Hello John!
It automatically generates nicely formatted help pages:

$ python hello.py --help
Usage: hello [OPTIONS]

  Simple program that greets NAME for a total of COUNT times.

Options:
  --count INTEGER  Number of greetings.
  --name TEXT      The person to greet.
  --help           Show this message and exit.


Click is designed to allow you to nest command line utilities. The idea is that you can have a system that works together with another system by tacking two Click instances together and they will continue working as they should.

Click was written to support the Flask microframework ecosystem because no tool could provide it with the functionality it needed.

Click is actually implemented as a wrapper around a mild fork of optparse and does not implement any parsing itself.

The reason it’s not based on argparse is that argparse does not allow proper nesting of commands by design and has some deficiencies when it comes to POSIX compliant argument handling.

The reason however Click is not using argparse is that it has some problematic behaviors that make handling arbitrary command line interfaces hard:

- argparse has built-in magic behavior to guess if something is an argument or an option. This becomes a problem when dealing with incomplete command lines as it’s not possible to know without having a full understanding of the command line how the parser is going to behave. This goes against Click’s ambitions of dispatching to subparsers.

- argparse currently does not support disabling of interspersed arguments. Without this feature it’s not possible to safely implement Click’s nested parsing nature.
