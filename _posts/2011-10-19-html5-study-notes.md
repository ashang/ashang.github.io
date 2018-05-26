---
author: aaronshang
comments: true
date: 2011-10-19 08:08:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2011/10/19/html5-study-notes/
slug: html5-study-notes
title: HTML5 study notes
wordpress_id: 1040
---

  
HTML5 learning notes  


 

HTML5 ~= HTML + CSS + JS  
  
[http://slides.html5rocks.com](http://slides.html5rocks.com/)

 

  


[HTML5 Presentation](http://slides.html5rocks.com/)

  


 

 

Web Storage   
  
// use localStorage for persistent storage  
// use sessionStorage for per tab storage

 

 

 

Web SQL Database  
  
var db = window.openDatabase("DBName", "1.0", "description", 5*1024*1024); //5MB  
db.transaction(function(tx) {  
 tx.executeSql("SELECT * FROM test", [], successCallback, errorCallback);  
});

 

 

 

IndexedDB

  


wss://[html5rocks.websocket.org/echo](http://html5rocks.websocket.org/echo)  
Error:Your browser does not have native support for WebSocket  
  
Build identifier: Mozilla/5.0 (X11; Linux x86_64; rv:6.0.2) Gecko/20100101 Firefox/6.0.2  
  
about:buildconfig

 

 

 

File / Hardware Access Deeper integration with the Operating System  
  
Native Drag & Drop   
Desktop Drag-In (File API) / Drag-Out   
Asynchronously write a file to a sandboxed file system using JavaScript  
Geolocation  
Device Orientation

 

 

Semantics & Markup  
More meaningful elements  
Markup for applications   
working...  
3/4 complete  
Microdata  
New form types   
  
Form field types on mobile  -- Input / Keyboard sensitive

 

 

 

Graphics / Multimedia 2D & 3D  
Audio + Video   
Canvas 2D   
Canvas 3D (WebGL)   
Inline SVG   
  
   <circle   
       fill="url(#myGradient)"  
       onmousedown="alert('hello');"/>  
 

 

 

 

CSS3 Presentation & Styling  
CSS Selectors:  
.row:nth-child(even) {  
 background: #dde;  
}  
  
Webfonts  
@font-face{  
 font-family: 'LeagueGothic';  
 src: url(LeagueGothic.otf);  
}  
  
@font-face{  
 font-family: 'Droid Sans';  
 src: url(Droid_Sans.ttf);  
}  
  
Text wrapping   
Text stroke  
Columns  
Opacity  
Transitions  
Animations  
~~~ ...
