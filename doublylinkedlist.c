#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *addrnxt;
    struct node *addrprev;
} *start, *curr, *newnode, *last ,*prev;

struct node* create(int);
void display();
void addnode(int);
int searchnode(int);
void insertbeg(int);
void insertmiddle(int,int);
int deletefirst();
int deleteMiddle(int);

int main()
{
    int n;
    int s; //searching
    int ch;
    int p; //delete middle
    int elm,pos;  // insert middle
    int flag;
    start = NULL;
    do
    {
        printf("\n1.Create\n2.Add node\n3.Display\n4.Searching\n5.insert at begining\n6.Insert middle\n7.Delete first node\n8.Delete Middle");
        printf("\nEnter your choice..");
        scanf("%d", &ch);
        printf("\n------------------------------------------------------------\n");
        switch (ch)
        {
        case 1:
            printf("\nEnter any number:");
            scanf("%d", &n);
            create(n);
            printf("\nLinked list created successfully...");
            break;

        case 2:
            printf("\nEnter any number to add in linked list:");
            scanf("%d", &n);
            addnode(n);
            printf("\nNode inserted successfully...");
            break;

        case 3:
            display();
            break;
            
        case 4:
        	printf("\nEnter element you want to search in linked list:");
        	scanf("%d",&s);
        	flag=searchnode(s);
        	
        	if(flag>0)
        	{
        		printf("\n %d is found at %d location",s,flag);
			}
			else
			{
				printf("\nElement not found...");
			}
			break;
			
		case 5:
			printf("\nEnter element you wannt to insert at begining:");
			scanf("%d",&n);
        	insertbeg(n);
        	printf("\nElement inserted sucessfully at begining og linked list...");
        	break;
        	
        case 6:
			printf("\nEnter element you want to insert:");
			scanf("%d",&elm);
			
			printf("\nEnter position at which you want to insert element:");
			scanf("%d",&pos);        	
        	
        	insertmiddle(elm,pos);
        	printf("\nElement successfully inserted at given position");
        	break;
        	
        case 7:
			deletefirst();
			printf("\nSuccessfully deleted first node"); 
        	break;
        	
        case 8:
        	printf("\nEnter position of element that you want to delete");
        	scanf("%d",&p);
        	
        	deleteMiddle(p);
        	printf("\nElement at position %d deleted successfully..",p);
        	break;
        	
        }

        printf("\n\nDo you want to continue:(1:yes other:No)");
        scanf("%d", &ch);
        printf("\n-----------------------------------------------------------\n");
    } while (ch == 1);
    return 0;
}

struct node* create(int n)
{
    newnode = malloc(sizeof(struct node));
    newnode->data = n;
    newnode->addrnxt = NULL;
    newnode->addrprev = NULL;

    if (start == NULL)
    {
        start = newnode;
        last = newnode;
    }

    return newnode;
}

void addnode(int n)
{
    create(n);
    last->addrnxt = newnode; 
    newnode->addrprev = last;
    last = newnode;
}

void display()
{
    if (start == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        curr = start;
        while (curr != NULL)
        {
            printf("| %u | %d | %u |====>", curr->addrprev, curr->data, curr->addrnxt);
            curr = curr->addrnxt;
        }
    }
}

int searchnode(int s)
{
	int cnt=0;
	int flag=0;
	
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		curr=start;
		while(curr != NULL)
		{
			cnt++;
			if(curr->data==s)
			{
				flag=cnt;
				break;
			}
			curr=curr->addrnxt;
		}
	}
	return flag;
}

void insertbeg(int n)
{
	newnode=create(n);
	newnode->addrnxt=start;
	start->addrprev=newnode;
	start=newnode;
}

void insertmiddle(int elm,int pos)
{
	int cnt=1;
	curr=start;
	prev=NULL;
	
	while(cnt < pos)
	{
		prev=curr;
		curr=curr->addrnxt;
		cnt++;
	}
	newnode=create(elm);
	prev->addrnxt=newnode;
	newnode->addrprev=prev;
	
	newnode->addrnxt=curr;
	curr->addrprev=newnode;
}

int deletefirst()
{
	curr=start;
	start=start->addrnxt;
	curr->addrnxt=NULL;
	start->addrprev=NULL;
	free(curr);
}

int deleteMiddle(int p)
{
	int cnt=1;
	curr=start;
	prev=NULL;
	
	while(cnt<p)
	{
		prev=curr;
		curr=curr->addrnxt;
		cnt++;
	}
	prev->addrnxt=curr->addrnxt;
	curr->addrnxt->addrprev=prev;
	free(curr);
}
