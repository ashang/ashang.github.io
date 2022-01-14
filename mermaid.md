---
date: 2020-09-23
title: mermaid
---

https://github.com/github/roadmap/issues/372

```mermaid
graph TD;
    A-->B;
    A-->C;
    B-->D;
    C-->D;
```

Text can be used to create rich diagrams:

```mermaid
sequenceDiagram
    autonumber
    Alice->>John: Hello John, how are you?
    loop Healthcheck
        John->>John: Fight against hypochondria
    end
    Note right of John: Rational thoughts!
    John-->>Alice: Great!
    John->>Bob: How about you?
    Bob-->>John: Jolly good!
```
