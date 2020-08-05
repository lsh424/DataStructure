//
//  stack-parenthesis.c
//  Stack
//
//  Created by seunghwan Lee on 2020/08/05.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>

//괄호 검사 알고리즘

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

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in); // n = 문자열 길이
    init_stack(&s);
    
    for (i = 0; i < n; i++){
        ch = in[i];
        
        switch (ch){
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if (is_empty(&s)) return 0;
                else {
                    open_ch = pop(&s);
                    if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
                        return 0;
                    }
                    break;
                }
        }
    }
    
    if (!is_empty(&s)) return 0; // 스택이 남아있으면 오류 발생
    return 1;
}

int main(void)
{
    char *p = "{A[(i+1)]=0}";
    
    if (check_matching(p) == 1) {
        printf("%s 괄호 검사 성공 \n", p);
    } else {
        printf("%s 괄호 검사 실패 \n", p);
    }
    return 0;
}
