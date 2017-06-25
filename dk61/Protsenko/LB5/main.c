#include "dk_tool.h"

int main() 
{
	FloatTree *Tree = createFloatTree();

	printf("/*Avaliable commands*/ :\n\n"
				" -> 1. Insert value\n"
				" -> 2. Delete element\n"
				" -> 3. Print tree\n"
				" -> 4. Destroy tree\n"
				" -> 0. Quit\n\n");
				
	int command = 0;
	
	do 
	{	
		printf("\n - Command : ");
		int check = scanf("%i", &command);
		
		if (check != 1)
		{
			printf("\n !Incorrect value! \n");
			return 0;
		}

				switch (command)
		 		{
		 			
				 	case 1:
				 	{
				  		float value = 0;
				  		printf("Enter a value to add : ");
				  		scanf("%f", &value);
				  		InsertFloatValueToTree(Tree, value);
				  		break;
				  	 }
				  	case 2: 
				  	{
				  		printTree(Tree);
						printf("\n");
						FloatNode *aNode = Tree->root;
						
						float value_to_delete;
						printf("\nEnter a value to delete : ");
				  		scanf("%f", &value_to_delete);
				  		
						deleteNodeWithValue(Tree,aNode, value_to_delete);
						
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
				  		destroyFloatTree(Tree);
				  		printf("\nThe Tree has been deleted!\n");
				  		FloatTree *Tree = createFloatTree();
				  		break;
				  	}
		 		}
	
	}
	while (command != 0);
	
	printf("  Closing...\n");
	return 0;
}
