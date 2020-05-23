#include "list.c"


typedef struct node list;

list* get(list *head,int number);

void append(list *head,int val);

void insert(list *head,int i,int val);

void del(list *head,int i);
