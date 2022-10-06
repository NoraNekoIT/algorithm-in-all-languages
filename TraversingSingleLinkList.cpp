#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void count_of_nodes();

int main()
{
struct node *head;
  count_of_nodes(head);
    return 0;
}
void count_of_nodes(struct node *head){
    int count = 0;
    if(head==NULL)
        printf("Linked list is empty ");
    struct node* ptr = NULL;
        ptr = head;
    while(ptr!=NULL)
    {
        count++;
    ptr = ptr->link;
    printf("%d",count);
    };
};
