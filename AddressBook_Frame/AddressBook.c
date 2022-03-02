#include "Operation.h"

static int compare(ptxl ptxl, const char * name)
{
	int i = 0;

	for (i = 0; i < ptxl ->count; i++)
	{
		if (strcmp(name , ptxl->stu[i].name) == 0)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	TXL txl;
	int input = 1;

	initiate(&txl);

	while (input)
	{
		menu();
		printf( "请输入0~8之间的选择:" );
		scanf( "%d", &input);
		switch (input)
		{
		case ADD:
			add(&txl);
			break;
		case FIND:
			find(&txl);
			break;
		case SHOW:
			show(&txl);
			break;
		case MODIFY:
			modify(&txl);
			break;
		case TEL:
			del(&txl);
			break;
		case EMPTY:
			empty(&txl);
			break;
		case SORT:
			sort(&txl);
			break;
		case SAVE:
			save(&txl);
			break;
		case EXIT:
			exit(EXIT_SUCCESS );
			break;
		}
	}

	return 0;
}

