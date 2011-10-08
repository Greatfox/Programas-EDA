#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;
/*
int main (int argc, char *argv[])
{
 string mens;
 fstream mensaje("texto.txt",ios::in);

 while (mensaje) 
  {
   getline(mensaje, mens, '\n' );
   for(int i=0;i<mens.length();i++)
       {
         cout<<char(mens[i]-7);
       }
       cout<<endl;
  }            
 
 return 0;
}

*/
int main (int argc, char *argv[])
{
 string mensaje;
 while(cin>>mensaje)
  {
	for(int i=0;i<mensaje.size();i++)  
    cout<<char(mensaje[i]-7);
    cout<<endl;
  }
 return 0;
}
