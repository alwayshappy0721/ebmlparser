#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode 
{
    XMLNode* data;
    struct QueueNode *next;
}QueueNode;
 
 
typedef struct Queue 
{
    QueueNode *front;
    QueueNode *rear; 
    int count; // number of nodes in Queue 큐 안의 노드 개수  
}Queue;

void initQueue(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
}

int isEmpty(Queue *queue)
{
    return queue->count == 0;    // 큐안의 노드 개수가 0이면 빈 상태
}

void enqueue(Queue *queue, XMLNode* data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode)); // newNode 생성
    newNode->data = data;
    newNode->next = NULL;
 
    if (isEmpty(queue))    // 큐가 비어있을 때
    {
        queue->front = newNode;       
    }
    else    // 비어있지 않을 때
    {
        queue->rear->next = newNode;    //맨 뒤의 다음을 newNode로 설정
    }
    queue->rear = newNode;    //맨 뒤를 newNode로 설정   
    queue->count++;    //큐안의 노드 개수를 1 증가
}


XMLNode* dequeue(Queue *queue)
{
    XMLNode* data;
    QueueNode *ptr;
    if (isEmpty(queue))    //큐가 비었을 때
    {
        printf("Error : Queue is empty!\n");
        return 0;
    }
    ptr = queue->front;    //맨 앞의 노드 ptr 설정 
    data = ptr->data;    // return 할 데이터  
    queue->front = ptr->next;    //맨 앞은 ptr의 다음 노드로 설정
    free(ptr);    // ptr 해제 
    queue->count--;    //큐의 노드 개수를 1 감소
    
    return data;
}
