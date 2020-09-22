#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE	100

typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SeQueue;

typedef SeQueue CSqQueue;

void InitQueue(CSqQueue *pQ)
{
	pQ->front = pQ->rear = 0;
}

bool QuEmpty(CSqQueue pQ)
{
	return (pQ.front == pQ.rear);
}

bool QuFull(CSqQueue pQ)
{
	if (pQ.front == (pQ.rear + 1) % MAXSIZE)
		return 1;
	return 0;
}

int EnQueue(CSqQueue *pQ, ElemType e)
{
	if (QuFull(*pQ))
		return -1;
	pQ->data[pQ->rear] = e;
	pQ->rear = (pQ->rear + 1) % MAXSIZE;
	return 1;
}

int DeQueue(CSqQueue *pQ, ElemType &e)
{
	if (QuEmpty(*pQ))
		return -1;
	e = pQ->data[pQ->front];
	pQ->front = (pQ->front + 1) % MAXSIZE;
	return 1;
}

void ShowQueue(CSqQueue pQ)
{
	while (pQ.front != pQ.rear)
	{
		printf("%d ", pQ.data[pQ.front]);
		pQ.front++;
	}
}

int LenQueue(CSqQueue pQ)
{
	return (pQ.rear - pQ.front + MAXSIZE) % MAXSIZE;
}

int CreateQueue(CSqQueue *pQ)
{
	int i, n;
	ElemType e;
	printf("Please enter the length of queue: ");
	scanf_s("%d", &n);
	if (n > MAXSIZE)
		return -1;
	for (i = 1; i <= n; i++)
	{
		printf("Please enter NO.%d enter element: ", i);
		scanf_s("%d", &e);
		EnQueue(pQ, e);
	}
	return 1;
}

int main()
{
	int e;
	CSqQueue *pQ = (CSqQueue*)malloc(sizeof(CSqQueue));
	InitQueue(pQ);
	CreateQueue(pQ);

	printf("Element of queue: ");
	ShowQueue(*pQ);
	printf("\n");

	printf("Length of queue: ");
	printf("%d", LenQueue(*pQ));
	printf("\n");

	printf("Delete Element: ");
	printf("%d", DeQueue(pQ, e));
	printf("\n");
	printf("Delete Element: %d", e);
	printf("\n");
	printf("Element of queue: ");
	ShowQueue(*pQ);
	printf("\n");
	
	printf("Add Element: ");
	printf("%d", EnQueue(pQ, 100));
	printf("\n");
	printf("Element of queue: ");
	ShowQueue(*pQ);
	printf("\n");
	printf("Length of queue: ");
	printf("%d", LenQueue(*pQ));
	printf("\n");

	system("pause");
	return 0;
}