#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char word[1025];
    int count;
    struct Node *next;
} Node;

Node *create_node(const char *word)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

Node *insert(Node **head, const char *word)
{
    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (!strcmp(current->word, word))
        {
            current->count++;
            return current;
        }
        previous = current;
        current = current->next;
    }

    Node *new_node = create_node(word);
    if (previous == NULL)
        *head = new_node;
    else
        previous->next = new_node;
    return new_node;
}

Node *search(Node *head, const char *word)
{
    Node *current = head;
    while (current != NULL)
    {
        if (!strcmp(current->word, word))
            return current;
        current = current->next;
    }
    return NULL;
}

void free_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;
    char input_word[1025];

    while (fgets(input_word, 1024, stdin) != NULL)
    {
        int len = strlen(input_word);
        if (input_word[len - 1] == '\n')
            input_word[len - 1] = '\0';
        if (input_word[0] == '-')
        {
            Node *node_to_remove = search(head, input_word + 1);
            if (node_to_remove != NULL)
                node_to_remove->count--;
            else
            {
                Node *tmp = insert(&head, input_word + 1);
                tmp->count = -1;
            }
        }
        else
            insert(&head, input_word);
    }

    Node *current = head;
    while (current != NULL)
    {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }

    free_list(head);
    return 0;
}
