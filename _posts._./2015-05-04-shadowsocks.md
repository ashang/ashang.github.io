

服务器端

/etc/apt/sources.list目录下添加shadowsocks.list,文件内容如下：

    deb http://shadowsocks.org/debian wheezy main

    wget -O- http://shadowsocks.org/debian/1D27208A.gpg | sudo apt-key add -

    sudo apt-get update
    sudo apt-get install shadowsocks-libev

    /etc/shadowsocks-libev/config.json

    {
        "server":"your_server_ip",
        "server_port":8388,
        "local_port":1080,
        "password":"barfoo!",
        "timeout":60,
        "method":"aes-256-cfb"
    }

填上服务器密码,修改一下访问密码,加密方法选择高强度加密方法aes-256-cfb,最后重新启动shadowsocks-libev即可．


    sudo service shadowsocks-libev restart

客户端

    sudo apt-get install shadowsocks

/etc/shadowsocks-libev/config.json

    {
        "server":"my_server_ip",
        "server_port":8388,
        "local_address": "127.0.0.1",
        "local_port":1080,
        "password":"mypassword",
        "timeout":300,
        "method":"aes-256-cfb",
        "fast_open": false,
        "workers": 1
    }

修改与服务器相关的item
默认安装的shadowsocks是用于启动服务器的,因此修改一下/etc/init.d/shadowsocks使其用于运行客户端daemon程序

    #DAEMON=/usr/bin/ssserver     # Introduce the server's location here
    DAEMON=/usr/bin/sslocal     # Introduce the cilent's location here

保存后重新启动shadowsocks

    sudo service shadowsocks restart

客户端软件访问本地端口127.0.0.1:1080即可．
