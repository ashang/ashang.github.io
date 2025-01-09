
# bash chromeos-install.sh -src ChromeOS_recovery.img -dst /mnt/chromeos.img -s 32

# bash chromeos-install.sh -src ChromeOS_recovery.img -dst /dev/sdb

    options=acpi_power_button,sysfs_tablet_mode
        第一个框架选项让按下电源键弹出关机菜单
        第二个框架选项允许通过控制系统文件系统来切换平板模式（翻折YOGA暂不能激活平板模式）
    enforce_hyperthreading=1
        启用英特尔超线程（最近的安全漏洞使得Chrome OS默认禁用了超线程），更好的性能（可能有安全隐患）
    psmouse.synaptics_intertouch=1
        Synaptic触控板多指手势控制

使用Brunch框架运行的Chrome OS更新也需要对Brunch框架进行更新（理论上来说，你也可以仅更新Chrome OS而不更新Brunch框架，但是可能会出现一些兼容性问题）。更新不会清除原本的个人数据，但并不能简单地透过内建的OTA实现“空中更新”，手动倒也不难。和安装类似，需要下载新版本的Brunch框架和恢复镜像，解压缩恢复镜像zip文件（提取.bin出来），然后打开Crosh终端（浏览器按下Ctrl + Alt + T，然后键入shell回车）：

cd ~/Downloads
# 恢复镜像和Brunch框架压缩包文件名可能不同，仅作示范
# chromeos-update -r chromeos_13505.63.0_rammus_recovery_stable-channel_mp-v2.bin -f brunch_r87_stable_20201216.tar.gz

稍等片刻，提示完成后关闭选项卡并重启电脑，新版本便升级完成！

