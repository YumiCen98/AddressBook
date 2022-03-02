#ifndef __OPERATION_H_
#define __OPERATION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000//通讯录中最大存储人数
#define FILENAME "./address.txt"

//定义颜色代码
#define COLOR_NONE          "\033[0m"       //恢复默认
#define FONT_COLOR_YELLOW   "\033[1;33m"    //黄色高亮
#define FONT_COLOR_RED      "\033[1;31m"    //红色高亮
#define FONT_COLOR_BLUE     "\033[1;34m"    //蓝色高亮

//功能
enum OP
{
	EXIT,
	ADD,
	FIND,
	SHOW,
	MODIFY,
	TEL,
	EMPTY,
	SORT,
	SAVE
};

//个人信息
typedef struct Stu
{
	char name[10];
	char sex[3];
	int age;
	char Tel[12];
	char add[30];
}Stu;

//通讯录

typedef struct TongXunLu
{
	Stu stu[MAX];
	int count;
}TXL,* ptxl;

void initiate(ptxl ptxl);   //启动
void add(ptxl ptxl);        //添加通讯录中的人，最多添加1000个
void find(ptxl ptxl);       //在通讯录中查找需要查找的人，按姓名查找
void show(ptxl ptxl);       //显示当前通讯录中所有人
void modify(ptxl ptxl);     //修改通讯录中某一人的信息
void del(ptxl ptxl);        //删除通讯录中某一人的信息
void empty(ptxl ptxl);      //清空通讯录中所有人信息
void sort(ptxl ptxl);       //排序通讯录中的所有人，按名字排序的
void save(ptxl ptxl);       //保存到文件
void menu();//菜单

#endif
