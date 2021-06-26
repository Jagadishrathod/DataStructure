#include<stdio.h>

struct CircularQueue
{
  	int a[5];
  	int rear;
  	int front;
  	int size;
};

void enqueue(struct CircularQueue *pq, int x);
int dequeue(struct CircularQueue *pq);
void print(struct CircularQueue q);
int isFull(struct CircularQueue q);
int isEmpty(struct CircularQueue q);
int search(struct CircularQueue q,int si);

void main(){
	struct CircularQueue q;
	q.front = -1;
	q.rear = -1;
	q.size = 5;
	printf("---------Circular Queue---------\n");
	
	int choice = 1;
  	while(choice > 0){
  		printf("What do you want do?\n");
  		printf("Insert		-	1\n");
  		printf("Delete		-	2\n");
  		printf("Check if Full	-	3\n");
  		printf("Check if Empty	-	4\n");
  		printf("Search 		-	5\n");
  		printf("Exit		-	0\n");
  		printf("Enter Option: ");
		scanf("%d",&choice);
		
		if(choice == 1){
  			//Enqueue
  			printf("-------------Insert--------------\n");
			printf("Enter value: ");
			int val = 0;
			scanf("%d",&val);
			enqueue(&q,val);
			print(q);
  		}
  		
  		if(choice == 2){
			//Dequeue
			printf("-------------Delete--------------\n");
			int v = dequeue(&q);
			if(v != -555){
				printf("Value deleted: %d\n",v);
				print(q);
			}
			
		}
	
		if(choice == 3){
			//IsFull
			int f = isFull(q);
			if(f == 1)
				printf("\nThe Queue is Full.\n\n");
			if(f == 0)
				printf("\nThe Queue is not Full.\n\n");
		}
	
		if(choice == 4){
			//IsEmpty
			int f2 = isEmpty(q);
			if(f2 == 1)
				printf("\nThe Queue is Empty.\n\n");
			if(f2 == 0)
				printf("\nThe Queue is not Empty.\n\n");
		}
		
		if(choice == 5){
			//Confirmed List search
			printf("-------------Search---------------\n");
			int p = 0;
			printf("Enter a value to search: ");
			scanf("%d",&p);
			int f2 = search(q,p);
			if(f2 == -1){
				printf("Entered value %d is NOT found in the queue.\n",p);
			}
			else {
				printf("Entered value %d exists in the Queue as element %d.\n",p,f2 + 1);
			}
		}
		
		printf("********************************\n\n");
	}
	
	
}

void enqueue(struct CircularQueue *pq, int x){
	//Boundary Conditions
	if((pq->rear + 1)% pq->size == pq->front)
		printf("\nCannot insert values as the queue is already full.\n\n");
	//Empty Condition
	else if(pq->front == -1 && pq->rear == -1){
		pq->front++;
		pq->rear++;
		pq->a[pq->rear] = x;
	}
	else {
		pq->rear = (pq->rear + 1)% pq->size;
		pq->a[pq->rear] = x;
	}
}

int dequeue(struct CircularQueue *pq){
	int temp = -555;
	//Boundary Conditions
	if(pq->front == -1 && pq->rear == -1)
		printf("\nCannot delete as the queue is already empty.\n\n");	
	else if(pq->rear == pq->front){
		temp = pq->a[pq->rear];
		pq->front = -1;
		pq->rear = -1;
	}	
	else {
		temp = pq->a[pq->front];
		pq->front = (pq->front + 1)% pq->size;
	}
	return (temp);
}

void print(struct CircularQueue q){
	if(q.front == -1)
		printf("\n\nQueue is empty.\n\n");
	else {
		printf("Elements of queue are,\n");
		if(q.front > q.rear){
			for(int i = q.front;i < q.size;i++){
				printf("Element %d: %d\n",i,q.a[i]);
			}
			for(int i = 0;i < q.rear + 1;i++){
				printf("Element %d: %d\n",i,q.a[i]);
			}
		}
		else {
			for(int i = q.front;i < q.rear + 1; i++){
				printf("Element %d: %d\n",i,q.a[i]);
			}
		}
		
	}
}

int isFull(struct CircularQueue q){
	if((q.rear + 1)% q.size == q.front)
		return 1;
	else 
		return 0;
}

int isEmpty(struct CircularQueue q){
	if(q.front == -1 && q.rear == -1)
		return 1;
	else 
		return 0;
}

int search(struct CircularQueue q, int si){
	int so = -1;
	int y = 0;
	if(q.front != -1 && q.rear != -1){
		for(int i = q.front;i < q.rear + 1;i = (i + 1)%q.size){
			if(q.a[i] == si){
				so++;
				i = q.rear + 1;
				y = 1;
				break;
			}
			else 
				so++;
		}
	}
	else 
		printf("\nCannot search as queue is empty.\n\n");
	if(y==0)
		so=-1;
		return so;
}

