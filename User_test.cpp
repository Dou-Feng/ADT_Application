#include <stdio.h>
#include <string>
#include <iostream>
#include "User.h"

#define COLLSIZE 600
#define MAXSIZE 200

using namespace std;
#pragma warning(disable:4996)
void visit(Member e) {
	cout << "id:" << e.id
		<< ", name:" << e.name << endl;
}

int main() {
	User *users[MAXSIZE];
	int cindex = -1, size = 0;
	int id1, id2;
	enum KINDS kind = FRIEND;
	Member m;
	int int_s;
	char name[20];
	char des[200];

	int op = 0;
	Member coll[COLLSIZE];
	memset(coll, 0, sizeof(Member) * COLLSIZE);

	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the ADT" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. user init  \t2. user destroy\n"
			<< "3. insert  \t4. remove\n"
			<< "5. modify\t6. find\n"
			<< "7. interfriends\t8. interfans\n"
			<< "9. interfolloweds\t10. read\n"
			<< "11. save\t12. switch users\n";
		cout << "---------------------------------" << endl;
		cout << "input your choice :";
		cin >> op;
		switch (op)
		{
		case 1:
			if (size < MAXSIZE) {
				strcpy(name, "A");
				users[size] = new User(size + 1, name);
				cindex = size++;
			}
			break;
		case 2:
			if (cindex > 0) {
				users[cindex]->~User();
				cout << "finished!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 3:
			if (cindex > 0) {
				cout << "input your choice : (1. friends 2. fans 3. followed)";
				cin >> int_s;
				if (int_s == 1) {
					kind = FRIEND;
				}
				else if (int_s == 2) {
					kind = FAN;
				}
				else if (int_s == 3) {
					kind = FOLLOWED;
				}
				else {
					cout << "failed!" << endl;
					break;
				}
				cout << "input the id :"; cin >> m.id;
				cout << "input the name :"; cin >> m.name;
				cout << "input the description :"; cin >> m.description;
				if (users[cindex]->add(kind, m))
					cout << "finished!" << endl; 
				else 
					cout << "failed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 4:
			if (cindex > 0) {
				cout << "input your choice : (1. friends 2. fans 3. followed)";
				cin >> int_s;
				if (int_s == 1) {
					kind = FRIEND;
				}
				else if (int_s == 2) {
					kind = FAN;
				}
				else if (int_s == 3) {
					kind = FOLLOWED;
				}
				else {
					cout << "failed!" << endl;
					break;
				}
				cout << "input the id :"; cin >> m.id;
				if (users[cindex]->remove(kind, m))
					cout << "finished!" << endl;
				else
					cout << "failed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 5:
			if (cindex > 0) {
				cout << "input your choice : (1. friends 2. fans 3. followed)";
				cin >> int_s;
				if (int_s == 1) {
					kind = FRIEND;
				}
				else if (int_s == 2) {
					kind = FAN;
				}
				else if (int_s == 3) {
					kind = FOLLOWED;
				}
				else {
					cout << "failed!" << endl;
					break;
				}
				cout << "input the id :"; cin >> m.id;
				cout << "input the name :"; cin >> m.name;
				cout << "input the description"; cin >> m.description;
				if (users[cindex]->modify(kind, m.id, m))
					cout << "finished!" << endl;
				else
					cout << "failed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 6:
			if (cindex > 0) {
				cout << "input your choice : (1. friends 2. fans 3. followed)";
				cin >> int_s;
				if (int_s == 1) {
					kind = FRIEND;
				}
				else if (int_s == 2) {
					kind = FAN;
				}
				else if (int_s == 3) {
					kind = FOLLOWED;
				}
				else {
					cout << "failed!" << endl;
					break;
				}
				cout << "input the id :"; cin >> m.id;
				if ((m = users[cindex]->find(kind, m)).id != UNINIT) {
					visit(m);
					cout << "finished!" << endl;
				}
				else
					cout << "failed!" << endl;
			}
			else {
				cout << "failed!" << endl;
			}
			getchar(); getchar();
			break;
		case 7:
			if (size > 1) {
				cout << "input two user's id :";
				cin >> id1;
				cin >> id2;
				if (id1 > size || id2 > size) {
					cout << "failed" << endl;
					break;
				}
				else {
					User::InterFriends(coll, users[id1 - 1], users[id2 - 1]);
				}
			}
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			
			break;
		case 11:
			
			break;
		case 12:
			
			break;
		
		default:
			break;
		}
	}
	return 0;
}