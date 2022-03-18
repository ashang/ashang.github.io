---
title: ethernet
date: 2017-07-08
---

## Crossover cable

If your NIC support auto mdi(x), it's not necessary to use crossover.

If not, simple, straight-through cable won't even work.

Best way to check this, is to connect two of these computers with a straight-through cable.

    +---------------------+
    |       Linux         |
    |   .168      .169    |
    +-----+--------+------+
          │        │
    +-----+--------+------+
    |       Switch        |
    +---------+-----------+
              │
    +---------+-----------+
    |         .1          |
    |       Gateway       |
    +---------------------+
