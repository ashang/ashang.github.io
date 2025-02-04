
    U-Boot 的 uImage 由一个 header 和一个或多个数据部分组成，每个部分可能是：
        Linux 内核 (zImage)
        initrd（RAM 磁盘）
        设备树（FDT，Flattened Device Tree）
    多内核、多 RAM 磁盘和多个设备树的 uImage 可能会使用 multi-image 或 FIT (Flattened Image Tree) 结构。

构建方式

    Multi-Image (mkimage -T multi)
        传统方式，将多个二进制文件（内核、RAM 磁盘、设备树等）拼接，并生成一个 uImage，但 U-Boot 解析时需要手动指定索引。
    FIT (Flattened Image Tree) (mkimage -T fit)
        现代方式，支持多内核、多设备树等，并可通过 U-Boot 变量动态选择合适的部分。

加载流程

    U-Boot 读取 uImage，检查 header 确保格式正确。
    根据配置（通常由 bootcmd 或 bootargs 控制），选择合适的内核、RAM 磁盘和设备树。
    将选定的内核、initrd 和 FDT 加载到 RAM，并跳转到内核入口点执行。

查看 uImage 详情

使用 mkimage 工具：

mkimage -l uImage

或者，如果是 FIT 格式：

dumpimage -l uImage


## FIT 描述文件

创建 fit.its（Device Tree Source 格式）：

/dts-v1/;

/ {
    description = "FIT Image with multiple kernels";
    #address-cells = <1>;

    images {
        kernel-1 {
            description = "Linux Kernel 1";
            data = /incbin/("zImage1");
            type = "kernel";
            arch = "arm";
            os = "linux";
            compression = "none";
            load = <0x82000000>;
            entry = <0x82000000>;
        };

        kernel-2 {
            description = "Linux Kernel 2";
            data = /incbin/("zImage2");
            type = "kernel";
            arch = "arm";
            os = "linux";
            compression = "none";
            load = <0x82100000>;
            entry = <0x82100000>;
        };

        fdt-1 {
            description = "Device Tree Blob 1";
            data = /incbin/("dtb1.dtb");
            type = "flat_dt";
            arch = "arm";
            compression = "none";
        };

        fdt-2 {
            description = "Device Tree Blob 2";
            data = /incbin/("dtb2.dtb");
            type = "flat_dt";
            arch = "arm";
            compression = "none";
        };
    };

    configurations {
        default = "config-1";

        config-1 {
            description = "Config for Kernel 1";
            kernel = "kernel-1";
            fdt = "fdt-1";
        };

        config-2 {
            description = "Config for Kernel 2";
            kernel = "kernel-2";
            fdt = "fdt-2";
        };
    };
};

2.2 生成 FIT 镜像

mkimage -f fit.its uImage.fit

2.3 U-Boot 加载 FIT Image

U-Boot 可以自动解析 FIT 结构：

setenv loadaddr 0x82000000
fatload mmc 0:1 ${loadaddr} uImage.fit

# 直接启动默认配置
bootm ${loadaddr}

# 或手动选择配置
bootm ${loadaddr}#config-2

##
mkimage -A arm -O linux -T multi -C none -n "Multi-Image Test" \
    -d zImage:initrd.img:dtb.dtb uImage.multi

1.2 U-Boot 加载 Multi-Image

U-Boot 不能直接解析 multi-image 的各个部分，必须手动加载：

setenv loadaddr 0x82000000   # 内核加载地址
setenv initrd_addr 0x83000000  # RAM 磁盘地址
setenv fdt_addr 0x84000000  # 设备树地址

# 读取 Multi-Image 到内存
fatload mmc 0:1 ${loadaddr} uImage.multi

# 提取各部分
imxtract ${loadaddr} 0 ${loadaddr}
imxtract ${loadaddr} 1 ${initrd_addr}
imxtract ${loadaddr} 2 ${fdt_addr}

# 启动 Linux
bootz ${loadaddr} ${initrd_addr} ${fdt_addr}

U-Boot 的 imxtract 命令用于提取 multi-image 的不同部分。





