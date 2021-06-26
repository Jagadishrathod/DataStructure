#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *nptr;
};

void push(int x);
int pop();
void print();
int isFull();
int isEmpty();

struct node *top = NULL;

void main(){
	printf("-------Stack using LL-------\n");
	int choice = 1;
	while(choice > 0){
  		printf("What do you want do?\n");
  		printf("Push		-	1\n");
  		printf("Pop		-	2\n");
  		printf("Check if Full	-	3\n");
  		printf("Check if Empty	-	4\n");
  		printf("Exit		-	0\n");
  		printf("Enter Option: ");
		scanf("%d",&choice);
		
		if(choice == 1){
  			//Push
  			printf("-------Push--------\n");
			printf("Enter value: ");
			int p;
			scanf("%d",&p);
			push(p);
			print();
  		}
  		
  		if(choice == 2){
			//Pop
			if(isEmpty() == 0){
				int v = pop();	
				printf("Popped value is %d.\n",v);
			}
			else 
				printf("Cannot pop as stack is empty.\n");
				print();
		}
	
		if(choice == 3){
			//IsFull
			int f = isFull();
			if(f == 1)
				printf("\nThe Stack is Full.\n\n");
			if(f == 0)
				printf("\nThe Stack is not Full.\n\n");
		}
	
		if(choice == 4){
			//IsEmpty
			int f2 = isEmpty();
			if(f2 == 1)
				printf("\nThe Stack is Empty.\n\n");
			if(f2 == 0)
				printf("\nThe Stack is not Empty.\n\n");
		}
			
		printf("*************************\n\n");
	}
}

//Functions
void push(int x){
	struct node *temp = malloc(sizeof(struct node));
	if(temp==NULL)
		printf("No memory.\n");
	else {
		if(top==NULL){
			top=temp;
			temp->x = x;
			temp->nptr = NULL;
		}
		else {
			temp->x = x;
			temp->nptr = top;
			top = temp;
		}
	}
}

int pop(){
	int t=top->x;
	if(top->nptr==NULL){
		top=NULL;
	}
	else {
		top=top->nptr;
	}
	return t;
}

int isFull(){
	if(malloc(sizeof(struct node))==NULL)
		return 1;
	else 
		return 0;
}

int isEmpty(){
	if(top==NULL)
		return 1;
	else 
		return 0;
}

void print(){
	if(top==NULL){
		printf("No elements in stack.\n");
	}
	else {
		printf("\nElements of stack are,\n");
		struct node *tptr = top;
		int i=1;
		for(;tptr!=NULL;tptr=tptr->nptr){
			printf("Node %d: %d\n",i,tptr->x);
			i++;
		}
		printf("\n\n");
	}
}
