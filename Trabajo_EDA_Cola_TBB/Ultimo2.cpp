#include <iostream>
#include <tbb/blocked_range.h>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/tbb_thread.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>

using namespace std;
using namespace tbb;
typedef  spin_mutex myMutex; /*!< Definiendo un tipo spin_mutex como myMutex.*/


/**
 * @class Col
 * @brief La clase Col esta implementada usando la Cola del STL (queue).
 * 
 * Esta clase nos permite a traves de sus funciones colocar y sacar elementos de una cola usando threads, y mutex para evitar que se saquen elementos de esta cuando no existe elementos o poner mas elementos de los que el tamaño maximo permite.
 */

class Col
{
  public:
  
  myMutex poner; /*!< Declaramos un MUTEX (myMutex) con el nombre de poner.*/
  myMutex sacar; /*!< Declaramos un MUTEX (myMutex) con el nombre de sacar.*/
  myMutex liberar; /*!< Declaramos un MUTEX (myMutex) con el nombre de liberar.*/
  myMutex ocupar; /*!< Declaramos un MUTEX (myMutex) con el nombre de ocupar.*/

  int tam; /*!< Variable que indica el tamaño que tendra la cola.*/
  queue <int> cola; /*!< Declaramos la Cola Usando la Cola del STL.*/
  
  public:
  
/**
 * @fn Col
 * @brief Constructor de la Cola al que se le pasa el tamaño que esta tendrá.
 */  

  Col(int a) 
   {
    tam=a;
    myMutex::scoped_lock lock4(liberar);/*! myMutex::scoped_lock lock4(liberar)< Lock al mutex Liberar para no se pueda sacar elementos cuando recien se ha creado la cola.*/
   }

/**
 * @fn pon
 * @brief Función de tipo Void que se encarga de poner elementos en la cola. Solo permite insertar un maximo de elementos definido po la variable tam,
 * si se quiere ingresar mas elementos de lo permitido, la cola se bloquea hasta que elimine un elemnto de ella y exista un espacio.
 */   

 void pon(int num)
            {
             myMutex::scoped_lock lock1(poner);/*!myMutex::scoped_lock lock1(poner)< Lock al mutex Poner para que solo una thread por vez pueda poner un elemento en la Cola.*/
             if(cola.size()>=tam)
               {
		myMutex::scoped_lock lock2(ocupar);/*!myMutex::scoped_lock lock2(ocupar)< Lock al mutex Ocupar para que no se pueda poner mas elementos cuando la cola a llegado a su tamaño 								máximo.*/
                cout<<"Esta lleno "<<endl;sleep(1); /*!cout<<"Esta lleno "<<endl;sleep(1)< Mensaje que nos indica que la cola esta llena.*/
                myMutex::scoped_lock lock4(liberar); 
                lock4.release();  /*!lock4.release()< Liberando al mutex Liberar que bloqueaba el poder sacar elementos cuando la pila recien es creada.*/
                                
               }
             
             cola.push(num); /*!cola.push(num)< Poniendo un elemento en la cola.*/
             lock1.release(); /*!lock1.release()< Liberando el mutex Poner para dejar que otra thread pueda colocar un elemento en la cola.*/
             
             }

    
/**
 * @fn sa
 * @brief Función del tipo Void que se encarga de sacar elementos en la cola.
 */
void sa(){
          
	       myMutex::scoped_lock lock3(sacar); /*!myMutex::scoped_lock lock3(sacar)< Lock al mutex Sacar para que solo una thread por vez pueda sacar un elemento de la Cola.*/
	        if(cola.size()<=0)
              {
               
               myMutex::scoped_lock lock1(liberar); /*!myMutex::scoped_lock lock1(liberar)< Lock al mutex Liberar para que no se pueda sacar mas elementos cuando la cola este vacía.*/
               cout<<"Esta vacio "<<endl;sleep(1); /*!< Mensaje que nos indica que la cola esta vacia.*/
               myMutex::scoped_lock lock4(ocupar);
               lock4.release(); 
              }

	       cout<<"sacando el dato "<<cola.front()<<endl;sleep(1); 
               cola.pop(); /*!cola.pop()< Sacando un elemento de la cola.*/
               lock3.release(); /*!lock3.release()< Liberando el mutex Sacar para dejar que otra thread pueda sacar un elemento de la cola.*/
               

           }

/**
 * @fn imprimir
 * @brief Función del tipo Void que se encarga de imprimir los elementos dela cola.
 */

