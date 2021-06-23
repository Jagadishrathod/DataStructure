#include<stdio.h>
#include<stdlib.h>

struct Tnode
{
	int data;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};

void insert(int x);
void Min(struct Tnode *ptr);
void Max(struct Tnode *ptr);
void LevelOrder(struct Tnode *ptr);
void Inorder(struct Tnode *ptr);
void delete(int x);
void Level(struct Tnode *ptr,int level);
int height(struct Tnode *ptr);


struct Tnode *rptr = NULL;

void insert(int x){
   	struct Tnode *tmp = malloc(sizeof(struct Tnode));
	tmp->data = x;
	tmp->lcptr = NULL;
   	tmp->rcptr = NULL;
   	if(rptr == NULL){	
		rptr = tmp;
	}
	else{
		struct Tnode *ptr = rptr;
		struct Tnode *pptr = NULL;
    	while(ptr != NULL){
			pptr = ptr;
         	if(x < ptr->data){
				ptr = ptr->lcptr;	
			}
			else{
				ptr = ptr->rcptr;
			}
		}
		if(x < pptr->data)
			pptr->lcptr = tmp;
		else
			pptr->rcptr = tmp;	
	}	

}
void Inorder(struct Tnode *ptr){
	if(ptr != NULL){
		Inorder(ptr->lcptr);
		printf("%d ",ptr->data);
		Inorder(ptr->rcptr);
	}
}
void LevelOrder(struct Tnode *ptr){
	if(ptr != NULL){
		int h = height(ptr);
		for(int i = 1; i <= h; i++ )
			Level(ptr,i);
	}
}
void Level(struct Tnode *ptr, int level){
	if(ptr != NULL){
		if(level == 1)
			printf("%d ",ptr->data);
		else if(level>1){
			Level(ptr->lcptr, level-1);
			Level(ptr->rcptr, level-1);
		}
	}
}
int height(struct Tnode *ptr){
	if(ptr == NULL)
		return 0;
	else {
		int lh = height(ptr->lcptr);
		int rh = height(ptr->rcptr);
		if(lh>rh)
			return (lh+1);
		else 
			return (rh+1);
	}
}
void Min(struct Tnode *ptr){
	while(ptr->lcptr != NULL)
	ptr = ptr->lcptr;
	printf("\nThe minimum element is %d.\n",ptr->data);
}
void Max(struct Tnode *ptr){
	while(ptr->rcptr != NULL)
		ptr = ptr->rcptr;
		printf("\nThe maximum element is %d.\n",ptr->data);
}
void delete(int x){	
   	struct Tnode *ptmp = NULL;
	struct Tnode *ptr = rptr;
	struct Tnode *pptr = NULL;	
	while(ptr != NULL && ptr->data != x){
		pptr = ptr;		
		if(x >= ptr->data)
			ptr = ptr->rcptr;	
		else 
			ptr = ptr->lcptr;
	}	
	if(ptr == NULL){
		printf("\n Deletion Fails\n");
	}
	else if(rptr->lcptr == NULL && rptr->rcptr == NULL){		
		rptr = NULL;	
	}
	else if(ptr->lcptr == NULL && ptr->rcptr == NULL){		
		if(x < pptr->data)
			pptr->lcptr = NULL;
		else
			pptr->rcptr = NULL;
	}
	else if(ptr->lcptr == NULL && ptr->rcptr != NULL || ptr->lcptr != NULL && ptr->rcptr == NULL){		
		if(x < pptr->data && ptr->lcptr != NULL)
			pptr->lcptr = ptr->lcptr;		
		else if(x < pptr->data && ptr->lcptr == NULL)
			pptr->lcptr = ptr->rcptr;
		else if(x >= pptr->data && ptr->lcptr != NULL)
			pptr->rcptr = ptr->lcptr;
		else
			pptr->rcptr = ptr->rcptr;   
	}
	else{		
		struct Tnode *tmp=ptr;
   	  	ptmp = tmp;		
		tmp = tmp->rcptr;
		while(tmp->lcptr != NULL){
       		ptmp = tmp;
			tmp = tmp->lcptr;
		}		
		ptr->data = tmp->data;	 
       	if(tmp->data < ptmp->data)
         	ptmp->lcptr = tmp->rcptr;
       	else
       		ptmp->rcptr = tmp->rcptr;

	}
}

void main(){
	printf("---Min, Max and Level Order---\n");
	int choice = 1;
  	while(choice > 0){
  		printf("What do you want do? \n");
  		printf("Insert		-	1\n");
  		printf("Delete		-	2\n");
  		printf("Minimum		-	3\n");
  		printf("Maximum		-	4\n");
  		printf("Level Order	-	5\n");
  		printf("Print 		-	6\n");
  		printf("Exit		-	0\n");
  		printf("Enter Option:\t\t");
		scanf("%d",&choice);
		
		if(choice == 1){
  			//Insert
  			int x;
  			printf("-----------Insert------------\n");
			printf("Enter value: ");
			scanf("%d",&x);
			insert(x);
  		}
  		if(choice == 2){
			//Delete
			int a;
			printf("------------Delete-------------\n");
			printf("Enter value to delete: ");
			scanf("%d",&a);
			delete(a);
		}
		if(choice == 3){
			//Minimum
			if(rptr == NULL)
				printf("\nNo minimum as BST is Empty.\n");
			else
				Min(rptr);
		}
		if(choice == 4){
			//Maximum
			if(rptr == NULL)
				printf("\nNo maximum as BST is Empty.\n");
			else
				Max(rptr);
		}
		if(choice == 5){
			//LevelOrder
			if(rptr == NULL)
				printf("\nBST is Empty.\n");
			else {
				LevelOrder(rptr);
				printf("\n\n");
			}
		}
		if(choice == 6){
			//Inorder
			if(rptr == NULL)
				printf("\nBST is Empty.\n");
			else {
				Inorder(rptr);
				printf("\n\n");
			}
		}
		
		printf("**************************\n\n");
	}
}

