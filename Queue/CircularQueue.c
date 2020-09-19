//
//  CircularQueue.c
//  CircularQueue
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
    q -> front = 0;
    q -> rear = 0;
}

void queue_print(QueueType *q) {
    printf("front: %d, rear: %d \n", q -> front, q -> rear);
    
    if (!is_empty(q)){
        int i = q -> front;
        do{
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%d |", q->data[i]);
            if (i == q -> rear){
                break;
            }
        } while(i != q->front);
    }
    printf("\n");
}

int is_full(QueueType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
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
    
    q -> rear = (q-> rear+1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
}

// dequeue
int dequeue(QueueType *q) {
    if (is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q->front];
}
                 
int main(void) {
    QueueType q;
    int element = 10;
    
    init_queue(&q);
    
    printf("데이터 추가 단계 \n\n");
    
    while(!is_full(&q)){
        enqueue(&q, element);
        queue_print(&q);
        element += 10;
    }
    printf("큐 포화상태 \n\n");
    
    printf("데이터 삭제 단계 \n\n");
    
    while(!is_empty(&q)){
        element = dequeue(&q);
        printf("꺼낸 정수: %d \n", element);
        queue_print(&q);
    }
    
    printf("큐 공백상태 \n\n");
    return 0;
}
