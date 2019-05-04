#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

typedef struct node Node;
int len = 0;

Node* createNode(int val){
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	/*
	if(temp == -1){
		print("Error allocating node\n");
		exit(0);
	}
	*/
	temp->val = val;
	return temp;
}

Node* insertNode(Node* head,  int val){
	Node* newNode = createNode(val);
	if(head == NULL){
		head = newNode;
	}
	else{
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	len++;
	return head;
}

Node* deleteNode(Node* head, int val){
	if(head == NULL) {
		printf("Empty linked list\n");
	}
	else {
		Node* temp = head;
		Node* prev;
		if(head->val == val){
			head = head->next;
			printf("%d Node deleted\n", val);
		}
		else{
			while(temp != NULL && temp->val != val){
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL){
				printf("%d Node not found\n", val);
			}else{
				prev->next = temp->next;
				printf("%d Node deleted\n", val);
			}
		}
	}
	return  head;
}

void printNodes(Node* head){
	Node* temp = head;
	if(head == NULL){
		printf("Empty linked list\n");
		return;
	}
	while(temp->next != NULL){
		printf("%d\t", temp->val);
		temp = temp->next;
	}
	printf("%d\n", temp->val);
}

Node* reverseLinkedList(Node* head){
	if(head == NULL){
		printf("Empty linked list\n");
		return;
	}
	Node *start = NULL, *temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		if(start == NULL){
			start = temp;
			start->next = NULL;
		}
		else{
			temp->next = start;
			start = temp;
		}
	}
	/*
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
	*/
	return temp;
}

int main(void){
	Node* head = createNode(12);
	head = insertNode(head, 11);
	head = insertNode(head, 13);
	head = insertNode(head, 14);
	head = insertNode(head, 123);
	head = insertNode(head, 67);
	printNodes(head);
	/*
	Node* t = insertNode(NULL, 1);
	printNodes(head);
	head = deleteNode(head, 12);
	printNodes(head);
	head = deleteNode(head, 13);
	printNodes(head);
	head = deleteNode(head, 14);
	printNodes(head);
	head = deleteNode(head, 145);
	printNodes(head);
	head = deleteNode(head, 11);
	*/
	head = reverseLinkedList(head);
	printNodes(head);
	return 0;
}
