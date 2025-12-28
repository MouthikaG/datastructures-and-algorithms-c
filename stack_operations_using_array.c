#define MAX 100
int stack[MAX];

typedef struct Node{
	int data;
	struct node * next;
	node;
};

void create stack(){
	top=-1;
}

void push(int X){
	if top(top==MAX-1){
		printf("stack is full! insertion not possible.\n");
		return;}
		stack [++top]=X;
	}
	
	int pop(){
		if(top==-1){
			printf("stack is empty!deletion not possible.\n");
			return -1;
		}
	}
}
return 0;
}
