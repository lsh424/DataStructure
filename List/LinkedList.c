//
//  LinkedList.c
//  List
//
//  Created by seunghwan Lee on 2020/12/01.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

// 첫 노드 삽입
ListNode* insert_first(ListNode *head, int value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = head;
    head = p;
    return head;
}

// 특정 노드 뒤 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    
    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;
    return head;
}

// 첫번째 노드 삭제
ListNode* delete_first(ListNode *head){
    ListNode *removed;
    
    if (head == NULL){
        return NULL;
    }
    
    removed = head;
    head = removed -> link;
    free(removed);
    return head;
}

// pre가 가리키는 노드의 다음 노드 삭제
ListNode* delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed = pre -> link;
    pre -> link = removed -> link;
    free(removed);
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p -> link){
        printf("%d ->", p -> data);
    }
    printf("NULL \n");
}

int main(void){
    ListNode *head = NULL;
    
    for (int i = 0; i <5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    
    for (int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }
    
    return 0;
}
