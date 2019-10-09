#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int item;
  struct Node *next;
} Node;

int menu();
struct Node * addToempty(int, struct Node * );
struct Node * addBeg(int, struct Node *);
struct Node * addEnd(int, struct Node *);
struct Node * addAfter(int, int, struct Node *);
void display(struct Node *);

int main()
{
  struct Node *head = NULL;
  int option, num, reqnum;
  option = menu();
  while(option <=5)
  {
    switch(option)
    {
      case 1:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = addBeg(num, head);
        break;

      case 2:
        printf("Enter the number\n");
        scanf("%d", &num);
        head = addEnd(num, head);
        break;
      
      case 3:
        printf("Enter the number\n");
        scanf("%d", &num);
        printf("Enter the number after which the above number will be inserted\n");
        scanf("%d", &reqnum);
        head = addAfter(num, reqnum, head);
        break;

      case 4:
        display(head);
	break;
      case 5:
        exit(0);	
    }
    option = menu();
  }
}

int menu()
{
  int option;
  printf("1.Insert an element in the beginning of the list\n");
  printf("2.Insert at the end of the list\n");
  printf("3.Insert after an number in the list\n");
  printf("4.Display\n5.Exit\n");
  scanf("%d", &option);
  
  return option;
}

struct Node * addToempty(int num, struct Node *head1)
{
  if(head1 != NULL)
  {
    return head1;
  }
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head->item = num;
  head->next = head;
  return head;
}

struct Node * addBeg(int num, struct Node *head)
{
 	
  if(head == NULL)
  {
    return addToempty(num, head);
  }
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->item = num;
 /* if (head == NULL){
   head = temp;
   tail = temp;
   temp->next = head;
  }else{
    struct Node *temp1 = head;
    temp->next = temp1;
    head = temp;


  }*/

  temp->next = head->next;
  head->next = temp;
  return head;
}

struct Node * addEnd(int num, struct Node *head)
{
  if(head == NULL)
  {
    return addToempty(num, head);
  }
  struct Node *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->item = num;
  temp->next = head->next;
  head->next = temp;
  head = temp;
  return head;
}

struct Node * addAfter(int num, int reqnum, struct Node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return NULL;
  }
  struct Node *temp1, *temp2;
  temp2 = head;
  do
  {
    if(temp2->item == reqnum)
    {
      temp1 = (struct Node *)malloc(sizeof(struct Node));
      temp1->item = num;
      temp1->next = temp2->next;
      temp2->next = temp1;
      if(temp2 == head)
      {
        head = temp1;
      }
      return head;
    }
    temp2 = temp2->next;
  }while(temp2 != head->next);

  if(temp2 == head->next)
  {
    printf("The number given not found\n");
    return head;
  }
  
  return head;
}

void display(struct Node *head)
{
  if(head == NULL)
  {
    printf("The list is empty\n");
    return;
  }
  struct Node *temp;
  temp = head;
  do
  {
    printf("%d ", temp->item);
    temp = temp->next;
  }while(temp != head);
  printf("\n");
}
