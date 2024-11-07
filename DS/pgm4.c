#include<stdio.h> 
int A[100],size,top; 
 
//push an element into stack 
 
void push(int item) 
{  
  if(top==size-1) 
     printf("\n Stack is full"); 
  else 
  { 
     top++; 
     A[top]=item; 
  } 
} 
   
//pop an element from the stack   
 
void pop() 
{ 
  if(top==-1) 
     printf("\n Stack is empty"); 
  else 
  { 
    printf("\n The popped element is %d",A[top]); 
    top--; 
  }         
} 
 
// Display the content of the stack 
 
void display() 
{ 
  int i; 
  if(top==-1) 
    printf("\n The stack is empty"); 
  else 
  { 
    printf("\n The element in stack"); 
    for(i=0;i<=top;i++) 
    { 
      printf("\n %d" ,A[i]); 
    } 
    printf("<-top"); 
  }  
} 
 
// status of the stack 
 
void status()  
{ 
  float free; 
  if(top==-1) 
    printf("Stack is empty"); 
  else 
  { 
   printf("Stack top element is %d :\n",A[top]); 
   if(top==size-1) 
      printf("\n stack is full"); 
   else  
    { 
      free=(float)(size-top-1)*100/size; 
      printf("\n Free space=%f ",free); 
    } 
  } 
}  
 
//Function for main() 
 
void main() 
{ 
 int choice,n; 
 top=-1; 
 printf("\n Enter the size of stack :"); 
 scanf("%d",&size); 
 do  
 { 
   // MENU driven program 
   printf(" \n MENU"); 
   printf("\n 1.PUSH  \t 2.POP \t 3.DISPLAY \t 4.STATUS \t 5.EXIT"); 
   printf("\n Enter the choice :"); 
   scanf(" %d",&choice); 
   switch(choice) 
   { 
    case 1 : printf("Enter the value to be pushed :"); 
             scanf("%d",&n); 
             push(n); 
             display(); 
             break; 
    case 2 : pop(); 
             display(); 
             break; 
    case 3 : display(); 
             break; 
    case 4 : status(); 
             break; 
    case 5 : break; 
    default: printf(" \n Invaild choice!Please try again"); 
   } 
 }while(choice!=5); 
} 
