#include <stdio.h>
#include <stdlib.h>
#include "node2.h"
#include "bst2.h"

treeNode* searchBST(treeNode* root, element x) {
	treeNode* p = root;
	int count = 0;
	while (p != NULL) {
		count++;
		if (x < p->key)
			p = p->left;
		else if (x == p->key)
		{
			printf("%3d��°�� Ž�� ����", count);
			return p;
		}
		else
			p = p->right;
	}
	count++;
	printf("%3d��°�� Ž�� ����! ã�� Ű�� �����ϴ�!", count);
	
	return p;
}

treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}
	else if (x < p->key)
		p->left = insertBSTNode(p->left, x);
	else if (x > p->key)
		p->right = insertBSTNode(p->right, x);
	else
		printf("\n �̹� �����ϴ� Ű");

	return p;
}

void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ_parent, * succ;
	treeNode* child;

	parent = NULL;
	p = root;

	while ((p != NULL) && (key != p->key)) {
		parent = p;
		if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}

	if (p == NULL) {
		printf("\n �������� �ʴ� key");
		return;
	}

	if (p->left == NULL && p->right == NULL) {
		if (parent != NULL) {
			if (parent->left == p)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
	}
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL)
			child = p->left;
		else
			child = p->right;

		if (parent != NULL) {
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;
	}
	else {
		succ_parent = p;
		succ = p->left;
		
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		
		if (succ_parent->left == succ)
			succ_parent->left = succ->left;
		else
			succ_parent->right = succ->left;

		p->key = succ->key;
		p = succ;
	}
	free(p);
}