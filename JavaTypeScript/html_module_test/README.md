# html中使用
[VUE有两种使用方式，一种实在html中直接使用vue做开发，一种是企业级的单页面应用。后者是主流的使用方式，真正项目中很少使用前一种方式。原认为前一种方式主要作用是为了降低VUE的学习门槛——通过在大家熟悉的HTML环境中使用vue，大家很容易去了解和熟悉VUE.](https://blog.csdn.net/guoyp2126/article/details/126166787)

* 第一种方式参考[这个](https://zhuanlan.zhihu.com/p/31225698)
* 第二种方式vue-cli或者vite直接生成

## 普通html导入
```javascript
import  { createApp } from 'vue' // 这个得加上type="module" 默认为type="application/javascript"
```
module加载的是es6语言，浏览器只认es5，脚手架将有[babel](https://www.babeljs.cn/docs/)能将es6转换为向后兼容的语言

## 注意事项
* 如果直接在浏览器中打开了上面的 index.html，你会发现它抛出了一个错误，因为 ES 模块不能通过 file:// 协议工作。为了使其工作，你需要使用本地 HTTP 服务器通过 http:// 协议提供index.html。要启动一个本地的 HTTP 服务器，请先安装 Node.js，然后从命令行在 HTML 文件所在文件夹下运行 npx serve。你也可以使用其他任何可以基于正确的 MIME 类型服务静态文件的 HTTP 服务器。

* 不能使用typescript 编译成javascript，这样的话export default编译成html不可以识别

* html如果在服务器环境下运行的话就要使用注册的静态文件`/assets`，`@`标识只有在情况下vue-cli情况下才可使用

* 前后端分离就有两个端口，前段一个端口，后端一个端口，然后两者交互