#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void menu();
void game1();
void game2();

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘

void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋

char IsWin(char board[ROW][COL], int row, int col);//判断胜负

int IsFull(char board[ROW][COL], int row, int col);//遍历棋盘


void PlayerMove1(char board[ROW][COL], int row, int col);//玩家1下棋
void PlayerMove2(char board[ROW][COL], int row, int col);//玩家2下棋
