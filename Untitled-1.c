#include<stdio.h>
#include<conio.h>
#include<dos.h>
// #include<alloc.h>
#include<process.h>
#include<string.h>

struct stack
{
	char s[25];
	int top;
}st;


void push(char a)
{
	st.top++;
	st.s[st.top]=a;
}

char pop()
{
	char d;
	d=st.s[st.top];
	st.top--;
	return d;
}

int f(char k)
{
	switch(k)
	{
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 3;
			break;
		case '/':
			return 3;
			break;
		case '^':
			return 6;
			break;
		case '(':
			return 9;
			break;
		case ')':
			return 0;
			break;
		default:
			return 7;
			break;
	}
}
int g(char h)
{
	switch(h)
	{
		case '+':
			return 2;
			break;
		case '-':
			return 2;
			break;
		case '*':
			return 4;
			break;
		case '/':
			return 4;
			break;
		case '^':
			return 5;
			break;
		case '(':
			return 0;
			break;
		case ')':
			return 0;
			break;
		default:
			return 8;
			break;
	}
}

int r(char l)
{
	switch(l)
	{
		case '+':
			return -1;
			break;
		case '-':
			return -1;
			break;
		case '*':
			return -1;
			break;
		case '/':
			return -1;
			break;
		case '^':
			return -1;
			break;
		case '(':
			return 0;
			break;

		case ')':
			return 0;
			break;
		default:
			return 1;
			break;
	}
}


void main()
{
	char infix[25],a,temp,polish[25];
	int i,rank=0,c=0,b;
	st.top=-1;
	// clrscr();

	push('(');

	printf("\nEnter infix expression : ");
	scanf("%s",infix);
	strcpy(polish,'\0');

	b=strlen(infix);
	infix[b]=')';
	infix[b+1]='\0';

	for(i=0;i<=b;i++)
	{
		while(f(infix[i])<g(st.s[st.top]))
		{
			temp=pop();
			polish[c++]=temp;
			rank=rank+r(temp);
			if(rank<1)
			{
				printf("\nInvalid Expression.");
				exit(0);
			}
		}
		if(f(infix[i])!=g(st.s[st.top]))
		{
			push(infix[i]);
		}
		else
		{
			pop();
		}
	}
	if(rank!=1)
	{
		printf("\nInvalid");
	}

	polish[c]='\0';

	printf("Postfix Expression : %s",polish);
	getch();
}