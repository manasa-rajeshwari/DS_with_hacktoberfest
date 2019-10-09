#include<stdio.h>
#include<stdlib.h>

#define MAX 2
int rear = 0, front = 0, queue[MAX];
int option();
void enqueue();
void dequeue();
void display();

int main(){
  int op;
  op = option();
  while (op != 5){
    switch(op){
      case 1:{
        enqueue();
	break;
      }
      case 2:{
        dequeue();
        break;	
      }
      case 3:{
        display();
	break;
      }

    }
    op = option();
 }
}
int option(){
  int opt = 0;
  printf("\nWhat do you want to do??\n1.Adding elements to queue\n2.Deleting an element\n3.Display what all are present in queue\n4.Nothing\nYour option please:   ");
  scanf("%d", &opt);
  return opt;
}
void enqueue(){
  int nu = 0;
  if(rear != MAX) {
    printf("Enter the elements to queue: ");
    scanf("%d", &nu);
    queue[rear]= nu;
    rear++;
    printf("rear = %d\n", rear);
  }else if (rear == MAX && front != 0){
    rear = 0;
  }
}
void dequeue(){
  if (rear == front){
   printf("\nQueue empty");
  }else{
   printf("front is %d\n", front);	  
   printf("Deleted element is %d\n", queue[front]);
   front++;  
   printf("front after deletion %d\n", front);
  }
}
void display(){
 int i;
 if (rear == front){
  printf("\nQueue empty\n");
 }else{
  printf("Queue is \n");
  for(i = front; i <= rear-1; i++){
   printf("%d\n", queue[i]);
  }
 }
}
