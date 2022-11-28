echo "
1. 解压
    tar -xvf file.tar         .tar
    tar -xzvf file.tar.gz     .tar.gz
    tar -xjvf file.tar.bz2    .tar.bz2
    tar -xZvf file.tar.Z      .tar.Z
    unrar e file.rar          ./rar
    unzip file.zip            ./zip
    1.1 其它
        -C ./dir/ 指定路径
2. 压缩
    tar -cvf file.tar /tmp/        .tar
    tar -zcvf tmp.tar.gz /tmp/     .tar.gz
    tar -jcvf file.tar.bz2    .tar.bz2
    tar -Zcvf file.tar.Z      .tar.Z


"