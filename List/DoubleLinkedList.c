//
//  DoubleLinkedList.c
//  List
//
//  Created by seunghwan Lee on 2020/12/01.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
}DListNode;

// 이중 연결 리스트 초기화
void init(DListNode *phead){
    phead -> llink = phead;
    phead -> rlink = phead;
}

// 새로운 데이터 before노드 오른쪽에 삽입
void insert(DListNode *before, element data){
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode -> data = data;
    newnode -> llink = before;
    newnode -> rlink = before -> rlink;
    before -> rlink -> llink = newnode;
    before -> rlink = newnode;
}

// 노드 삭제
void delete(DListNode *head, DListNode *removed){
    if (removed == head){
        return;
    }
    
    removed -> llink -> rlink = removed -> rlink;
    removed -> rlink -> llink = removed -> llink;
    free(removed);
}

void print_dlist(DListNode *phead){
    DListNode *p;
    for(p = phead ->rlink; p!= phead; p = p ->rlink){
        printf("<-| |%d| | ->", p -> data);
    }
    printf("\n");
}

int main(void){
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    
    printf("삽입 \n");
    for(int i =0; i <5; i++){
        // 헤드 노드 오른쪽에 새로운 노드 삽입
        insert(head,i);
        print_dlist(head);
    }
    
    printf("삭제 \n");
    for(int i = 0; i < 5; i++){
        print_dlist(head);
        delete(head, head -> rlink);
    }
    free(head);
    return 0;
}
