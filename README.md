# JALKitDll

动态链接库Demo

1、JALKitDll：output JALKitDll.lib

2、JALKitDemo：JALKitDemo.exe

提示

1、JALKitDll的工程和JALKitDemo的Runtime Library必须设置一致,否则运行时可能出错。

2、/MD,动态调用运行时库，发布后必须安装运行时库（比如VS2010的msvr100.dll）

3、/MT,编译是加入静态运行时库，体积臃肿。

4、如果是MFC工程

/MD需设置Use of MFC为（Use MFC in a Shared DLL）

/MT需设置Use of MFC为（Use MFC in a Static Library）

5、动态加载时：如果用到导出类，需要注意函数方法加virtual，否则无法调用。
