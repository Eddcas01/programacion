#pragma once

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int M1[50][50];//RUTAS
int M2[50][50];//ESTADOS 
int n = 0, cntb = 0, k = 0, salir = 0, ok = 0, op = 0;

void ingreso(int n)
{
	/////////////////////////// LLENADO DE M1 /////////////////////////////////////////////////
	cout << endl << endl << "\t*******" << endl;
	cout << "\t*----->MATRIZ<----*" << endl;
	cout << "\t*******" << endl << endl;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i != j)
			{
				cout << "\tIngrese dato en posocion (" << j << "," << i << ")" << " -> ";
				cin >> M1[j][i];
				if (M1[j][i] == -1)
				{
					M1[j][i] = 1000000;
				}
			}
			else
			{
				M1[j][i] = 0;
			}

		}
	}
	/////////////////////////// LLENADO DE M2 /////////////////////////////////////////////////
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i != j)
			{

				M2[j][i] = 1 + i;
			}
			else
			{
				M2[j][i] = 0;
			}

		}
	}
}
int digitos(int x) {//devuelve el numero de digitos de un numero
	int ndig = 0;

	while (x > 0)
	{
		x = x / 10;
		ndig++;
	}
	return ndig;
}
int ndigitos(int x) //devuelve el mayor numero de digitos de los numeros de la matriz
{
	int a = 0, b = 0;
	for (int j = 0; j < x; j++)
	{
		for (int i = 0; i < x; i++)
		{
			a = digitos(M1[j][i]);
			if (a == digitos(1000000))
			{
				a = 0;
			}
			if (a>b)
			{
				b = a;
			}
		}
	}
	return b;
}

void Imprimir(int n)
{
	int l = 0, g = 1, h = 0, dif = 0;
	string esp = "";
	dif = ((ndigitos(n)*n) + ((n) * 2) + (n * 2) + 3) - 21;//diferencia enre longitud del encabezado 1 y largo de la matriz 1
	if (dif<0)//si la diferencia es negativa
	{
		dif = 0;
	}
	while (h<dif)//espaciado del encabezado 2 
	{
		esp += " "; h++;
	}
	cout << endl << endl << "\t********		" << esp << "********" << endl;
	cout << "\t*-----> MATRIZ <----*		" << esp << "----> ESTADOS <----" << endl;
	cout << "\t********		" << esp << "********" << endl << endl;
	for (int j = 0; j < n; j++)//columnas
	{
		cout << "\t";
		///////////////////// IMPRESION MATRIZ 1 ///////////////////////////////////
		for (int i = 0; i < n; i++)//filas matriz 1
		{
			if (M1[j][i] == 1000000 || M1[j][i] == 0)//si es infinito o cero
			{
				g = 0;
				dif = ndigitos(n) - 1;
				esp = "";
				while (g<dif)
				{
					esp += " ";
					g++;
				}
				cout << "[" << "-" << esp << "]  ";
			}
			else//un dato normal
			{
				l = 0;
				dif = ndigitos(n) - digitos(M1[j][i]);
				esp = "";
				while (l<dif)
				{
					esp += " ";
					l++;
				}
				cout << "[" << M1[j][i] << esp << "]  ";
			}

		}
		esp = "";
		h = 0;
		dif = 21 - ((ndigitos(n)*n) + ((n) * 2) + (n * 2) + 3);//diferencia enre longitud del encabezado 1 y largo de la matriz 1
		if (dif<0)//si la diferencia es negativa
		{
			dif = 0;
		}
		while (h<dif)//espaciado del encabezado 2 
		{
			esp += " "; h++;
		}
		cout << "		" + esp;
		//////////////////////// IMPRESION MATRIZ 2 ///////////////////////////
		for (int i = 0; i < n; i++)//filas matriz 2
		{
			if (M2[j][i] == 0)//si el dato es cero
			{
				g = 0;
				dif = ndigitos(n) - 1;
				esp = "";
				while (g<dif)
				{
					esp += " ";
					g++;
				}
				cout << "[" << "-" << esp << "]  ";
			}
			else // un dato normal
			{
				l = 0;
				dif = ndigitos(n) - digitos(M2[j][i]);
				esp = "";
				while (l<dif)
				{
					esp += " ";
					l++;
				}
				cout << "[" << M2[j][i] << esp << "]  ";
			}
		}
		cout << endl;
	}
}
void FW(int n, int f1, int c1, int f2, int c2, int ok)
{
	if (salir == n)// sentinela  de salida luego de terminar ciclos completos en vertical con cada una de las horizontales
	{
		return;
	}
	else {

		if (k == n)// sentinela de ciclo completo en vertical
		{
			salir++;
			if (ok == 0)
			{
				cout << "\n\tOPERANDO (" << salir << "," << salir << ")\n";
				Imprimir(n);
			}
			k = 0;
			FW(n, 0, c1 + 1, f2 + 1, 0, ok);
		}
		if (cntb == n)//sentinela  de ciclos completo en horizontal
		{
			cntb = 0;
			k++;
			FW(n, f1 + 1, c1, f2, 0, ok);
		}
		else {
			if (M1[f1][c1] != 0)//si el valor pos 1 es vacio
			{
				if (M1[f2][c2] != 0)//si el valor  pos 2 es vacio
				{
					if (M1[f1][c2] != 0) // si la interseccion entre pos 1 y pos 2  es vacia
					{
						if (f1 != f2)
						{
							if (M1[f1][c1] + M1[f2][c2] < M1[f1][c2])
							{
								M1[f1][c2] = M1[f1][c1] + M1[f2][c2];
								M2[f1][c2] = f2 + 1;// cambio en matriz de estados
							}
							cntb++;//saltos en horizontal
							FW(n, f1, c1, f2, c2 + 1, ok);
						}
						else
						{
							FW(n, f1, c1, f2 + 1, c2 + 1, ok);// si se cruzan las posiciones en la misma fila, se avanzara sin contar
						}								 // ya que es el renglon en el que se esta trabajando


					}
					else
					{
						cntb++;//saltos en horizontal
						FW(n, f1, c1, f2, c2 + 1, ok);// si la interseccion entre pos 1 y pos 2 es vacia se pasa a la siguiente posocion de fila
					}
				}
				else
				{
					cntb++;//saltos en horizontal
					FW(n, f1, c1, f2, c2 + 1, ok);//si el valor  pos 2 es vacio se pasa a la sifuiente posicion de fila
				}
			}
			else
			{
				k++;//saltos en vectical
				FW(n, f1 + 1, c1, f2, c2, ok);//si el valor a es vacio se pasa al siguiente valor de columna
			}
		}
	}

}

