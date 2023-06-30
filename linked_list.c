#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add(struct node **head, int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void print(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void print_address(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL){
        printf("%d\t %p\t %p\n",temp->data,&(temp->data),temp->next);
        temp = temp->next;
    }
}

void reverse(struct node **head)
{
    struct node *cur = *head;
    struct node *prev = NULL,*next = NULL;
    while(cur !=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void last(struct node **head)
{
    struct node *new,*temp;
    new = (struct node *)malloc(sizeof(struct node));
    int data;
    if(new == NULL)
    {
        printf("Can't inserted\n");
    }
    else
    {
        printf("Enter the data to insert in the last : ");
        scanf("%d",&data);
        new->data = data;
        temp = *head;
        if(temp == NULL){
                new->data = data;
                *head = NULL;
                printf("Node has inserted in the last\n");
                        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        }
}

void random_insert(struct node **head)
{
    struct node *new,*temp;
    new = (struct node*)malloc(sizeof(struct node));
    int data,i,loc;
    if(new == NULL){
        printf("Node not inserted\n");
    }
    else
    {
    printf("enter the data to insert randomly: ");
    scanf("%d",&data);
    new->data = data;
    printf("Enter the position to insert the data : ");
    scanf("%d",&loc);
    temp = *head;
    for(i=1; i<loc-1; i++)
    {
        temp = temp->next;
        if(temp == NULL){
            printf("Not able to insert the node because the entered position is exceeds the list\n");
            return;
        }
    }
    new->next = temp->next;
    temp->next = new;
    printf("Node has inserted in entered position\n");
}
}

int main()
{
    struct node *head = NULL;
    int data,n,i,s;
    printf("Enter the size of linked list : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter %d value : ",i+1);
        scanf("%d",&data);
        add(&head, data);
    }
    printf("Forward linked list\n");
    print(head);
    reverse(&head);
    printf("reverse linked list\n");
    print(head);
    last(&head);
    printf("Last node insert\n"); 
    print(head);
    printf("Enter an element to insert in the begining : ");
    scanf("%d",&s);
    add(&head,s);
    printf("node has inserted in the begining position\n");
    print(head);
    random_insert(&head);
    printf("Random node insert for the existing list\n");
    print(head);
    printf("Addresses linking \n");
    print_address(head);
    
    return 0;
}