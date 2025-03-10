
if tty -s >/dev/null 2>&1; then
    echo "Interactive SSH session"
else
    echo "Non-interactive SSH session"
exit
fi

if [ -z $SSH_TTY ] && [ -z $PS1 ]; then
    echo "Non-interactive mode"
echo HERE
exit
else
    echo "Interactive mode"
echo there
fi

export PS1="AAA> "

if [ -t 0 ]; then
  echo "jiaohu t 0"
else
  echo "feijiaohu"
  exit
fi

case $- in
    *i*) echo "Interactive ii mode";;
    *) echo "Non-interactive ii mode";;
esac

if [ "$-" != *i* ]; then
    echo "Non-interactive mod iiiie"
else
    echo "Interactiv iiiie mode"
fi
