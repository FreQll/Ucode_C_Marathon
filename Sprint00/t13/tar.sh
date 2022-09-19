if [ $1 = -c ]
then
   tar -c -f "$2" ${@:3}
elif [ $1 = -e ]
then
   tar --extract -f "$2"
fi
