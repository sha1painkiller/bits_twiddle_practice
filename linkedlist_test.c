#include <stdlib.h>
#include <stdio.h>

struct llist {
    int data;
    struct llist *next;
    struct llist *prev;
};

void insert_l(struct llist *ll, int val)
{
    struct llist *tmp = ll;
    while (ll->next != NULL)
    {
        ll = ll->next;
    }
    tmp = malloc(sizeof(struct llist));
    tmp->data = val;
    tmp->next = NULL;
    ll->next = tmp;
    tmp->prev = ll;
    printf("insert %d\n", val);
}

void remove_l(struct llist *ll, int val)
{
}

int main()
{
    int arry[10] = {15,42,28,74,36,11,59,10,33,16};
    int i;
    struct llist *root = NULL;
    struct llist *tmp = NULL;

    root = malloc(sizeof(struct llist));
    root->data = arry[0];
    root->next = NULL;
    root->prev = NULL;

    for (i = 1; i < 10; i++)
        insert_l(root, arry[i]);

    // forward traverse linked list
    tmp = root;
    printf("start forward traversal: ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    
    // backward traverse the linked list
    tmp = root;
    printf("start backward traversal: ");
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    while (tmp->prev != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
    printf("%d \n", tmp->data);        
}
