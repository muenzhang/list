#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
}list;

list* get(list *head,int number){
    list *p = head;
    for(int i = 0;i < number && p -> next;i++){
        p = p -> next;
    }
    return p;
}

void append(list *head,int val){
    list *p = head;
    while(p -> next){
        p = p -> next;
    }

    list *a = malloc(sizeof(list));
    a -> val = val;
    a -> next = NULL;
    p -> next = a;
}

void insert(list *head,int i,int val){
    if (i == 0){
        list* a = malloc(sizeof(list));
        a -> val = head -> val;
        a -> next = head -> next;
        head -> next = a;
        head -> val = val;
    }
    if (i != 0){
        list *p = head;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;
        list* a = malloc(sizeof(list));
        a -> val = val;
        a -> next = p -> next;
        p -> next = a;


    }
}

void del(list *head,int i){
    if (i == 0){
        head -> val = head -> next -> val;
        head -> next = head -> next -> next;
    }
    if (i != 0){
        list *p = head;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;
        p -> next = p -> next -> next;
    }
}


