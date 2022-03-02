#include "Operation.h"

void initiate(ptxl ptxl)
{
	ptxl->count = 0;
}

void add(ptxl ptxl)
{
	/*
	 * 1、判断表是否满
	 * 2、读数据
	 * 3、count修改
	 */
	
}

void find(ptxl ptxl)
{

	/*
	 * 1、读取要查找的姓名
	 * 2、比较表里是否存在，温馨提示：strcmp
	 * 3、读到之后进行打印
	 */
}

void show(ptxl ptxl)
{
	int i = 0;

	printf( "姓名\t性别\t年龄\t电话\t\t住址\n" );

	for (i = 0; i < ptxl ->count; i++)
	{
		printf( "%s\t%s\t%d\t%s\t%2s\n" , ptxl->stu[i].name, ptxl->stu[i].sex, ptxl ->stu[i].age, ptxl->stu[i].Tel, ptxl->stu[i].add);
	}
}

void modify(ptxl ptxl)
{

	/*
	 * 1、输入改人员的姓名
	 * 2、比较表里是否存在
	 * 3、不存在没事，存在重新输入人员信息
	 */
}

void del(ptxl ptxl)
{

	/*
	 * 1、判断是否为空
	 * 2、读取要删除人员的姓名
	 * 3、比较表里是否存在
	 * 4、删除（注意循环条件）
	 */
}

void empty(ptxl ptxl)
{
	ptxl->count = 0;
	printf( "通讯录以清空!\n" );
}

void sort(ptxl ptxl)
{

	/*
	 * 利用排序方式对姓名进行排序：比如冒泡
	 */
}

void save(ptxl ptxl)
{

	/* 1、调用fopen获取流
	 * 2、调用fwrite写入文件
	 * 3、调用fclose关闭流
	 */
	return ;
}

void menu()
{
	printf( "************************************************\n" );
	printf( "****                通讯录系统              ****\n" );
	printf( "************************************************\n" );
	printf( "         【1】添加联系人\n" );
	printf( "         【2】查找联系人\n" );
	printf( "         【3】显示联系人\n" );
	printf( "         【4】修改联系人\n" );
	printf( "         【5】删除联系人\n" );
	printf( "         【6】清空联系人\n" );
	printf( "         【7】排序联系人\n" );
	printf( "         【8】保存联系人\n" );
	printf( "         【0】退出程序   \n" );
	printf( "------------------------------------------------\n" );
}