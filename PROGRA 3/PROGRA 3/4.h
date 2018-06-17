#pragma once
#include <stdio.h>
#include<iostream>
#include <stdlib.h>

using namespace std;
int dt;
class nodo4 {
private:
	int dato;

	nodo4 *sig;
	nodo4 *ant;
	friend class lista_enlace;

};

class lista_enlace {
public:

	lista_enlace();
	~lista_enlace();

	//obtener
	int obtenerFrontal() const;
	int obtenerFinal() const;

	//establecer
	void insertar_inicio(int dt);
	void insertar_final(int dt);
	void insertar_segunda(int dt);
	void insertar_anteUltima(int dt);
	void borrar_primero();
	void borrar_segundo();
	void borrar_ultimo();
	void borrar_mayor();
	void mostrar();

private:
	//nodo4s centinela de la lista o estructura
	nodo4 *cabeza;
	nodo4 *fin;
};

//crear y enlazar las funciones
void menu4() {
	int op;
	lista_enlace li;
menu:
	system("cls");
	cout << "*******MENU******\n";
	cout << "1.INGRESO DE DATOS AL INCIO\n";
	cout << "2.INGRESO DE DATOS EN SEGUNDL\n";
	cout << "3.INGRESO DE DATOS AL FNAL\n";
	cout << "4.INGRESO DE DATOS ANTE ULTIMO\n";
	cout << "5.ELIMINAR PRIMER nodo4\n";
	cout << "6.ELIMINAR ULTIMO nodo4\n";
	cout << "7.ELIMINAR SEGUNDO\n";
	cout << "8.MOSTRAR LISTA \n";
	cin >> op;

	switch (op)
	{
	case 1:
		system("cls");
		cout << "***INSERTANDO AL INICIO***\n";
		cout << "INGRESE LOS DATOS DEL nodo4\n";
		cin >> dt;
		li.insertar_inicio(dt);
		goto menu;
		break;


	case 2:
		system("cls");
		cout << "****INSERTANDO EN SEGUNDA****\n";
		cout << "INGRESE LOS DATOS DEL nodo4\n";
		cin >> dt;
		li.insertar_segunda(dt);
		system("pause");
		goto menu;
		break;
	case 3:
		system("cls");
		cout << "*****INSERTANDO AL FINAL***\n";
		cout << "INGRESE LOS DATOS DEL nodo4\n";
		cin >> dt;
		li.insertar_final(dt);
		goto menu;
		break;
	case 4:
		system("cls");
		cout << "*****INSERTAR DATOS ANTEULTIMO***\n";
		cout << "INGRESE LOS DATOS DEL nodo4\n";
		cin >> dt;
		li.insertar_anteUltima(dt);
		goto menu;
		break;
	case 5:
		system("cls");
		cout << "******LISTA*******\n";
		li.mostrar();
		li.borrar_primero();
		cout << "\n";
		system("pause");
		system("cls");
		cout << "****LISTA ACTUALIZADA*****\n";
		li.mostrar();
		cout << "\n";
		system("pause");
		goto menu;
		break;
	case 6:
		system("cls");
		cout << "******LISTA*******\n";
		li.mostrar();
		li.borrar_ultimo();
		cout << "\n";
		system("pause");
		system("cls");
		cout << "****LISTA ACTUALIZADA*****\n";
		li.mostrar();
		cout << "\n";
		system("pause");
		goto menu;
		break;
	case 7:
		system("cls");
		cout << "******LISTA*******\n";
		li.mostrar();
		li.borrar_segundo();
		cout << "\n";
		system("pause");
		system("cls");
		cout << "****LISTA ACTUALIZADA*****\n";
		li.mostrar();
		cout << "\n";
		system("pause");
		goto menu;
		break;
	case 8:
		system("cls");
		cout << "******LISTA*******\n";
		li.mostrar();
		cout << "\n";
		system("pause");
		goto menu;
		break;


	}
}
lista_enlace::lista_enlace() {
	cabeza = new nodo4;
	fin = new nodo4;
	cabeza->sig = fin;
	fin->ant = cabeza;
	cabeza->ant = NULL;
	fin->sig = NULL;
}
lista_enlace::~lista_enlace() {

	while (cabeza->sig != fin)
	{
		borrar_primero();
		delete cabeza;
		delete fin;

	}


}

