#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;

/*int main (int argc, char *argv[])
{
 bool b=0;
 string mensaje;
 
 while(cin>>mensaje)
  {
//   cin.getline (mensaje,1000);					
	for(int i=0;i<mensaje.size();i++)  
      {
	   	if(mensaje[i]=='"')
           {
              if(b==0)
			    {
				 cout<<"``";
                 b=1;
				}
			  else
			    {
				 cout<<"''";
                 b=0;
				}	
		   }
       
        else {
			 cout<<mensaje[i];
			 if(mensaje[i]=='.')
			 cout<<endl;
			 }
	  }  
	cout<<" ";

  }
 return 0;
}
*/


int main (int argc, char *argv[])
{
  bool b=0;
  char mensaje [256];
  
  while(cin.getline (mensaje,256))	
   {
   
   for(int i=0;i<strlen(mensaje);i++)
   {
	   	if(mensaje[i]=='"')
           {
              if(b==0)
			    {
				 cout<<"``";
                 b=1;
				}
			  else
			    {
				 cout<<"''";
                 b=0;
				}	
		   }
       
        else {
			 cout<<mensaje[i];
		
			 }
	  }  
  cout<<endl;
}

 return 0;
}
