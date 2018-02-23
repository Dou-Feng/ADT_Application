#include "AVLTree.h"
#include <stack>


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


/*���Ե�ǰ���Ϊ���Ķ�������������������*/
void AVLTree::l_Rotate(AVLTree **p) {

	AVLTree *rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

/*���Ե�ǰ���Ϊ���Ķ�������������������*/
void AVLTree::r_Rotate(AVLTree **p) {

	AVLTree *rc = (*p)->lchild;
	(*p)->lchild = rc->rchild;
	rc->rchild = *p;
	*p = rc;
}

/*����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
�㷨����ʱ��ָ��Tָ���µĸ����*/
void AVLTree::leftBalance(AVLTree **T) {
	AVLTree *lc = (*T)->lchild;  //lcָ��*T�������������
	if (lc == nullptr) return;
	AVLTree *rd = nullptr;
	switch (lc->bf) {  //���*T����������ƽ��ȣ�������Ӧ��ƽ�⴦��
	case LH:  //�½�������*T�����ӵ��������ϣ�Ҫ������������
		(*T)->bf = lc->bf = EH;
		r_Rotate(T);
		break;
	case EH:  //deleteAVL��Ҫ��insertAVL�ò���  
		(*T)->bf = LH;
		lc->bf = RH;
		r_Rotate(T);
		break;
	case RH:  //�½�������*T�����ӵ��������ϣ�Ҫ��˫������
		rd = lc->rchild;  //ָ��*T�����ӵ��������ĸ����
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

/*����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����
�㷨����ʱ��ָ��Tָ���µĸ����*/
void AVLTree::rightBalance(AVLTree **T) {
	AVLTree *rc = (*T)->rchild;  //lcָ��*T�������������
	AVLTree *ld = nullptr;
	switch (rc->bf) {  //���*T����������ƽ��ȣ�������Ӧ��ƽ�⴦��
	case RH:  //�½�������*T���Һ��ӵ��������ϣ�Ҫ������������
		(*T)->bf = rc->bf = EH;
		l_Rotate(T);
		break;
	case EH:  //deleteAVL��Ҫ��insertAVL�ò���  
		(*T)->bf = RH;
		rc->bf = LH;
		l_Rotate(T);
		break;
	case LH:  //�½�������*T���Һ��ӵ��������ϣ�Ҫ��˫������
		ld = rc->lchild;  //ָ��*T���Һ��ӵ��������ĸ����
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

/*�ݹ���ôݻٺ�����ֱ���ݻ�������*/
Status AVLTree::DestroyAVL(AVLTree **p) {
	if (*p == nullptr)
		return 0;
	if ((*p)->lchild != nullptr) {
		DestroyAVL(&(*p)->lchild);
	}
	if ((*p)->rchild != nullptr) {
		DestroyAVL(&(*p)->rchild);
	}
	if (*p != nullptr) {
		free(*p);
		return 1;
	}
	else {
		return 0;
	}
}

/*������㣬AVL�������ǳ�Ѹ�٣�ʱ��������log������*/
Member AVLTree::SearchAVL(AVLTree * T, int key)
{
	Member aT;
	AVLTree *p = T;
	while (p != nullptr)
	{
		if (key < p->data.id) {
			p = p->lchild;
		}
		else if (key > p->data.id) {
			p = p->rchild;
		}
		else if (key == p->data.id) {
			aT = p->data;
			return aT;
		}
	}
	return aT;
}

/*��ʼ���������൱�������˹�������*/
AVLTree *AVLTree::InitAVL(Member e) {
	return new AVLTree(e);
}

/*����ƽ�������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��
Ϊe���½�㣬������1�����򷵻�0,����������ʹ����������ʧȥƽ�⣬����
ƽ�⴦������ֵtaller��ӦT�������*/ 
Status AVLTree::InsertAVL(AVLTree **T, Member e, bool &taller) {
	if (!*T) { //��Tû�б���ʼ��ʱ
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

/*����AVL��ʹ�ú���ָ��*/
Status AVLTree::TraverseAVL(AVLTree *T, void (*f)(Member)) {
	if (T == nullptr)
		return 0;
	if (T != nullptr)
		f(T->data);
	if (T->lchild != nullptr) {
		TraverseAVL(T->lchild, f);
	}
	if (T->rchild != nullptr) {
		TraverseAVL(T->rchild, f);
	}
	return 1;
}

/*����ƽ��Ķ���������t�д��ں�e����ͬ�ؼ��ֵĽ�㣬��ɾ��֮
������true�����򷵻�false������ɾ����ʹ����������
ʧȥƽ�⣬����ƽ����ת������������shorter��ӳt�䰫���
*/
Status AVLTree::DeleteAVL(AVLTree ** T, int key, bool & shorter)
{
	if (*T == nullptr)
		return 0;
	if (key == (*T)->data.id) {
		AVLTree *q = nullptr;
		if ((*T)->lchild == nullptr) {
			q = *T;
			*T = (*T)->rchild;
			delete q;
			shorter = true;
		}
		else if ((*T)->rchild == nullptr) {
			q = (*T);
			*T = (*T)->lchild;
			delete q;
			shorter = true;
		}
		else {
			q = (*T)->lchild;
			while (q->rchild) {
				q = q->rchild;
			}
			(*T)->data = q->data;
			DeleteAVL(&(*T)->lchild, q->data.id, shorter);
			if (shorter) { //����ԭ���ƽ����Ҫ��ת
				switch ((*T)->bf) {
				case LH:
					(*T)->bf = EH;
					shorter = true;
					break;
				case EH:
					(*T)->bf = RH;
					shorter = false;
				case RH:
					if ((*T)->rchild->bf == EH) {
						shorter = false;
					}
					else
						shorter = true;
					rightBalance(T);
					break;
				}
			}
		}
	}
	else if (key < (*T)->data.id) {
		if (!DeleteAVL(&(*T)->lchild, key, shorter)) {
			return 0;
		}
		if (shorter) {
			switch ((*T)->bf) {
			case LH:
				(*T)->bf = EH;
				shorter = true;
				break;
			case EH:
				(*T)->bf = RH;
				shorter = false;
			case RH:
				if ((*T)->rchild->bf == EH) {
					shorter = false;
				}
				else
					shorter = true;
				rightBalance(T);
				break;
			}
		}
	} 
	else {
		if (!DeleteAVL(&(*T)->rchild, key, shorter)) {
			return false;
		}
		if (shorter) {
			switch ((*T)->bf) {
			case LH:
				leftBalance(T);
				if ((*T)->lchild->bf == EH) {
					shorter = false;
				} else
					shorter = true;
			case EH:
				(*T)->bf = LH;
				shorter = false;
			case RH:
				(*T)->bf = EH;
				shorter = true;
				break;
			}
		}
	}
	return 1;
}

