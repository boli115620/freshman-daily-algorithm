/*
    文件说明：
    作者：Boris
    主函数-调试line.h中的其他函数
*/

#include<stdio.h>
#include"line.h"

//常量区

//其他变量

int main(void)
{
    //线性表的初始化
    LineList *mylist = InitLineList(mylist);
    printf("线性表初始化成功=%d \n",!!mylist);
    printf("插入是否成功=%d \n",!!InsertList(mylist,1,10));
}