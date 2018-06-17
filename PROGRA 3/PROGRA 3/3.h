#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<Windows.h>
#define DERECHA 1
#define IZQUIERDA 0
#define TRUE 1
#define FALSE 0
using namespace std;;
typedef struct nodo3
{
	int dato;
	int FE;
	struct nodo3 *D;
	struct nodo3 *IZ;
	struct nodo3 *padre;
}*AVL;

void Insertar(AVL *nodo3, int dato);
void Eliminar_nodo3(AVL *n, int dato);
int Buscar(AVL n, int dato);
int EsHoja(AVL n);
int Num_nodo3s(AVL n, int* c);
int Altura_Arbol(AVL n, int* altura);
int Nivel_nodo3(AVL n, int dato);
void InOrden(AVL, void(*func)(int*));
void PreOrden(AVL, void(*func)(int*));
void PostOrden(AVL, void(*func)(int*));
void Equilibrar(AVL *raiz, AVL nodo3, int, int);
void RSI(AVL *r, AVL nodo3);
void RSD(AVL *r, AVL nodo3);
void RDI(AVL *r, AVL nodo3);
void RDD(AVL *r, AVL nodo3);
void Eliminar_Arbol(AVL *nodo3);
void auxContador(AVL n, int*);
void auxAltura(AVL a, int, int*);
void Mostrar(int *n);
void verArbol(AVL arbol, int n);



void menu3() {// ESTE ERA EL MAIN
	AVL Arbol = NULL;

	int i, num, ndatos, opcion;

	do
	{
		system("cls");
		printf("\n");
		printf("\n*********************");
		printf("\n1. Insertar         *");
		printf("\n2. Mostrar          *");
		printf("\n3. Buscar           *");
		printf("\n4. Eliminar nodo3    *");
		printf("\n5. Eliminar árbol   *");
		printf("\n6. Salir            *");
		printf("\n*********************");

		printf("\n\n\n");

		printf(" Elija opción    ");

		scanf_s("%d", &opcion);




		switch (opcion)
		{
		case 1:   system("cls");

			printf("\n INGRESE CANTIDAD DE nodo3S ->");

			scanf_s("%d", &ndatos);

			system("cls");

			printf("\n Introduzca %d dato ->\n\n", ndatos);

			for (i = 1; i <= ndatos; i++)
			{
				scanf_s("%d", &num);

				Insertar(&Arbol, num);
			}
			system("cls");
			printf("\n Número nodo3s ----> %d ", Num_nodo3s(Arbol, &num));

			printf("\n\n Altura `árbol ----> %d ", Altura_Arbol(Arbol, &num));

			printf("\n\n InOrden      ----> ");
			InOrden(Arbol, Mostrar);
			printf("\n\n PreOrden     ----> ");
			PreOrden(Arbol, Mostrar);
			printf("\n\n PostOrden    ----> ");
			PostOrden(Arbol, Mostrar);
			printf("\n\n\n\n\n\n\n\n");

			system("pause");

			system("cls");
			break;






		case 2:   system("cls");
			verArbol(Arbol, 0);
			printf("\n\n Introduzca nodo3      ");

			scanf_s("%d", &num);

			system("cls");

			printf("\n\n Nivel de %d  ---->  %d\n", num, Nivel_nodo3(Arbol, num));

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;


		case 3:   system("cls");

			printf("\n Introduzca dato a buscar      ");

			scanf_s("%d", &num);

			system("cls");

			Buscar(Arbol, num);

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;


		case 4:  system("cls");

			printf("\n Introduzca dato a eliminar      ");

			scanf_s("%d", &num);

			system("cls");

			Eliminar_nodo3(&Arbol, num);

			printf("\n\n Eliminado    ----> %d  ", num);

			printf("\n\n InOrden      ----> ");

			InOrden(Arbol, Mostrar);

			printf("\n\n Número nodo3s ----> %d", Num_nodo3s(Arbol, &num));

			printf("\n\n Altura árbol ----> %d", Altura_Arbol(Arbol, &num));

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;






		case 5:  system("cls");

			Eliminar_Arbol(&Arbol);

			printf("\n ARBOL ELIMINADO");

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;

		case 6: 	
			system("cls");
			cout << "\n\n\n\t\tSALIENDO...";
			Sleep(1500);  break;

		default:  system("cls");

			break;
		}
	} while (opcion != 6);

}


