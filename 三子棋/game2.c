#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void game2()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//定义数组棋盘

	InitBoard(board, ROW, COL);//初始化棋盘为空格
	DisplayBoard(board, ROW, COL);//打印棋盘
	//下棋
	while (1)
	{
		PlayerMove1(board, ROW, COL);//玩家1下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		IsWin(board, ROW, COL);//判断胜负
		ret = IsWin(board, ROW, COL);//接收判定值
		if (ret != 'C')//返回值等于C继续游戏
			break;

		PlayerMove2(board, ROW, COL);//玩家2下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		IsWin(board, ROW, COL);//判断胜负
		ret = IsWin(board, ROW, COL);//接收判定值
		if (ret != 'C')//返回值等于C继续游戏
			break;
	}
	if (ret == 'O')
		printf("Player1 Win!\n");
	else if (ret == 'X')
		printf("Player2 Win!\n");
	else if (ret == 'Q')
		printf("平局\n");
}


//玩家1下棋
void PlayerMove1(char board[ROW][COL], int row, int col)
{
	printf("Player1 Turn:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标是否在棋盘内
		{
			if (board[x - 1][y - 1] == ' ')//判断坐标是否被占用
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}


//玩家2下棋
void PlayerMove2(char board[ROW][COL], int row, int col)
{
	printf("Player2 Turn:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标是否在棋盘内
		{
			if (board[x - 1][y - 1] == ' ')//判断坐标是否被占用
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}