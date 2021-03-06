#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>
struct NODE
{
	int info;
	struct NODE *ptr;
};
typedef struct NODE * node;
int count = 0;
void CreateAndInsert(node *start, int pos)
{
	int i;
	node prev = NULL, cur = *start, temp;
	if(pos <=0 || pos > count+1)
	{
		printf("\n You entered an invalid position.");
		return;
	}
	temp = malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("\nOut of memory.");
		return;
	}
	printf("\nEnter the value to be stored: ");
	scanf("%d", &temp->info);
	temp->ptr = NULL;

	if (*start == NULL)
	{
		*start = temp;
	}
	else
	{
		for(i=1; i<pos; ++i)
		{
			prev = cur;
			cur = cur->ptr;
		}
		temp->ptr = cur;
		if(pos == 1)	*start = temp;
		else	prev->ptr = temp;
	}
	++count;
	printf("\nNode with data %d was inserted.", temp->info);
}
void Delete(node *start, int pos)
{
	node prev = NULL, cur = *start, temp;
	int data, i;
	if (*start == NULL)
	{
		printf("List underflow.");
		return;
	}
	if(pos <=0 || pos > count+1)
	{
		printf("\n You entered an invalid position.");
		return;
	}
	for(i=1; i<pos; ++i)
	{
		prev = cur;
		cur = cur->ptr;
	}
	temp = cur;
	data = temp->info;
	if(count == 1)
	{
		*start = NULL;
	}
	if(pos == 1)
	{
		*start = temp->ptr;
	}
	else
	{
		prev->ptr=temp->ptr;
	}
	//free(temp);
	//Remedy Heap Corruption error

	--count;
	printf("\nNode with data = %d was deleted from the List.", data);
}
void Display(node *start)
{
	node temp = *start;
	if (temp == NULL)
	{
		printf("\nThe List is empty.");
		return;
	}
	printf("\nThe List contains:\n");
	while (temp != NULL)
	{
		printf("--> %d ", temp->info);
		temp = temp->ptr;
	}
}
void main()
{
	node start = NULL;
	int ch, insertChoice, pos;
	while (1)
	{
		printf("\nLINKED LIST");
		printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		system("cls");
		//clrscr();
		switch (ch)
		{
		case 1:
			printf("\n1. Insert at front");
			printf("\n2. Insert at rear");
			printf("\n3. Insert at specified position");
			printf("\nEnter your choice: ");
			scanf("%d", &insertChoice);
			switch(insertChoice)
			{
				case 1: CreateAndInsert(&start, 1);
				break;
				case 2: CreateAndInsert(&start, count+1);
				break;
				case 3: printf("\nEnter the position where you want to inser the new node: ");
					scanf("%d", &pos);
					CreateAndInsert(&start, pos);
				break;
				default: printf("\n You chose an invalid option.");
			}

			break;
		case 2: printf("\n1. Delete from front");
			printf("\n2. Delete from rear");
			printf("\n3. Delete from specified position");
			printf("\nEnter your choice: ");
			scanf("%d", &insertChoice);
			switch(insertChoice)
			{
				case 1: Delete(&start, 1);
				break;
				case 2: Delete(&start, count);
				break;
				case 3: printf("\nEnter the position where you want to inser the new node: ");
					scanf("%d", &pos);
					Delete(&start, pos);
				break;
				default: printf("\n You chose an invalid option.");
			}

			break;
		case 3: Display(&start);
			break;
		case 4: return;
		default: printf("\nInvalid choice. Try again.");
		}
	}
}