#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[25];
    int score;
    struct node *next;
} node;
//insert node at head
void create(node **head,char *name,int score){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->score = score;
    temp->next = NULL;
    if(head==NULL){
        *head = temp;
    }
    else{
        temp->next = *head;
        *head = temp;
    }
}
//find mid and split
void split(node *first,node **a,node **b){

    node *fast;
    node *slow;

    fast = first->next;
    slow = first;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *b = slow->next;

    *a = first;
    slow->next = NULL;

    
}
//merge the node
node *merge(node *a,node *b){

    node *result;

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    if(a->score>b->score){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(b->next, a);
    }

    return result;
}

void mergesort (node **head){
    node *first = *head;
    node *a;
    node *b;

    if((first==NULL)||(first->next==NULL)){
        return;
    }

    split(first, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *head = merge(a,b);
}

void print(node **head){

    node *temp = *head;
    printf("name score\n");
    while(temp!=NULL){
        printf("%s %d\n",temp->name,temp->score);
        temp = temp->next;
    }
}
int main(){
    int time,score;

    printf("Number of records you want to key in:");
    scanf("%d", &time);
    node *head = NULL;

    char name[25];

    while(time--){
        printf("Enter name & score:");
        scanf(" %s %d", name, &score);
        create(&head, name, score);
    }
    mergesort(&head);
    print(&head);
}
