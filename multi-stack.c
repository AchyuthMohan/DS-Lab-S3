#include<stdio.h>
#define size 30
int array[size];
int top1 = -1;
int top2 = size;
void push1 (int item)
{
  if (top1 < top2 - 1)
    {
      top1++;
      array[top1] = item;

    }
  else
    {
      printf ("Stack overflow ");
    }
}

void push2(int item)
{
  if (top1<top2-1)
    {
      top2--;
      array[top2] = item;

    }
  else
    {
      printf ("Stack overflow..");
    }
}

int pop1 ()
{
  if(top1>=0)
    {
      return array[top1--];
    }
  else
    {
      printf ("Stack underflow...");
    }
}

int pop2 ()
{
  if (top2 < size)
    {
      return array[top2--];
    }
  else
    {
      printf ("Stack underflow..");
    }
}

int main ()
{
  int ch, flag = 0, item, n;
  while (flag == 0)
    {
      printf
	("\n1.Push 1\n2.Push 2\n3.Pop 1\n4.Pop\n5.exit 2\nEnter your choice:  ");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  {
	    printf ("Enter the element t be pushed: ");
	    scanf ("%d", &item);
	    push1 (item);
	    break;
	  }
	case 2:
	  {
	    printf ("Enter the element to be pushed: ");
	    scanf ("%d", &item);
	    push2 (item);
	    break;

	  }
	case 3:
	  {
	    int n = pop1 ();
	    printf ("Element popped: %d\n", n);
	    break;
	  }
	case 4:
	  {
	    int n = pop2 ();
	    printf ("Element popped: %d\n", n);
	    break;
	  }
	case 5:
	  {
	    flag = 1;
	  }
	}


    }
  return 0;
}
