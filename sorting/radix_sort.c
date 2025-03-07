#include<stdio.h>
#include<stdlib.h>
 
struct  node
{
	int data ;
	struct node *next;
}*start=NULL;
 
void radix_sorting();
int larger_dig();
int digit(int num, int k);
 
main()
{
	struct node *temp,*q;
	int count,n,num_item;
 
	printf("Enter the Number of Elements to be Inserted into the List : ");
	scanf("%d", &n);
 
	for(count=0;count<n;count++)
	{
		printf("Enter element %d : ",count+1);
		scanf("%d",&num_item);
 
		temp= malloc(sizeof(struct node));
		temp->data=num_item;
		temp->next=NULL;
 
		if(start==NULL) 
			start=temp;
		else
		{
			q=start;
			while(q->next!=NULL)
				q=q->next;
			q->next=temp;
		}
	}
 
	radix_sorting();
	printf("Sorted List is :\n");
	
	q=start;
	while( q !=NULL)
	{
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n");
 
}
 
void radix_sorting()
{
	int count,k,dig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];
 
	least_sig=1;
	most_sig=larger_dig(start);
 
	for(k=least_sig; k<=most_sig; k++) 
	{
		for(count=0; count<=9 ; count++)
		{
			rear[count] = NULL;
			front[count] = NULL ;
		}
		
		for( p=start; p!=NULL; p=p->next )
		{
			dig = digit(p->data, k);
		
			if(front[dig] == NULL)			
				front[dig] = p ;
			else
				rear[dig]->next = p;
			rear[dig] = p;
		}
		
		count=0;
		while(front[count] == NULL)
			count++;
		start = front[count];	
		while(count<9) 
		{
			if(rear[count+1]!=NULL)
				rear[count]->next=front[count+1];
			else
				rear[count+1]=rear[count];
			count++;
		}
		rear[9]->next=NULL;
	}
}
 
int larger_dig()
{
	struct node *p=start;
	int large=0,ndigit=0;
 
	while(p != NULL)
	{
		if(p ->data > large)
			large = p->data;
		p = p->next ;
	}
 
	while(large != 0)
	{
		ndigit++;
		large = large/10 ;
	}
	return(ndigit);
}
 
int digit(int num, int k)
{
	int digit, count ;
	for(count=1; count<=k; count++)
	{
		digit = num % 10 ;
		num = num /10 ;
	}
	return(digit);
}
