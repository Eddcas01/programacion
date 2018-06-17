#include<iostream>
#include "4.h"
#include"8.h"
#include"3.h"
#include"6.h"
using namespace std;

int main() 
{
	int opmain = 0;
	do
	{
		system("cls");
		cout << "\n\t\t################# - MENU - ################\n";
		cout << "\t\t# 1.                                        #\n";
		cout << "\t\t# 2.                                        #\n";
		cout << "\t\t# 3. ARBOLES AVL                            #\n";
		cout << "\t\t# 4. LISTAS                                 #\n";
		cout << "\t\t# 5.                                        #\n";
		cout << "\t\t# 6. ARBOL DE OPERACIONES                   #\n";
		cout << "\t\t# 7.                                        #\n";
		cout << "\t\t# 8. FLOYD - WARSHALL                       #\n";
		cout << "\t\t# 9.                                        #\n";
		cout << "\t\t# 10.                                       #\n";
		cout << "\t\t#############################################\n";
		cout << "\t\tseleccione una opcion -> ";
		cin >> opmain;

		switch (opmain)
		{
		case 1: break;
		case 2: break;
		case 3:menu3(); break;
		case 4:menu4(); break;
		case 5: break;
		case 6:menu6(); break;
		case 7: break;
		case 8:menu8(); break;
		case 9:break;
		case 10: break;

		default:
			break;
		}
	} while (opmain!=0);
	
	
	system("pause>nul");

}