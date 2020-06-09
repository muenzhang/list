#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
    int len;
}list;

list* listCreate(){
	list *a = (list*)malloc(sizeof(list));
	a -> next = NULL;
	a -> val = -1;
	a -> len = 0;
	list *head = a;
	
	return head;
}

int len(list* head){
	return head -> len;
}

list* get(list *head,int number){
	if (head -> len <= number){
		printf("IndexError: list index out of range len(list) = %d,number = %d\n",len(head),number);
		exit(-1);
		return NULL;
	}
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
		head -> len += 1;
		return head;
	}
    
    while(p && p -> next){
        p = p -> next;
    }

    list *a = (list*)malloc(sizeof(list));
    a -> val = val;
    a -> next = NULL;
    
    p -> next = a;
    
    head -> len += 1;
    
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
	if (head -> len < i){
		printf("IndexError: list index out of range len(list) = %d,number = %d\n",len(head),i);
		exit(-1);
		return NULL;
	}
	
    if (i == 0){
    	if (!head -> next){
			list *a = (list*)malloc(sizeof(list));
			a -> val = val;
			a -> next = NULL;
			head -> next = a;
			head -> len += 1;
			return head;
		}

		list *a = (list*)malloc(sizeof(list));
        a -> val = head -> next -> val;
        a -> next = head -> next -> next;
        head -> next -> next = a;
        head ->  next -> val = val;
        head -> len += 1;
    }
    
    if (i != 0){
        list *p = head -> next;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;
        list* a = (list*)malloc(sizeof(list));
        a -> val = val;
        a -> next = p -> next;
        p -> next = a;
        head -> len += 1;


    }
}

int del(list *head,int i){
	
	if (len(head) <= i){
		printf("IndexError: list assignment index out of range.len(list) = %d,number = %d\n",len(head),i);
		exit(-1);
		return -1;
	}
	
	if (i == 0){
		if (!head -> next -> next){
			list *p = head -> next;
			head -> next = NULL;
			head -> len -= 1;
			free(p);
			return 0;
		}
		if (!head -> next -> next -> next){
			list *p = head -> next;
			head -> next = head -> next -> next;
			head -> len -= 1;
			free(p);
			return 0;
		}
		
  		head -> next -> val = head -> next -> next -> val;
  		list *p = head -> next -> next;
		head -> next -> next = head -> next -> next -> next;
		head -> len -= 1;
		free(p);
	}
    if (i != 0){
        list *p = head -> next;
        for(int j = 1;j < i && p -> next;j++)
            p = p -> next;

		list *p2 = p -> next;
        p -> next = p -> next -> next;
        head -> len -= 1;
        free(p2);
    }
}
