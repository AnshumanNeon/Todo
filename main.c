#include <stdio.h>
#include <string.h>

struct Todo
{
	int done;
	char name[100];
};

int n = 0;

struct Todo list[] = {};

void add_todo()
{
	char todo[100] = "";
	printf("enter the todo name: ");
	scanf("%s", todo);
	struct Todo new_todo;
	new_todo.done = 0;
	memcpy(new_todo.name, todo, sizeof(todo));
	list[n] = new_todo;
	n = n + 1;

	printf("Successfully added to the Todo list\n\n");
}

void print_todo()
{
	for(int i = 0; i < n; i++)
	{
		printf("%d. %s ", i + 1, list[i].name);
		
		if(list[i].done != 0)
		{
			printf("Done!\n");
		}
		else
		{
			printf("Not Done\n");
		}
	}
}

void remove_todo()
{
	int index;
	printf("enter the index of the todo to remove: ");
	scanf("%d", &index);
	
	if(index == n)
	{
		list[index - 1].done = 0;
		memcpy(list[index - 1].name, "", sizeof(list[index - 1].name));;
		n = n - 1;
		printf("Successfully removed Todo!\n\n");
	}
	else if(index > n || index < 1)
	{
		printf("ERRORR, index given out of range!\n\n");
		return;
	}
	else
	{
		for(int i = index - 1; i < n; i++)
		{
			list[i] = list[i + 1];
		}
		n = n - 1;
		printf("Successfully removed Todo!\n\n");
	}
}

void edit_done()
{
	int index, user_done;
	printf("Enter the index of the todo whose 'Done' you want to change: ");
	scanf("%d", &index);
	printf("Enter the value of 'Done' you want to enter (0 for not done and 1 for done): ");
	scanf("%d", &user_done);
	if(index > n || index < 1)
        {
                printf("ERRORR, index given out of range!\n\n");
                return;
        }
	else
	{
		list[index - 1].done = user_done;
		printf("Successfully changed the 'Done' value fo the Todo!\n\n");
	}
}

void take_input()
{
	int input = 0;
	scanf("%d", &input);
	
	switch(input)
	{
		case 1:
			print_todo();
			take_input();
			break;
		case 2:
			add_todo();
			take_input();
			break;
		case 3:
			remove_todo();
			take_input();
			break;
		case 4:
			edit_done();
			take_input();
			break;
		default:
			printf("You pressed 5 or something else that I do not remember and I am assuming that you want to just get out cuz you cannot handle so many Todos, so I am letting you exit, alright?\n");
			break;
	}
}

int main()
{
	printf("This is a todo app, here you will add todos. Try one of the following instructions:\n");
	printf("1. print current todo list.\n2. add a new todo.\n3. remove a todo.\n4. Change if Done.\n5. Exit.\n");

	take_input();

	return 0;
}