void Insertar(AVL *nodo3, int dato)
{
	AVL padre = NULL;

	AVL actual = *nodo3;

	while (actual != NULL && dato != actual->dato)
	{
		padre = actual;

		if (dato < actual->dato)

			actual = actual->IZ;

		else if (dato > actual->dato)

			actual = actual->D;
	}
	if (actual != NULL)

		return;

	if (padre == NULL)
	{
		*nodo3 = (AVL)malloc(sizeof(struct nodo3));

		(*nodo3)->dato = dato;

		(*nodo3)->IZ = (*nodo3)->D = NULL;

		(*nodo3)->padre = NULL;

		(*nodo3)->FE = 0;
	}

	else if (dato < padre->dato)
	{
		actual = (AVL)malloc(sizeof(struct nodo3));

		padre->IZ = actual;

		actual->dato = dato;

		actual->IZ = actual->D = NULL;

		actual->padre = padre;

		actual->FE = 0;

		Equilibrar(nodo3, padre, IZQUIERDA, TRUE);
	}
	else if (dato > padre->dato)
	{
		actual = (AVL)malloc(sizeof(struct nodo3));

		padre->D = actual;

		actual->dato = dato;

		actual->IZ = actual->D = NULL;

		actual->padre = padre;

		actual->FE = 0;

		Equilibrar(nodo3, padre, DERECHA, TRUE);
	}
}

void Equilibrar(AVL *r, AVL nodo3, int rama, int dato)
{
	int salir = FALSE;

	while (nodo3 && !salir)
	{
		if (dato)

			if (rama == IZQUIERDA)

				nodo3->FE--;

			else

				nodo3->FE++;

		else

			if (rama == IZQUIERDA)

				nodo3->FE++;

			else

				nodo3->FE--;

		if (nodo3->FE == 0)

			salir = TRUE;

		else if (nodo3->FE == -2)
		{
			if (nodo3->IZ->FE == 1)

				RDD(r, nodo3);

			else

				RSD(r, nodo3);

			salir = TRUE;

		}
		else if (nodo3->FE == 2) {

			if (nodo3->D->FE == -1)

				RDI(r, nodo3);

			else

				RSI(r, nodo3);

			salir = TRUE;
		}
		if (nodo3->padre)

			if (nodo3->padre->D == nodo3)

				rama = DERECHA;

			else

				rama = IZQUIERDA;

		nodo3 = nodo3->padre;
	}
}

int EsHoja(AVL nodo3)
{
	return !nodo3->D && !nodo3->IZ;
}


void RDD(AVL *r, AVL nodo3)
{
	AVL Padre = nodo3->padre;
	AVL A = nodo3;
	AVL B = A->IZ;
	AVL C = B->D;
	AVL CI = C->IZ;
	AVL CD = C->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = C;
		else
			Padre->IZ = C;
	else
		*r = C;
	B->D = CI;
	A->IZ = CD;
	C->IZ = B;
	C->D = A;
	C->padre = Padre;
	A->padre = B->padre = C;
	if (CI)
		CI->padre = B;
	if (CD)
		CD->padre = A;

	switch (C->FE)
	{
	case -1: B->FE = 0;

		A->FE = 1;

		break;

	case 0:  B->FE = 0;

		A->FE = 0;

		break;

	case 1:  B->FE = -1;

		A->FE = 0;

		break;
	}
	C->FE = 0;
}


void RDI(AVL *r, AVL nodo3)
{
	AVL Padre = nodo3->padre;
	AVL A = nodo3;
	AVL B = A->D;
	AVL C = B->IZ;
	AVL CI = C->IZ;
	AVL CD = C->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = C;
		else
			Padre->IZ = C;
	else
		*r = C;

	A->D = CI;
	B->IZ = CD;
	C->IZ = A;
	C->D = B;
	C->padre = Padre;
	A->padre = B->padre = C;
	if (CI)
		CI->padre = A;
	if (CD)
		CD->padre = B;

	switch (C->FE)
	{
	case -1: A->FE = 0;

		B->FE = 1;

		break;

	case 0:  A->FE = 0;

		B->FE = 0;

		break;

	case 1:  A->FE = -1;

		B->FE = 0;

		break;
	}
	C->FE = 0;
}

void RSD(AVL *r, AVL nodo3)
{
	AVL Padre = nodo3->padre;
	AVL A = nodo3;
	AVL B = A->IZ;
	AVL C = B->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = B;
		else
			Padre->IZ = B;
	else
		*r = B;

	A->IZ = C;

	B->D = A;

	A->padre = B;

	if (C)

		C->padre = A;

	B->padre = Padre;

	A->FE = 0;

	B->FE = 0;
}

void RSI(AVL *r, AVL nodo3)
{
	AVL Padre = nodo3->padre;
	AVL A = nodo3;
	AVL B = A->D;
	AVL C = B->IZ;
	if (Padre)
		if (Padre->D == A)
			Padre->D = B;
		else
			Padre->IZ = B;
	else
		*r = B;

	A->D = C;

	B->IZ = A;

	A->padre = B;

	if (C)

		C->padre = A;

	B->padre = Padre;

	A->FE = 0;

	B->FE = 0;
}

