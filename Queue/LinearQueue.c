//
//  LinearQueue.c
//  LinearQueue
//
//  Created by seunghwan Lee on 2020/09/19.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
    
} QueueType;

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q -> front = -1;
    q -> rear = -1;
}

void queue_print(QueueType *q) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++){
        if(i <= q -> front || i > q->rear){
            printf(" |");
        }else{
            printf("%d |", q ->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){
    if (q->rear == MAX_QUEUE_SIZE - 1){
        return 1;
    }else{
        return 0;
    }
}

int is_empty(QueueType *q) {
    return (q->front == q ->rear);
}

// enqueue
void enqueue(QueueType *q, int item) {
    if (is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q -> data[++(q->rear)] = item;
}

// dequeue
int dequeue(QueueType *q) {
    if (is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item = q -> data[++(q->front)];
    return item;
}
                 
int main(void) {
    QueueType q;
    
    init_queue(&q);
    
    enqueue(&q, 10);
    queue_print(&q);
    enqueue(&q, 20);
    queue_print(&q);
    enqueue(&q, 30);
    queue_print(&q);
    
    dequeue(&q);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);
    
    return 0;
}
