#include <stdio.h>
#include <string>
#include <iostream>
#include "AVLTree.h"

using namespace std;

void visit(Member e) {
	cout << "id:" <<e.id
		<< ", name:" << e.name << endl;
}

#pragma warning(disable:4996)
int main() {
	int op = 0;
	AVLTree *T = nullptr;
	Member e;
	int id; bool taller = false, shorter = false;
	string des;
	char name[100];
	FILE *file;
	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the AVL" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. Init AVL\t2. Destroy AVL\n"
			<< "3. Search AVL\t4. Insert AVL\n"
			<< "5. Delete AVL\t6. Traverse AVL" << endl
			<< "7. input data from files" << endl;
		cout << "---------------------------------" << endl;
		cout << "input your choice :" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "input the id: ";
			cin >> e.id;
			T = AVLTree::InitAVL(e);
			cout << "init finish!" << endl;
			getchar();
			getchar();
			break;
		case 2:
			if (AVLTree::DestroyAVL(&T)) {
				T = nullptr;
				cout << "destroy finished!" << endl;
			}
			else {
				cout << "destroy failed!" << endl;
			} 
			getchar(); getchar();
			break;
		case 3:
			cout << "input the id :";
			cin >> e.id;
			e = AVLTree::SearchAVL(T, e.id);
			if (e.id == UNINIT) {
				cout << "Not found!" << endl;
			}
			else {
				cout << "find it!\nID:" << e.id << endl;
			}
			getchar();
			getchar();
			break;
		case 4:
			cout << "input the id: ";
			cin >> e.id;
			AVLTree::InsertAVL(&T, e, taller);
			cout << "insert finish!" << endl;
			getchar();
			getchar();
			break;
		case 5:
			cout << "input the delete id:";
			cin >> id;
			if (AVLTree::DeleteAVL(&T, id, shorter)) {
				cout << "delete finished!" << endl;
			}
			else {
				cout << "delete failed!" << endl;
			}
			getchar();
			getchar();
			break;
		case 6:
			if (AVLTree::TraverseAVL(T, visit)) {
				cout << "Traverse finished!" << endl;
			} else {
				cout << "Traverse failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 7:
			file = fopen("friends.txt", "r");
			while (fscanf(file, "%d%s", &e.id, name) > 0)
			{
				e.name = name;
				AVLTree::InsertAVL(&T, e, taller);
			}
			cout << "read finished!" << endl;
			e.name = "";
			fclose(file);
			getchar(); getchar();
		default:
			break;
		}
	}
	return 0;
}