void Eliminar_nodo3(AVL *n, int dato)
{
	AVL padre = NULL;

	AVL actual;

	AVL nodo3;

	int aux;

	actual = *n;

	while (actual != NULL)
	{
		if (dato == actual->dato)
		{
			if (EsHoja(actual))
			{
				if (padre)

					if (padre->D == actual)

						padre->D = NULL;

					else if (padre->IZ == actual)

						padre->IZ = NULL;

				free(actual);

				actual = NULL;

				if ((padre->D == actual && padre->FE == 1) || (padre->IZ == actual && padre->FE == -1))
				{
					padre->FE = 0;

					actual = padre;

					padre = actual->padre;
				}
				if (padre)

					if (padre->D == actual)

						Equilibrar(n, padre, DERECHA, FALSE);

					else

						Equilibrar(n, padre, IZQUIERDA, FALSE);

				return;

			}
			else {

				padre = actual;

				if (actual->D)
				{
					nodo3 = actual->D;

					while (nodo3->IZ)
					{
						padre = nodo3;

						nodo3 = nodo3->IZ;
					}
				}

				else {

					nodo3 = actual->IZ;

					while (nodo3->D)
					{
						padre = nodo3;

						nodo3 = nodo3->D;
					}
				}

				aux = actual->dato;

				actual->dato = nodo3->dato;

				nodo3->dato = aux;

				actual = nodo3;
			}

		}
		else {

			padre = actual;

			if (dato > actual->dato)

				actual = actual->D;

			else if (dato < actual->dato)

				actual = actual->IZ;
		}
	}
}


void InOrden(AVL nodo3, void(*func)(int*))
{
	if (nodo3->IZ)

		InOrden(nodo3->IZ, func);

	func(&(nodo3->dato));

	if (nodo3->D)

		InOrden(nodo3->D, func);
}
void PreOrden(AVL nodo3, void(*func)(int*))
{
	func(&nodo3->dato);

	if (nodo3->IZ)

		PreOrden(nodo3->IZ, func);

	if (nodo3->D)

		PreOrden(nodo3->D, func);
}
void PostOrden(AVL nodo3, void(*func)(int*))
{
	if (nodo3->IZ)

		PostOrden(nodo3->IZ, func);

	if (nodo3->D)

		PostOrden(nodo3->D, func);

	func(&nodo3->dato);
}


int Buscar(AVL nodo3, int dato)
{
	AVL actual = nodo3;
	while (actual != NULL)
	{
		if (dato == actual->dato)
		{
			printf("\n %d  EXISTE", dato);
			return TRUE;
		}
		else if (dato < actual->dato)
			actual = actual->IZ;
		else if (dato > actual->dato)
			actual = actual->D;
	}
	printf("\n %d  NO EXISTE", dato);
	return FALSE;
}

int Nivel_nodo3(AVL nodo3, int dato)
{
	int altura = 0;
	AVL actual = nodo3;
	while (actual != NULL)
	{
		if (dato == actual->dato)
			return altura;
		else {
			altura++;
			if (dato < actual->dato)
				actual = actual->IZ;
			else if (dato > actual->dato)
				actual = actual->D;
		}
	}
	return -1;
}

void auxContador(AVL nodo3, int *c)
{
	(*c)++;
	if (nodo3->IZ)
		auxContador(nodo3->IZ, c);
	if (nodo3->D)
		auxContador(nodo3->D, c);
}

int Num_nodo3s(AVL nodo3, int *cont)
{
	*cont = 0;
	auxContador(nodo3, cont);
	return *cont;
}

void auxAltura(AVL nodo3, int a, int *altura)
{
	if (nodo3->IZ)
		auxAltura(nodo3->IZ, a + 1, altura);
	if (nodo3->D)
		auxAltura(nodo3->D, a + 1, altura);
	if (EsHoja(nodo3) && a > *altura)
		*altura = a;
}

int Altura_Arbol(AVL nodo3, int *altura)
{
	*altura = 0;
	auxAltura(nodo3, 0, altura);
	return *altura;
}

void Mostrar(int *n)
{
	printf("%d, ", *n);
}

void Eliminar_Arbol(AVL *nodo3)
{
	if (*nodo3)
	{
		Eliminar_Arbol(&(*nodo3)->IZ);
		Eliminar_Arbol(&(*nodo3)->D);
		free(*nodo3);
		*nodo3 = NULL;
	}
}
void verArbol(AVL arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->D, n + 1);
	cout << "\t\t\t\t";
	for (int i = 0; i<n; i++)
		cout << "  ";

	cout << arbol->dato << endl;

	verArbol(arbol->IZ, n + 1);
}
