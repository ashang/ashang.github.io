The line terminator expected for each file format is:

- unix
  - LF only (each line ends with an LF character)
  - Unix based systems and Mac OS X and later.
- dos
  - CRLF (each line ends with CR then LF)
  - DOS and Windows.
- mac
  - CR only (each line ends with a CR character)
  - Mac OS version 9 and earlier

- CR is carriage return (return cursor to left margin), which is Ctrl-M or ^M or hex 0D.
  - In bash, default is `emacs` mode, so a `Ctrl-M` would be CR, to run the command line input.

- LF is linefeed (move cursor down), which is Ctrl-J or ^J or hex 0A. Sometimes, LF is written as NL (newline).
  - In Vim, `Shift-J` would join the next line to end of current line.


The 'fileformat' option is local to each buffer. It is set by Vim when a file is read, or can be specified in a command telling Vim how to read a file. In addition, the 'fileformat' option can be changed to specify the line endings that will be added to each line when the buffer is written to a file.

The 'fileformats' option is global and specifies which file formats will be tried when Vim reads a file (unless otherwise specified, Vim attempts to automatically detect which file format should be used to read a file). The first file format in 'fileformats' is also used as the default for a new buffer.

The following command displays the fileformat option (abbreviated as ff) for the current buffer, and the  fileformats global option (abbreviated as ffs) which determines how Vim reads and writes files: 

```
:help 'ff'
```

```
:help 'ffs'
```

```
:set ff? ffs?
```

Vim has a built-in preference for the unix format.

If all lines in the file end with CRLF, the dos file format will be applied, meaning that each CRLF is removed when reading the lines into a buffer, and the buffer 'ff' option will be dos.
If one or more lines end with LF only, the unix file format will be applied, meaning that each LF is removed (but each CR will be present in the buffer, and will display as ^M), and the buffer 'ff' option will be unix.

## To remove CR
- `strings A>B`
- TR
  - `tr -d "\r" <src >dest`
  - `tr -d "\015" dest`
  - `cat filename | tr -d "^V^M" >newfile`
- SED
  - `sed -e "s/^V^M//" filename`
- VIM
  - `:%s/^M$//g`
- dos2unix YOUR_FILE_NAMES
