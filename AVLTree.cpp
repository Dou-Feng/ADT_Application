#include "AVLTree.h"



AVLTree::AVLTree()
{
	this->bf = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
}

AVLTree::AVLTree(Member e) {
	this->bf = 0;
	this->lchild = nullptr;
	this->rchild = nullptr;
	this->data = e;
}
AVLTree::~AVLTree() {

}

/*对以当前结点为根的二叉排序树作左旋处理*/
void AVLTree::l_Rotate(AVLTree **p) {

	AVLTree *rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

/*对以当前结点为根的二叉排序树作右旋处理*/
void AVLTree::r_Rotate(AVLTree **p) {

	AVLTree *rc = (*p)->lchild;
	(*p)->lchild = rc->rchild;
	rc->rchild = *p;
	*p = rc;
}

/*对以指针T所指结点为根的二叉树作左平衡旋转处理
算法结束时，指针T指向新的根结点*/
void AVLTree::leftBalance(AVLTree **T) {
	AVLTree *lc = (*T)->lchild;  //lc指向*T的左子树根结点
	AVLTree *rd = nullptr;
	switch (lc->bf) {  //检查*T的左子树的平衡度，并作相应的平衡处理
	case LH:  //新结点插入在*T的左孩子的左子树上，要做单右旋处理
		(*T)->bf = lc->bf = EH;
		r_Rotate(T);
		break;
	case RH:  //新结点插入在*T的左孩子的右子树上，要做双旋处理
		rd = lc->rchild;  //指向*T的左孩子的右子树的根结点
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		default:
			break;
		} //end switch(rd->bf)
		rd->bf = EH;
		l_Rotate(&(*T)->lchild);
		r_Rotate(T);
	} //end switch(lc->bf)
}

/*对以指针T所指结点为根的二叉树作左平衡旋转处理
算法结束时，指针T指向新的根结点*/
void AVLTree::rightBalance(AVLTree **T) {
	AVLTree *rc = (*T)->rchild;  //lc指向*T的右子树根结点
	AVLTree *ld = nullptr;
	switch (rc->bf) {  //检查*T的右子树的平衡度，并作相应的平衡处理
	case RH:  //新结点插入在*T的右孩子的右子树上，要做单左旋处理
		(*T)->bf = rc->bf = EH;
		l_Rotate(T);
		break;
	case LH:  //新结点插入在*T的右孩子的左子树上，要做双旋处理
		ld = rc->lchild;  //指向*T的右孩子的左子树的根结点
		switch (ld->bf)
		{
		case RH:
			(*T)->bf = LH;
			rc->bf = EH;
			break;
		case EH:
			(*T)->bf = rc->bf = EH;
			break;
		case LH:
			(*T)->bf = EH;
			rc->bf = RH;
			break;
		default:
			break;
		} //end switch(ld->bf)
		ld->bf = EH;
		r_Rotate(&(*T)->rchild);
		l_Rotate(T);
	} //end switch(rc->bf)
}

/*递归调用摧毁函数，直到摧毁整棵树*/
Status AVLTree::DestroyAVL(AVLTree &p) {

	if (p.lchild != nullptr) {
		DestroyAVL(*p.lchild);
	}
	if (p.rchild != nullptr) {
		DestroyAVL(*p.rchild);
	}
	p.~AVLTree();
	return 1;
}

AVLTree *AVLTree::InitAVL(Member e) {
	return new AVLTree(e);
}

/*若在平衡二叉树T中不存在和e有相同关键字的结点，则插入一个数据元素
为e的新结点，并返回1，否则返回0,。若因插入而使二叉排序树失去平衡，则作
平衡处理。布尔值taller反应T长高与否*/ 
Status AVLTree::InsertAVL(AVLTree **T, Member e, bool &taller) {
	if (!*T) { //当T没有被初始化时
		*T = new AVLTree();
		(*T)->data = e;
		(*T)->bf = EH;
		taller = true;
	}
	else {
		if (e.id == (*T)->data.id) {
			taller = false;
			return 0;
		} 
		if (e.id < (*T)->data.id) {
			if (!InsertAVL(&(*T)->lchild, e, taller)) return 0;
			if (taller) {
				switch ((*T)->bf) {
				case LH:
					leftBalance(T);
					taller = false;
					break;
				case RH:
					(*T)->bf = EH;
					taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					taller = true;
					break;
				default:
					break;
				} //end switch
			} //end if (taller)
		} 
		else {
			if (!InsertAVL(&(*T)->rchild, e, taller)) return 0;
			if (taller) 
				switch ((*T)->bf) {
				case LH:
					(*T)->bf = EH;
					taller = false;
					break;
				case EH:
					(*T)->bf = RH;
					taller = true;
					break;
				case RH:
					rightBalance(T);
					taller = false;
					break;
				} //end switch
		} //end else
	} // end else
	return 1;
}

