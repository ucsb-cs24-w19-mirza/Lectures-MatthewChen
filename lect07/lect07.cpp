#include <iostream>
using namespace std;
class BST{ //This version will have no duplicates
	private:
	class BSTNode{
		BSTNode* left;
		BSTNode* right;
		BSTNode* parent;
		int const data;
	
	};
	BSTNode* root;
	
	BSTNode* successor(BSTNode* node);
	BSTNode* predecessor(BSTNode* node);

	BSTNode* min(BSTNode* tree);
	BSTNode* max(BSTNode* tree);

	BSTNode* search(int value);
	void deleteNode(BSTNode* node);
	
	public:
	bool search(BSTNode* tree, int value);
	int max();
	int min();
	void deleteNode(int value);
};

void BST::deleteNode(BSTNode* node){
	//Leaf
	if(!node->right && !node->left){
		if(node->parent->left == node){
			node->parent->left == NULL;
			delete node;
		}
		else{
			node->parent->right == NULL;
			delete node;
		}
	}


	//1 Child
	//replace with child
	//2 Children
	//find predecessor or sucessor and replace witht that
}



BSTNode* BST::successor(BSTNode* node){
	if(node->right){
		return min(node->right);
	}
	else{
		BSTNode* parent = node->parent;
		if(!parent){
			return NULL;
		}
		while(parent->data < node->data){
			parent = parent->parent;
			if(!parent){
				return NULL;
			}
		}
		return parent;
	}
}

BSTNode* BST::predecessor(BSTNode* node){
	if(node->left){
		return max(node->left);
	}
	else{
		BSTNode* parent = node->parent;
		if(!parent){
			return NULL;
		}
		while(parent->data > node->data){
			parent = parent->parent;
			if(!parent){
				return NULL;
			}
		}
		return parent;
	}
}

BSTNode* BST::search(BSTNode* tree, int value){
	if(!tree){return NULL;}
	
	if(tree->data == value){
		return tree;
	}
	else if(tree->data > value){
		return search(tree->left, value);
	}
	else{
		return search(tree->right, value);
	}
}

bool BST::search(int value){
	BSTNode* node = search(root, value);
	if(node){
		return true;
	}
	else{
		return false;
	}
}

BSTNode* BST::min(BSTNode* tree){
	if(!tree->left){
		return tree;
	}
	return min(tree->left);
}

BSTNode* BST::max(BSTNode* tree){
	if(!tree->right){
		return tree;
	}
	return min(tree->right);
}

int BST::min(){
	return min(root)->data;
}

int BST::max(BSTNode* tree){
	return max(root)->data;
}




int main(){
	return 0;
}
