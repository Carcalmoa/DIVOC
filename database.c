#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"
#include "inout.h"


void p_init(struct aPatient *table, int *number){ //we introduced in the current table the past patients
 char line[256];
 FILE *file;
 file=fopen("patients.txt","r");
 if (file!=NULL){
   while ((fgets (line, sizeof(line), file)) != NULL){ //we pass the content of the file to the string line
    sscanf(line,"%s %s %d %d %d %c",
    table[*number].name,table[*number].dni,&table[*number].age,&table[*number].fever,&table[*number].cough,&table[*number].symptom);
    (*number)++;
   }
  fclose (file);
 }

}


void p_register(struct aPatient *table, int *number){ 
  char name[25];
  char dni[10];
  printf("\nRegister\n");
  get_string("\nName",name,1,24);
  strcpy(table[*number].name,name);//save the name in table
  get_string("\nDNI",dni,9,9);
  while(verify_DNI(dni)==0){
   printf("\nInvalid DNI\n");
   get_string("\nDNI",dni,9,9);
  }
  strcpy(table[*number].dni,dni);//save the DNI in table
  table[*number].age=get_integer(1900,2020,"\nDate");
  table[*number].fever=yes_or_no("\nFever (y/n): ");
  table[*number].cough=yes_or_no("\nCough (y/n): ");
  table[*number].symptom=get_character("FSTMN","\nSymptom");
  printf("\nNew patient:\n");
  display_patient(table[*number]);// number initialized to 0 in divoc
  (*number)++;//next patient
  
}


void p_search(struct aPatient *table, int *number){
  int i,eq=0;
  char dni[10];//dni introduced by the user
  printf("\nSearch\n");
  if(*number==0)
   printf("\nNo patients yet\n");
  else{
   get_string("\nDNI",dni,9,9);
    for(i=0;i<(*number);i++){
       if(strcmp(dni,table[i].dni)==0){//0 if they are equals
        eq=1;
        break;
       }
    }
    if(eq==0)
     printf("\nUnknown patient\n");
    else{
      printf("\nPatient data:\n");  
      display_patient(table[i]);
    }  
  }

}
  

void p_discharge(struct aPatient *table, int *number){ 
 int i,k,eq=0;
 char dni[10];//dni enter by the user
  printf("\nDischarge\n");
  if(*number==0)
  printf("\nNo patients yet\n");
  else{
    get_string("\nDNI",dni,9,9);
    for(i=0;i<(*number);i++){
     if(strcmp(dni,table[i].dni)==0){//0 if they are equals
      for(k=i;k<(*number)-1;k++){
       table[k]=table[k+1];
      }
     (*number)--;
     eq=1;
     break;
    }
   }
   if(eq==0)
    printf("\nUnknown patient\n");
   else
    printf("\nDischarged patient\n");    
 }
  
}


void p_list(struct aPatient *table, int *number){
 int i,year;
  printf("\nList\n");
  if(*number==0){
   printf("\nNo patients yet\n");
  }
  else{
   year=get_integer(1900,2020,"\nDate");
   printf("\nPatients born before %d:\n",year);
   for(i=0;i<(*number);i++){
    if(table[i].age<=year){
     display_patient(table[i]);
    }
   }
  }
 return;
}
 

void p_mark(struct aPatient *table, int *number){ 
 int i;
  printf("\nPositives\n");
  if(*number==0)
   printf("\nNo patients yet\n");
  else{
   printf("\nPositive patients:\n");
   for(i=0;i<*number;i++){
    if ((table[i].fever==1)&&(table[i].cough==1)&&(table[i].symptom!='N'))   
    display_patient(table[i]);
   }
  }
  
}
 

int p_exit(struct aPatient *table, int *number){
 printf("\nExit\n");
 if (yes_or_no("\nAre you sure you want to exit the program? (y/n): ")==1){
    int i=0;
    FILE *file;
    file=fopen("patients.txt","w");
    while (i<*number) {//pass to the file all the patients
     fprintf(file, "%s %s %d %d %d %c\n",table[i].name, table[i].dni, table[i].age, table[i].fever, table[i].cough, table[i].symptom);
     i++;
    }
    fclose(file);
  return 1;
 }
 else 
  return 0;

}



