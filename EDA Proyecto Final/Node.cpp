#include "Node.h"


{
Node::Node() /*!< Implementación Constructor sin Parametros*/
	
	
}


Node::Node(char t,int id1,Node* idp){ /*!< Implementación Constructor con Parametros*/
	
	data=t; /*!< Dato*/
	id=id1; /*!< Identificador*/
	padre=idp; /*!< Puntero al padre*/	
}

Node::~Node() /*!< Implementación del Destructor*/
{

}
void Node::print()/*!< Implementación del Método para imprimir el Nodo y sus Hijos*/
{
	map<char,Node * >::iterator it;   			/*!< Iterador para recoorer los Hijos del Nodo Padre */
	for ( it=hijos.begin() ; it != hijos.end(); it++ )	/*!< For que recorre los Hijos de un Nodo*/
			      cout << (*it).first << " , " ;	/*!< Imprimiendo la Data de cada Nodo Hijo*/
					cout<<endl;	
}
