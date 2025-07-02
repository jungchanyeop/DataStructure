#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));

	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;

	return root;
}

treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* temp = p->right;
	if (temp == NULL)
		return temp;
	
	if (p->isThreadRight == 1)
		return temp;
	
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

void threadInorder(treeThNode* root) {
	treeThNode* temp = root;
	while (temp->left)
		temp = temp->left;
	do {
		printf("%c ", temp->data);
		temp = findThreadSuccessor(temp);
	} while (temp);
}