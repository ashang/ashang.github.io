```
#!/bin/sh
killall -qw yandex-disk
exit 0
```

```
#!/bin/sh

set -e

if [ "$1" != "purge" ]
then
    exit 0
fi

if [ -e "/etc/apt/sources.list.d/yandex-disk.list" ]
then

    APT_KEY="`which apt-key 2> /dev/null`"
    if [ -x "$APT_KEY" ]
    then
        # don't fail if the key wasn't found
        "$APT_KEY" rm 7C90E5AF >/dev/null 2>&1 || true
    fi

    rm -f "/etc/apt/sources.list.d/yandex-disk.list"
fi

exit 0
```

```
#!/bin/sh

case "$1" in
    configure)
    EXT_REPOURL="http://repo.yandex.ru/yandex-disk" # URL of the external repository
    INT_REPOURL="http://dist.yandex.ru/repo.yandex.ru/yandex-disk" # URL of the internal repository
    REPOLIST_PATH="/etc/apt/sources.list.d/yandex-disk.list"

    TIMEOUT=4
    GPG_FILE="YANDEX-DISK-KEY.GPG"
	KEY_FILE="`mktemp -t $GPG_FILE.XXXX`"
    WGET="`which wget 2>/dev/null`"
    CURL="`which curl 2>/dev/null`"
    REPOURL=$EXT_REPOURL # Value of this var will be added to the list of repos

	if [ -n "$WGET" ]
	then
    	echo Using $WGET
    	$WGET -q --timeout=$TIMEOUT --tries=1 -O $KEY_FILE "$INT_REPOURL/$GPG_FILE"
    	if [ "$?" = "0" ]
    	then    #internal
        	INTERNAL="true"
		else
    		$WGET -q --timeout=$TIMEOUT -O $KEY_FILE "$EXT_REPOURL/$GPG_FILE"
    	fi
	else
    	if [ -n "$CURL" ]
    	then
        	echo Using $CURL
        	$CURL -s -f --connect-timeout $TIMEOUT -o $KEY_FILE "$INT_REPOURL/$GPG_FILE"
        	if [ "$?" = "0" ]
        	then    #internal
            	INTERNAL="true"
			else
        		$CURL -s -f --connect-timeout $TIMEOUT -o $KEY_FILE "$EXT_REPOURL/$GPG_FILE"
        	fi
    	else
        	echo Configuring repository...
    	fi
	fi

	if [ "$INTERNAL" = "true" ]
	then
		REPOURL=$INT_REPOURL
	fi

	if [ -f $KEY_FILE ]
	then
        apt-key add $KEY_FILE >> /dev/null
		rm -f $KEY_FILE >> /dev/null 2>/dev/null
	fi

	if [ -n "$REPOURL" ]
	then
        GREPOUTPUT=$(grep -H -i "$REPOURL" $REPOLIST_PATH 2>/dev/null)
        if [ -z "$GREPOUTPUT" ]
        then # Add repo to the list
        	echo "deb $REPOURL/deb/ stable main" >> $REPOLIST_PATH
        fi

	fi
    ;;
esac

exit 0
```
