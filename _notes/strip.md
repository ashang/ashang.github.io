---
title: "Strip"
date: 2021-06-10T11:30:30+08:00
---

The `strip` command removes the symbol table, debugging information, and line number information from ELF object files.

# strip

`strip` can be done by linker;

In, gcc, use the option `-s`.

## Remove section

```shell
strip -R .note.ABI-tag /usr/lib/x86_64-linux-gnu/libQt5Core.so.5
```

## Kernel modules

Try this, a selective strip of modules keeping the special symbols that
insmod needs to initialise modules, handle variables etc. Due to what
appears to be a bug in script, it cannot strip globals.

```perl
#!/usr/bin/perl -w
#
# Given a list of objects, strip all static symbols except those
# required by insmod.
#
# Copyright Keith Owens <kaos@ocs.com.au>. GPL.
# Sat Feb 1 12:52:17 EST 1997
#
# Mainly intended for reducing the size of modules to save space
# on emergency and install disks. Be aware that removing the
# static symbols reduces the amount of diagnostic information
# available for oops. Not recommended for normal module usage.
#
# This code requires the modules use MODULE_PARM and EXPORT_.
# Do not strip modules that have not been converted to use
# MODULE_PARM or are using the old method of exporting symbols.
# In particular do not use on modules prior to 2.1.20 (approx).
#
# The objects are stripped in /tmp, only if the strip works is
# the original overwritten. If the command line to strip the
# symbols becomes too long, the strip is done in multiple passes.
# Running strip_module twice on the same object is safe (and a
# waste of time).
#

require 5;
use strict;
use English;

my $strip = "/usr/bin/strip";
my $nm = "/usr/bin/nm";
my $cp = "/bin/cp";
my $mv = "/bin/mv";
my $rm = "/bin/rm";
my $tmp = "/tmp";
my $command_size = 400; # arbitrary but safe

my $tmpcopy = "$tmp/$PID.object";
my $nmout = "$tmp/$PID.nmout";

my $i;

for ($i = 0; $i <= $#ARGV; ++$i) {
strip_module($ARGV[$i]);
}

do_command("$rm -f $tmpcopy $nmout");

exit(0);

sub strip_module()
{
my ($object) = @_;
my (%keep, %to_strip, $symbol, $command, $changed, $line, @f);
do_command("$cp -a $object $tmpcopy");
do_command("$nm $tmpcopy > $nmout");
open(NMOUT, "<$nmout") || die "cannot read $nmout";
while (defined($line = <NMOUT>)) {
chop($line);
my @field = split(' ', substr($line, 9));

if ($field[1] eq 'init_module' ||
$field[1] eq 'cleanup_module') {
$keep{$field[1]} = "";
}

# b static variable, uninitialised
# d static variable, initialised
# r static array, initialised
# t static label/procedures

# You should be able to strip the following if you are feeling
# brave but the strip command refuses to strip individual global
# symbols. A plain strip will remove them but selective strip
# fails. Bug in strip?
# C global variable, uninitialised
# D global variable, initialised
# R global array, initialised
# T global label/procedure

if ($field[0] =~ /^[bdrt]$/
# || $field[0] =~ /^[CDRT]$/
) {
$to_strip{$field[1]} = "";
}
elsif ($field[0] ne '?') {
$keep{$field[1]} = "";
}
elsif ($line =~ /\? __ksymtab_/ ||
$line =~ /\? __kstrtab_/) {
$keep{substr($field[1], 10)} = "";
}
elsif ($line =~ /\? __module_parm_/) {
$keep{substr($field[1], 14)} = "";
}
}
close(NMOUT);
$command = "";
$changed = 0;
foreach $symbol (keys(%to_strip)) {
if (!defined($keep{$symbol})) {
$changed = 1;
if (length($command) > $command_size) {
do_command("$strip $command $tmpcopy");
$command = "";
}
$command = "$command --strip-symbol=$symbol";
}
}
if ($command ne "") {
$changed = 1;
do_command("$strip $command $tmpcopy");
}
if ($changed) {
do_command("$mv $tmpcopy $object");
}
}

sub do_command()
{
my ($command) = @_;
my $ret;
if (($ret = system($command)) != 0) {
die("command \"$command\" failed $ret");
}
}
```

## Creating two part executables

```make
# Used for 'make symbol' recipe. Only executables that have been fully linked can be stripped
DEBUG_LIB_SYM = libcryptopp.so.debug
DEBUG_EXE_SYM = cryptest.exe.debug
...

symbol symbols:
	-objcopy --only-keep-debug cryptest.exe $(DEBUG_EXE_SYM)
	-objcopy --only-keep-debug libcryptopp.so $(DEBUG_LIB_SYM)
	-chmod a+r *.debug
	-chmod a-x *.debug
	-strip --strip-debug --strip-unneeded cryptest.exe
	-strip --strip-debug --strip-unneeded libcryptopp.so
	-objcopy --add-gnu-debuglink=$(DEBUG_EXE_SYM) cryptest.exe
	-objcopy --add-gnu-debuglink=$(DEBUG_LIB_SYM) libcryptopp.so
```

Must have the same BuildID[sha1].
