//
//  stack_with_array.c
//  Stack
//
//  Created by seunghwan Lee on 2020/08/06.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define Max_STACK_SIZE 100 // 스택 최대 크기 100
typedef int element;
element stack[Max_STACK_SIZE]; // 1차원 배열로 크기100인 스택 만들기
int top = - 1;

// 공백 상태 검출 함수
int is_empty() {
    return (top == -1);
}

// 포화 상태 검출 함수
int is_full() {
    return (top == (Max_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item) {
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러 \n");
        return;
    } else {
        stack[++top] = item;
    }
}

element pop(){
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int main(void){
    push(1);
    push(2);
    push(3);
    push(4);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}
