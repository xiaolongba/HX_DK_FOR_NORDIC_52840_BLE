## 如何下载红旭无线开发板资料
原本这里的内容其实应该很早就要面世的.但是,我们团队内部一直就生成PDF文档以及源码上传至百度网盘还是将Markdown写的文档以及源码上传至Github上没有一致的结论.两种不同的意见如下:
 - 百度网盘

   受传统单片机的思想影响,很多开发板的资料都是放在百度网盘.开发板生产商通过网盘链接的方式存储以及分享他们的资料.

   - 优点

     大多数嵌入式工程师对这种方式都已经习惯了,学习成本较低;

   - 缺点
     1. 百度网盘经常以**扫黄**为由,删除之前分享的链接,经常会出现过一段时间导致链接失效的情史发生;
     2. 百度网盘因为**极度缺钱**,非会员下载不能全速下载;
     3. 百度网盘的资料细化之后,浏览不方便;
     4. 如果有一部分资料更新,一时半会找到不到更新的是哪些.经常会出现"群主,开发板的资料更新了没有?"这样的对话,经常要人肉通知.

 - Github

   最开始是互联网搞IT那边兴起的.但是,随着时代进步发展,Github慢慢地引伸至嵌入式领域特别是物联网.因为物联网相当于桥梁将传统的嵌入式与互联网联系起来并绑定在一起.

    - 优点

      1. 用户可以通过<code>git log</code>的命令查看修改的内容;
      2. "群主,开发板的资料更新了没有?"这样的对话再也不会重现,用户只需要通过<code>git pull</code>即可下载更新的那部分的内容,而不必下载整个资料;
      3. 可以清晰地浏览整个开发板资料的架构;
      4. 使用markdown写出来的文档,排版更加好看更加丰富;
      5. 如果开发板生产商提供的资料有错误的地方,可以pull request告之开发板生产商.然后,开发板生产商合并即可完成错误的引正;最后,用户只要<code>git pull</code>即可下载更新的那部分的内容.

   - 缺点

     增加用户的学习时间成本

综上所述,我们最终选定Github为主,百度网盘为辅的方式来存储红旭无线开发板的资料.其中,Github主要用于存储教程以及其对应的源码,而百度网盘则存放一些视频.



### 如何下载

Github的下载有两种方式,分别如下所示:

- 打开[红旭开发板资料代码仓](https://github.com/xiaolongba/wireless-tech),直接<code>clone or download</code>---><code>Download ZIP</code>.但是这种不推荐,因为这样跟直接跟百度网盘下载的方式没什么区别;

  ![](https://raw.githubusercontent.com/xiaolongba/picture/master/github%E4%B8%8B%E8%BD%BD%E6%96%B9%E5%BC%8F1.gif)

  

- 使[Git](https://git-scm.com/)来下载红旭开发板资料,操作步骤如下:

  1. 下载[Git工具](https://git-scm.com/download/win)

  2. 下载完成之后,在任意想要存放红旭无线开发板资料的地方,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

     ```c
     git clone https://github.com/xiaolongba/wireless-tech.git
     ```

     即可从Github将资料下载至本地.

     ![](https://raw.githubusercontent.com/xiaolongba/picture/master/github%E4%B8%8B%E8%BD%BD%E6%96%B9%E5%BC%8F2.gif)

     

### 如何查看更新的内容

这个就比较简单,在红旭无线开发板资料的根目录(即有<code>.git</code>的那一层目录)下,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

```c
git log
```

即可查看更新了什么内容.

![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E6%9F%A5%E7%9C%8B%E6%9B%B4%E6%96%B0%E7%9A%84%E5%86%85%E5%AE%B9.gif)



### 如何同步

这也就是我们平时所说的,开发板供应商的资料理论上永远都是最新的.因此,只想把开发板供应商更新的那部分内容下载下来.只需要在红旭无线开发板资料的根目录(即有<code>.git</code>的那一层目录)下,右击鼠标选择<code>Git Bash here</code>.然后再弹出来的窗口输入

```c
git pull
```

即可跟Github上的红旭开发板资料同步了,不必要又重新下载整个资料,方便地一逼.

![](https://raw.githubusercontent.com/xiaolongba/picture/master/%E5%90%8C%E6%AD%A5github%E5%86%85%E5%AE%B9.gif)



### 如何只下载Github指定的文件夹内容

有的用户可能比较优秀,他再首次下载时,不想下载整个资料.只想下载他想要的那个文件夹里的内容.本质上Github是没有这样的功能的.但是,全球几十亿人口,总会有一些出类拔萃的人才已经帮我们铺平了道路实现这个功能.即<code>google 浏览器 + gitzip for github插件</code>.

![](https://github.com/xiaolongba/picture/raw/master/GitHub%E4%B8%8B%E8%BD%BD%E5%8D%95%E7%8B%AC%E7%9A%84%E6%96%87%E4%BB%B6%E5%A4%B9%E7%9A%84%E6%96%B9%E6%B3%95.gif)



### 最后

希望广大使用百度网盘的嵌入式工程师,尽快投入Github的怀抱吧.科技才是生产力的第一要素,而不是旧或固化的思想和大脑.