#include <stdio.h>
#include <string>
#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
	int op = 0;
	AVLTree *T = nullptr;
	Member e;
	int id; bool taller = false;
	string name;
	string des;
	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the AVL" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. Init AVL\t2. Destroy AVL\n"
			<< "3. Search AVL\t4. Insert AVL\n"
			<< "5. Delete AVL\t6. Traverse AVL" << endl;
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

			break;
		case 3:

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

			break;
		case 6:

			break;
		default:
			break;
		}
	}
	return 0;
}