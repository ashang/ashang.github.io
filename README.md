## Features
- Compatible with GitHub Pages
- Responsive design (looks just as good on mobile)
- Syntax highlighting, with the help of Pygments
- Sticky posts
- [x] Tiny CSS & No Dependency
- [x] Dark/Light Theme
- [x] Custom 404 Page
- [x] Tags Page
- [x] Code Highlighter
- [x] Social Share
- [x] Atom & Json feeds
- [x] Robots.txt
- [x] Sitemap
- [x] Next & Previous Post
- [x] Disqus
- [x] Mathjax Support
- [x] Google Analytics

4. Rename `index.md` to `index.html`. Without this, the `jekyll-paginate` gem will not work.

5. In `about.md`, change the `layout:` field to `post`:

```Markdown
layout: post
```

2. Delete the unnecessary files/folders: `CODE_OF_CONDUCT.md`, `LICENSE`, `README.md`, `tale.gemspec`

3. Delete the `baseurl` line in `_config.yml`:

Comments are disabled by default. To enable them, look for the following line in `_config.yml` and change `jekyll-tale` to your site's Disqus id.

```yml
disqus: jekyll-tale
```

Next, add `comments: true` to the YAML front matter of the posts which you would like to enable comments for.
