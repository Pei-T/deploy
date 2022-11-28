echo -e "
\033[34m1. Package: \033[0m
  ros2 pkg create --build-type ament_cmake \033[33mpackage_name\033[0m \033[32m// 创建package。\033[0m
  ros2 pkg list \033[32m// 显示所有的package。\033[0m
\033[34m2. Node: \033[0m
  ros2 node list \033[32m// 显示所有的节点。\033[0m
  ros2 node info \033[33m/node_name\033[0m \033[32m// 显示节点信息，包括订阅、发布的消息，开启的服务和动作等。\033[0m
\033[36m3. Topic\033[0m
  ros2 topic list \033[32m// 显示所有topic。\033[0m
  ros2 topic info \033[33mtopic_name\033[0m \033[32m// 显示有多少publisher，多少subscriber。\033[0m
  ros2 topic type \033[33mtopic_name\033[0m \033[32m// 显示topic类型。\033[0m
  ros2 topic find \033[33mtype_name\033[0m \033[32m// 显示该数据类型下有多少活动的Topic。\033[0m
  ros2 topic echo \033[33mtopic_name\033[0m \033[32m// 接收该Topic下的数据。\033[0m
  ros2 topic pub \033[33mtopic_name\033[0m // 往Topic中发送数据，回车后使用方向键操作。\033[0m

"