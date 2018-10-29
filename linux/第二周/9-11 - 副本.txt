#循环控制
#for while until
for arg in [list]
do
    command(s)......
done
for arg in [list] ; do

############################
#!/bin/bash
for planet in "Mercury 36" "Venus 67" "Earth 93"  "Mars 142" "Jupiter 483"
do
    set -- $planet  # Parses variable "planet" and sets positional parameters.
    #"--" 将防止$planet为空,或者是以一个破折号开头。
    #可能需要保存原始的位置参数,因为它们被覆盖了。
    echo "$1		$2,000,000 miles from the sun"
    #-------two  tabs---把后边的0和$2连接起来
done
exit 0

###########################
while [condition]
do  
    command
done
while [condition] ; do

#while循环例子
#!/bin/bash  
var0=0
LIMIT=10
while [ "$var0" -lt "$LIMIT" ]
do
    echo -n "$var0 "        # -n 将会阻止产生新行
    var0=`expr $var0 + 1`   # var0=$(($var0+1))  也可以
                           # var0=$((var0 + 1)) 也可以
                           # let "var0 += 1"    也可以
done                      # 使用其他的方法也行
echo
exit 0


#until [condition 条件一直为false，执行循环体]
until [condition-is-true]
do
    command
done

#example until
#!/bin/bash
END_CONDITION=end
until [ "$var1" = "$END_CONDITION" ] #在循环的顶部判断条件.
do
echo "Input variable #1 "
echo "($END_CONDITION to exit)"
read var1
echo "variable #1 = $var1"
echo
done  
exit 0


#运行
Input variable #1
end to exit
end
variable #1 = 1

# break  continue
var0 = 0
for ["$var0" -lt 10]
do
    var0 = 'expr $var0 + 1'
    if ["$var0" = 1]
        then
            #break
            continue
    fi
    echo "$var0"
done

num  echo "($num)nd"
#测试与分支
#case 
case "$variable" in
    "$condition1") 
        command...
    ;;
    "$condition2")
        command...
    ;;
esac

#!/bin/bash
#case-cmd.sh: 使用命令替换来产生"case"变量
case $( arch ) in   #arch"返回机器的类型,等价于'uname -m'...
    i386 ) echo "80386-based machine";;
    i486 ) echo "80486-based machine";;
    i586 ) echo "Pentium-based machine";;
    i686 ) echo "Pentium2+-based machine";;
    *    ) echo "Other type of machine";;
esac
exit 0

#select菜单选择工具
select variable in [list]
do
    command
    break
done

#!/bin/bash
PS3 = 'Choose your favorite vegetable: ' #设置提示符字串
echo
select vegetable in "beans" "carrots" "potatoes" "onions" "rutabagas"
do
    echo
    echo "Your favorite veggie is $vegetable."
    echo "Yuck!"
    echo
    break  # 如果这里没有'break'会发生什么?
done
exit 0

:<<!
    任务1： 参数大小比较，
    从终端输入两个参数然后比较大小，输出较大的数
    定义-输入-判断为空-if

    任务2： 统计当前目录中文件的个数
    定义 -循环遍历目录
!
a = $1
b = $2
#判断变量a，b是否为空，只要有一个为空，那就重新输入
#!/bin/bash
a=$1
b=$2
#判断a或者b变量是否为空，只要有一个为空就打印提示语句并退出
if [ -z $a ] || [ -z $b ]
then
    echo "please enter 2 no"
    exit 1
#判断a和b的大小，并根据判断结果打印语句
fi
if [ $a -eq $b ] 
then
    echo "number a = number b" 
else if [ $a -gt $b ] 
then
        echo "number a>number b"
    elif [ $a -lt $b ]
        then
            echo "number a<number b"
    fi
fi


##########################

#!/bin/bash
#变量counter用于统计文件的数目
counter=0
#变量files遍历一遍当前文件夹
for files in *
do
	#判断的files是否是文件，如果是就将counter变量的值加一再赋给自己
	if [ -f "$files" ]
	then
		counter=`expr $counter + 1`
	fi
done
echo "There are $counter file in `pwd` "



:<<!
#被注释的内容   
!

：'
#被注释的内容
'

if false;then
#被注释的内容
fi

:<<任意字符或者数字
#被注释的内容
任意字符或者数字
:<<?

?

((0)) && {
#被注释的内容
}
