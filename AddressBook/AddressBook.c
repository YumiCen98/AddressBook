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
		printf(FONT_COLOR_BLUE"请输入0~8之间的选择:"COLOR_NONE);
		scanf("%d", &input);

		if((input >= 0) && (input <= 9))
		{
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
			default:
				printf(FONT_COLOR_RED"[序号有误, 重新输入]\n"COLOR_NONE);
				break;
			}
		}
		else
		{
			printf(FONT_COLOR_RED"[请输入数字]\n"COLOR_NONE);
			break;
		}
	}

	return 0;
}

