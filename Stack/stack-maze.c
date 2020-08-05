//
//  stack-maze.c
//  Stack
//
//  Created by seunghwan Lee on 2020/08/05.
//  Copyright © 2020 LSH. All rights reserved.
//

#include <stdio.h>

// 미로탐색 문제

typedef struct {
    short r;
    short c;
} element;

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

element here = {1,0}, entry = {1,0};


// 미로, 1 = 벽 e = 입구 x = 출구
char maze[6][6] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

// 위치 스택에 삽입
void push_loc(StackType *s, int r, int c){
    if (r < 0 || c <0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s,tmp);
    }
}

// 미로 화면 출력
void maze_print(char maze[6][6]) {
    printf("\n");
    for(int r = 0; r < 6; r++){
        for (int c = 0; c < 6; c++){
            printf("%c",maze[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    int r,c;
    StackType s;
    
    init_stack(&s);
    here = entry;
    
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c+1);
        push_loc(&s, r, c-1);
        
        if(is_empty(&s)) {
            printf("실패 \n");
            return 0;
        } else {
            here = pop(&s);
        }
    }
    printf("성공 \n");
    return 0;
}


