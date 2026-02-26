2026.2.26
尝试将项目文件夹在vscode上运行
    [已解决]遇到了终端输出中文为乱码的问题
        根本问题：g++的输出默认为UTF-8编码，而终端为GBK编码
        code Runner插件的编码问题，通过在setting.josn中加入新的指令解决
        解决方式：
        '''
        "code-runner.executorMap": {
        "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -finput-charset=UTF-8 -fexec-charset=GBK && .\\$fileNameWithoutExt",
        }    
        '''
        通过"-fexec-charset=GBK"命令设置g++输出时按照GBK编码来输出，适配终端

    
