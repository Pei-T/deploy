echo -e "=====================================================
\033[36m1. Tcpdump\033[0m
  tcpdump -n \033[32m不转换host\033[0m
  tcpdump -i eth0 -c 10 -w ./file.pcap \033[32m// 抓取某网卡，某数量，保存到某文件。\033[0m
  tcpdump host 192.168.1.20 \033[32m// 设置源IP, src host或dst host。\033[0m
  tcpdump port 22 \033[32m// 抓取网卡端口22的包。\033[0m
  tcpdump tcp \033[32m// 抓取某协议的包。\033[0m
  tcpdump -r file.pcap \033[32m// 从某文件中读取包。\033[0m
=====================================================
"