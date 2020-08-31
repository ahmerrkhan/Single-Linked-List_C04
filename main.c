#include <stdio.h>
#include <stdlib.h>

/*Functions Prototype*/
void insert_at_last(void);
void insert_at_begin(void);
void insert_after_spec(void);

void delete_at_last(void);
void delete_at_begin(void);
void delete_at_spec(void);

void searching(void);
int length(void);
void display(void);

struct node   //creating node of struct type
{
    int data;
    struct node *link;
};
  struct node *root = NULL;

int main()     //main function
{
    int choice,len;

    while(1)
    {
        printf("\n-----------------------\n");
        printf("   SINGLY LINKED LIST  \n");
        printf("-----------------------\n");

        printf("1.Insert Element at Last.\n");
        printf("2.Insert Element at begin.\n");
        printf("3.Insert Element after Specific Position.\n");
        printf("4.Delete Element at Last.\n");
        printf("5.Delete Element at begin.\n");
        printf("6.Delete Element of Specific Location.\n");
        printf("7.Search Element in List.\n");
        printf("8.Length of List.\n");
        printf("9.Display Elements of List.\n");
        printf("10.Exit.\n\n");

        printf("Enter Your Choice : \n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: insert_at_last();
            break;
        case 2:insert_at_begin();
            break;
        case 3:insert_after_spec();
            break;
        case 4:delete_at_last();
            break;
        case 5:delete_at_begin();
            break;
        case 6:delete_at_spec();
            break;
        case 7:searching();
            break;
        case 8:len=length();
               printf("Length of Linked list: %d",len);
            break;
        case 9:display();
            break;
        case 10: exit(1);
            break;
        default:printf("Incorrect Choice! Try again.\n\n");
            break;
        }
    }
}

void insert_at_last()  //1st function
{
    struct node *temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter Data:\n");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}
void insert_at_begin()   //2nd function
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter Data:\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }

}
void insert_after_spec()    //3rd function
{
    int i=1,pos;
    struct node *temp,*p;

    printf("Enter Position after you want to insert :\n");
    scanf("%d",&pos);
    if(pos>length())
    {
        printf("Invalid Positionn.\n");
    }
    else
    {
       temp=(struct node*)malloc(sizeof(struct node));
       printf("Enter Data:\n");
       scanf("%d",&temp->data);
       temp->link=NULL;

        p=root;
        while(i<pos)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
}
void delete_at_last()      //4th function
{
    struct node *temp,*p;
    if(root==NULL)
    {
        printf("No Elements in Link List.\n");
    }
    else
    {
        p=root;
        while(p->link!=NULL)
        {
            temp=p;
            p=p->link;
        }
        if(p==root)
        {
            root=0;
        }
        else
        {
            temp->link=NULL;
        }
        free(p);
    }
}
void delete_at_begin()    //5th function
{
    struct node *temp;
    if(root==NULL)
    {
        printf("No Elements in Link List.\n");
    }
    else
    {
        temp=root;
        root=root->link;
        free(temp);
    }
}
void delete_at_spec()    //6th function
{
    struct node *temp,*p;
    int i=1,loc;
    printf("Enter location you want to Delete :\n");
    scanf("%d",&loc);
    temp=root;
    while(i<loc-1)
    {
        temp=temp->link;
        i++;
    }
    p=temp->link;
    temp->link=p->link;
    p->link=NULL;
    free(p);
}
void searching()     //7th function
{
    struct node *temp;
    int item,i=0,flag;
    temp=root;
    if(temp==NULL)
    {
        printf("No Elements in Linked List.\n");
    }
    else
    {
        printf("Enter value to be searched :\n");
        scanf("%d",&item);
        while(temp!=NULL)
        {
            if(temp->data==item)
            {
                printf("Element found at %d position.\n",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->link;
        }
        if(flag==1)
        {
            printf("Element not found in Linked List.\n");
        }
    }

}
int length()     //8th function
{
    int count;

    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void display()   //9th function
{
  struct node *temp;
  if(root==NULL)
  {
      printf("No Elements in Link List.\n");
  }
  else
  {
      temp=root;
      while(temp!=NULL)
      {
          printf("%d|",temp->data);
          temp=temp->link;
      }
  }
}
////////END OF SINGLY LINKED LIST//////////
