#include <stdlib.h>
#include <stdio.h>

typedef struct treenode
{
    struct treenode *l_child;
    int data;
    struct treenode * r_child;
} treenode;

typedef struct treenode_queue {
    struct treenode *cur;
    struct treenode_queue *next;
} treenode_queue;

void add_bfs_q(treenode_queue *q, treenode **tn)
{
    if (*tn == NULL)
    {
        printf("tn is NULL\n");
        return;
    }


    while(q->next != NULL)
    {
        q = q->next;
    }
    q->next = malloc(sizeof(treenode_queue));
    q = q->next;
    q->cur = *tn;
    q->next = NULL;
}

void bfs(treenode **btr)
{
    treenode_queue *bt_q = NULL;
    treenode *tmp = *btr;

    if (tmp)
    {
        bt_q = malloc(sizeof(treenode_queue));
        bt_q->cur = tmp;
        bt_q->next = NULL;
    }
    else
    {
        printf("empty tree\n");
        return;
    }

    // start bfs interation
    printf("BFS sequence: ");
    while(bt_q)
    {
        tmp = bt_q->cur;
        if (tmp->l_child)
            add_bfs_q(bt_q, &(tmp->l_child));
        if (tmp->r_child)
            add_bfs_q(bt_q, &(tmp->r_child));
        
        printf("%d ",tmp->data);

        bt_q = bt_q->next;
        free(tmp);
    }
    printf("\n");
}

int main(void)
{
    int arry[] = {4,6,10,6,2,5,7,9,13,4};
    treenode *bt = NULL;
    int i;

    // construt an arbitrary tree structure for BFS traversal
    printf("Construct original data: ");
    for (i = 0; i < 10; i++)
    {
        construct_bt(&bt, arry[i]);
    }
    printf("\n");

    bfs(&bt);

    return 0;
}

int construct_bt(treenode **bt, int val)
{
    treenode *trav_t = *bt ;
    
    if (trav_t == NULL)
    {
        *bt = (treenode *) malloc(sizeof(treenode));
        (*bt)->l_child = NULL;
        (*bt)->data = val;
        (*bt)->r_child = NULL;
        printf("%d ",val);
    }
    else
    {
        if ((*bt)->l_child == NULL)
        {
            construct_bt(&((*bt)->l_child), val);
        }
        else
        {
            construct_bt(&((*bt)->r_child), val);
        }
    }
}

