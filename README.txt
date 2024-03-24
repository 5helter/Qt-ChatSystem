#此项目是基于Qt和MySQL的聊天软件
#使用此聊天软件需要有一个MySQL服务器
#配置MySQL服务器的执行文件为chat_system.sql
#登录此软件需要数据库管理员在`client`表中插入用户信息，创建用户并授予`my_friends` `my_task` my_group` `my_gmessage` `my_cmessage` 等视图的查询权限，其余表的插入权限 

#chatit为可执行文件目录
#testMySQL为源代码目录
#该源代码需要先编译获得qt mysql驱动才能编译运行