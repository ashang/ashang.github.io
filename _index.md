---
title: "casa ! :tada:"
description: "This is a demo of the Congo theme for Hugo."
---

a powerful, lightweight theme for Hugo built with Tailwind CSS.

[theme documentation]({{< ref "docs" >}}). Congo is flexible and is great for both static page-based content (like this demo) or a traditional blog with a feed of recent posts.

<div class="flex px-4 py-2 mb-8 text-base rounded-md bg-primary-100 dark:bg-primary-900">
  <span class="flex items-center pe-3 text-primary-400">
    {{< icon "triangle-exclamation" >}}
  </span>
  <span class="flex items-center justify-between grow dark:text-neutral-300">
    <span class="prose dark:prose-invert">This is a demo of the <code id="layout">page</code> layout.</span>
    <button
      id="switch-layout-button"
      class="px-4 !text-neutral !no-underline rounded-md bg-primary-600 hover:!bg-primary-500 dark:bg-primary-800 dark:hover:!bg-primary-700"
    >
      Switch layout &orarr;
    </button>
  </span>
</div>

{< figure src="festivities.svg" class="m-auto mt-6 max-w-prose" >}}

```
{{ ticks %}}
* Screen reader and keyboard accessible
* Responsive
* Numerous shortcodes
* Toggleable dark theme
* Toggleable table of contents per blog post
* 一大大问题是引号扩为空格？全角？
{{ /ticks %}}
```

```
<div class="ticks">
  {{ .Inner | markdownify }}
</div>
```
