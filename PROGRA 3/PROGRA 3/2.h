#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
	int nro;
	struct nodo *izq, *der, *padre;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
para mayor facilidad de creacion de variables */


//protos
bool Busqueda(ABB &arbol, int n);
void Eliminarnodo(nodo *);
nodo *minimo(nodo *);
void reemplazar(nodo*, nodo *);
void destruirNodo(nodo *);
void EliminarnodoDer(nodo *);
void EliminarIZQ(nodo *);
nodo *minimoDer(nodo *);
void reemplazarDer(nodo*, nodo *);
void destruirNodoDer(nodo *);

ABB crearNodo(int x, nodo *padre)
{
	ABB nuevoNodo = new nodo;
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;


	return nuevoNodo;
}
void insertar(ABB &arbol, int x, nodo *padre)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(x, padre);

	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x, arbol);
	else if (x > arbol->nro)
		insertar(arbol->der, x, arbol);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

bool Busqueda(ABB &arbol, int n) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->nro == n) {
		return true;
	}
	else if (n< arbol->nro)
	{
		return Busqueda(arbol->izq, n);
	}
	else {
		return Busqueda(arbol->der, n);
	}

}
void Eliminar(nodo *arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else if (n<arbol->nro) {
		Eliminar(arbol->izq, n);//si el valor es menor busca por la izquierda

	}
	else if (n>arbol->nro) {
		Eliminar(arbol->der, n);//si es mayor vamos a buscar por la derecha
	}
	else// si noo es mayor ni menor y el arbol no esta vacio "lo encontramos"
	{

		Eliminarnodo(arbol);
	}



}

//funcion para determinar el nodo mas izquierdo posible

nodo *minimo(nodo *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {//si tiene hijo izq
		return minimo(arbol->izq);
	}
	else
	{
		return arbol; //si no tinen hijo izq le regresamos el misno nodo

	}


}
void Eliminarnodo(nodo *nodoEliminar) {

	//puede ser hoja 0 hijos
	//hijo izquierdo o derecho

	//eliminacion con 2 subarboles hijos
	if (nodoEliminar->izq && nodoEliminar->der) {
		nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->nro = menor->nro;
		Eliminarnodo(menor);
	}
	else if (nodoEliminar->izq) {//si tiene hijo izq
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->der) {//si tiene hijo der
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else {//nodo terminal
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);

	}


}
void reemplazar(nodo *arbol, nodo *nuevoNodo) {
	if (arbol->padre) {
		//arbol->padre hay que asignarle el nuevo hijo
		if (arbol->nro == arbol->padre->izq->nro) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->nro == arbol->padre->der->nro) {
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		//asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;


	}



}
void destruirNodo(nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;

	delete nodo;

}
//eliminacion por la izquierda-todo derecha
void EliminarIZQ(nodo *arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else if (n<arbol->nro) {
		EliminarIZQ(arbol->izq, n);//si el valor es menor busca por la izquierda

	}
	else if (n>arbol->nro) {
		EliminarIZQ(arbol->der, n);//si es mayor vamos a buscar por la derecha
	}
	else// si noo es mayor ni menor y el arbol no esta vacio "lo encontramos"
	{

		EliminarnodoDer(arbol);
	}



}

//funcion para determinar el nodo mas derecho posible

nodo *minimoDer(nodo *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->der) {//si tiene hijo izq
		return minimoDer(arbol->der);
	}
	else
	{
		return arbol; //si no tinen hijo izq le regresamos el misno nodo

	}


}
void EliminarnodoDer(nodo *nodoEliminar) {

	//puede ser hoja 0 hijos
	//hijo izquierdo o derecho

	//eliminacion con 2 subarboles hijos
	if (nodoEliminar->izq && nodoEliminar->der) {
		nodo *menor = minimoDer(nodoEliminar->izq);
		nodoEliminar->nro = menor->nro;
		EliminarnodoDer(menor);
	}
	else if (nodoEliminar->izq) {//si tiene hijo izq
		reemplazarDer(nodoEliminar, nodoEliminar->izq);
		destruirNodoDer(nodoEliminar);
	}
	else if (nodoEliminar->der) {//si tiene hijo der
		reemplazarDer(nodoEliminar, nodoEliminar->der);
		destruirNodoDer(nodoEliminar);
	}
	else {//nodo terminal
		reemplazarDer(nodoEliminar, NULL);
		destruirNodoDer(nodoEliminar);

	}


}
void reemplazarDer(nodo *arbol, nodo *nuevoNodo) {
	if (arbol->padre) {
		//arbol->padre hay que asignarle el nuevo hijo
		if (arbol->nro == arbol->padre->izq->nro) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->nro == arbol->padre->der->nro) {
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		//asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}



}
void destruirNodoDer(nodo *nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;

	delete nodo;

}


void menu2()
{

	int op;
	int dato;
	ABB arbol = NULL;   // creado Arbol

	int n;  // numero de nodos del arbol
	int x; // elemento a insertar en cada nodo
menu:
	system("cls");
	cout << "***** MENU ******\n";
	cout << "1.ingresar arbol\n";
	cout << "2.ver arbol\n ";
	cout << "3.morstrar ordenamientos\n";
	cout << "4.Buscar en arbol\n";
	cout << "5.Eliminar un nodo del arbol\n";
	cout << "6.Eliminar por la izquierda\n";
	cout << "7.salir\n ";
	cin >> op;
	do {
		switch (op)
		{
		case 1:cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

			cout << " Numero de nodos del arbol:  ";
			cin >> n;
			cout << endl;

			for (int i = 0; i < n; i++)
			{
				cout << " Numero del nodo " << i + 1 << ": ";
				cin >> x;
				insertar(arbol, x, NULL);
			}
			system("pause");
			goto menu;
			break;
		case 2:
			system("cls");

			cout << "\n Mostrando ABB \n\n";
			verArbol(arbol, 0);


			system("pause");
			goto menu;
			break;

		case 3:
			system("cls");
			cout << "\n Recorridos del ABB";

			cout << "\n\n En orden   :  ";   enOrden(arbol);
			cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
			cout << "\n\n Post Orden :  ";   postOrden(arbol);

			cout << endl << endl;

			system("pause");
			goto menu;
			break;


		case 4:
			system("cls");
			cout << "ingrese el elemento a buscar\n";
			cin >> dato;

			if (Busqueda(arbol, dato) == true) {
				cout << "elemento" << dato << "Ha sido encontrado " << endl;
			}
			else {
				cout << "elemento no encontrado\n";
			}

			system("pause");
			goto menu;

		case 5:
			system("cls");
			cout << "Digite el numero a eliminar\n";
			cin >> dato;
			Eliminar(arbol, dato);
			system("pause");
			goto menu;
			break;
		case 6:
			system("cls");
			cout << "Digite el numero a eliminar\n";
			cin >> dato;
			EliminarIZQ(arbol, dato);
			system("pause");
			goto menu;
			break;
		}

	} while (op != 7);

}