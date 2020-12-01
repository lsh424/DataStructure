//
//  CircularLinkedList.c
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

// 원형 연결 리스트의 처음에 삽입
ListNode* insert_first(ListNode *head, element data){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node -> data = data;
    if (head == NULL){
        head = node;
        node -> link = head;
    }else{
        node -> link = head -> link;
        head -> link = node;
    }
    return head;
}

// 원형 연결 리스트 끝에 삽입
ListNode* insert_last(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    
    node -> data = data;
    
    if (head == NULL){
        head = node;
        node -> link = head;
    }else{
        node -> link = head -> link;
        head -> link = node;
        head = node;
    }
    return head;
}


void print_list(ListNode *head){
    ListNode *p;
    
    if(head == NULL){
        return;
    }
    
    p = head -> link;
    do{
        printf("%d->", p->data);
        p = p ->link;
    } while(p != head);
    printf("%d->", p -> data);
}

int main(void){
    ListNode *head = NULL;
    
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    printf("\n");
    
    return 0;
}
