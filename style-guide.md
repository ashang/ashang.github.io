---
layout: page
title: Style - A Page
---

## Quoting

>“Creativity is allowing yourself to make mistakes. Design is knowing which ones to keep.” ― __Scott Adams__

---

### Syntax Highlighter

```css
#header h1 { 
    color: #fff;
    margin-bottom: 1.5em; 
}

.author-avatar {
    border-radius: 5px;
    display: block;
    height: 60px;   
    margin-right: 30px;
    width: 60px;
}
```

```js
// Simple map
var map;
function initMap() {
    map = new google.maps.Map(document.getElementById('map'), {
        center: {lat: -34.397, lng: 150.644},
        zoom: 8
        });
}
```

## Tables

<table>
    <caption>Table Demo</caption>
    <thead>
        <tr>
            <th>Content categories</th>
            <th>Flow content</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Permitted content</td>
            <td>
                In this order:
                <ul>
                    <li>an optional <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/caption"><code>&lt;caption&gt;</code></a> element,</li>
                    <li>zero or more <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/colgroup"><code>&lt;colgroup&gt;</code></a> elements,</li>
                    <li>an optional <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/thead"><code>&lt;thead&gt;</code></a> element,</li>
                    <li>one of the two alternatives:
                        <ul>
                            <li>one <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tfoot"><code>&lt;tfoot&gt;</code></a> element, followed by:
                                <ul>
                                    <li>zero or more <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tbody"><code>&lt;tbody&gt;</code></a> elements,</li>
                                    <li>or one or more <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tr"><code>&lt;tr&gt;</code></a> elements,</li>
                                </ul>
                            </li>
                            <li>a second alternative followed by an optional <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tfoot"><code>&lt;tfoot&gt;</code></a> element:
                                <ul>
                                    <li>either zero or more <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tbody"><code>&lt;tbody&gt;</code></a> elements,</li>
                                    <li>or one or more <a href="https://developer.mozilla.org/en-US/docs/Web/HTML/Element/tr"><code>&lt;tr&gt;</code></a> elements</li>
                                </ul>
                            </li>
                        </ul>
                    </li>
                </ul>
            </td>
        </tr>
        <tr>
            <td>Tag omission</td>
            <td>None, both the <span title="syntax-start-tag">start tag</span> and the <span title="syntax-end-tag">end tag</span> are mandatory</td>
        </tr>
        <tr>
            <td>Permitted parent elements</td>
            <td>Any element that accepts flow content</td>
        </tr>
        <tr>
            <td>Normative document</td>
            <td>HTML5, section 4.9.1 (HTML4.01, section 11.2.1)</td>
        </tr>
    </tbody>
</table>
