#include<iostream>
#include<string>

using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode* ConstructCore(int *startPreorder, int *endPreorder, int* startInorder, int* endInorder){
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();//
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;
	if (startPreorder == endPreorder){
		if (startInorder == endInorder && *startPreorder == *startInorder){
			return root;
		}
		else
			throw std::exception("Invalid input.");
	}
	int* rootPoint = startInorder;
	while (rootPoint<=endInorder && *rootPoint != rootValue){
		rootPoint++;
	}
	if (startInorder == endInorder)
		throw std::exception("Invalid input.");
	int leftTreeLength = rootPoint - startInorder;

	if (leftTreeLength > 0){//construct the left sub_tree
		root->m_pLeft = ConstructCore(startPreorder+1, startPreorder+leftTreeLength, startInorder, rootPoint-1);
	}
	if (endInorder - rootPoint >= 0){//construct the right sub_tree
		root->m_pRight = ConstructCore(startPreorder+leftTreeLength+1, endPreorder, rootPoint+1, endInorder);
	}
	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
	if (preorder == nullptr || inorder == nullptr || length <=0)
		return nullptr;
	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

int main(){
	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int length = 8;
	BinaryTreeNode* bt = Construct(preorder, inorder, length);
	return 0;
}