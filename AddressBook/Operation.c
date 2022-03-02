#include "Operation.h"

void menu()
{
	printf( FONT_COLOR_YELLOW"************************************************\n" COLOR_NONE);
	printf( FONT_COLOR_YELLOW"****                通讯录系统              ****\n" COLOR_NONE);
	printf( FONT_COLOR_YELLOW"************************************************\n" COLOR_NONE);
	printf( "         【1】添加联系人\n" );
	printf( "         【2】查找联系人\n" );
	printf( "         【3】显示联系人\n" );
	printf( "         【4】修改联系人\n" );
	printf( "         【5】删除联系人\n" );
	printf( "         【6】清空联系人\n" );
	printf( "         【7】排序联系人\n" );
	printf( "         【8】保存联系人\n" );
	printf( "         【0】退出程序   \n" );
	printf( FONT_COLOR_YELLOW"------------------------------------------------\n" COLOR_NONE);

    return ;
}

void show(ptxl ptxl)
{
	int i = 0;
	//printf( "姓名\t性别\t年龄\t电话\t\t住址\n" );
	for (i=0; i < ptxl->count; i++)
	{
		printf( "%s\t%s\t%d\t%s\t%2s\n" , ptxl->stu[i].name, ptxl->stu[i].sex, ptxl ->stu[i].age, ptxl->stu[i].Tel, ptxl->stu[i].add);
	}
}

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
    if(ptxl->count > MAX)
    {
        system("clear");
        printf(FONT_COLOR_RED"[添加失败，表已满]\n"COLOR_NONE);
        return ;
    }

    printf( FONT_COLOR_YELLOW"输入：姓名 性别 年龄 电话 住址\n"COLOR_NONE);
    printf( FONT_COLOR_BLUE">>："COLOR_NONE);
    scanf( "%s%s%d%s%s" , ptxl->stu[ptxl->count].name, ptxl->stu[ptxl->count].sex, &ptxl ->stu[ptxl->count].age, ptxl->stu[ptxl->count].Tel, ptxl->stu[ptxl->count].add);
    /*
    printf( "姓名:\n" );
    scanf("%s", ptxl->stu[ptxl->count].name);
    printf( "性别:\n" );
    scanf("%s", ptxl->stu[ptxl->count].sex);
    printf( "年龄:\n" );
    scanf("%d", &ptxl->stu[ptxl->count].age);
    printf( "电话:\n" );
    scanf("%s", ptxl->stu[ptxl->count].Tel);
    printf( "住址:\n" );
    scanf("%s", ptxl->stu[ptxl->count].add);
    */
    ptxl->count++;
    printf(FONT_COLOR_YELLOW"[添加成功]\n"COLOR_NONE);

    return ;
}

void find(ptxl ptxl)
{

	/*
	 * 1、读取要查找的姓名
	 * 2、比较表里是否存在，温馨提示：strcmp
	 * 3、读到之后进行打印
	 */
    int i;
    char name[10] = "";

    printf(FONT_COLOR_BLUE"输入要查找的姓名："COLOR_NONE);
    scanf("%s", name);

    for(i=0; i<ptxl->count; i++)
    {
        if(strcmp(ptxl->stu[i].name, name) == 0)
        {
            printf( "%s\t%s\t%d\t%s\t%2s\n" , ptxl->stu[i].name, ptxl->stu[i].sex, ptxl ->stu[i].age, ptxl->stu[i].Tel, ptxl->stu[i].add);
            return ;
        }
    }

    printf(FONT_COLOR_RED"[没有该联系人]\n"COLOR_NONE);

    return ;
}

void modify(ptxl ptxl)
{

	/*
	 * 1、输入改人员的姓名
	 * 2、比较表里是否存在
	 * 3、不存在没事，存在重新输入人员信息
	 */

    int i;
    char name[10] = "";

    printf(FONT_COLOR_BLUE"输入要修改人员的姓名："COLOR_NONE);
    scanf("%s", name);

    for(i=0; i<ptxl->count; i++)
    {
        if(strcmp(ptxl->stu[i].name, name) == 0)
        {
            printf( FONT_COLOR_YELLOW"输入：姓名 性别 年龄 电话 住址\n" COLOR_NONE);
            printf( FONT_COLOR_BLUE">>："COLOR_NONE);
            scanf( "%s%s%d%s%s" , ptxl->stu[i].name, ptxl->stu[i].sex, &ptxl ->stu[i].age, ptxl->stu[i].Tel, ptxl->stu[i].add);
            printf(FONT_COLOR_YELLOW"[修改完成]\n"COLOR_NONE);
            return ;
        }
    }
    printf(FONT_COLOR_RED"[没有该联系人]\n"COLOR_NONE);

    return ;
}

