#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void displaylist();
void insertnodeatbeginning(int data);
void insertatany(int data,int position);
void insertnodeatend(int data);
void deletefirstnode();
void deleteanynode(int position);
void deletenodeatend();

int main()
{
    int n,data,position;
    printf("Enter the total number of nodes:");
    scanf("%d",&n);
    createlist(n);

    printf("\nData in the list\n");
    displaylist();

    int c, d;
    for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}


    printf("\n\n----------INSERTION OPERATION----------");
    printf("\nEnter the data you want to insert at beginning:");
    scanf("%d",&data);
    insertnodeatbeginning(data);
    displaylist();

    printf("Enter the data you want to insert at any position:");
    scanf("%d",&data);
    printf("Enter the position you want to insert:");
    scanf("%d",&position);
    insertatany(data,position);
    displaylist();

    printf("Enter the data you want to insert at end:");
    scanf("%d",&data);
    insertnodeatend(data);
    displaylist();

    for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}

    printf("\n\n----------DELETION OPERATION----------");
    printf("\nData after deletion from first node is:");
    deletefirstnode();
    displaylist();

    printf("Enter the position you want to delete:");
    scanf("%d",&position);
    deleteanynode(position);
    displaylist();

    printf("Data after deletion from last node is:");
    deletenodeatend();
    displaylist();

    return 0;
}

void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("\nEnter the data of node 1:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d:",i);
                scanf("%d",&data);
                newnode->data=data;
                newnode->next=NULL;

                temp->next=newnode;
                temp=temp->next;

            }
        }
        printf("Singly link list created successfully.\n");
    }
}


void displaylist()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("Data=%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void insertnodeatbeginning(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Unable to allocate memory.\n");
    }
    else
    {
        newnode->data=data;
        newnode->next=head;
        head=newnode;

        printf("Data inserted successfully.\n");
    }
}

void insertatany(int data, int position)
{
    int i;
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        temp = head;
        for(i=2; i<=position; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Data inserted successfully\n");
        }
        else
        {
           newNode->data=data;
            newNode->next=NULL;

            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;
        }
    }
}


void insertnodeatend(int data)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newnode->data=data;
        newnode->next=NULL;

        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        printf("Data inserted successfully\n");
    }
}

void deletefirstnode()
{
    struct node *todelete;
    if(head==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        todelete=head;
        head=head->next;

        printf("\nData deleted=%d\n",todelete->data);
        free(todelete);
        printf("Successfully deleted first node from list\n");
    }
}


void deleteanynode(int position)
{
    int i;
    struct node *todelete,*prevnode;

    if(head==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        todelete=head;
        prevnode=head;
        for(i=2;i<=position;i++)
        {
            prevnode=todelete;
            todelete=todelete->next;
            if(todelete==NULL)
                break;
        }
        if(todelete!=NULL)
        {
            if(todelete==head)
                head=head->next;
            prevnode->next=todelete->next;
            todelete->next=NULL;

            free(todelete);
            printf("Successfully deleted node from the list.\n");
        }
        else
        {
            printf("Invalid position unable to delete.\n");
        }
    }
}


void deletenodeatend()
{
    struct node *todelete,*secondlastnode;
    if(head==NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        todelete=head;
        secondlastnode=head;
        while(todelete->next!=NULL)
        {
            secondlastnode=todelete;
            todelete=todelete->next;
        }
        if(todelete==head)
        {
            head=NULL;
        }
        else
        {
            secondlastnode->next=NULL;
        }
        free(todelete);

        printf("\nSuccessfully deleted last node.\n");
    }
}
