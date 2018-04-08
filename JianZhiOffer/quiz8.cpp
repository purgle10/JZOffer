#include <iostream>

using namespace std;

struct TreeNode{
	int m_nValue;
	TreeNode *m_pLeft;
	TreeNode *m_pRight;
	TreeNode *m_pParent;
};

void create(TreeNode* &node){
	char value;
	cin >> value;
	if (value == '#'){
		node = nullptr;
	}
	else{
		node = new TreeNode();
		node->m_nValue = int(value - '0');
		create(node->m_pLeft);
		if (node->m_pLeft)
			node->m_pLeft->m_pParent = node;
		create(node->m_pRight); // is same to pre reverse
		if (node->m_pRight)
			node->m_pRight->m_pParent = node;
	}
	return;
}

TreeNode* findNextNode(TreeNode *node){
	if (!node->m_pLeft && !node->m_pRight){
		if (node == node->m_pParent->m_pLeft){
			return node->m_pParent;
		}
		else{			
			TreeNode *tmp = new TreeNode();
			tmp = node;
			while (!tmp->m_pParent->m_pParent){
				tmp = tmp->m_pParent;
			}
			if (tmp == tmp->m_pParent->m_pLeft)
				return tmp->m_pParent;
			else
				return nullptr;
		}
	}
	else if (node->m_pRight->m_pLeft){
		return node->m_pRight->m_pLeft;
	}
	else if (!node->m_pRight->m_pLeft)
		return node->m_pRight;
}

int main(){
	TreeNode *node = new TreeNode();
	node->m_pParent = nullptr;
	create(node);
	TreeNode* nextNode;
	nextNode = findNextNode(node);
}