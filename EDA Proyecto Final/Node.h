#ifndef NODE_H_
#define NODE_H_


#include <map>
#include <iostream>
#include "string.h"
using namespace std;

/*
 * Es la base del LZtrie ,representa un bloque ,
 * guarda el camino de una sub frase desde la raiz
 * hasta la ultima letra del bloque.
 * 
 */


class Node
{
	
public:
	
	/*
	 * Su id en conforme va leyendo el texto y armando los bloques
	 */
	int id;	
	/*
	 * Guarda el id del recorrido in order de la trie
	 */
	int rank;
	/*
	 * Guarda a su antecesor ,para rearmar el bloque siguiendo el camino
	 * hasta la raiz
	 */
	Node *	padre;	
	/*
	 * La letra que corresponde al nodo, esta letra no es unica,
	 * puede repetirce en la trie
	 * 
	 */
	char data;	

	/*
	 * Un map de todos su hijos, el acceso es lineal, ademas de 
	 * estar ordenado
	 */
	map <char,Node *> hijos;
	
	/*
	 * Constructor por defecto
	 */	
	Node();
	/*
	 * Constructor que recibe
	 * t->su char a ingresar
	 * id1->su id de ingreso
	 * idp->un puntero a su padre
	 */
	Node(char t,int id1,Node* idp);
	/*
	 * Imprime a sus hijos
	 */	
	void print();
	
	virtual ~Node();	
	
	
};

#endif /*NODE_H_*/
