#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;



struct datos {
	string narch;
	string cant_h;
	string usuario;
}data;
/*                Estructura de los nodo5s de la cola
------------------------------------------------------------------------*/
struct nodo5
{
	datos dato;
	int nro;
	struct nodo5 *sgte;
};


/*                      Estructura de la cola
------------------------------------------------------------------------*/
struct cola
{
	nodo5 *delante;
	nodo5 *atras;
};


/*                        Encolar elemento
------------------------------------------------------------------------*/
void encolar(struct cola &q, string valor, string valor2, string valor3)
{
	struct nodo5 *aux = new(struct nodo5);
	aux->dato.narch = valor;
	aux->dato.cant_h = valor2;
	aux->dato.usuario = valor3;
	aux->sgte = NULL;

	if (q.delante == NULL)
		q.delante = aux;   // encola el primero elemento
	else
		(q.atras)->sgte = aux;

	q.atras = aux;        // puntero que siempre apunta al ultimo elemento

}

/*                        Desencolar elemento
------------------------------------------------------------------------*/
void desencolar(struct cola &q)
{
	string a1, a2, a3;
	struct nodo5 *aux;

	aux = q.delante;      // aux apunta al inicio de la cola
	a1 = aux->dato.narch;
	a2 = aux->dato.cant_h;
	a3 = aux->dato.usuario;
	q.delante = (q.delante)->sgte;
	delete(aux);          // libera memoria a donde apuntaba aux

}

/*                        Mostrar Cola
------------------------------------------------------------------------*/
void muestraCola(struct cola q)
{
	struct nodo5 *aux;

	aux = q.delante;

	while (aux != NULL)
	{
		cout << "Nombre del Archivo: " << aux->dato.narch << " Direccion " << &aux << endl << " Cantidad de hojas: " << aux->dato.cant_h << " Direccion " << &aux << endl << " Nombre de usuario: " << aux->dato.usuario << " Direccion " << &aux << endl;
		aux = aux->sgte;
	}
}

/*              Eliminar todos los elementos de la Cola
------------------------------------------------------------------------*/
void vaciaCola(struct cola &q)
{
	struct nodo5 *aux;

	while (q.delante != NULL)
	{
		aux = q.delante;
		q.delante = aux->sgte;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;

}

/*                        Menu de opciones
------------------------------------------------------------------------*/
void menu()
{
	cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
	cout << " 1. ENCOLAR                               " << endl;
	cout << " 2. DESENCOLAR                            " << endl;
	cout << " 3. MOSTRAR COLA                          " << endl;
	cout << " 4. VACIAR COLA                           " << endl;
	cout << " 5. SALIR                                 " << endl;

	cout << "\n INGRESE OPCION: ";
}

/*                        Funcion Principal
------------------------------------------------------------------------*/
void menu5(){

	struct cola q;

	q.delante = NULL;
	q.atras = NULL;


	int dato;  // numero a encolar
	int op;    // opcion del menu
	int x;    // numero que devuelve la funcon pop
	string nombre;
	string hojas;
	string usu;
	nodo5* nuevonodo5 = new nodo5();
	system("color 0b");

	do
	{
		menu();  cin >> op;

		switch (op)
		{
		case 1:


			cout << "\n Ingrese el nombre del archivo "; cin >> nombre;
			cout << "\n Ingrese cantidad de hojas "; cin >> hojas;
			cout << "\n Ingrese usuario "; cin >> usu;
			encolar(q, nombre, hojas, usu);
			break;


		case 2:

			desencolar(q);
			break;


		case 3:

			cout << "\n\n MOSTRANDO COLA\n\n";
			if (q.delante != NULL) muestraCola(q);
			else   cout << "\n\n\tCola vacia...!" << endl;
			break;


		case 4:

			vaciaCola(q);
			cout << "\n\n\t\tHecho...\n\n";
			break;

		}

		cout << endl << endl;
		system("pause");  system("cls");

	} while (op != 5);


}
