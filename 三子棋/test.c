#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}

	} while (input);

	return 0;
}