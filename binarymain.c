#include <stdio.h>
#include "binarytree.h"

/*
	Shane West

	
	This program provides the user with a menu that deals
	with binary trees. The menu contains four options: Add, Delete,
	List(Ascending), List(Descending), and Quit. 
*/

int menu(void);

int main(void) {
	int selection, data_to_add, data_removed;
	binarytree root;
	init_tree(&root);
  	selection = menu();
  	while (selection != 5) {
   	  switch (selection) {
	
/*
	Case 1: Add
	
	If the user chooses "Add" the program well check to see 
	if the binary tree is full. If the binary tree is not full the program
	will receive a number from the user and add it to the tree. If the tree
	is full the user will be prompted with an error message.

*/
        case 1: if (!is_full()) {
			printf("Enter a number: ");
			scanf("%d", &data_to_add);
			add_tree(&root, data_to_add);
		} else
			printf("Tree is full!\n");
                break;

/*
	Case 2: Delete
	
	If the user chooses "Delete" the program well check to see 
	if the tree is empty. If the tree is not empty the program
	will  ask the user which number they would like to remove.
	If the number entered by the user is in the tree it will be
	removed. If the number is not in the tree or the tree is empty
	the user will be prompted with error message.

*/

        case 2: if (!is_empty(root)) {
			printf("Enter number to be removed: ");
			scanf("%d", &data_removed);
			delete_tree(&root, data_removed);
		} else
			printf("Tree is empty!\n");
		break;
					
/*
	Case 3: List(Ascending)
	
	If the user chooses "List(Ascending)" the program well check to see 
	if the tree is empty. If the tree is not empty the program
	will print out the tree in ascending order. If the tree is empty the 
	user will be prompted with an error message.

*/

	case 3: if (!is_empty(root)) {
			LNR(root);
		} else
			printf("Tree is empty!\n");
		break;
					
/*
	Case 4: List(Descending)
						
	If the user chooses "List(Descending)" the program well check to see 
	if the tree is empty. If the tree is not empty the program
	will print out the tree in descending order. If the tree is empty the
	user will be prompted with an error message.
*/
	case 4: if (!is_empty(root)) {
			RNL(root);
		} else
			printf("Tree is empty!\n");
		break;
					
/*
	Default:
	
	If the user does not enter a selection between 1-5 the program
	will prompt the user with an error message.
*/
					
	   default: printf("%d is not a valid selection\n", selection);
     }
     selection = menu();
  }

/*
	If the user enters 5(Quit) the program will end.
*/
  printf("Bye!\n");
}

/*
	Menu Subprogram
	
	This prints out the options for the menu, gets a selection
	from the user, and returns that selection.
*/
	
int menu(void) {
    int choice;
  	printf("1: Add\n");
  	printf("2: Delete\n");
  	printf("3: List(Ascending)\n");
	printf("4: List(Descending)\n");
  	printf("5: Quit\n");
  	printf("Enter a Selection: ");
  	scanf("%d", &choice);
  	return choice;
}
