#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"


BTNode* BuyBinTreeNode(BTDataType data) {
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _CreatBinTree(BTDataType* array, int size, int* index,BTDataType invalid) {
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index]) {
		//根结点
		pRoot = BuyBinTreeNode(array[*index]);
		//根的左子树
		++(*index);
		pRoot->_pLeft = _CreatBinTree(array, size, index,invalid);
		//根的右子树
		++(*index);
		pRoot->_pRight = _CreatBinTree(array, size, index,invalid);
	}
	return pRoot;
}
BTNode* CreatBinTree(BTDataType* array, int size, BTDataType invalid) {
	int index = 0;
	return _CreatBinTree(array, size, &index,invalid);
}
