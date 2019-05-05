#include<stdio.h>
#include<stdlib.h>

struct queue{
	int arr[100];
	int len;

	void init() {
		len = -1;
	}
		
	int isEmpty(){
		if(len == -1) return 0;
		return 1;
	}

	int size() {
		return (len + 1);
	}

	void Enqueue(int val) {
		if(len == 100) {
			printf("Queue is full\n");
		}
		else {
			arr[++len] = val;
		}
	}
	
	int Dequeue() {
		if(len == -1) {
			printf("Queue is empty\n");
			return -1;
		}
		return arr[len--];
	}

	void print() {
		int i = 0;
		while(i < len)
			printf("%d\t", arr[i++]);
		printf("\n");
	}
};

typedef struct queue Queue;

struct stack{
	Queue *q1;
	Queue *q2;
	int top;
	int count, size;

	void init() {
		q1 = (Queue*)malloc(sizeof(Queue));
		q1->init();
		q2 = (Queue*)malloc(sizeof(Queue));
		q2->init();
		top = -1;
	}

	void push(int val) {
		if(top == 100) {
			printf("Stack is full\n");
			return;
		}
		if(q1->isEmpty() == 0) {
			q1->Enqueue(val);
		}
		else {
			count = 0;
                        size = q1->size();
                        while(count < size) {
                                q2->Enqueue(q1->Dequeue());
                                count++;
                        }
                        q1->Enqueue(val);
		}
		top++;
	}

	int pop() {
		if(top == -1) {
			printf("Stack is empty\n");
			return -1;
		}
		if(q1->isEmpty() == 0) {
			if(q2->isEmpty()) {
				printf(".Stack is empty\n");
				return -1;
			}
			count = 0;
			size = q2->size();
			while(count < (size - 1)) {
				q2->Enqueue(q2->Dequeue());
				count++;
			}
			return q2->Dequeue();
		}
		else {
			return q1->Dequeue();
		}
		top--;
	}

	void print() {
		q1->print();
		q2->print();
	}
};

typedef struct stack Stack;

int main(void) {
	Stack s;

	s.init();	

	s.push(12);
	s.print();
	s.push(13);
	s.print();
	s.push(14);
	s.print();

	printf("%d\n", s.pop());
	s.print();
	printf("%d\n", s.pop());
	printf("%d\n", s.pop());
	printf("%d\n", s.pop());

	return 0;
}
