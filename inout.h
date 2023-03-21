#ifndef INOUT_H
#define INOUT_H


void get_string(char *prompt, char *my_string, int min, int max);

int get_integer(int min, int max, char *prompt);

char get_character(char *checkword, char *string);

int  yes_or_no(char *S);

void display_patient(struct aPatient table);

int verify_DNI (char *DNI);

void headline(char *S, char *symb);

void stripe(char *symb);

#endif