//obtener
int lista_enlace::obtenerFrontal() const {

	return cabeza->sig->dato;
}
int lista_enlace::obtenerFinal() const {

	return fin->ant->dato;
}

//establecer
void lista_enlace::insertar_inicio(int dt) {
	//crear nodo4
	nodo4 *nd = new nodo4;
	//definir punteros del nuevo nodo4

	nd->dato = dt;
	nd->ant = cabeza;
	nd->sig = cabeza->sig;

	//arreglar los punteros del nuevo nodo4
	cabeza->sig->ant = nd;
	cabeza->sig = nd;
}
void lista_enlace::insertar_final(int dt) {
	//crear nodo4
	nodo4 *nd = new nodo4;
	//definir punteros del nuevo nodo4
	nd->dato = dt;
	nd->ant = fin->ant;
	nd->sig = fin;
	//arreglar punteros del nuevo nodo4


	fin->ant->sig = nd;
	fin->ant = nd;

}
void lista_enlace::insertar_segunda(int dt) {

	nodo4 *nd = cabeza->sig;
	nodo4 *nd1 = new nodo4;

	if (cabeza->sig != fin)
	{



		nd1->dato = dt;
		nd1->ant = nd;
		nd1->sig = nd->sig;

		nd->sig->ant = nd1;
		nd->sig = nd1;
	}
	else {

		cout << "LA LISTA ESTA VACIA NO PUEDE INSERTAR EN SEGUNDA POSICION DE UNA LISTA INEXISTENTE\n";
	}

}
void lista_enlace::insertar_anteUltima(int dt) {
	nodo4 *nd = fin->ant;
	nodo4 *nd1 = new nodo4;
	if (cabeza->sig != fin)
	{
		nd1->dato = dt;
		nd1->ant = nd->ant;
		nd1->sig = nd;


		nd->ant->sig = nd1;
		nd->ant = nd1;
	}
	else {

		cout << "LA LISTA ESTA VACIA NO PUEDE INSERTAR EN ANTEULTIMA POSICION DE UNA LISTA INEXISTENTE\n";
		system("pause");
	}


}
void lista_enlace::borrar_primero() {
	nodo4 *nd = cabeza->sig->sig;
	if (cabeza->sig != fin)
	{
		delete cabeza->sig;

		cabeza->sig = nd;
		nd->ant = cabeza;
	}
	else {

		cout << "LA LISTA ESTA VACIA NO PUEDE BORRAR PRIMERO\n";
		system("pause");
	}


}
void lista_enlace::borrar_segundo() {

	nodo4 *nd = cabeza->sig->sig->sig;
	nodo4 *nd1 = cabeza->sig;
	if (cabeza->sig != fin)
	{
		delete cabeza->sig->sig;

		nd1->sig = nd;
		nd->ant = nd1;
	}
	else {

		cout << "LA LISTA ESTA VACIA NO PUEDE BORRAR SEGUNDO\n";
		system("pause");
	}



}
void lista_enlace::borrar_ultimo() {
	nodo4 *nd = fin->ant->ant;
	if (cabeza->sig != fin)
	{

		delete fin->ant;
		fin->ant = nd;
		nd->sig = fin;
	}
	else {

		cout << "LA LISTA ESTA VACIA NO PUEDE BORRAR ULTIMO\n";
		system("pause");
	}



}
void lista_enlace::borrar_mayor() {

}

void lista_enlace::mostrar() {
	nodo4 *nd = cabeza->sig;

	while (nd != fin)
	{
		cout << nd->dato << "|";
		nd = nd->sig;
	}

}

