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
	//�൱�ڳ�ʼ������
	static AVLTree *InitAVL(Member e); //��ʼ��
	static Status InsertAVL(AVLTree **T, Member e, bool &taller); //�������
	static Status DestroyAVL(AVLTree **T); //�ݻٲ���
	static Member SearchAVL(AVLTree *T, int key); //��������
	static Status TraverseAVL(AVLTree *T, void (*f)(Member)); //��������
	Status TraverseAVL_n(AVLTree * T, Member * p, int & index, void(*f)(Member *p, int &index, Member *data));
	Status TraverseAVL_n(AVLTree * T, int & index, void(*f)(int &index));
	static Status DeleteAVL(AVLTree **T, int key, bool &shorter); //ɾ������
	static void r_Rotate(AVLTree **p); //������ָ�����
	static void l_Rotate(AVLTree **p); //������ָ�����
	static void leftBalance(AVLTree **T); //��ƽ�����
	static void rightBalance(AVLTree **T); //��ƽ�����

public:
	Member data;  //����
	int bf;  //ƽ������
	AVLTree *lchild, *rchild; //���Һ���
};

