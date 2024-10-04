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
	char board[ROW][COL] = { 0 };//������������

	InitBoard(board, ROW, COL);//��ʼ������Ϊ�ո�
	DisplayBoard(board, ROW, COL);//��ӡ����
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);//��ӡ����
		IsWin(board, ROW, COL);//�ж�ʤ��
		ret = IsWin(board, ROW, COL);//�����ж�ֵ
		if (ret != 'C')//����ֵ����C������Ϸ
			break;


		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);//��ӡ����
		IsWin(board, ROW, COL);//�ж�ʤ��
		ret = IsWin(board, ROW, COL);//�����ж�ֵ
		if (ret != 'C')//����ֵ����C������Ϸ
			break;
	}
	if (ret == 'O')
		printf("Player Win!\n");
	else if (ret == 'X')
		printf("Computer Win\n");
	else if(ret == 'Q')
		printf("ƽ��\n");
}


//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//��
	{
		int j = 0;
		for (j = 0; j < col; j++)//��
		{
			board[i][j] = ' ';
		}
	}
}


//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//����һ��'|'����ӡ
				printf("|");
		}
		printf("\n");//����һ�к���
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


//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("Player Turn:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж������Ƿ���������
		{
			if (board[x - 1][y - 1] == ' ')//�ж������Ƿ�ռ��
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
				printf("���걻ռ�ã�����������\n");
		}
		else
			printf("����Ƿ�������������\n");
	}
}


//��������
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


//�ж�ʤ��
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]//һ��������������ڵ����
				 && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	//��
	for (i = 0; i < row - 2; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]
				&& board[i][j] != ' ') // ȷ�����ǿո�
			{
				return board[i][j]; // ����ƥ����ַ�
			}
		}
	}

	//�Խ������ϵ�����
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

	//�Խ������µ�����
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

	//ƽ��
	if (IsFull(board, ROW, COL))
	{
		return ('Q');
	}

	return ('C');
}
	

//�������� ����������Ƿ��п���ĵط����ж��Ƿ�ƽ��
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