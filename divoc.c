#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"
#include "inout.h"


int main(){
  int fin;
  char q;
  fin=0;
  struct aPatient thePatients[100];//aPatients is the struct and thePatients the array with patients
  int numPatients=0;//number

  p_init(thePatients, &numPatients);
 
  //Headboard
  stripe("-");
  headline("DIVOC_","|");
  stripe("-");
    
  //Menu  
  do {
   printf("\n\nR) Register a patient\n");
   printf("S) Search for a patient\n");
   printf("D) Discharge a patient\n");
   printf("L) List patients by age\n");
   printf("P) Mark positive\n");
   printf("\nX) Exit the program\n");
   q = get_character("RSDLPX","\nChoose an option ");
   q = toupper(q);

   switch(q) {
    case 'R':
      p_register(thePatients, &numPatients);
      break;
    case 'S':
      p_search(thePatients, &numPatients);
      break;
    case 'L':
      p_list(thePatients, &numPatients);
      break;
    case 'D':
      p_discharge(thePatients, &numPatients);
      break;
    case 'P':
      p_mark(thePatients, &numPatients);
      break;
    case 'X':fin=p_exit(thePatients, &numPatients);
      break;

   }
   
  }while (fin==0);//until is x and then y
 
}



    




