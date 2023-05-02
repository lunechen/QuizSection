#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int score;
    char name[21];
} Node;

int cmp(const void *a, const void *b)
{
    return ((Node *)b)->score - ((Node *)a)->score;
}

int main()
{
    Node student[41];
    for (int i = 0; i <= 40; i++)
    {
        memset(student[i].name, 0, sizeof(student[i].name));
        student[i].score = -100;
    }
    int n;
    printf("Number of records you want to key in:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter name & score:");
        scanf(" %s %d", student[i].name, &(student[i].score));
    }
    qsort(student, n, sizeof(student[0]), cmp);
    printf("name score\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", student[i].name, student[i].score);
    }
    return 0;
}
