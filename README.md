# 此项目是基于Qt和MySQL的聊天软件
## 使用此聊天软件需要配置一个MySQL服务器

配置MySQL服务器的执行文件为 **chat_system.sql**，配置完成后，系统内置了用户名为1000 1001 1002三位用户名，可直接在软件内使用密码：1 登录使用
## 用户注册

该系统用户注册需要数据库管理员在数据库中加入用户，并设置密码
密码必须以apex#结尾
此外还需要数据库管理员在`client`表中插入用户信息，创建用户并授予
`my_friends` 
`my_task` 
`my_group` 
`my_gmessage` 
`my_cmessage` 
等视图的查询权限，其余表的插入权限

## chatit文件夹提供了可执行文件
## testMySQL为源代码目录
## 该源代码需要先编译获得qt mysql驱动才能编译运行

## 运行效果图
![登录界面.png](https://img2.imgtp.com/2024/05/13/oYsrDJbs.png)
![一对一聊天界面.png](https://img2.imgtp.com/2024/05/13/4AgmB7QH.png)
![群聊模式.png](https://img2.imgtp.com/2024/05/13/oImv2lSJ.png)
![其他功能示例.png](https://img2.imgtp.com/2024/05/13/9ZglOXN0.png)
