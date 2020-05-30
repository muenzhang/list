#include "list.c"


typedef struct node list;

list* listCreate();

int search(list* head,int j);

int len(list* head);

list* get(list *head,int number);

list* append(list *head,int val);

list* insert(list *head,int i,int val);

int del(list *head,int i);
