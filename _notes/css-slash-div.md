```diff
diff --git i/_sass/foundation-components/_grid.scss w/_sass/foundation-components/_grid.scss
index aa4e77c..eda2dc7 100755
--- i/_sass/foundation-components/_grid.scss
+++ w/_sass/foundation-components/_grid.scss
@@ -29,7 +29,7 @@ $last-child-float: $opposite-direction !default;
 // $colNumber - Found in settings file
 // $totalColumns - Found in settings file
 @function grid-calc($colNumber, $totalColumns) {
-  @return percentage(($colNumber / $totalColumns));
+  @return percentage(calc($colNumber / $totalColumns));
 }
 
 //
@@ -116,8 +116,8 @@ $last-child-float: $opposite-direction !default;
   // Gutter padding whenever a column isn't set to collapse
   // (use $collapse:null to do nothing)
   @else if $collapse == false {
-    padding-left: ($column-gutter / 2);
-    padding-right: ($column-gutter / 2);
+    padding-left: calc($column-gutter / 2);
+    padding-right: calc($column-gutter / 2);
   }
 
   // If a column number is given, calculate width
```


```diff
diff --git i/_sass/foundation-components/_forms.scss w/_sass/foundation-components/_forms.scss
index 80124fd..90545dd 100755
--- i/_sass/foundation-components/_forms.scss
+++ w/_sass/foundation-components/_forms.scss
@@ -84,10 +84,12 @@ $select-hover-bg-color: scale-color($select-bg-color, $lightness: -3%) !default;
 
 // We use this mixin to give us form styles for rows inside of forms
 @mixin form-row-base {
-  .row { margin: 0 ((-$form-spacing) / 2);
-
+  //.row { margin: 0 ((-$form-spacing) / 2);
+  //Deprecation Warning: Using / for division outside of calc() is deprecated and will be removed in Dart Sass 2.0.0.
+  //Recommendation: math.div(-$form-spacing, 2) or calc((-1 * $form-spacing) / 2)
+    .row { margin: 0 calc((-1 * $form-spacing) / 2);
     .column,
-    .columns { padding: 0 ($form-spacing / 2); }
+    .columns { padding: 0 calc($form-spacing / 2); }
 
     // Use this to collapse the margins of a form row
     &.collapse { margin: 0;
@@ -103,7 +105,7 @@ $select-hover-bg-color: scale-color($select-bg-color, $lightness: -3%) !default;
   input.column,
   input.columns,
   textarea.column,
-  textarea.columns { padding-#{$default-float}: ($form-spacing / 2); }
+  textarea.columns { padding-#{$default-float}: calc($form-spacing / 2); }
 }
 
 // @MIXIN
@@ -122,7 +124,7 @@ $select-hover-bg-color: scale-color($select-bg-color, $lightness: -3%) !default;
   display: block;
   font-size: $input-font-size;
   margin: 0 0 $form-spacing 0;
-  padding: $form-spacing / 2;
+  padding: calc($form-spacing / 2);
   height: ($input-font-size + ($form-spacing * 1.5) - rem-calc(1));
   width: 100%;
   @include box-sizing(border-box);
@@ -176,7 +178,7 @@ $select-hover-bg-color: scale-color($select-bg-color, $lightness: -3%) !default;
   }
   @else if $alignment == inline {
     margin: 0 0 $form-spacing 0;
-    padding: $form-spacing / 2 + rem-calc($input-border-width) 0;
+    padding: calc($form-spacing / 2) + rem-calc($input-border-width) 0;
   }
 }
 
@@ -343,7 +345,7 @@ $select-hover-bg-color: scale-color($select-bg-color, $lightness: -3%) !default;
     width: $input-border-width;
     color: $input-border-color;
   }
-  padding: ($form-spacing / 2);
+  padding: calc($form-spacing / 2);
   font-size: $input-font-size;
   font-family: $body-font-family;
   color: $input-font-color;
```
