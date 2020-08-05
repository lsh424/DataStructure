//
//  stack-2.c
//  Recursion
//
//  Created by seunghwan Lee on 2020/08/05.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 수식 계산

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

element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }else {
        return s -> data[(s -> top)];
    }
}

// 연산자 우선순위 반환 함수
int prec(char op){
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

// 중위 표기식 -> 후위 표기식 변환 함수
void infix_to_postfix(char exp[]){
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    
    init_stack(&s);
    
    for (i=0; i<len;i++){
        ch = exp[i];
        switch(ch) {
            case '+': case '-': case '*': case '/':
                
                // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))){
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(':
                push(&s,ch);
                break;
            case ')':
                
                // 오른쪽 괄호
                top_op = pop(&s);
                
                // 왼쪽 괄호를 만날때까지 출력
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch); // 피연산자 출력
                break;
        }
    }
    while(!is_empty(&s)){
        printf("%c", pop(&s)); // 스택에 저장된 나머지 연산자들 출력
    }
}


// 후위 표기식 계산 함수
int eval(char exp[]){
    StackType s;
    
    int op1, op2, value;
    int i, n = strlen(exp);
    char ch;
    init_stack(&s);
    
    for (i = 0; i < n; i++){
        ch = exp[i];
        
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0'; // 입력: 피연산자
            push(&s, value);
        } else {
            op2 = pop(&s);
            op1 = pop(&s);
            
            switch (ch) {
                case '+':
                    push(&s, op1+op2);
                    break;
                case '-':
                    push(&s, op1-op2);
                    break;
                case '*':
                    push(&s, op1*op2);
                    break;
                case '/':
                    push(&s, op1/op2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main(void){
    
    char *s1;
    
    char *s = "(2+3)*4+9";
    printf("중위표기식 수식: %s \n", s);
    printf("후위표기식 수식: ");
    infix_to_postfix(s);
//    printf("\n");
    printf("%s\n", s1);
    printf("\n");
    
    int result;
    printf("후위표기식: 82/3-32*+ \n");
    result = eval("82/3-32*+");
    printf("결과: %d \n", result);
    return 0;
}
