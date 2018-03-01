#include <stdio.h>
#include <string>
#include <iostream>
#include "ADT.h"


#define COLLSIZE 600
#define MAXSIZE 200

using namespace std;
#pragma warning(disable:4996)
void visit(Member e) {
	cout << "id:" << e.id
		<< ", name:" << e.name << endl;
}

int main() {
	ADT *adt[MAXSIZE];
	int cindex = -1, size = 0;
	FILE *f;
	Member m;
	char name[15];
	char url[40];
	int id_t;
	int op = 0;
	Member coll[COLLSIZE];
	memset(coll, 0, sizeof(Member) * COLLSIZE);
	ADT *set = nullptr;
	ADT *set_find = nullptr;
	int i = -1;
	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the ADT" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. set_init		2. set_destroy\n"
			<< "3. set_insert		4. set_remove\n"
			<< "5. set_inter		6. set_union\n"
			<< "7. set_diff		8. set_size\n"
			<< "9. set_traverse		10. set_subset\n"
			<< "11. set_equal		12. readDataFromFiles\t\n"
			<< "13. set_modify		14. set_Member\n"
			<< "15. switch ADT		16. saveDataIntoFiles\n"
			<< "17. set_insert_set	18. set_remove_set\n";
		cout << "---------------------------------" << endl;
		cout << "input your choice :" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			if (size < MAXSIZE) {
				strcpy(name, "A");
				adt[size] = new ADT();
				cindex = size++;
				set = adt[cindex];
				cout << "init finished" << endl;
				cout << "Current index:" << cindex << endl;
			}
			else {
				cout << "Init failed!" << endl;
			}
			getchar();
			getchar();
			break;
		case 2:
			if (cindex >= 0) {
				set->destroy();
				size--;
				if (size == 0)
					cindex = -1;
				else {
					for (int i = cindex; i < size; i++) {
						adt[i] = adt[i + 1];
					}
					if (cindex == size)
						set = adt[--cindex];
					else if (cindex > size)
						set = adt[0];
					else
						set = adt[cindex];
				}
				cout << "finished!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar();
			getchar();
			break;
		case 3:
			if (cindex >= 0) {
				cout << "input id :";
				cin >> m.id;
				cout << "input name :";
				cin >> m.name;
				cout << "input description :";
				cin >> m.description;
				set->insert(m);
				cout << "insert finished!" << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 4:
			if (cindex >= 0) {
				cout << "input id :";
				cin >> m.id;
				if (set->remove(m))
					cout << "remove finished!" << endl;
				else 
					cout << "remove failed!" << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 5:
			if (cindex >= 0) {
				cout << "input index of the set:(<" << size << ")";
				cin >> i;
				if (i < 0 || i > size) {
					getchar();
					getchar();
					break;
				}
				set_find = ADT::set_intersection(coll, set, adt[i]);
				AVLTree::TraverseAVL(set_find->elems, visit);
				cout << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 6:
			if (cindex >= 0) {
				cout << "input index of the set:(<" << size << ")";
				cin >> i;
				if (i < 0 || i > size) {
					getchar();
					getchar();
					break;
				}
				set_find = ADT::set_union(coll, set, adt[i]);
				AVLTree::TraverseAVL(set_find->elems, visit);
				cout << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 7:
			if (cindex >= 0) {
				cout << "input index of the set:(<" << size << ")";
				cin >> i;
				if (i < 0 || i > size) {
					getchar();
					getchar();
					break;
				}
				set_find = ADT::set_different(coll, set, adt[i]);
				AVLTree::TraverseAVL(set_find->elems, visit);
				cout << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 8:
			if (cindex >= 0) {
				cout << "Set size :" << set->getSize() << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 9:
			if (cindex >= 0) {
				cout << "The list of members:" << endl;
				AVLTree::TraverseAVL(set->elems, visit);
				cout << "end" << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 10:
			if (cindex >= 0) {
				cout << "input index of the set:(<" << size << ")";
				cin >> i;
				if (i < 0 || i > size) {
					getchar();
					getchar();
					break;
				}
				if (set->set_subset(adt[i], set)) {
					cout << "The list of members of index" << i << endl;
					AVLTree::TraverseAVL(adt[i]->elems, visit);
					cout << "The list of members of current index" << endl;
					AVLTree::TraverseAVL(set->elems, visit);
					cout << "It is Subset of current set" << endl;
				}
				else {
					cout << "Not Subset!" << endl;
				}
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 11:
			if (cindex >= 0) {
				cout << "input index of the set:(<" << size << ")";
				cin >> i;
				if (i < 0 || i > size) {
					getchar();
					getchar();
					break;
				}
				if (ADT::set_equal(set, adt[i]))
					cout << "set equal!" << endl;
				else
					cout << "set Not equal!" << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 12:
			if (cindex >= 0) {
				cout << "input file name:";
				cin >> url;
				f = fopen(url, "r");
				if (!f) {
					cout << "open file failed!" << endl;
					getchar();
					getchar();
					break;
				}
				if (set->read(f))
					cout << "Read finished!" << endl;
				else
					cout << "Read failed!" << endl;
				fclose(f);
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 13:
			if (cindex >= 0) {
				cout << "input modify id :";
				cin >> id_t;
				cout << "input member's id :";
				cin >> m.id;
				cout << "input member's name :";
				cin >> m.name;
				if (set->modify(id_t, m)) {
					cout << "modify finished!" << endl;
				}
				else {
					cout << "modify failed!" << endl;
				}
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 14:
			if (cindex >= 0) {
				cout << "input modify id :";
				cin >> id_t;

				if ((m = set->find(id_t)).id != UNINIT) {
					cout << "Find result is :" << endl;
					cout << "id :" << m.id << " ,name :" << m.name << endl;
				}
				else {
					cout << "find failed!" << endl;
				}
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 15:
			if (cindex >= 0) {
				cout << "input the index :(<" << size << ")" << endl;
				cin >> i;
				if (i > size) {
					cout << "fail!" << endl;
					getchar();
					getchar();
					break;
				}
				cindex = i;
				set = adt[cindex];
				cout << "Current index is:" << cindex << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar();
			getchar();
			break;
		case 16:
			if (cindex >= 0) {
				cout << "input file name:";
				cin >> url;
				f = fopen(url, "w");
				if (!f) {
					cout << "open file failed!" << endl;
					getchar();
					getchar();
					break;
				}
				if (set->save(f))
					cout << "Read finished!" << endl;
				else
					cout << "Read failed!" << endl;
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 17:
			if (cindex >= 0) {
				cout << "input the index :(<" << size << ")" << endl;
				cin >> i;
				if (i > size) {
					cout << "fail!" << endl;
					getchar();
					getchar();
					break;
				}
				if (id_t = set->insert(adt[i]))
					cout << "insert sucess!Insert " << id_t << " members" << endl;
				else
					cout << "insert failed!";
				
			}
			else {
				cout << "Not Init";
			}
			getchar();
			getchar();
			break;
		case 18:
			if (cindex >= 0) {
				cout << "input the index :(<" << size << ")" << endl;
				cin >> i;
				if (i > size) {
					cout << "fail!" << endl;
					getchar();
					getchar();
					break;
				}
				if (id_t = set->remove(adt[i]))
					cout << "remove sucess!remove " << id_t << " members" << endl;
				else
					cout << "remove failed!";

			}
			else {
				cout << "Not Init";
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