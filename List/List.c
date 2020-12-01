//
//  List.c
//  List
//
//  Created by seunghwan Lee on 2020/12/01.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 // 리스트 최대 크기
typedef int element;

typedef struct {
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리
void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화
void init(ArrayListType *L){
    L -> size = 0;
}

int is_empty(ArrayListType *L){
    return L -> size == 0; // 비어있으면 1, 그렇지 않으면 0 반환
}

int is_full(ArrayListType *L) {
    return L -> size == MAX_LIST_SIZE; // 가득 찼으면 1 그렇지 않으면 0 반환
}

element get_entry(ArrayListType *L, int pos){
    if (pos < 0 || pos >= L -> size){
        error("위치 오류");
    }
    return L -> array[pos];
}

void print_list(ArrayListType *L) {
    int i;
    for (i = 0; i < L -> size; i++){
        printf("%d->", L -> array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *L, element item){
    if(L->size >= MAX_LIST_SIZE){
        error("List Overflow");
    }
    L -> array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L) && (pos>=0) && (pos<= L->size)) {
        for(int i = (L -> size - 1); i >= pos; i--){
            L -> array[i+1] = L -> array[i];
        }
        L -> array[pos] = item;
        L -> size++;
    }
}

element delete(ArrayListType *L, int pos){
    element item;
    
    if (pos < 0 || pos >= L -> size){
        error("위치 오류");
    }
    
    item = L -> array[pos];
    
    for (int i = pos; i<(L->size - 1); i++){
        L -> array[i] = L -> array[i+1];
    }
    L -> size--;
    return item;
}

int main(void){
    ArrayListType list;
    
    init(&list);
    
    insert(&list, 0, 10); // 0번째 위치에 10 추가
    print_list(&list);
    insert(&list, 0, 20); // 0번째 위치에 20 추가
    print_list(&list);
    insert(&list, 0, 30); // 0번째 위치에 30 추가
    print_list(&list);
    insert_last(&list, 40); // 맨 끝에 40 추가
    print_list(&list);
    delete(&list,0); // 0번째 항목 삭제
    print_list(&list);
    return 0;
}







