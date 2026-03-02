# 项目仓库相关更新及问题

## 问题模板
### 问题n：
- **日期**：
- **现象**：
- **原因**：
- **解决过程**：
  1. ...
  2. ...
  3. ...
- **结果**：
- **启示**：

## 更新列表
### 将项目移动到vscode上运行
### 问题1：
- **日期**：2026-02-26
- **现象**：遇到了终端输出中文为乱码的问题
- **原因**：g++的输出默认为UTF-8编码，而终端为GBK编码
- **解决过程**：
  1. code Runner插件的编码问题，通过在setting.josn中加入新的指令解决
        ```
        "code-runner.executorMap": {
        "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -finput-charset=UTF-8 -fexec-charset=GBK && .\\$fileNameWithoutExt",
        }    
        ```
  2. 通过`-fexec-charset=GBK`命令设置g++输出时按照GBK编码来输出，适配终端
- **结果**：最终输出正常
- **启示**：注意编码问题
- [x] 已解决
---
        

    
