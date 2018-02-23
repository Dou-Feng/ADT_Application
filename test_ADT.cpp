#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int op = 0;
	while (op >= 0)
	{
		system("cls");	printf("\n\n");
		cout << "\tTest for the ADT" << endl;
		cout << "---------------------------------" << endl;
		cout << "1. set_init  \t2. set_destroy\n"
			<< "3. set_insert  \t4. set_remove\n"
			<< "5. set_intersection\t6. set_union\n" 
			<< "7. set_diffrence     \t8. set_size\n" 
			<< "9. set_member     \t10. set_subset" << endl;
		cout << "---------------------------------" << endl;
		cout << "input your choice :" << endl;
		cin >> op;
		switch (op)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		default:
			break;
		}
	}
	return 0;
}