void del(ptxl ptxl)
{

	/*
	 * 1、判断是否为空
	 * 2、读取要删除人员的姓名
	 * 3、比较表里是否存在
	 * 4、删除（注意循环条件）
	 */
    int i, j;
    char name[10] = "";

    if(ptxl->count == 0)
    {
        printf(FONT_COLOR_RED"[删除失败，表已空]\n"COLOR_NONE);
        return ;
    }
    printf(FONT_COLOR_YELLOW "输入要删除的联系人：" COLOR_NONE);
    scanf( "%s" , name);
    for(i=0; i<ptxl->count; i++)
    {
        if(strcmp(ptxl->stu[i].name, name) == 0)
        {
            for(j=i; j<ptxl->count; j++)
            {
                ptxl->stu[i] = ptxl->stu[i+1];
                ptxl->count--;
            }
            printf(FONT_COLOR_YELLOW"[删除成功]\n"COLOR_NONE);
            return ;
        }
    }
    printf(FONT_COLOR_RED"[没有该联系人]\n"COLOR_NONE);

    return ;
}

void empty(ptxl ptxl)
{
	ptxl->count = 0;
	printf( FONT_COLOR_YELLOW"[通讯录已清空!]\n" COLOR_NONE);
}

void sort(ptxl ptxl)
{

	/*
	 * 利用排序方式对姓名进行排序：比如冒泡
	 */

    int i, j;
    Stu temp;

    for(i=0; i<ptxl->count; i++)
    {
        for(j=0; j<ptxl->count-i-1; j++)
        {
            //比较每个员工姓名的第一个字母，按从小到大排序
            if((strncmp(ptxl->stu[j+1].name, ptxl->stu[j].name, 1)) < 0)
            {
                temp = ptxl->stu[j+1];
                ptxl->stu[j+1] = ptxl->stu[j];
                ptxl->stu[j] = temp;
            }
        }
    }
    printf(FONT_COLOR_YELLOW"[排序完成]\n"COLOR_NONE);

    return;
}

void save(ptxl ptxl)
{

	/* 1、调用fopen获取流
	 * 2、调用fwrite写入文件
	 * 3、调用fclose关闭流
	 */

    int i;
    FILE *fp;

    if((fp = fopen(FILENAME, "w+")) == NULL)
    {
        perror("fopen");
        return ;
    }

    for(i=0; i<ptxl->count; i++)
    {
        /*
        if((fwrite(&ptxl->stu[i], 1, sizeof(Stu), fp)) == 0)
        {
            printf("保存失败\n");
            perror("fwrite");
            return ;
        }
        */
        //将结构体中int类型的变量转化为字符串
        char age[5] = "";
        sprintf(age, "%d", ptxl->stu[i].age);

        fwrite(ptxl->stu[i].name, 1, sizeof(ptxl->stu[i].name), fp);
        fwrite("\t", 1, 1, fp); //写入tab
        fwrite(ptxl->stu[i].sex, 1, sizeof(ptxl->stu[i].sex), fp);
        fwrite("\t", 1, 1, fp);
        fwrite(age, 1, sizeof(age), fp);
        fwrite("\t", 1, 1, fp);
        fwrite(ptxl->stu[i].Tel, 1, sizeof(ptxl->stu[i].Tel), fp);
        fwrite("\t", 1, 1, fp);
        fwrite(ptxl->stu[i].add, 1, sizeof(ptxl->stu[i].add), fp);

        //写入换行
        fwrite("\n", 1, 1, fp);

    }

    if(fclose(fp) == EOF)
    {
        perror("fclose");
        return ;
    }

    printf(FONT_COLOR_YELLOW"[保存完成]\n"COLOR_NONE);

	return ;
}

