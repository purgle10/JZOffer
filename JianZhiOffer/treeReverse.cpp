#include<iostream>
#include<string>

using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void preReverse(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	cout << node->m_nValue << endl;
	preReverse(node->m_pLeft);
	preReverse(node->m_pRight);
}

void inReverse(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	inReverse(node->m_pLeft);
	cout << node->m_nValue << endl;
	inReverse(node->m_pRight);
}

void backReverse(BinaryTreeNode *node){
	if (node == nullptr)
		return;
	backReverse(node->m_pLeft);
	backReverse(node->m_pRight);
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
	preReverse(node);
	inReverse(node);
	backReverse(node);
}