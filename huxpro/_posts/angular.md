
Angular 是框架，React 是类库。


Angular 是一个完整的框架，本身就提供了比 React 多得多的建议和功能。而要用 React，开发者通常还需要借助别的类库来打造一个真正的应用。比如你可能需要额外的库来处理路由、强制单向数据流、进行 API 调用、做测试以及管理依赖等等。



Angular 自带了不少主张，所以能够帮助你更快开始，不至于因为要做很多决定而无所适从。这种强制的一致性也能帮助新人更快适应其开发模式，并使得开发者在不同团队间切换更具可行性。

Angular 核心团队让我非常欣赏的一点是，他们拥抱了 TypeScript，这就造成了另一个优势。

TypeScript = 阳关大道
没错，并非所有人都喜欢 TypeScript，但是 Angular 2 毅然决然地选择了它确实是个巨大的优势。反观 React，网上的各种示例应用令人沮丧地不一致——ES5 和 ES6 的项目基本上各占一半，而且目前存在三种不同的组件声明方式。这无疑给初学者造成了困惑。（Angular 还拥抱了装饰器（decorator）而不是继承（extends）——很多人认为这也是个加分项）。



React 的 JSX 是非常耀眼的亮点。


Angular 2 还拥抱了 Web Component 标准。


JSX
JSX 是一种类似 HTML 的语法，但它实际上会被编译成 JavaScript。将标签与代码混写在同一个文件中意味着输入一个组件的函数或者变量时你将享受到自动补全的福利。而 Angular 基于字符串的模版就相形见绌了：很多编辑器都不会高亮它们（只会显示单色）、只有有限的代码补全支持，并且一直到运行时才会报错。并且，通常你也只能得到很有限的错误提示。不过，Angular 的团队造了一个自己的 HTML 解析器来解决这个问题。


React 报错清晰快速
当你在 React 的 JSX 中不小心手抖打错时，它并不会被编译。这是一件非常美妙的事情：无论你是忘记闭合了标签还是引用了一个不存在的属性（property），你都可以立刻知道到底是哪一行出错了。JSX 编译器会指出你手抖的具体行号，彻彻底底加速你的开发。

相反，当你在 Angular 2 中不小心敲错了一个变量时，鸦雀无声。Angular 2 并不会在编译时做什么，它会等到运行时才静默报错。它报错得如此之慢，我加载完整个应用然后奇怪为什么我的数据没有显示出来呢？这太不爽了。

React 以 JavaScript 为中心
终于来了。这才是 React 和 Angular 的根本区别。很不幸，Angular 2 仍然是以 HTML 而非 JavaScript 为中心的。Angular 2 并没有解决它设计上的根本问题：

Angular 2 继续把 “JS” 放到 HTML 里。React 则把 “HTML” 放到 JS 里。

这种分歧带来的影响真是再怎么强调也不为过。它们从根本上影响着开发体验。Angular 以 HTML 为中心的设计留下了巨大的缺陷。




Angular 2 的内联母版（inline master templates）使用了这样的语法：

1
2
3
4
5
<ul>
  <li *ngFor="#hero of heroes">
    {{hero.name}}
  </li>
</ul>
上面这个代码片段遍历了一组 hero，而我比较关心的几点是：

通过星号来声明一个“母版”实在是太晦涩了
hero 前的英镑符号（#）用于声明一个局部模版变量。这个概念感觉非常鸡肋（如果你偏好不使用 #，你也可以使用 var- 前缀写法）
为 HTML 加入了循环语义的HTML 特性（attribute）ngFor 是 Angular 特有的东西
相比上面 Angular 2 的语法，React 的语法可是纯净的 JavaScript （不过我得承认下面的属性 key 是个 React 的私货）

1
2
3
4
5
<ul>
  { heroes.map(hero =>
    <li key={hero.id}>{hero.name}</li>
  )}
</ul>
鉴于 JS 原生支持循环，React JSX 利用 JS 的力量来做到这类事情简直易如反掌，配合 map、filter 能做的还远不止此。






React 因为语法和概念的简约而与众不同。我们不妨品味下当今流行的 JS 框架/库都是如何实现遍历的：

1
2
3
4
5
Ember     : {{# each}}
Angular 1 : ng-repeat
Angular 2 : ngFor
Knockout  : data-bind="foreach"
React     : 直接用 JS 就好啦 :)
除了 React，所有其它框架都用自己的专有语法重新发明了一个我们在 JavaScript 常见得不能再常见的东西：循环。这大概就是 React 的美妙之处，利用 JavaScript 的力量来处理标签，而不是什么奇怪的新语法。

Angular 2 中的奇怪语法还有点击事件的绑定：

1
(click)="onSelect(hero)"
相反，React 再一次使用了普通的 JavaScript：

1
onClick={this.onSelect.bind(this, hero)}
并且，鉴于 React 内建了一个模拟的事件机制（Angular 2 也有），你并不需要去担心使用内联语法声明事件处理器所暗含的性能问题。

为什么要强迫自己满脑子都是一个框架的特殊语法呢？为什么不直接拥抱 JS 的力量？

奢华的开发体验
JSX 具备的代码自动补全、编译时检查与丰富的错误提示已经创造了非常棒的开发体验，既为我们减少了输入，与节约了时间。而配合上热替换（hot reloading）与时间旅行（time travel），你将获得前所未有的开发体验，效率高到飞起。





是一些常见框架/库压缩后的大小（来源）：

Angular 2: 566k (766k with RxJS)
Ember: 435k
Angular 1: 143k
React + Redux: 139k
列出的都是框架级的、用于浏览器且压缩后的大小（但并未 gzip）。需要补充的是，Angular 2 的尺寸在最终版本发布时应该会有所减小。

为了做一个更真实的对比，我将 Angular 2 官方教程中的 Tour of Heroes 应用用 Angular 2 和 React（还用上了新的 React Slingshot 入门套件）都实现了一遍，结果如何呢？

Angular 2: 764k 压缩后
React + Redux: 151k 压缩后
可以看到，做一个差不多的东西，Angular 2 目前的尺寸是 React + Redux 的五倍还多。




Angular 致力的 HTML 中心设计比 React 的 JavaScript 中心模型要复杂太多。在 React 中，你并不需要学习 ng-什么什么 这种框架特有的 HTML 补丁（shim），你只要写 JavaScript 就好了。这才是我相信的未来。



