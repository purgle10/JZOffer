#include<iostream>
#include<string>

using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void preTraversal(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	cout << node->m_nValue << endl; // it's the core process to do anything. 
	preTraversal(node->m_pLeft);
	preTraversal(node->m_pRight);
}

void inTraversal(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	inTraversal(node->m_pLeft);
	cout << node->m_nValue << endl;
	inTraversal(node->m_pRight);
}

void backTraversal(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	backTraversal(node->m_pLeft);
	backTraversal(node->m_pRight);
	cout << node->m_nValue << endl;
}

void create(BinaryTreeNode* &node){
	char value;
	cin >> value;
	if (value == '#'){
		node = nullptr;
	}
	else{
		node = new BinaryTreeNode();
		node->m_nValue = int(value - '0');
		create(node->m_pLeft);
		create(node->m_pRight);
	}
	return;
}

int main(){
	BinaryTreeNode *node = new BinaryTreeNode();
	create(node);
	preTraversal(node);
	inTraversal(node);
	backTraversal(node);
}