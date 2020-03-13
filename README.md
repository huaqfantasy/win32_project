# my_first_win32_project
problem：
1>
error LNK2019: 无法解析的外部符号 _main该符号在函数___XXXX中被引用
reason:
  1.你用vc建了一个控制台程序，它的入口函数应该是main,而你使用了WinMain.
  2.你用vc打开了一个.c/.cpp文件，然后直接编译这个文件，这个文件中使用了WinMian而不是main作为入口函数。vc这时的默认设置是针对控制台程序的。
solve：
1.进入project->setting->c/c++,在category中选择preprocessor,在processor definitions中删除_CONSOLE,添加_WINDOWS

2.进入project->setting->Link, 在Projectoptions中将 /subsystem:console改为/subsystem:windows.

3.保存设置，Rebuild All.

2>C2065 “g_hInstance”: 未声明的标识符
reason:
声明函数再函数调用后，调整位置即可。

3>C++ LPCWSTR tagWNDCLASSW::lpszClassName
4>不能将 "const char *" 类型的值分配到 "LPSTR" 类型的实体
reason:类型不匹配
sovle：
1.项目->属性—>字符集—>使用多字节字符集
2.显示类型转换

--------OpenSCManager-------
SC_HANDLE schSCManager = NULL;
function 
OpenSCManager(lpMachineName, lpDatabaseName: PChar;dwDesiredAccess: DWORD): SC_HANDLE; stdcall;
lpmachinename：目标机器名，如果该指针为NULL ，或者如果它指向一个空字符串，函数连接到服务控制管理器在本地计算机上。
lpdatabasename：服务控制管理数据库，此字符串应指定ServicesActive 。如果该指针为NULL ，该ServicesActive数据库默认情况下打开。
dwDesiredAccess：指定服务的访问控制管理权限，SC_MANAGER_ALL_ACCESS：所有权限
                                          SC_MANAGER_CONNECT：
                                          SC_MANAGER_CREATE_SERVICE：
                                          SC_MANAGER_ENUMERATE_SERVICE：
                                          SC_MANAGER_LOCK：
                                          SC_MANAGER_QUERY_LOCK_STATUS：
                                          如果函数成功，返回值是一个句柄指定的服务控制管理器数据库。如果函数失败，返回值为NULL 。要获得扩展错误信息，请使用GetLastError 获得错误代码。
OpenSCManager函数是在创建一个服务对象（CreateService），并且把它加入到要调用的API中。
-------end----------                                          
