#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"
#include "inout.h"

void get_string(char *prompt, char *my_string, int min, int max){                        //name and dni
 int length;
 char line[256];//read the whole string introduced by the user
 char added[256];
 char word[256];
 int num=0;
 do{
  printf( "%s (%d-%d char):",prompt,min,max);
  fgets(line,sizeof(line), stdin);
  num= sscanf (line,"%s%s",word,added);
  if(num==1)
   length=strlen(word);
  else 
   length=-1;
 }while((length>max)||(length<min));
 strcpy(my_string,word);//my_string is the final string to the struct 
 return ;

}


int get_integer(int min, int max, char *prompt){                                         //age
 int num;
 char line[100];//read the whole string introduced by the user
 char added[100];
 int date;
 do{
  printf("%s [%d-%d]:", prompt, min, max);
  fgets(line,sizeof(line), stdin);
  num= sscanf (line,"%d%s",&date,added);
 }while(date<min || date>max || num!=1);
 return date;
 
}


char get_character(char *checkword,char *string){                                         //symptom
 char added[100];
 char letter;
 char line[256];//read the whole string introduced by the user
 int num;
 int valid=0;
 do{
  printf("%s(%s): ", string, checkword);
  fgets(line,sizeof(line),stdin);
  num = sscanf(line, "%c%s", &letter, added);
  letter=toupper(letter);
  if (strchr(checkword,letter)!= NULL) //search the letter in the string 
   valid=1;    
 } while((num==0) || (num>1) || valid==0);
 return letter;
 
}


int yes_or_no(char *S){                                                                    //exit,fever and cough
 char line[100];//read the whole string introduced by the user
 char letter;
 char added[100];
 int num,fin=2;
 do{
  num=0;
  printf("%s", S);
  fgets(line,sizeof(line),stdin);
  num = sscanf(line, "%c%s", &letter, added);
  letter=toupper(letter);
  if (num==1){
   if(letter=='Y')
    fin=1;
   if(letter=='N')
    fin=0;
  }
 } while(fin==2);
 if(fin==0)
  return 0;
 else
  return 1;

}


void display_patient(struct aPatient table){
 printf(">%24s;%s;%d;%d;%d;%c;\n", table.name, table.dni, table.age, table.fever,table.cough,table.symptom);
 return; 

}


int verify_DNI(char *DNI){
 int index;
 int i=0;
 int DNInumber;//8 digits of dni
 char DNIstring[9];//8 first characters of dni
 char letter;
 char wordcheck[]= "TRWAGMYFPDXBNJZSQVHLCKE";
 sscanf(DNI, "%8s%c", DNIstring,&letter);
 for(i=0;i<8;i++){//we check is the whole string are numbers
  if(isdigit(DNIstring[i])==0)//returns 0 when it is not a digit
    return 0;
 }
 DNInumber=atoi(DNIstring);
 index=DNInumber%23;
 if(wordcheck[index]==letter)
  return 1;
 else
  return 0;

} 


void stripe(char *symb){
 int i;
 for(i=0;i<50;i++){
  printf("%c",*symb);
 }
 printf("\n");
 return;
  
}


void headline(char *S, char *symb){
 int i; 
 printf("%c",*symb);
 for(i=0;i<21;i++){
  printf(" ");
 }
 printf("%s",S);
 for(i=0;i<21;i++){
  printf(" ");
 }
 printf("%c\n",*symb);
 return;
 
}



