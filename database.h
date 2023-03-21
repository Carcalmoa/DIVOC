#ifndef DATABASE_H
#define DATABASE_H

struct aPatient{
  char name[25];
  char dni[10];
  int age;
  int fever;
  int cough;
  char symptom;
};

void p_init(struct aPatient *table, int *number);// struct aPatient tipo de variable, *table es el address de thepatients

void p_register(struct aPatient *table, int *number);

void p_search(struct aPatient *table, int *number);

void p_discharge(struct aPatient *table, int *number);

void p_list(struct aPatient *table, int *number);

void p_mark(struct aPatient *table, int *number);

int p_exit(struct aPatient *table, int *number);

#endif
