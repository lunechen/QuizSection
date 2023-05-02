#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_student_number 40
#define no_exchange 1
#define exchange 0

struct info{
    char name[20];
    int grade;
}CLASS[MAX_student_number];

void Bubble_sort(struct info arr[], int num){
    struct info temp;
    int flag = 0;
    for(int i = 1; (i < num) && (flag != no_exchange); i++){ //i:the exchange times need
        flag = no_exchange;
        for(int j = 0; j < num - i; j++){ //after exchanging, the last one must be the biggest
            if(arr[j].grade > arr[j+1].grade){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = exchange;
            }
        }
    }
}

int main(){
    printf("Number of records you want to key in:");
    int student_number;
    scanf("%d", &student_number);//scan '\n' char with ' '

    //keep inputing information
    for(int i = 0; i < student_number; i++){
        printf("Enter name & score:");
        scanf(" %20s %d", CLASS[i].name, &CLASS[i].grade);
    }

    //Sort
    Bubble_sort(CLASS, student_number);


    //outcome
    printf("name score\n");
    for(int i = student_number - 1; i >= 0; i--){
        printf("%s %d\n", CLASS[i].name, CLASS[i].grade);
    }
    return 0;
}
