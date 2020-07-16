#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[30];char designation[20];
	int pay;
	struct node *next;
};
char password[10]={"dev"};
 void paswd()
{
  char choice,pass[10];
  int j=0;
  clrscr();
  gotoxy(15,5);
  printf("***Password Protected***");
  gotoxy(15,7);
  printf("Enter Password:");
  while(choice!=13)
  { choice=getch();
  putch('*');
  if(choice!=13)
  { pass[j]=choice;
  j++;
  }
  }
  pass[j]='\0';
  if(strcmp(pass,password)==0)
  { gotoxy(15,9);
  printf("\nPassword match");
  gotoxy(17,10);
  printf("\nPress any key to continue.....");
  getch();
  clrscr();
  }
  else
  { gotoxy(15,16);
  printf("\nWarning!!Incorrect Password");
  getch();
  paswd();
  }
}
void display()
{       FILE *fp = fopen ( "Record.txt", "r" );
	printf("Contents of the Record:-\n\n");

   if ( fp != NULL )
   {
      char line [ 128 ];
      while ( fgets ( line, sizeof line, fp ) != NULL )
      {
	 fputs ( line, stdout );
      }
	  fclose ( fp );
   }
   else
   {
      printf ("\nFile cannot be opened.");
   }
}


/*void swap(struct node *a, struct node *b)
{    char n[30];
      char d[20];
    int p;
    p=a->pay;
    a->pay=b->pay;
    b->pay=p;


    strcpy(n,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,n);


    strcpy(d,a->designation);
    strcpy(a->designation,b->designation);
    strcpy(b->designation,d);
}


void sort(struct node *start)
{
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;
    if (start == NULL)
	return;
    do
    {
	swapped = 0;
	ptr1 = start;

	while (ptr1->next != lptr)
	{
	    if (stricmp(ptr1->name,ptr1->next->name)>0)
	    {
		swap(ptr1, ptr1->next);
		swapped = 1;
	    }
	    ptr1 = ptr1->next;
	}
	lptr = ptr1;
    }while (swapped);
}*/


void Delete(struct node **head_ref ,char n[30])
{

    struct node* temp = *head_ref, *prev;

    if (temp != NULL && stricmp(temp->name,n)==0)
    {
	*head_ref = temp->next;
	free(temp);
	return;
    }

    while (temp != NULL && stricmp(temp->name,n)!=0)
    {
	     prev = temp;
	     temp = temp->next;
    }
   prev->next = temp->next;
   free(temp);
}

void add(struct node** h_ref, char n[30],char d[20],int p)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	struct node *last=*h_ref;

	strcpy(new_node->name,n);
	strcpy(new_node->designation,d);
	new_node->pay=p;
    new_node->next=NULL;

    if (*h_ref==NULL)
    {
       *h_ref=new_node;
       return;
    }

    while(last->next!=NULL)
	last=last->next;

	last->next=new_node;
    return;
}



struct node* middle(struct node* start, struct node* last)
{    struct node* slow = start;
   struct node* fast = start -> next;
    if (slow == NULL)
	return NULL;


    while (fast != last)
    {
	fast = fast -> next;
	if (fast != last)
	{
	    slow = slow -> next;
	    fast = fast -> next;
	}
    }
    return slow;
}
void clearfile()
{
	FILE *fp=fopen("Record.txt","w");
	fclose(fp);
}

void fillfile(struct node *head)
{
	struct node *temp=head;
	FILE *fp=fopen("Record.txt","a");
	while(temp!=NULL)
	{
		fprintf(fp,"Name: %s Designation: %s Pay: %d\n",temp->name,temp->designation,temp->pay);
		temp=temp->next;
	}
	fclose(fp);
}

void search(struct node *head, char n[30])
{
    struct node* start = head;
    struct node* last = NULL;
    do
    {

	struct node* mid = middle(start, last);

	if (mid == NULL)
	    return ;

	if (stricmp(mid->name,n)==0)
		{   printf("      ENTRY FOUND:-\n\n");
		printf("Employee Name: %s,  " ,mid->name);
		printf("Employee Designation: %s\n",mid->designation);
		printf("Employee Salary: %d\n\n",mid->pay);
			return;
		}

	else if (stricmp(mid->name,n)<0)
	    start = mid -> next;

	else
	    last = mid;

    } while(start!=NULL && start!=last && (last == NULL || last -> next != start));
	printf("NO SUCH ENTRY WAS FOUND.\n\n\n");
    return;
}

