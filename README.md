# 3DAOI
模拟3DAOI程式检测流程

---

## Environment

Qt 5.9.0

## Tree
```
└── 3DAOI
    ├── README.md                   // 帮助文档
    ├── src                         
    │   ├── main.cpp                // 主函数
    │   ├── App
    │   │   ├── AppStartup          // 软件启动
    │   │   ├── AppSetting          // 软件设置
    │   │   ├── CaptureSetting      // 图像设置
    │   │   └── DataGenerator       // 数据生成器
    │   ├── Job                     
    │   │   ├── InspectionData      // 检测数据
    │   │   ├── Board               // 基板
    │   │   ├── MeasuredObjList     // 被测对象列表
    │   │   └── MeasuredObj         // 被测对象
    │   ├── SDK                      
    │   │   ├── Rectangle           // 矩形
    │   │   ├── CustomException     // 自定义异常
    │   │   └── DataHelper          // 数据帮助
    │   ├── DB                      // 数据库
    │   │   ├── Blob         
    │   │   ├── SqliteDB
    │   │   └── SqliteDBTest
    │   └── Setting                 // 配置文件        
    │   │   ├── AppSetting.ini         
    │   │   └── CaptureSetting.ini     
    │   └── plato_3DAOI.pro              
    ├── include                     // 头文件
    │   ├── ...
    │    ...
    ├── lib                         // 库文件      
    │   ├── ...
    │    ...
    ├── data                        // 检测程式与数据
    └── doc                         // 文档
```
## Version
v1.0

## Instructions
- 启动软件，加载AppSetting.ini和CaptureSetting.ini，考虑其中异常如何处理
- 在2个配置都加载成功的基础上，扫描JobFolderPath目录下的程式
- 如果JobFolderPath没有文件的话，自动生成程序（包括内存中的数据结构）：
    1. 生成50个Target，20个chip，30个ic，命名以"chip_xxx/ic_xxx"
    2. 生成其它要求必要的信息
- 如果JobFolderPath有文件的话，把文件全部在屏幕上列举出来，然后让用户选择
- 加载用户选择的程式（考虑版本兼容的问题）
- 读取成功后把所有的InspectionData信息在屏幕上打印出来
- 读取成功后把所有的InspectionData信息同时以xml格式输出
    1. 输出到JobFolderPath，同名后缀名不同
    2. 格式请参考BoardData.xml，调用使用Qt的XML库


- 注意：   
   1.如果软件未能正常启动，提示“检测功能不可用，请重新配置！”，这是因为缺少功能相关的重要配置文件，导致加载失败，解决方案如下：  
   将doc目录下的CaptureSetting.ini复制到src/Setting目录下即可  
   2.如果需要测试版本兼容，但程式目录下无旧版本，可将doc目录下的V1版本程式复制到data目录下
