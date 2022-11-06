---
layout: post
title: markdownlint
---

```toml
markdown = "npm exec --yes -- markdownlint-cli README.md CONTRIBUTING.md docs/ --ignore docs/CNAME"
```

```json
"lint": "markdownlint \"src/**/*.md\"",
```

```json
{
    "default": true,
    "MD003": { "style": "atx" },
    "MD007": { "indent": 4 },
    "no-hard-tabs": false
}
```
