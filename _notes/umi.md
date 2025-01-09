

$ yarnpkg create umi myapp
yarn create v1.22.10
[1/4] Resolving packages...
warning create-umi > sylvanas > @umijs/fabric > stylelint > @stylelint/postcss-markdown@0.36.2: Use the original unforked package instead: postcss-markdown
warning create-umi > yeoman-environment > globby > fast-glob > micromatch > snapdragon > source-map-resolve > resolve-url@0.2.1: https://github.com/lydell/resolve-url#deprecated
warning create-umi > yeoman-environment > globby > fast-glob > micromatch > snapdragon > source-map-resolve > urix@0.1.0: Please see https://github.com/lydell/urix#deprecated
[2/4] Fetching packages...
[3/4] Linking dependencies...
[4/4] Building fresh packages...
success Installed "create-umi@0.27.0" with binaries:
      - create-umi
? Select the boilerplate type ant-design-pro
? 🤓 Which language do you want to use? TypeScript
? 🚀 Do you need all the blocks or a simple scaffold? simple
Cloning into 'myapp'...
remote: Enumerating objects: 206, done.
remote: Counting objects: 100% (206/206), done.
remote: Compressing objects: 100% (188/188), done.
remote: Total 206 (delta 36), reused 84 (delta 13), pack-reused 0
Receiving objects: 100% (206/206), 118.31 KiB | 165.00 KiB/s, done.
Resolving deltas: 100% (36/36), done.
> 🚚 clone success
> Clean up...
📋 Copied to clipboard, just use Ctrl+V
✨ File Generate Done
Done in 1622.89s.





数据流插件
在过去的几年中，前端一直都使用 redux 来作为默认的数据流方案，但是 redux 系列一直存在样板代码多，代码提示效果差等问题，导致开发体验一直不是很好。虽然 redux 的功能很强大， 但是在中后台开发中全局公用数据较少，没有复杂的数据流。借着 hooks 的东风我们在 V5 中提供了一个轻量的数据流方案 plugin-model 。

plugin-model 提供了 hooks 方案的 API, 并且基于 umi 的运行时能力提供了实时的 TypeScript 提示。




# Bundleless 就在此时应运而生。现代浏览器已经支持了 es6 的模块，那么我们就可以再项目中直接使用的 es6 ，而减少编译甚至于不编译。在首次生成 es 模块之后，获得极快的项目启动速度。umi 也提供了 Bundleless 方案 mfsu。

mfsu (Module Federation Speed Up) 是一种基于 webpack5 新特性 Module Federation 的打包提速方案。核心原理是将应用的依赖构建为一个 Module Federation 的 remote 应用，以免去应用热更新时对依赖的编译。 因此，开启 mfsu 可以大幅减少热更新所需的时间。在生产模式，也可以通过提前编译依赖，大幅提升部署效率。

我们在 config.s 中配置 mfsu:{} 和 wepack5:{} 就能享受到编译性能提升的快乐。

export default defineConfig({ 
    +  mfsu : {},
    +  webpack5: {}, 
    +  dynamicImport: {},
})



# ️ OpenAPI
中后台开发中最重要的事情之一就是联调，在这期间后端一般都需要维护一份文档来告诉我们具体的 API 有什么功能，具体的字段信息有哪些，这些信息的维护成本相当高的。如果中途作了更改但是忘记更新文档就会造成信息不同步，在测试时很有可能会造成一个 bug。

Pro V5 支持使用 OpenAPI 3.0.1 的接口描述文档，这份文档可以用 Swagger 来生成，对于后端来说可能需要一点工作量，但是带来的收益是远远超出投入的。

Pro 会根据 OpenAPI 来自动生成接口和基础类，配合 TypeScript 的使用，我们可以丝滑的接入后端的数据，并且与使用 tsc 来监控后端字段改变导致的字段不对齐问题。