 void imprimir(){

                 while(cola.size()!=0)
                   {cout<<"frente: "<<cola.front()<<endl;
                    cola.pop();  }
                }

};



/**
 * @class meter 
 * @brief La clase meter me permite usar la clase Col como un Function Object.
 * 
 * Esta clase nos permite ingresar elementos a la cola Col accesandola como una Function Object.
 */


class meter
{
 Col * pc;  /*!< Puntero del tipo Col.*/
 int cc;  /*!< Entero al que se le pasa el elementoa poner en la cola .*/
 
 public:
 
/**
 * @fn meter
 * @brief Constructor de la clase meter al cual se le pasa una referencia a una Cola y un elemento a meter en la cola.
 */
 

 meter (Col &a,int c)
                     {
                     
                      pc=&a;cc=c;
                     }

/**
 * @fn operator()()
 * @brief Funcion que nos permite sobrecargar el operador () e ingresarle asi a la Cola Col un elemento a traves de su funcion Pon.
 */
 

 void operator ()() {
                     for(int i=0;i<20;i++)
                      {pc->pon(cc); cout<<"metiendo un dato"<<cc<<endl;sleep(1);}
                     
                    }
 
};



/**
 * @class sacar 
 * @brief La clase sacar me permite usar la clase Col como un Function Object.
 * 
 * Esta clase nos permite sacar elementos a la cola Col accesandola como una Function Object.
 */


class sacar
{
 Col * pc; /*!< Puntero del tipo Col.*/
 
 public:

/**
 * @fn sacar
 * @brief Constructor de la clase sacar al cual se le pasa una referencia a una Cola.
 */ 


 sacar (Col &a)
 {pc=&a;}

/**
 * @fn operator()()
 * @brief Funcion que nos permite sobrecargar el operador () ysacarle asi a la Cola Col un elemento a traves de su funcion Sa.
 */

 void operator ()(){for(int i=0;i<20;i++)
                    {pc->sa();}}
 
};



int main() 

{

 srand(time(0));
 Col cola(4); /*!<Creando una cola Col de Tamaño 4.*/
 //meter a(cola,3);
 //sacar b (cola(3));
 tbb_thread t1(*new meter(cola,3)); /*!tbb_thread t1(*new meter(cola,3))<Creando una thread con el nombre de t1 a la que se le pasa un elemento para que coloque en la Cola Col.*/
 tbb_thread t2(*new meter(cola,4)); /*!tbb_thread t1(*new meter(cola,4))<Creando una thread con el nombre de t2 a la que se le pasa un elemento para que coloque en la Cola Col.*/
 tbb_thread t3(*new meter(cola,5)); /*!tbb_thread t1(*new meter(cola,5))<Creando una thread con el nombre de t3 a la que se le pasa un elemento para que coloque en la Cola Col.*/
 tbb_thread t4(*new meter(cola,6)); /*!tbb_thread t1(*new meter(cola,6))<Creando una thread con el nombre de t4 a la que se le pasa un elemento para que coloque en la Cola Col.*/
 
 tbb_thread t5(*new sacar(cola)); /*!tbb_thread t5(*new sacar(cola))<Creando una thread para que saque un elemento de la Cola Col.*/
 tbb_thread t6(*new sacar(cola)); /*!tbb_thread t5(*new sacar(cola))<Creando una thread para que saque un elemento de la Cola Col.*/
 t1.join(); /*!t1.join()<Instruccion para evitar que la funcion principal acabe antes de que se ejecute la thread indicada. En este caso t1.*/
 t2.join();
 t3.join();
 t4.join();
 t5.join();
 t6.join();


 //cola.imprimir();

 return 0;

}


