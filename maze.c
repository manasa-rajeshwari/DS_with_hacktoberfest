#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

/* Stack data structure implementation */
struct Node
{
  int data;
  struct Node* link;
};

struct Node* top;

void push(int newdata)
{
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = newdata;
  temp->link = top;
  top = temp;
}

int pop()
{
  int t;
  struct Node* temp = top;
  top = top->link;
  t = temp->data;
  return(t);
}

/*
movement function checks for possible paths and pushes them onto stack in
reverse precedence order i.e. up,left,down,right
*/
void movement(int arr[16][16],int i,int j)
{
  if(i-1 >= 0)
  {
    if((arr[i-1][j] == 0 || arr[i-1][j] == 2) == 1)
    {
      push(4);  /* refers to up movement*/
    }
  }
  if(j-1 >= 0)
  {
    if((arr[i][j-1] == 0 || arr[i][j-1] == 2) == 1)
    {
      push(3);  /*refers to left movement*/
    }
  }
  if(i+1 < 16)
  {
    if(arr[i+1][j] == 0) 
    {
      push(2);  /*refers to down movement */
    }
  }
  if(j+1 < 16)
  {
    if(arr[i][j+1] == 0)
    {
      push(1);  /* refers to right movement */
    }
  }
} 
/* Function to print maze */
void printmaze(int arr[16][16],int n1,int n2)
{
  int i,j;
  int left = 10,top = 10,right = 30,bottom = 30;
  for(i = 0;i < 16;i++)
  {
    for(j = 0;j < 16;j++)
    {
      if(arr[i][j] == 1)
      {
        setcolor(RED);
        bar(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
        setcolor(BLACK);
        rectangle(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
        continue;
      }
      if((i == n1 && j == n2) == 1)
      {
        setcolor(BLUE);
        bar(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
        setcolor(BLACK);
        rectangle(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
      }
      else if(arr[i][j] == 2)
      {
       setcolor(GREEN);
        bar(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
        setcolor(BLACK);
        rectangle(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
      }
      else
      {
        setcolor(WHITE);
        bar(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
        setcolor(BLACK);
        rectangle(left+(20*j),top+(20*i),right+(20*j),bottom+(20*i));
      }
    }
  }
  return;
}
/* The below function initializes all elements in multidimensional arr to 0*/
void init(int arr[16][16])
{
  int i,j;
  for(i = 0;i < 16;i++)
  {
    for(j = 0;j < 16;j++)
    {
     arr[i][j] = 0;
    }
  }
}
/* changes the value of right element in the multidimensional array to 2*/
void moveright(int arr[16][16],int i,int j)
{
  if(arr[i][j+1] == 2)
  {
    printf("No path\n");
    exit(1);
  }
  if(arr[i][j+1] == 1)
  {
    printf("No path\n");
    exit(1);
  }
  arr[i][j+1] = 2;
  
}
/* changes the value of left element in the multidimensional array to 2*/
void moveleft(int arr[16][16],int i,int j)
{
  if(arr[i][j-1] == 1)
  {
    printf("No path\n");
    exit(1);
  }
  arr[i][j-1] = 2;
}
/* changes the value of above element in the multidimensional array to 2*/
void moveup(int arr[16][16],int i,int j)
{
  if(arr[i-1][j] == 1)
  {
    printf("No path\n");
    exit(1);
  }
  arr[i-1][j] = 2;
}
/* changes the value of below element in the multidimensional array to 2*/
void movedown(int arr[16][16],int i,int j)
{
  if(arr[i+1][j] == 2)
  {
    printf("No path\n");
    exit(1);
  }
  if(arr[i+1][j] == 1)
  {
    printf("No path\n");
    exit(1);
  }
  arr[i+1][j] = 2;
} 
int main()
{
  int arr[16][16],n1,n2,i,b,m,j;
  printf("Enter no. of obstacles:");
  scanf("%d",&b);  /* Takes no. of obstacles as inputs (i.e. the no. of red blocks in output)*/
  init(arr);  /* initializes all elements to 0 */
  srand(time(0));  /* srand function geerates pseudo random integers taking time as seed */
  for(i = 0;i < b;i++)    /*The loop is repeated untill the blocks generated = no. of obstacles*/
  {
    n1 = rand()%16;    /* one number is generated randomly from 0 to 15 */   
    n2 = rand()%16;    /* one number is generated randomly from 0 to 15 */
    arr[n1][n2] = 1;   /* Assigns those randomly generated blocks as obstacles*/
  }
  arr[0][0] = 2;   /* initial position of rat in the maze */
  arr[15][15] = 0;    /* Destination block */
  int gd = DETECT,gm;   /* for graphical interface */
  initgraph(&gd,&gm,NULL);
  printmaze(arr,0,0);  
  delay(200);
  cleardevice();
  i = 0;
  j = 0;
  movement(arr,i,j);    /* checks for possible path at (0,0) */
  if(top == NULL)    /*checks for empty stack*/
  {
    printf("No Path\n");
    exit(1);
  }
  m = pop();
  /* movement based on stack value */
  if(m == 1)
  {
    moveright(arr,i,j);
    j = j+1;
  }
  if(m == 2)
  {
    movedown(arr,i,j);
    i = i+1;
  }
  if(m == 3)
  {
    moveleft(arr,i,j);
    j = j - 1;
  }
  if(m == 4)
  {
    moveup(arr,i,j);
    i = i - 1;
  }
  printmaze(arr,i,j);
  delay(400);
  cleardevice();/*clears display screen*/
  while(arr[15][15] != 2)
  {
    /* The above operations are repeated untill rat reaches its destination */
    movement(arr,i,j);
    if(top == NULL)
    {
      printf("No route\n");
      break;
    }
    m = pop();
    if(m == 1)
    {
      moveright(arr,i,j);
      j = j+1;
    }
    if(m == 2)
    {
      movedown(arr,i,j);
      i = i+1;
    }
    if(m == 3)
    {
      moveleft(arr,i,j);
      j = j - 1;
    }
    if(m == 4)
    {
      if(arr[i-1][j] == 1)
      {
        continue;
      }
      moveup(arr,i,j);
      i = i - 1;
    }
    printmaze(arr,i,j);
    delay(400);
    cleardevice();
    /*checks for empty stack and also at 0th location*/
    if(((i == 0 && j == 0) && top == NULL) == 1)
    {
      printf("No path\n");
      break;
    }
    if(top == NULL)
    {
      printf("No path\n");
      break;
    }
  }
  /*checks whether the rat reached the end or not*/
  if(arr[15][15] != 2)
  {
    closegraph();
    printf("No Route\n");
    exit(1);
  }
  system("clear");/* clears screen*/ 
  printmaze(arr,i,j);
  delay(5000);        
  closegraph();
}
/*
K Pranav Bharadwaj
17MCME06
*/
