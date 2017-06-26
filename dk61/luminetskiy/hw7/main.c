#include "dk_tool.h"

int main() 
{
	CharTree *Tree = createCharTree();

	printf("/*Avaliable commands*/ :\n\n"
				" -> 1. Insert symbol to tree\n"
				" -> 2. Delete symbol from tree\n"
				" -> 3. Print tree\n"
				" -> 4. Destroy tree\n"
				" -> 5. Quit\n\n");
				
	int command = 0;
	
	do 
	{	
		printf("\n ->Enter command: ");
		int check = scanf("%i", &command);
		
		if (check != 1)
		{
			printf("\n!Incorrect value!\n");
			return 0;
		}

				switch (command)
		 		{
		 			
				 	case 1:
				 	{
				  		char symbol;
				  		printf("Enter a symbol to add : ");
				  		scanf(" %c", &symbol);
				  		InsertCharValueToTree(Tree, symbol);
				  		break;
				  	 }
				  	case 2: 
				  	{
				  		printTree(Tree);
						printf("\n");
						CharNode *aNode = Tree->root;
						
						char symbol_to_delete;
						printf("\nEnter a symbol to delete : ");
				  		scanf(" %c", &symbol_to_delete);
				  		
						deleteNodeWithValue(Tree,aNode, symbol_to_delete);
						
						int count = 1;
						count = countNodesWithTree(Tree);
						printf("The count of nodes in modified tree is : [%d]\n", count);
						
						printTree(Tree);
						printf("\n");
						break;
				  	}
				  		
				  	case 3:
				  	{
				  		printTree(Tree);
				  		printf("\n");
				  		break;
				  	}
				  	case 4:
				  	{
				  		destroyCharTree(Tree);
				  		printf("\nThe Tree has been deleted!\n");
				  		CharTree *Tree = createCharTree();
				  		break;
				  	}
		 		}
	
	}
	while (command != 0);
	
	printf("\n\nClosing...\n");
	return 0;
}
