
     * When we use system() to run a command, it's equivalent to '/bin/sh -c xxx'.
     * This will first fork() and then execxx() a command as a subprocess.
     * The subproccess will inherit all the file descriptor(include sockets).
     * So if here we start ovsdb-server as a daemon, it will inherit all the
     * connections to finders(also to other modules). When nsx-integration shutting
     * down but ovsdb-server still running(because of xovs), the connections to
     * finders will not close. This will cause nsx-integration exit abnormally.
     *
     * The solution is close-on-exec flag.
     * http://stackoverflow.com/questions/1643304/how-to-set-close-on-exec-by-default
