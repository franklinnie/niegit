#include <stdio.h>

struct listnode{
	int data;
	struct listnode* next;
};


typedef struct listnode listnode;

void listturn(listnode *node)
{
	listnode *temp = node;
	while(node->next!=NULL) {
		temp->next->next = node;
		temp = node->next;
		node = node->next;
		printf("node data is %d\n", node->data);
	}
}

int main()
{
	listnode *node = ( listnode*)malloc(sizeof( listnode)*10);
	memset(node, 0, sizeof(listnode)*10);
	int i = 0;
		
	listnode *head = node;
	for(i = 0; i < 10; i++) {
		node->data = i+1;
		node->next = node + 1;
		node = node + 1;
		
	} 
	node->next = NULL;
	node = head;
	while(node->next != NULL )
	{
		printf("node data is %d\n", node->data);
		node = node->next;
	}
	node = head;
	listturn(node);
	head = node;
	while(node->next != NULL )
	{
		printf("node data is %d\n", node->data);
		node = node->next;
	}

	return 0; 
}
