#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

/*
	Initializing a Binary Tree
	
	Using pass by reference, this subprogram sets a binary tree to null.
*/

void init_tree(binarytree *t) {
	(*t) = (binarytree)malloc(sizeof(struct treenode));
	(*t) = NULL;	
}

/*
	Checks to see if a tree is empty
	
	This subprogram determines whether or not the binary tree is null.
	It returns either a "true" value or a "false" value.
*/

boolean is_empty(binarytree t) {
	return (t == NULL);
}

/*
	Check to see if a tree is full
	
	This programs creates a temporary binary tree and attempts
	to allocate memory the size of a treenode structure.
	If sucessful, temp will point to that memory, the subprogram
	will return FALSE, and temp will be freed. If unsucessful temp
	will point to null and return TRUE.
*/

boolean is_full(void) {
	binarytree temp;
	temp = (binarytree)malloc(sizeof(struct treenode));
	if (temp == NULL)
		return TRUE;
	else {
		free (temp);
		return FALSE;
	}
}

/*
	Adding to a binary tree
	
	This subprogram receives a tree using pass by reference and data to
	be added using pass by value. If the current position is empty, memory
	will be allocated the size of a treenode, the data to be added will be
	put in it, and its left and right pointers will be set to null. If current
	the position is not empty and the data to add is less than or equal to the current
	position's data, the program will call itself and will be sent the left subtree.
	If current the position is not empty and the data to add is greater than or equal to
	the current position's data, the program will call itself and will be sent the
	right subtree.
	
*/

void add_tree(binarytree *t, int x) {
	if ((*t) == NULL) {
		(*t) = (binarytree)malloc(sizeof(struct treenode));
		(*t) -> data = x;
		(*t) -> left = NULL;
		(*t) -> right = NULL;
	} else if (x <= (*t) -> data) {
		add_tree(&(*t) -> left, x);
	} else {
		add_tree(&(*t) -> right, x);
	}
}

/*
	Popping items off a stack
	
	This subprogram receives stack using pass by reference. It creates a
	temporary stack called temp. It then sets the temporary stack pointer
	to the top of the stack, sets the data to be popped equal to temp's data,
	moves the top pointer to temp's next pointer, frees temp, and returns
	data popped.
*/

void delete_tree(binarytree *t, int x) {
	binarytree temp;
	temp = (binarytree)malloc(sizeof(struct treenode));	
	if ((*t) != NULL) {
		if ((*t) -> data == x) {
			if (((*t) -> left == NULL) && ((*t) -> right == NULL)) {
				temp = (*t);
				(*t) = NULL;
				free(temp);
				printf("%d was removed\n", x);			
			} else if (((*t) -> left != NULL) && ((*t) -> right == NULL)) {
				temp = (*t);
				(*t) = (*t) -> left;
				free(temp);
				printf("%d was removed\n", x);			
			} else if (((*t) -> left == NULL) && ((*t) -> right != NULL)) {
				temp = (*t);
				(*t) = (*t) -> right;
				free(temp);
				printf("%d was removed\n", x);			
			} else if (((*t) -> left != NULL) && ((*t) -> right != NULL)) {
				temp = (*t) -> left;
				while (temp -> right != NULL) {
					temp = (*t) -> right;
				}
				temp -> right = (*t) -> right;
				temp = (*t);
				(*t) = (*t) -> left;
				free(temp);
				printf("%d was removed\n", x);			
			}
		} else if (x <= (*t) -> data) {
			delete_tree(&(*t) -> left, x);
		} else {
			delete_tree(&(*t) -> right, x);
		}
	} else {
		printf("Error: The number you entered is not in the tree.\n");
	}
}

/*
	Printing a binary tree(Ascending Order)
	
	This subprogram checks to see if the tree is empty. If not, it calls
	itself recursively sending the left subtree, prints the data of the current
	position, and calls itself recursively again sending the right subtree. Printing
	th contents in ascending order.
*/

void LNR(binarytree t) {
	if (!is_empty(t)) {
		LNR(t -> left);
		printf("%d\n", t -> data);
		LNR(t -> right);
	}
}

/*
	Printing a binary tree(Descending Order)
	
	This subprogram checks to see if the tree is empty. If not, it calls
	itself recursively sending the right subtree, prints the data of the current
	position, and calls itself recursively again sending the left subtree. Printing
	th contents in descending order.
*/

void RNL(binarytree t) {
	if (!is_empty(t)) {
		RNL(t -> right);
		printf("%d\n", t -> data);
		RNL(t -> left);
	}
}
