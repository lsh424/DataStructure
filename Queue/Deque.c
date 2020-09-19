//
//  Deque.c
//  Deque
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
} DequeType;

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *q){
    q -> front = 0;
    q -> rear = 0;
}

int is_full(DequeType *q){
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

int is_empty(DequeType *q){
    return (q->front == q ->rear);
}

void deque_print(DequeType *q) {
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

// 삽입 함수

void add_front(DequeType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    
    q -> data[q->front] = item;
    q -> front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(DequeType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    
    q -> rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q -> data[q->rear] = item;
}

// 삭제 함수

element delete_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    
    q -> front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q->front];
}

element delete_rear(DequeType *q){
    int prev = q -> rear;
    
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    
    q -> rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q -> data[prev];
}
                 
int main(void) {
    DequeType q;
    init_deque(&q);
    
    for(int i = 0;i < 4; i++){
        if (i < 2){
            add_front(&q, i);
        }else{
            add_rear(&q, i);
        }
        deque_print(&q);
    }
    
    printf("\n");
    
    for(int i = 0;i < 4; i++){
        
        if (i<2){
            delete_rear(&q);
        }else{
            delete_front(&q);
        }
        deque_print(&q);
    }
    return 0;
}
