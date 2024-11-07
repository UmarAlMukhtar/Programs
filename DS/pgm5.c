//QUEUE
#include<stdio.h> 
int A[20],size,front,rear; 
// Function for inserting an item to Queue 
void ENQUEUE(int item) 
{ 
  if(rear==size-1) 
   printf("Queue overflow\n"); 
  else if(rear==-1) 
  { 
    front=0; 
    rear=0; 
    A[rear]=item; 
  } 
   else 
   { 
      rear++; 
      A[rear]=item; 
   } 
} 
// Function for deleting an item from Queue 
void DEQUEUE() 
{ 
 if(front==-1) 
  printf("Queue is empty\n");  
 else if(front==rear) 
  { 
    printf("Deleted item is %d\n",A[front]);     
    rear=-1; 
    front=-1; 
  } 
  else 
  { 
     printf("Deleted item is %d\n",A[front]);     
     front++; 
  }  
} 
// Function for displaying the items in the Queue 
void display() 
{ 
  int i; 
  if(front==-1) 
  { 
     printf("Queue is empty\n");  
  } 
  else 
  {  
    printf("The queue elements are \n"); 
    printf("f->"); 
    for(i=front;i<=rear;i++) 
    { 
      printf("%d\t",A[i]); 
    } 
    printf("<-r\n"); 
    printf("front=%d\n",front); 
    printf("rear=%d\n",rear); 
     
  }   
} 
// Function for main() 
int main() 
{ 
 int opt,item; 
 rear=-1; 
 front=-1; 
 printf("Enter the size of Queue: \n"); 
 scanf("%d",&size); 
 do 
 {  
  printf("Menu\n"); 
  printf("\n 1.ENQUEUE\t 2.DEQUEUE \t 3.DISPLAY \t 4.EXIT"); 
  printf("\n Enter the option:"); 
  scanf("%d",&opt); 
  switch(opt) 
  {  
    case 1 : printf("Enter the item to be inserted: \n"); 
             scanf("%d",&item); 
             ENQUEUE(item); 
             display();     
             break; 
    case 2 : DEQUEUE(); 
             display(); 
             break; 
    case 3 : display(); 
             break; 
    case 4 : break; 
              
    case 5 : printf(" \nInvaild choice!Please try again"); 
  } 
 }while(opt!=4); 
} 
