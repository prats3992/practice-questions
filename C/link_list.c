#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *createNode(int val) /* allocates memory for NODE in the heap*/
{
    NODE *p;
    p = malloc(sizeof(NODE));
    p->data = val;
    p->next = NULL;
    return p;
}
NODE *addNode(NODE *h, int val)
{
    if (h == NULL) /*empty list*/
    {
        h = createNode(val);
        return h;
    }
    /*for the existing list ...*/
    NODE *tmp = h;
    while (h->next != NULL) /*as long as it is NOT the LAST NODE*/
    {
        h = h->next;
    }
    h->next = createNode(val); // h->next->next=NULL
    return tmp;
}
void printList(NODE *h)
{
    while (h) // i did h->next!=NULL
    {
        printf("%d\n", h->data);
        h = h->next;
    }
}
int main()
{
    NODE *head = NULL;
    int num;
    do
    {
        printf("Enter Data: ");
        scanf("%d", &num);
        head = addNode(head, num);
    } while (num != 0);
    printf("The list members are \n");
    printList(head);
    return 0;
}
