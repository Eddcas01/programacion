#pragma once
#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void push();
void numeros();
void pop(int cnt);
void dequeue(int cnt);
void Mostrar_cola(int cnt);

int vecaux[20];
string alfa[] = { "","","","","","","","","","","","","","","","","","","","" };
string vec[] = { "A","B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U","V","W","X","Y","Z" };


int cnt = 20;
void menu1() {//ESTE ERA EL MAIN
	

		int op = 0, stop = 0;
		do
		{
			system("cls");
			cout << "       ALFABETO\n=====================" << endl;
			cout << "| 1) LLENAR VECTOR   |" << endl;
			cout << "| 2) POP             |" << endl;
			cout << "| 3) DESENCOLAR      |" << endl;
			cout << "| 4) MOSTRAR         |" << endl;
			cout << "| 5) SALIR           |" << endl;
			cout << " ====================" << endl;
			cout << "INGRESE UNA OPCION -> ";
			cin >> op;
			switch (op)
			{
			case 1:
				system("cls");
				do
				{
					system("cls");
					numeros();
					push();
					Mostrar_cola(cnt);
					cout << "DESEA VOLVER A SORTEAR? (0 para salir)";
					cin >> stop;
				} while (stop != 0);
				break;
			case 2:
				system("cls");
				do
				{
					if (cnt == 0)
					{
						cout << "EL VECTOR ESTA VACIO..." << endl;
						Sleep(1500);
						stop = 0;
					}
					else
					{
						Mostrar_cola(cnt);
						pop(cnt);
						cnt = cnt - 1;
						Mostrar_cola(cnt);
						cout << "DESEA ELIMINAR OTRO LETRA? (0 para salir)";
						cin >> stop;
					}


				} while (stop != 0);
				break;
			case 3:
				system("cls");
				do
				{
					if (cnt == 0)
					{
						cout << "EL VECTOR ESTA VACIO..." << endl;
						Sleep(1500);
						stop = 0;
					}
					else
					{
						Mostrar_cola(cnt);
						dequeue(cnt);
						cnt = cnt - 1;
						Mostrar_cola(cnt);
						cout << "DESEA ELIMINAR OTRA LETRA? (0 para salir)";
						cin >> stop;
					}

				} while (stop != 0);
				break;
			case 4:
				system("cls");
				Mostrar_cola(cnt);
				system("pause>nul");
				break;

			case 5:
				cout << "SALIENDO..." << endl;
				Sleep(1500);
				break;

			default:
				cout << "OPCION NO VALIDA" << endl;
				Sleep(1500);
				break;

			}

		} while (op != 5);



	}

	///////////////////////////// PILA //////////////////////////////////////////////////
	void push()
	{
		for (int i = 0; i < 20; i++)
		{
			alfa[i] = vec[vecaux[i]];

		}
	}
	void pop(int cnt)
	{
		char l = {};
		cout << " ELIMINAR -> POSICION -> " << cnt << " LETRA -> " << alfa[cnt - 1] << endl;
		alfa[cnt] = l;
	}


	///////////////////////////////// COLA ////////////////////////////
	void dequeue(int cnt)
	{
		int cnt2 = cnt;
		cout << " ELIMINAR -> POSICION -> " << cnt - (cnt - 1) << " LETRA -> " << alfa[0] << endl;
		alfa[0] = alfa[1];
		while (cnt2 >= 0)
		{
			alfa[cnt - (cnt2 - 1)] = alfa[cnt - (cnt2 - 2)];
			cnt2--;

		}

	}
	void Mostrar_cola(int cnt)
	{

		cout << " VECTOR:" << endl;
		for (int i = 0; i < cnt * 2; i++)
		{
			cout << "=";
		}
		cout << endl;
		for (int i = 0; i < cnt; i++)
		{
			cout << alfa[i] << "|";
		}
		cout << endl;
		for (int i = 0; i < cnt * 2; i++)
		{
			cout << "=";
		}
		cout << endl << "CANTIDAD DE LETRAS ACTUALES: " << cnt << endl;
	}

	void numeros() {

		int aux = 0;

		srand(time(0));

		for (int i = 0; i < 20; i++) {
			aux = (1 + rand() % 20);

			int aux2 = 0;

			while (aux2 < i) {

				if (aux != vecaux[aux2])
					aux2++;

				else {
					aux = (1 + rand() % 20);
					aux2 = 0;

				}
			}

			vecaux[i] = aux;


		}
	}
