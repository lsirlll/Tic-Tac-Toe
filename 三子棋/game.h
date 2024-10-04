#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void menu();
void game1();
void game2();

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����

void PlayerMove(char board[ROW][COL], int row, int col);//�������
void ComputerMove(char board[ROW][COL], int row, int col);//��������

char IsWin(char board[ROW][COL], int row, int col);//�ж�ʤ��

int IsFull(char board[ROW][COL], int row, int col);//��������


void PlayerMove1(char board[ROW][COL], int row, int col);//���1����
void PlayerMove2(char board[ROW][COL], int row, int col);//���2����
