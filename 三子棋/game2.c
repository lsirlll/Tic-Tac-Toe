#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void game2()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };//������������

	InitBoard(board, ROW, COL);//��ʼ������Ϊ�ո�
	DisplayBoard(board, ROW, COL);//��ӡ����
	//����
	while (1)
	{
		PlayerMove1(board, ROW, COL);//���1����
		DisplayBoard(board, ROW, COL);//��ӡ����
		IsWin(board, ROW, COL);//�ж�ʤ��
		ret = IsWin(board, ROW, COL);//�����ж�ֵ
		if (ret != 'C')//����ֵ����C������Ϸ
			break;

		PlayerMove2(board, ROW, COL);//���2����
		DisplayBoard(board, ROW, COL);//��ӡ����
		IsWin(board, ROW, COL);//�ж�ʤ��
		ret = IsWin(board, ROW, COL);//�����ж�ֵ
		if (ret != 'C')//����ֵ����C������Ϸ
			break;
	}
	if (ret == 'O')
		printf("Player1 Win!\n");
	else if (ret == 'X')
		printf("Player2 Win!\n");
	else if (ret == 'Q')
		printf("ƽ��\n");
}


//���1����
void PlayerMove1(char board[ROW][COL], int row, int col)
{
	printf("Player1 Turn:>\n");
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


//���2����
void PlayerMove2(char board[ROW][COL], int row, int col)
{
	printf("Player2 Turn:>\n");
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
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("���걻ռ�ã�����������\n");
		}
		else
			printf("����Ƿ�������������\n");
	}
}