void menu8() { // ESTE ERA EL MAIN
	int res = 0;
	do
	{
	
		salir = 0, cntb = 0, k = 0, n = 0;	cout << endl << endl << "\t**********" << endl;
		cout << "\t*----- >FLoyd Warshall <----*" << endl;
		cout << "\t***********" << endl << endl;

		cout << "\t--> Debera ingresar dato por dato <-- \n";
		cout << "\tIngrese tamanio para la Matriz Cuadrada -> ";
		cin >> n;
		cout << "\tPara representar infinito ingrese -1" << endl;
		ingreso(n);
		do
		{

			system("cls");
			op = 0;
			cout << endl << endl << "\t**********" << endl;
			cout << "\t*----- >FLoyd Warshall <----*" << endl;
			cout << "\t***********" << endl << endl;
			cout << "\t0) Ver Matrices por ciclos \n ";
			cout << "\t1) Ver Reslutado Directo  \n";
			cout << "\t2) Matriz nueva \n ";
			cout << "\t3) Salir\n ";
			cout << "\t-> ";
			cin >> op;
			if (op == 1)
			{
				res = 1;
			}
			if (res == 0)
			{
				if (op == 0)
				{
					cout << "\n\tMATRIZ ORIGINAL\n";
				}
				if (op != 2 && op != 3 && op != 1)
				{
					Imprimir(n);
				}
				if (op == 1 || op == 0)
				{
					FW(n, 0, 0, 0, 0, op);
					if (op == 0 || op == 1)
					{
						cout << "\n\tRESULTADO\n";
						Imprimir(n);
					}
				}
			}
			else
			{
				if (op == 1 || op == 0)
				{
					FW(n, 0, 0, 0, 0, op);
					cout << "\n\tRESULTADO\n";
					Imprimir(n);
				}

			}

			system("pause>nul");
		} while (op != 3 && op != 2);
	} while (op == 2);
}




