
安全性和权限管理，建议创建一个专用的rsync用户和组：

bash复制

```bash
sudo useradd -g rsync -M -s /bin/nologin rsync
```

这将创建一个名为`rsync`的用户，属于`rsync`组，且该用户无法登录系统

。

### 3. **创建共享目录**

创建一个用于存储传输文件的目录，并将其属主设置为rsync用户和组：

bash复制

```bash
sudo mkdir /backup
sudo chown -R rsync:rsync /backup
```

### 4. **配置rsync守护进程**

编辑rsync的配置文件`/etc/rsyncd.conf`，添加以下内容：

ini复制

```ini
# rsyncd.conf
uid = rsync
gid = rsync
use chroot = no
max connections = 20
pid file = /var/run/rsyncd.pid
lock file = /var/run/rsyncd.lock
log file = /var/log/rsyncd.log

[backup]
path = /backup
read only = no
auth users = rsync_user
secrets file = /etc/rsync.password
```

- `uid`和`gid`：指定rsync服务运行时的用户和组。
    
- `use chroot = no`：允许访问共享目录之外的文件（如果需要更严格的安全性，可以设置为`yes`）。
    
- `[backup]`：定义一个模块名称，客户端可以通过该名称访问共享目录。
    
- `auth users`：指定允许访问的用户。
    
- `secrets file`：指定密码文件的位置
    

- 。
    

### 5. **创建密码文件**

在服务器上创建密码文件`/etc/rsync.password`，并设置权限：

bash复制

```bash
echo "rsync_user:password" | sudo tee /etc/rsync.password
sudo chmod 600 /etc/rsync.password
```

- `rsync_user`：与`auth users`中定义的用户一致。
    
- `password`：为该用户设置的密码
    

- 。
    

### 6. **启动rsync守护进程**

启动rsync服务：

bash复制

```bash
sudo rsync --daemon
```

如果需要在系统启动时自动运行rsync守护进程，可以将上述命令添加到`/etc/rc.local`文件中

。

### 7. **防火墙配置**

确保防火墙允许rsync的默认端口（873）通信：

- **使用`ufw`（适用于Ubuntu）**：
    
    bash复制
    
    ```bash
    sudo ufw allow 873
    ```
    
- **使用`firewalld`（适用于CentOS等）**：
    
    bash复制
    
    ```bash
    sudo firewall-cmd --permanent --add-port=873/tcp
    sudo firewall-cmd --reload
    ```
    

### 8. **客户端配置**

在客户端，可以通过以下命令连接到服务器并传输文件：

bash复制

```bash
rsync -avz /path/to/source rsync_user@server_ip::backup/ --password-file=/path/to/rsync.password
```

- `/path/to/source`：要传输的文件或目录。
    
- `rsync_user`：服务器上配置的用户。
    
- `server_ip`：服务器的IP地址。
    
- `backup`：服务器上配置的模块名称。
    
- `--password-file`：指定客户端的密码文件
    

- 。
    

### 9. **测试连接**

在客户端运行以下命令，确保可以成功连接并传输文件：

bash复制

```bash
rsync -avz rsync_user@server_ip::backup/ /path/to/destination
```

如果一切配置正确，文件将从服务器传输到客户端的指定目录。

通过以上步骤，你可以在不使用SSH服务的情况下，成功启动rsync服务并实现远程文件传输。

