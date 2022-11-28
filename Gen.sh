# Copyright (C) Horizon Robotics, Inc. - All Rights Reserved
# Unauthorized copying of this file, via any medium is strictly prohibited
# Proprietary and confidential
if [ $# == 0 ]; then
    python3 ~/gen.py -i ./gdb.out
    rm gdb.out
    mv gdb.svg /home/autoshare/pei.tang/
elif [ $# == 1 ]; then
    python3 ~/gen.py -i $1
    rm gdb.out
    mv gdb.svg /home/autoshare/pei.tang/
fi