void modify(struct node *P, char x[30])
{
    struct node* temp=P;
	char n[30];char d[20];int p=0;
    while (temp != NULL)
    {
	if (stricmp(temp->name,x)==0)
	{
		printf("	ENTRY FOUND:-\n\n");
			printf("Enter Employee's Name	(NOTE: DONT USE SPACES):\n");
			scanf("%s",n);
			printf("Enter Employee's Designation	(NOTE: DONT USE SPACES):\n");
			scanf("%s",d);
			printf("Enter Employee's Pay:");
			scanf("%d",&p);
			strcpy(temp->name,n);
			strcpy(temp->designation,d);
			temp->pay=p;
			return;
		}
	temp = temp->next;
    }
	printf("NO SUCH ENTRY WAS FOUND.\n\n\n");
    return;
}

void mainscr(struct node **h_ref)
{
 int ch=0;char n[30];char d[20];int p;

	   printf("\n\t\t\t\t=====================");
	   printf("\n\t\t\t\t  EMPLOYEE RECORD");
	   printf("\n\t\t\t\t=====================\n");
 printf("1. Add New Entry\n");
 printf("2. Display All Entries\n");
 printf("3. Search For An Entry\n");
 printf("4. Delete An Entry\n");
 printf("5. Modify An Entry\n");
 printf("6. Exit\n\n\n");
 printf("	Enter your choice:");
 scanf("%d",&ch);

 switch(ch)
 {
	case 1:
	printf("Enter Employee's Name	(NOTE: DONT USE SPACES):\n");
	scanf("%s",n);
	printf("Enter Employee's Designation	(NOTE: DONT USE SPACES):\n");
	scanf("%s",d);
	printf("Enter Employee's Pay:");
	scanf("%d",&p);
	add(h_ref,n,d,p);
	//sort(*h_ref);
	clrscr();
	printf("\n\n\nENTRY ADDED SUCCESSFULLY.\n\n\n");
	clearfile();fillfile(*h_ref);mainscr(h_ref);
	break;

	case 2:
	clrscr();
	display();
	printf("\n\nEnter any number to exit to main screen:");
	scanf("%d",&ch);
	clrscr();
	mainscr(h_ref);
	break;

	case 3:
	printf("\nEnter Employee's name	(NOTE: DONT USE SPACES):\n");
	scanf("%s",n);
	search(*h_ref,n);
	printf("\n\nEnter any number to exit to main screen:");
	scanf("%d",&ch);
	clrscr();
	mainscr(h_ref);
	break;


	case 4:
	printf("\nEnter Employee's Name	(NOTE: DONT USE SPACES):\n");
	scanf("%s",n);
	if(*h_ref==NULL)
	printf("\nEmpty List.\nEnter any number to exit to main screen:");
	else{
	Delete(h_ref,n);
	printf("\nDeletion Successful.");}
	printf("\nEnter any number to exit to main screen:");
	scanf("%d",&ch);
	clrscr();clearfile();fillfile(*h_ref);
	mainscr(h_ref);
	break;

	case 5:
	printf("\nEnter Employee's Name	(NOTE: DONT USE SPACES):\n");
	scanf("%s",n);
	modify(*h_ref,n);
	//sort(*h_ref);
	printf("\n\nEnter any number to exit to main screen:");
	scanf("%d",&ch);
	clrscr();clearfile();fillfile(*h_ref);
	mainscr(h_ref);
	break;

	case 6:exit(0);

	default:clrscr();mainscr(h_ref);
 }
}

int main()
{
	struct node *head=NULL;
	FILE* ptr = fopen("Record.txt","r");
    paswd();
    if (ptr!=NULL)
    {
    char n[30],d[20];int p;
    while (fscanf(ptr,"Name: %s Designation: %s Pay: %d\n",n,d,&p)!=EOF)
      add(&head,n,d,p);
	}
	fclose(ptr);
	mainscr(&head);
	return 0;
}
