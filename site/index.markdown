---
author: aaronshang
comments: true
date: 2010-10-18 07:48:03+00:00
layout: page
link: https://aaronshang.wordpress.com/site/
slug: site
title: site
wordpress_id: 35
---

**Notes on starting wordpress site**



	
  * Get WordPress from: [http://wordpress.org/latest.tar.gz](http://wordpress.org/latest.tar.gz) and explode it to** your_target_install_path**



	
  * Create database in MySQL:




<blockquote>

> 
> 
	
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





	
  * $EDITOR wp-config.php according to above MySQL operations.




	
  * Add to apache conf





<blockquote>Alias /weblog/ "/**your_target_install_path**/"

<Directory /your_target_install_path/>

> 
> <blockquote>DirectoryIndex index.php
AllowOverride FileInfo Options</blockquote>
> 
> 
</Directory></blockquote>





	
  * Done. Access URL: [http://localhost/weblog](http://localhost/weblog)


