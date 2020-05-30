#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
}list;

list* listCreate(){
	list *a = (list*)malloc(sizeof(list));
	a -> next = NULL;
	a -> val = -1;
	list *head = a;
	return head;
}

int len(list* head){
	list *p = head -> next;
	int count = 1;
	while (p -> next && head){
		p = p -> next;
		count++;
	}
	return count;
}

list* get(list *head,int number){
    list *p = head -> next;
    for(int i = 0;i < number && p -> next;i++){
        p = p -> next;
    }
    return p;
}

list* append(list *head,int val){
	
    list *p = head -> next;
    
    if (!p){
    	list *a = (list*)malloc(sizeof(list));
    	a -> val = val;
    	a -> next = NULL;
		head -> next = a;
		return head;
	}
    
    while(p && p -> next){
        p = p -> next;
    }

    list *a = (list*)malloc(sizeof(list));
    a -> val = val;
    a -> next = NULL;
    
    p -> next = a;
    
	return head;
    	
}


int search(list* head,int j){
	for (int i = 1;i < len(head);i++){
		if (get(head,i) -> val == j){
			return i;
		}
	}
	return -1;
}

list* insert(list *head,int i,int val){
	
	
    if (i == 0){
    	if (!head -> next){
			list *a = (list*)malloc(sizeof(list));
			a -> val = val;
			a -> next = NULL;
			head -> next = a;
			return head;
		}

		list *a = (list*)malloc(sizeof(list));
        a -> val = head -> next -> val;
        a -> next = head -> next -> next;
        head -> next -> next = a;
        head ->  next -> val = val;
    }
    
    if (i != 0){
        list *p = head -> next;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;
        list* a = (list*)malloc(sizeof(list));
        a -> val = val;
        a -> next = p -> next;
        p -> next = a;


    }
}

int del(list *head,int i){
	
	if (i == 0){
		if (!head -> next -> next){
			list *p = head -> next;
			head -> next = NULL;
			free(p);
			return 0;
		}
		if (!head -> next -> next -> next){
			list *p = head -> next;
			head -> next = head -> next -> next;
			free(p);
			return 0;
		}
		
  		head -> next -> val = head -> next -> next -> val;
  		list *p = head -> next -> next;
		head -> next -> next = head -> next -> next -> next;
		free(p);
	}
    if (i != 0){
        list *p = head -> next;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;

		list *p2 = p -> next;
        p -> next = p -> next -> next;
        free(p2);
    }
}
