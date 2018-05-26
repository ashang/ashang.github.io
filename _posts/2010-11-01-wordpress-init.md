---
author: aaronshang
comments: true
date: 2010-11-01 02:47:17+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/11/01/wordpress-init/
slug: wordpress-init
title: WordPress init
wordpress_id: 47
---

Notes on starting WordPress



	
  * Get WordPress from: [http://wordpress.org/latest.tar.gz](http://wordpress.org/latest.tar.gz) and explode it to** your_target_install_path**



	
  * Create database in MySQL:





<blockquote>
	
>   * $ mysql -u root -p
> 
	
>   * mysql> create database database_name;
> 
	
>   * mysql> grant all on database_name.* to database_user@localhost identified by 'password_for_this_user';
> 
	
>   * mysql> flush privileges;
> 
	
>   * mysql> exit
> 
</blockquote>




	
  * $ $EDITOR wp-config.php according to above MySQL operations.



	
  * Add to apache conf



<blockquote>Alias /weblog/ "/**your_target_install_path**/"

<Directory /your_target_install_path/>


> 
> <blockquote>DirectoryIndex index.php
AllowOverride FileInfo Options</blockquote>
> 
> 
</Directory></blockquote>




	
  * Done. Access URL: [http://your.domain/weblog](http://your.domain/weblog)


