#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void menu()
{
	printf("******************************************************\n");
	printf("******************************************************\n");
	printf("*****  1. computer play  2.player play  0. exit  *****\n");
	printf("******************************************************\n");
	printf("******************************************************\n");
}


void game1()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//定义数组棋盘

	InitBoard(board, ROW, COL);//初始化棋盘为空格
	DisplayBoard(board, ROW, COL);//打印棋盘
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		IsWin(board, ROW, COL);//判断胜负
		ret = IsWin(board, ROW, COL);//接收判定值
		if (ret != 'C')//返回值等于C继续游戏
			break;


		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//打印棋盘
		IsWin(board, ROW, COL);//判断胜负
		ret = IsWin(board, ROW, COL);//接收判定值
		if (ret != 'C')//返回值等于C继续游戏
			break;
	}
	if (ret == 'O')
		printf("Player Win!\n");
	else if (ret == 'X')
		printf("Computer Win\n");
	else if(ret == 'Q')
		printf("平局\n");
}


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//行
	{
		int j = 0;
		for (j = 0; j < col; j++)//列
		{
			board[i][j] = ' ';
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//最后的一个'|'不打印
				printf("|");
		}
		printf("\n");//打完一行后换行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}


//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("Player Turn:>\n");
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


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("Computer Turn:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}


//判断胜负
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//行
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]//一行随便有三个相邻的相等
				 && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	//列
	for (i = 0; i < row - 2; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]
				&& board[i][j] != ' ') // 确保不是空格
			{
				return board[i][j]; // 返回匹配的字符
			}
		}
	}

	//对角线左上到右下
	for (i = 0; i < row-2; i++)
	{
		for (j = 0; j < col-2; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2]
				 && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	//对角线左下到右上
	for (i = 0; i < row-2; i++)
	{
		for (j = 2; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2]
				 && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	//平局
	if (IsFull(board, ROW, COL))
	{
		return ('Q');
	}

	return ('C');
}
	

//遍历棋盘 检查棋盘上是否还有空余的地方以判断是否平局
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}

	return 1;
}