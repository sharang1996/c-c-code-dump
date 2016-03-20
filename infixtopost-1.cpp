#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100
/* 0 indicates Highest Priority */
/* After entering the expression put space in order to stop the expression
Like (a+b)space and then enter
*/

 struct stack
{
 int data[MAX];
 int top;
}s;

int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%'|| x=='^')
 return(2);
   return(3);
}

void initialize()
{
   s.top=-1;
}

int empty()
{
    if(s.top==-1)
 return(1);
    else
 return(0);
}

int full()
{
    if(s.top==MAX-1)
 return(1);
    else
 return(0);
}

void push(char x)
{
  s.top=s.top+1;
  s.data[s.top]=x;
}

char pop()
{
   int x;
   x=s.data[s.top];
   s.top=s.top-1;
   return(x);
}

char top()
{
    int t;
    t=s.data[s.top];
   return(t);
}


int main()
{
char x;
int token;
initialize();
printf("Enter infix expression(enter space to end  expression like (a+b) :\n");
  while((token=getchar())!=' ')
  {
    if(isalnum(token))
       printf("%c",token);
    else
           if(token == '(')
           push('(');
         /* else if(token == '[')
           push('[');
           else if(token == '{')
           push('{');*/
          
       else
       {
             if(token == ')')
             while((x=pop())!='(')
             printf("%c",x);
            /*else if(token == ']')
             while((x=pop())!='[')
             printf("%c",x);
            else if(token == '}')
             while((x=pop())!='{')
             printf("%c",x);
             */
         else
         {
         while(priority(token)<=priority(top()) && (!empty()))
             {
             x=pop();
             printf("%c",x);
             }
         push(token);
         }
       }
  }
  while(!empty())
    {
    x=pop();
    printf("%c",x);
    }
getch();
return 0;
}

