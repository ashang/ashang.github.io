


Icdiff

Another useful way of spotting errors and bugs in your code is by running a visual diff between two files. You can use existing command-line utilities available in your distribution, and some text editors also support this feature. Sometimes, though, the information can be somewhat difficult to read, and thus easily discern the differences.

Icdiff offers a color-coded diff functionality, allowing you to easily distinguish between lines or sections of code that have changed, and thus make any tweaks if needed. The usage is pretty straightforward, but you get the clarity and visibility you require. You can customize the look and feel. Icdiff also supports git





terminal side-by-side colorized word diff

Your terminal can display color, but most diff tools don't make good use of it. By highlighting changes, icdiff can show you the differences between similar files without getting in the way. This is especially helpful for identifying and understanding small changes within existing lines.

Instead of trying to be a diff replacement for all circumstances, the goal of icdiff is to be a tool you can reach for to get a better picture of what changed when it's not immediately obvious from diff.

Also includes support for git icdiff (as long as your git config is in ~/.gitconfig or ~/.config/git/config)




vs . vimdiff

 Your terminal can display color, but most diff tools don't make good use of it. By highlighting changes, icdiff can show you the differences between similar files without getting in the way. This is especially helpful for identifying and understanding small changes within existing lines.

 Instead of trying to be a diff replacement for all circumstances, the goal of icdiff is to be a tool you can reach for to get a better picture of what changed when it's not immediately obvious from diff.






 curl -s https://raw.githubusercontent.com/jeffkaufman/icdiff/release-1.9.2/icdiff \
   | sudo tee /usr/local/bin/icdiff > /dev/null \
     && sudo chmod ugo+rx /usr/local/bin/icdiff

     # Or install with pip:
     pip install icdiff

     # Or (ubuntu ≥ 17.10; debian ≥ 9):
     sudo apt-get install icdiff

     # Or (mac only, depends on homebrew):
     brew update && brew install icdiff



     https://github.com/jeffkaufman/icdiff



