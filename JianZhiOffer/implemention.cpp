//#include<iostream>
//#include<string>
//
//using namespace std;
//
//struct BinaryTreeNode{
//	int m_nValue;
//	BinaryTreeNode* m_pLeft;
//	BinaryTreeNode* m_pRight;
//};
//
//void preReverse(BinaryTreeNode *node){
//	if (node == nullptr)
//		return ;
//	cout << node->m_nValue << endl;
//	preReverse(node->m_pLeft);
//	preReverse(node->m_pRight);
//}
//
//void create(BinaryTreeNode* &node){
//	char value;
//	cin >> value;
//	if (value == '#'){
//		node = nullptr;
//	}
//	else{
//		node = new BinaryTreeNode();
//		node->m_nValue = int(value-'0');
//		create(node->m_pLeft);
//		create(node->m_pRight);
//	}
//	return;
//}
//
//int main(){
//	BinaryTreeNode *node = new BinaryTreeNode();
//	create(node);
//	preReverse(node);
//}