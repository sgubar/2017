#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
 {
	char* word;
	struct node *next;
 } node;

void AddWord(void);
void DeleteWord(void);
void PrintList(void);
void FindAWord(void);
void FindTheLongest(void);

node *list = NULL;

int main(int argc, char *argv[]) 
{
	int command;
	printf("/*Avaliable commands*/ :\n\n"
				" -> 1. Add word;\n"
				" -> 2. Delete word;\n"
				" -> 3. Search word;\n"
				" -> 4. Show the list;\n"
				" -> 5. Show longest word;\n"
				" -> 0. Quit;\n\n");
	do 
	{
		printf("\nYour command: ");
		int check = scanf("%d", &command);
		
			if (check == 1)
			{
				switch (command)
		 		{
				 case 1: AddWord(); break;
				 case 2: DeleteWord(); break;
				 case 3: FindAWord(); break;
				 case 4: PrintList(); break;
				 case 5: FindTheLongest(); break;
		 		}
			}
			else
			{
			printf("Error. Enter only numb!\n");
			fflush(stdin);
			}
	}
	while (command != 0);


	node *ptr = list;
	while (ptr != NULL) 
	{
		node *previous = ptr;
		ptr = ptr->next;
		free(previous);
	}
	return 0;
}

// Insert a node into list
 void AddWord(void) 
 {

	node *new = malloc(sizeof(node)); //memory for new node
	
	if (new == NULL) //check for out of memory
	{
	  printf("Out of memory!\n");
	  exit(1);
	}
	
	new->next = NULL; 
	
	printf("Enter a word : ");
	scanf("%s", &(new->word));
	printf("Done. %s is added to list\n", &(new->word));
	
	// empty list
	if (list == NULL)
	{
	  list = new;
	  return;
	}

	// at the middle of list
	node **lpp;
	for (lpp = &list; *lpp != NULL; lpp = &(*lpp)->next) 
	{
	  node *lp = *lpp;
	  
		if (new->word < lp->word)
		 {
		  new->next = lp;
		  *lpp = new;
		  return;
		 }
		else if (lp->word == new->word)
		 {
			free(new);
			return;
		 }
	}
	// at the end of list
	*lpp = new;
}


void DeleteWord(void) // delete an word from list function
 {
 	
 PrintList(); //show list before delete
	
	char* WordToDelete;          
	printf("\nEnter word to delete : ");	 //	get a word to delete
	scanf("%s", &WordToDelete);  
	int counter = 0;

	for (node **lpp = &list; *lpp != NULL; lpp = &(*lpp)->next) //lpp - pointer to list pointer
	 {
	 	
	  node *lp = *lpp;
	  
	 	if ((*lpp)->word == WordToDelete)
	 	{
	  	 printf("Done. %s is deleted\n", &WordToDelete);
	  	 *lpp = (*lpp)->next;
	  	 free(lp);
	  	 counter = 1;
	 	 break;
	 	}	
	 }
	 
	 if (counter != 1) printf("Word not exist or not deleted");
	 
 PrintList(); //show list after delete
 
}



void FindAWord(void)  //search for an item in the list function
 {
	char* WordToSearch;          		
	printf("Enter word to search : ");  //get a word to find
	scanf("%s", &WordToSearch);  		

	node *ptr = list;    //put pointer on list
	
	while (ptr != NULL) 
	 {
		if (ptr->word == WordToSearch) 
		{
			printf("Done. %s was found in list!\n", &WordToSearch);
			return;
		}

		ptr = ptr->next;
	}
	
	printf("!Not found in list!\n");
}

// iterate the list
void PrintList(void)
 {
	node *ptr = list;
	
	printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - \n");
	
	while (ptr != NULL)
	 {
		printf("(%s)->", &ptr->word);
		ptr = ptr->next;
	 }
	printf("%s", &ptr->word);
	
	printf("\n -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - ");
 }

void FindTheLongest(void) 	//Function for finding the longest word
{
	node *ptr = list; //Set the pointer on list
	 
	int max; //To derive a max_lenght from the loop and detect max_word
	char* max_word; //To derive a word from the loop 
	
	int i = 0; 
	int ctr[i];  //Set a counter arr to look over lenght
	
	 	while (ptr != NULL) 
		{
			ctr[i] = strlen(&(ptr->word)); 
			
			printf("Word : %s ; Lenght : %d\n", &ptr->word, ctr[i]);
				
				if (max < ctr[i]) //Compare length of max and current lenght ctr[i]
					{
						max = ctr[i]; //If ctr[i] > max => max = ctr[i]
						max_word = &(ptr->word); //New longest word
					}
				
			ptr = ptr->next; //Next element
			i++;	
		}
		printf("Longest word : %s\n" , max_word); //Print longest word
}
	