$ svn diff Makefile
Index: Makefile
===================================================================
--- Makefile    (revision 2839)
+++ Makefile    (working copy)
@@ -54,11 +54,11 @@
      @# umount /dev/loop0

      cp -af ${TOP_DIR}/../pica_bin/* ${TOP_DIR}/rootfs/pica/
-    -find ${TOP_DIR}/rootfs/pica/ -type f -executable -exec    
$(CROSS_COMPILE)strip {} \;
+ *@-find* ${TOP_DIR}/rootfs/pica/ -type f -executable -exec    
$(CROSS_COMPILE)strip {} \;
      cp -af rootfs/* ram_disk/
      @# This follows
      cp -af ${RAMDISK_DIR}/_install/* ram_disk/
-    -find ram_disk/ -name .svn  -exec rm -fr {} \;
+ *@-find* ram_disk/ *-ignore_readdir_race -nowarn* -name .svn  -exec rm 
-fr {} \;
      umount ram_disk
      gzip -f -9 initrd2m
      mkimage -A ppc -O linux -T ramdisk -C gzip -a 00000000 -e 00000000 
-d initrd2m.gz uInitrd2m



On 06/04/2010 05:43 PM, build@pica8.local wrote:
> All,
>
>   lb9a image making error.
>
> ####################################################
> # Screen capture as follow
> ####################################################
> a/
> find /lb9a/rootfs/pica/ -type f -executable -exec 
> ppc_85xx-strip {} \;
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_log.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_connection-limit_default.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/syslog_file_filename.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/rollback.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_version.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/bootmsg.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/clear_log.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_arp.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_system_connections.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/clear_arp.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/file_compare.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_root-login_allow.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/syslog_host.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_host_ip.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_protocol-version_v2.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_root-login_deny-passwd.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_protocol-version_v1.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/telnet_disable.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_task.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_protocol-version.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_root-login.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/file_show.sh: File format 
> not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/boot_image.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_root-login_deny.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_rate-limit.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/clear_system_reboot.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/cli_idle-timeout.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_system_reboot.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/telnet_connection-limit.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/ssh_connection-limit.sh: 
> File format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/show_system_core-dumps.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/bin/shell/source_address.sh: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/etc/templates/rib_pica.cmds: File 
> format not recognized
> ppc_85xx-strip: 
> /lb9a/rootfs/pica/etc/templates/xorp_policy.cmds: 
> File format not recognized
> ppc_85xx-strip: /lb9a/rootfs/pica/.svn/format: File 
> format not recognized
> ppc_85xx-strip: /lb9a/rootfs/pica/.svn/entries: File 
> format not recognized
> cp -af rootfs/* ram_disk/
> cp -af /lb9a/busybox-1.13.3/_install/* ram_disk/
> find ram_disk/ -name .svn -exec rm -fr {} \;
> find: `ram_disk/cf_card/.svn': No such file or directory
> find: `ram_disk/etc/dropbear/.svn': No such file or directory
> find: `ram_disk/etc/ssh/.svn': No such file or directory
> find: `ram_disk/etc/.svn': No such file or directory
> find: `ram_disk/lib/modules/.svn': No such file or directory
> find: `ram_disk/lib/.svn': No such file or directory
> find: `ram_disk/mnt/.svn': No such file or directory
> find: `ram_disk/opt/.svn': No such file or directory
> find: `ram_disk/pica/.svn': No such file or directory
> find: `ram_disk/proc/.svn': No such file or directory
> find: `ram_disk/sbin/.svn': No such file or directory
> find: `ram_disk/tmp/.svn': No such file or directory
> find: `ram_disk/usr/sbin/.svn': No such file or directory
> find: `ram_disk/usr/bin/.svn': No such file or directory
> find: `ram_disk/usr/share/.svn': No such file or directory
> find: `ram_disk/usr/share/udhcpc/.svn': No such file or directory
> find: `ram_disk/usr/.svn': No such file or directory
> find: `ram_disk/var/spool/.svn': No such file or directory
> find: `ram_disk/var/spool/cron/crontabs/.svn': No such file or directory
> find: `ram_disk/var/spool/cron/.svn': No such file or directory
> find: `ram_disk/var/log/.svn': No such file or directory
> find: `ram_disk/var/.svn': No such file or directory
> find: `ram_disk/var/empty/.svn': No such file or directory
> find: `ram_disk/var/run/.svn': No such file or directory
> make: [RAMDISK] Error


较新的内核都使用一个初始ramdisk来建立内核环境。当你重装一个内核，就需要用mkinitcpio重新生成这个初始ramdisk。mkinitcpio的一个特性就是它可以自动检测启动你的计算机需要哪些内核模块。要使自动检测可以正常运行，/dev、/sys和/proc都需要挂载到你的chroot里：
# mount -t proc none /mnt/proc
# mount -t sysfs none /mnt/sys
# mount --bind /dev /mnt/dev
现在，我们将chroot到这个磁盘中，这样你就可以象“正常启动计算机之后”一样用它。当然，很多事还是做不了的。
# chroot /mnt



## FIT

/dts-v1/;
/ {
    description = "Multi-Component FIT Image";
    #address-cells = <1>;

    images {
        kernel@1 {
            description = "Linux Kernel";
            data = /incbin/("zImage");
            type = "kernel";
            arch = "arm";
            os = "linux";
            compression = "none";
            load = <0x80008000>;
            entry = <0x80008000>;
        };

        fdt@1 {
            description = "Device Tree";
            data = /incbin/("board.dtb");
            type = "flat_dt";
            arch = "arm";
            compression = "none";
        };

        ramdisk@1 {
            description = "Initramfs";
            data = /incbin/("initramfs.cpio.gz");
            type = "ramdisk";
            arch = "arm";
            compression = "gzip";
        };
    };

    configurations {
        default = "config@1";
        config@1 {
            description = "Standard Boot";
            kernel = "kernel@1";
            fdt = "fdt@1";
            ramdisk = "ramdisk@1";
        };
    };
};

生成 FIT 镜像
bash
复制

mkimage -f image.its image.fit

# 从存储设备（如MMC）加载 FIT 镜像到内存地址 0x82000000
load mmc 0:1 0x82000000 image.fit

bootm 0x82000000#list
# 输出示例: config@1, config@2

# 选择默认配置启动
bootm 0x82000000

# 或明确指定配置
bootm 0x82000000#config@2

U-Boot 内部处理步骤

    解析 FIT 结构：U-Boot 读取 FIT 文件的设备树结构，识别镜像内的组件。

    加载组件到内存：根据配置中的 load 地址，将内核、ramdisk 和 FDT 复制到指定内存位置。

    传递启动参数：将 FDT 地址通过 bootargs 传递给内核。

    跳转到内核入口点：执行内核代码，完成启动。

应用场景

    多硬件支持：单 FIT 镜像适配不同板卡（通过不同 FDT 选择）。

    多系统配置：例如正常模式、恢复模式（不同内核或 ramdisk）。

    A/B 更新：双分区启动时切换不同内核版本。

## 传统 Multi-Component 方式（非 FIT）

# 从 MMC 加载内核到内存
load mmc 0:1 0x82000000 zImage

# 加载设备树文件
load mmc 0:1 0x83000000 board.dtb

# 加载 initramfs
load mmc 0:1 0x84000000 initramfs.cpio.gz

# 设置 bootargs（传递设备树地址和根文件系统参数）
setenv bootargs console=ttyS0,115200 root=/dev/ram0 rw

# 启动内核（bootz 用于 zImage，bootm 用于 uImage）
bootz 0x82000000 0x84000000:0x85000000 0x83000000

    bootz <kernel_addr> <initrd_start>:<initrd_end> <fdt_addr>

        kernel_addr：内核镜像的内存地址。

        initrd_start:initrd_end：ramdisk 的起始和结束地址（需计算大小）。

        fdt_addr：设备树的内存地址。

##  FIT 方式

FIT 将所有组件（内核、设备树、ramdisk）打包到单个镜像中，通过配置选择启动参数。需要提前生成 .fit 镜像（参考前文 .its 文件）。
示例步骤：

假设已生成 FIT 镜像 image.fit，存储在 MMC 设备的第一个分区：
bash
复制

# 加载 FIT 镜像到内存（例如地址 0x82000000）
load mmc 0:1 0x82000000 image.fit

# （可选）查看可用配置
bootm 0x82000000#list
# 输出示例: config@1, config@2

# 启动默认配置
bootm 0x82000000

# 或指定配置名（例如 config@2）
bootm 0x82000000#config@2

U-Boot 内部行为：

    解析 FIT 镜像：根据配置选择对应的内核、设备树和 ramdisk。

    自动加载组件：将内核、设备树和 ramdisk 复制到预定义的内存地址。

    传递参数并启动：自动设置 bootargs（如果配置中定义了参数），并跳转到内核入口点。

bootm 0x82000000#board_v2_config


恢复模式与正常模式

    传统方式：需加载不同内核和 ramdisk。
    bash
    复制

    load mmc 0:1 0x82000000 recovery_zImage
    load mmc 0:1 0x84000000 recovery_initrd
    bootz 0x82000000 0x84000000:0x85000000 0x83000000

    FIT 方式：直接切换配置。
    bash
    复制

    bootm 0x82000000#recovery_config



