#include <stdio.h>
#include <string>
#include <iostream>
#include "AVLTree.h"

using namespace std;

void visit(Member e) {
	cout << "id:" <<e.id
		<< ", name:" << e.name << endl;
}
void f(Member e) {
	cout << " " << e.id << " ";
}

#pragma warning(disable:4996)
int main() {
	int op = 0;
	AVLTree *T = nullptr;
	Member e;
	int id; bool taller = false, shorter = false;
	string des;
	char name[100];
	char url[30];
	FILE *file;
	char file_name[20];
	int read_time = 0;
	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the AVL" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. Init AVL	2. Destroy AVL\n"
				<< "3. Search AVL	4. Insert AVL\n"
				<< "5. Delete AVL	6. Traverse AVL" << endl
				<< "7. read		8. save\n 9. LevelTraverse" << endl;
		cout << "---------------------------------" << endl;
		cout << "input your choice :" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			if (!T) {
				cout << "input id:";
				cin >> id;
				T = new AVLTree(id);
				cout << "init finish!" << endl;
			}
			else {
				cout << "Init already" << endl;
			}
			getchar();
			getchar();
			break;
		case 2:
			if (T) {
				if (AVLTree::DestroyAVL(&T)) {
					T = nullptr;
					cout << "destroy finished!" << endl;
					T = nullptr;
				}
				else {
					cout << "destroy failed!" << endl;
				}
			}
			else
				cout << "Not init" << endl;
			getchar(); getchar();
			break;
		case 3:
			if (T) {
				cout << "input the id :";
				cin >> e.id;
				e = AVLTree::SearchAVL(T, e.id);
				if (e.id == UNINIT) {
					cout << "Not found!" << endl;
				}
				else {
					cout << "find it!\nID:" << e.id << endl;
				}
			} 
			else
				cout << "Not init" << endl;
			getchar();
			getchar();
			break;
		case 4:
			if (T) {
				cout << "input the id: ";
				cin >> e.id;
				AVLTree::InsertAVL(&T, e, taller);
				cout << "insert finish!" << endl;
			}
			else
				cout << "Not init" << endl;
			getchar();
			getchar();
			break;
		case 5:
			if (T) {
				cout << "input the delete id:";
				cin >> id;
				if (AVLTree::DeleteAVL(&T, id, shorter)) {
					cout << "delete finished!" << endl;
				}
				else {
					cout << "delete failed!" << endl;
				}
			}
			else
				cout << "Not init" << endl;
			getchar();
			getchar();
			break;
		case 6:
			if (T)
				if (AVLTree::TraverseAVL(T, visit)) {
					cout << "Traverse finished!" << endl;
				} else {
					cout << "Traverse failed!" << endl;
				}
			else
				cout << "Not init" << endl;
			getchar(); getchar();
			break;
		case 7:
			if (T) {
				cout << "input filename:";
				cin >> url;
				file = fopen(url, "r");
				if (!file) {
					cout << "file open failed!" << endl;
					getchar();
					getchar();
					break;
				}
				if ((read_time = AVLTree::file_read(&T, file)) > 0)
					cout << "read finished!" << ", time:" << read_time << endl;
				strcpy(e.name, "");
				fclose(file);
			}
			else
				cout << "Not init" << endl;
			getchar(); getchar();
			break;
		case 8:
			if (T) {
				cout << "input filename:";
				cin >> url;
				file = fopen(url, "w");
				if (!file) {
					cout << "file open failed!" << endl;
					getchar();
					getchar();
					break;
				}
				if (AVLTree::file_save(T, file)) {
					cout << "save finished!" << endl;
				}
				else {
					cout << "save failed!" << endl;
				}
				fclose(file);
			}
			else
				cout << "Not init" << endl;
			getchar();
			getchar();
			break;
		case 9:
			if (T) {
				AVLTree::levelOrderTraverse(T, f);

			}
			else {
				cout << "Not init!" << endl;
			}
			getchar();
			getchar();
			break;
		default:
			break;
		}
	}
	return 0;
}