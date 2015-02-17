#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

void printNode(struct node* n)
{
	// in java n.data
	printf("data=%d\n", n->data);
}

int main (int foo, char *bar[])
{
	struct node *head =  malloc(sizeof(struct node));
	head->data = -1;

	struct node *curr = head;
	//C99 syntax
	for(int i =0;i<10;i++){
		curr->next = malloc(sizeof(struct node));
		curr->next->data = i;
		curr = curr->next;
	}
	curr = head;
	while(curr){
		printNode(curr);
		curr = curr->next;
	}

	return 0;
}
