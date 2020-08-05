//
//  stack_wtith_struct.c
//  Stack
//
//  Created by seunghwan Lee on 2020/08/06.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType *s){
    s -> top = -1;
    s -> capacity = 1;
    s -> data = (element *)malloc((s -> capacity)*sizeof(element));
}

int is_empty(StackType *s) {
    return (s -> top == -1);
}

int is_full(StackType *s) {
    return (s -> top == s -> capacity);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        s -> capacity *= 2;
        s -> data = (element *)realloc(s -> data, sizeof(s -> capacity*sizeof(element)));
    }

    s -> data[++(s->top)] = item;

}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }else {
        return s -> data[(s -> top)--];
    }
}

int main(void) {
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}


// realloc 함수 - 이미 할당한 공간의 크기를 바꿀 때 realloc 함수를 사용한다.
