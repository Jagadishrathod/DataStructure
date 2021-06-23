#include<stdio.h>

struct stack{
	int top;
	int n[200];
};

void push(struct stack *p, int x);
int pop(struct stack *p);
void Evaluate(struct stack *p, char e[], int s);

void push(struct stack *p, int x){
	if(p->top == 199)
		printf("Given expression is too large.\n");
	else {
		p->top++;
		p->n[p->top] = x;
	}
}
int pop(struct stack *p){
	int popval = -967;//ERROR CODE
	if(p->top == -1)
		printf("Please enter a valid postfix expression.\n");
	else {
		popval = p->n[p->top];
		p->top--;
	}
	return popval;
}
void Evaluate(struct stack *p, char e[], int s){
	for(int i = 0; i < s; i++){
		if(e[i] > 47 && e[i] < 58){
			int temp = e[i];
			temp = temp - 48;
			push(p, temp);
		}
		else if(e[i] == '+'){
			int n1 = pop(p);
			int n2 = pop(p);
			int n = n1 + n2;
			if(n1 != -967 && n2 != -967){
				push(p, n);
			}
			else i = s + 1;
		}
		else if(e[i]=='-'){
			int n1 = pop(p);
			int n2 = pop(p);
			int n = n2-n1;
			if(n1 != -967 && n2 != -967){
				push(p, n);
			}
			else
				i = s + 1;
		}
		else if(e[i]=='*'){
			int n1 = pop(p);
			int n2 = pop(p);
			int n = n1 * n2;
			if(n1 != -967 && n2 != -967){
				push(p, n);
			}
			else
				i = s + 1;
		}
		else if(e[i] == '/'){
			int n1 = pop(p);
			int n2 = pop(p);
			int n = n2/n1;
			if(n1 != -967 && n2 != -967){
				push(p, n);
			}
			else
				i = s + 1;
		}
	}
	if(p->top != 0)
		printf("\nEntered expression is invalid.\n");
	else
		printf("\nThe answer is: %d\n",p->n[0]);
}

int main(){
	printf("---------Postfix----------\n");
	int t = 0;
	struct stack s;
	char exp[200];
	int len = 0;
	while(t == 0){
		s.top = -1;
		printf("Enter the postfix expression: ");
		scanf("%s",exp);
		printf("\nEntered Expression: %s%n\n",exp, &len);	
		len = len -21;
		Evaluate(&s, exp, len);
		printf("Do you want to exit (0 for no 1 for yes): ");
		scanf("%d",&t);
		printf("\n\n**************************\n\n");
	}
	
	return 0;
}



