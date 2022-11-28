
if [ $# == 1 ]; then
    find . -name "*$1*"
elif [ $# == 0 ]; then
    echo "find .sh"
    echo "find tar.gz"
    echo "find .cpp"
    echo "find hello"
fi

