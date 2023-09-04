



commit c5d494c304e0f8e2a9c85dc67c5cc0d9d1b649b3
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:13:25 2017 +0800

    use this file to start up.

    make docker to start a container.

diff --git a/Makefile b/Makefile
index b9a2b57..32fc396 100644
--- a/Makefile
+++ b/Makefile
@@ -52,7 +52,7 @@ docker_check:
        @which docker > /dev/null || (echo "*** Docker appears to be missing. Please install docker.io in>

 docker: docker_check
-       @docker/tools/onlbuilder -$(VERSION) --isolate --hostname onlbuilder$(VERSION) --pull --autobuild>
+       @docker/tools/onlbuilder -$(VERSION) --isolate --hostname onlbuilder$(VERSION) --pull

 # create an interative docker shell, for debugging builds
 docker-debug: docker_check

commit 358987ca279b896ec281187be6087e6cbcb886f9
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:53:06 2017 +0800

    use pica8 submodules.

diff --git a/setup.env b/setup.env
index 7e6f7f3..bfc3c13 100755
--- a/setup.env
+++ b/setup.env
@@ -34,8 +34,7 @@ $ONL/tools/make-versions.py --import-file=$ONL/tools/onlvi --class-name=OnlVersi
 export BUILDROOTMIRROR=${BUILDROOTMIRROR:-"http://buildroot.opennetlinux.org/dl"}

 # These submodules are required for almost everything.
-$ONL/tools/submodules.py $ONL sm/infra
-$ONL/tools/submodules.py $ONL sm/bigcode
+$ONL/tools/submodules.py $ONL pica8

 # Export the current debian suite
 export ONL_DEBIAN_SUITE=$(lsb_release -c -s)
@@ -46,4 +45,4 @@ if [ ! -f $ONL/.git/hooks/post-merge ] && [ -d $ONL/.git ]; then
 fi

 # submodule post update scripts.
-export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"
\ No newline at end of file
+export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"

commit 9269e66f6663436b8465717940c2d3ccf5b56f66
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:10:43 2017 +0800

    init


 # These submodules are required for almost everything.
-$ONL/tools/submodules.py $ONL sm/infra
-$ONL/tools/submodules.py $ONL sm/bigcode
+$ONL/tools/submodules.py $ONL pica8

 # Export the current debian suite
 export ONL_DEBIAN_SUITE=$(lsb_release -c -s)
@@ -46,4 +45,4 @@ if [ ! -f $ONL/.git/hooks/post-merge ] && [ -d $ONL/.git ]; then
 fi

 # submodule post update scripts.
-export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"
\ No newline at end of file
+export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"

commit 9269e66f6663436b8465717940c2d3ccf5b56f66
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:10:43 2017 +0800

    init

diff --git a/.bashrc b/.bashrc
new file mode 100644
index 0000000..4b10822
--- /dev/null
+++ b/.bashrc
@@ -0,0 +1,23 @@
+############################################################
+#
+# When running the ONL builder in isolation mode
+# $HOME is set to the root of the ONL tree from
+# which you entered the builder.
+#
+# The assumption here is that you are trying to build
+# the tree from which you entered the builder, and
+# thus we automatically source the setup.env file
+# upon starting the shell inside the container.
+#
+############################################################
+
+. setup.env
+
+set -e
+############################################################
commit a1860d89d1d0bd99ae49094190f937eb46da4228 (HEAD -> master, origin/master, origin/HEAD)
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:18:38 2017 +0800

    Use pica source code.

diff --git a/.gitmodules b/.gitmodules
index 1d345d4..6ffb271 100644
--- a/.gitmodules
+++ b/.gitmodules
@@ -1,18 +1,4 @@
-[submodule "packages/base/any/initrds/buildroot/builds/buildroot-mirror"]
-       path = packages/base/any/initrds/buildroot/builds/buildroot-mirror
-       url = git://github.com/opennetworklinux/buildroot-mirror
-[submodule "packages/base/any/kernels/legacy/linux-3.9.6"]
-       path = packages/base/any/kernels/legacy/linux-3.9.6
-       url = git://github.com/opennetworklinux/linux-3.9.6
-[submodule "sm/infra"]
-       path = sm/infra
-       url = git://github.com/floodlight/infra
-[submodule "sm/bigcode"]
-       path = sm/bigcode
-       url = git://github.com/floodlight/bigcode
-[submodule "packages/base/any/kernels/legacy/linux-3.8.13"]
-       url = git://github.com/floodlight/bigcode
-[submodule "packages/base/any/kernels/legacy/linux-3.8.13"]
-       path = packages/base/any/kernels/legacy/linux-3.8.13
-       url = git://github.com/opennetworklinux/linux-3.8.13
-[submodule "packages/platforms-closed"]
-       path = packages/platforms-closed
-       url = git@github.com:opennetworklinux/platforms-closed
+[submodule "pica8"]
+       path = pica8
+       url = git@code:repo/pica8.git
+

commit c5d494c304e0f8e2a9c85dc67c5cc0d9d1b649b3
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:13:25 2017 +0800

    use this file to start up.

    make docker to start a container.

diff --git a/Makefile b/Makefile
index b9a2b57..32fc396 100644
--- a/Makefile
+++ b/Makefile
@@ -52,7 +52,7 @@ docker_check:
        @which docker > /dev/null || (echo "*** Docker appears to be missing. Please install docker.io in>

 docker: docker_check
-       @docker/tools/onlbuilder -$(VERSION) --isolate --hostname onlbuilder$(VERSION) --pull --autobuild>
+       @docker/tools/onlbuilder -$(VERSION) --isolate --hostname onlbuilder$(VERSION) --pull

 # create an interative docker shell, for debugging builds
 docker-debug: docker_check

commit 358987ca279b896ec281187be6087e6cbcb886f9
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:53:06 2017 +0800

    use pica8 submodules.

diff --git a/setup.env b/setup.env
index 7e6f7f3..bfc3c13 100755
--- a/setup.env
+++ b/setup.env
@@ -34,8 +34,7 @@ $ONL/tools/make-versions.py --import-file=$ONL/tools/onlvi --class-name=OnlVersi
 export BUILDROOTMIRROR=${BUILDROOTMIRROR:-"http://buildroot.opennetlinux.org/dl"}

 # These submodules are required for almost everything.
-$ONL/tools/submodules.py $ONL sm/infra
-$ONL/tools/submodules.py $ONL sm/bigcode
+$ONL/tools/submodules.py $ONL pica8

 # Export the current debian suite
 export ONL_DEBIAN_SUITE=$(lsb_release -c -s)
@@ -46,4 +45,4 @@ if [ ! -f $ONL/.git/hooks/post-merge ] && [ -d $ONL/.git ]; then
 fi

 # submodule post update scripts.
-export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"
\ No newline at end of file
+export ONL_SUBMODULE_UPDATED_SCRIPTS="$ONL/tools/scripts/submodule-updated.sh"

commit 9269e66f6663436b8465717940c2d3ccf5b56f66
Author: Richard Zhang <richard.zhang@pica8.com>
Date:   Thu Sep 28 17:10:43 2017 +0800

    init

diff --git a/.bashrc b/.bashrc
new file mode 100644
index 0000000..4b10822
--- /dev/null
+++ b/.bashrc
@@ -0,0 +1,23 @@
+############################################################
+#
+# When running the ONL builder in isolation mode
+# $HOME is set to the root of the ONL tree from
+# which you entered the builder.
+#
+# The assumption here is that you are trying to build
+# the tree from which you entered the builder, and
+# thus we automatically source the setup.env file
+# upon starting the shell inside the container.
+#
+############################################################
+
+. setup.env
+
@@ -0,0 +1,23 @@
+############################################################
+#
+# When running the ONL builder in isolation mode
+# $HOME is set to the root of the ONL tree from
+# which you entered the builder.
+#
+# The assumption here is that you are trying to build
+# the tree from which you entered the builder, and
+# thus we automatically source the setup.env file
+# upon starting the shell inside the container.
+#
+############################################################
+
+. setup.env
+
+set -e
+
+if [ -n "$ONL_AUTOBUILD" ]; then
+    make all
+    exit 0
+else
+    echo Ready to build OpenNetworkLinux.
+fi
diff --git a/.gitignore b/.gitignore
new file mode 100644
:


