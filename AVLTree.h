#pragma once
#include "DataDef.h"

#define LH +1
#define EH 0
#define RH -1
#define RIGHT 1
#define LEFT 0
#define UNINIT -10010

typedef int Status;

class AVLTree
{
public:
	AVLTree();
	AVLTree(Member e);
	//相当于初始化操作
	~AVLTree();
	static AVLTree *InitAVL(Member e); //初始化
	static Status InsertAVL(AVLTree **T, Member e, bool &taller); //插入操作
	static Status DestroyAVL(AVLTree &T); //摧毁操作
	static Status SearchAVL(AVLTree &T); //搜索操作
	static Status TraverseAVL(AVLTree &T); //遍历操作

	static void r_Rotate(AVLTree **p); //右旋的指针更改
	static void l_Rotate(AVLTree **p); //左旋的指针更改
	static void leftBalance(AVLTree **T); //左平衡操作
	static void rightBalance(AVLTree **T); //右平衡操作

public:
	Member data;
	int bf;  //平衡因子
	AVLTree *lchild, *rchild; //左右孩子
};

