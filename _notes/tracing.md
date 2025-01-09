---
date: 2020-09-23
title: tracing
---


https://opentracing.io/

https://peter.bourgon.org/ok-log/

OpenTracing 于 2016 年 10 月加入 CNCF 基金会，是继 Kubernetes 和 Prometheus 之后，第三个加入 CNCF 的开源项目。它是一个中立的（厂商无关、平台无关）分布式追踪的 API 规范，提供统一接口，可方便开发者在自己的服务中集成一种或多种分布式追踪的实现。本文讲一讲 OpenTracing 的来龙去脉，以及在容器化和微服务盛行的今天，为什么分布式追踪显得格外有用。


Logging 和 Metrics。

Logging：用于记录离散的事件，包含程序执行到某一点或某一阶段的详细信息。
Metrics：可聚合的数据，且通常是固定类型的时序数据，包括 Counter、Gauge、Histogram 等。
Tracing：记录单个请求的处理流程，其中包括服务调用和处理时长等信息。
同时这三种定义相交的情况也比较常见。

Logging & Metrics：可聚合的事件。例如分析某对象存储的 Nginx 日志，统计某段时间内 GET、PUT、DELETE、OPTIONS 操作的总数。
Metrics & Tracing：单个请求中的可计量数据。例如 SQL 执行总时长、gRPC 调用总次数。
Tracing & Logging：请求阶段的标签数据。例如在 Tracing 的信息中标记详细的错误原因。
针对每种分析需求，我们都有非常强大的集中式分析工具。

Logging：ELK，近几年势头最猛的日志分析服务，无须多言。
Metrics：Prometheus，第二个加入 CNCF 的开源项目，非常好用。
Tracing：OpenTracing 和 Jaeger，Jaeger 是 Uber 开源的一个兼容 OpenTracing 标准的分布式追踪服务。目前 Jaeger 也加入了 CNCF。



分布式追踪系统大体分为三个部分，数据采集、数据持久化、数据展示。数据采集是指在代码中埋点，设置请求中要上报的阶段，以及设置当前记录的阶段隶属于哪个上级阶段。数据持久化则是指将上报的数据落盘存储，例如 Jaeger 就支持多种存储后端，可选用 Cassandra 或者 Elasticsearch。数据展示则是前端根据 Trace ID 查询与之关联的请求阶段，并在界面上呈现。

## Jaeger

https://pjw.io/articles/2018/05/18/jaeger-tutorial/

https://eng.uber.com/distributed-tracing/

## 非入侵的方式

除了通过修改应用程序代码增加分布式追踪之外，还有一种不需要修改代码的非入侵的方式，那就是 Service Mesh。Service Mesh 一般会被翻译成服务啮合层，它是在网络层面做文章，通过 Sidecar 的方式为 Pod 增加一层代理，通过这层网络代理来实现一些服务治理的功能，因为是工作在网络层面，可以做到跨语言、非入侵。Istio 则是目前最成熟的 Service Mash 工具，支持启用分布式追踪服务。Istio 会修改微服务之间发送的网络请求，在请求中注入 Trace 和 Span 标记，再将采集到的数据发送到支持 OpenTracing 的分布式追踪服务中，从而拿到请求在微服务中的调用链。当然这种方式也有缺点，它无法追踪某个微服务内部的调用过程，并且目前阶段 Istio 只能追踪 HTTP 请求，能够覆盖的范围比较有限。如果想追踪更详细的数据，还是需要在中间件和代码中埋点，不过好在埋点的过程并不复杂，不会成为一个额外的负担。


