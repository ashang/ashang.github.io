Options to optimize your content for search engines.
<!--more-->

- `meta_title:`
- `meta_description:`
- `permalink:`
- `sitemap.xml`
- HTML-Code uses schema.org-meta data

## Optimize Your Articles

`title: Your Post Title` by default for generating the `<title>`. You can overwrite the title with:

```
meta_title:
```

To tailor fit a description

```
meta_description:
```

…otherwise will use the excerpt or the first paragraph of your content.

The last important SEO-setting is the URL. By default uses `permalink: /:categories/:title/` but of course you can change the settings in *_config.yml* or overwrite the URL in front matter with…

```
permalink:
```

## Optimize Your Site

And while we discuss search engine optimization: Submit your site to Google Webmaster Tools/Search Console and Bing and enter the your Google Site Verification ID in *_config.yml*.

```
google_site_verification:
```

And last but not least, submit your *sitemap.xml* to Google Search Console and Bing Webmaster Tools.
