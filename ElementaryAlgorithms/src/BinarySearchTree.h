//Binary Search Tree

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <cstddef>

class Node
{
public:
	int data;
	Node *left,*right;
	Node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

class BST
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
			return new Node(data);
		else
		{
			Node* cur;
			if(data <= root->data)
			{
				cur = insert(root->left, data);
				root->left = cur;
			}
			else
			{
				cur = insert(root->right, data);
				root->right = cur;
			 }
			return root;
		}
	}
    void getHeight(Node* n, int& l, int& maxLevel)
    {
        l++;
        if (n->left != NULL)
            getHeight(n->left, l, maxLevel);
        if (n->right != NULL)
            getHeight(n->right, l, maxLevel);
        if (maxLevel < l)
            maxLevel = l;
        l--;
    }
    int getHeight(Node* root)
    {
        int level = 0;
        int maxLevel = 0;
        getHeight(root, level, maxLevel);
        return maxLevel;
    }
};

void testBST()
{
    BST myTree;
    Node* root=NULL;
    int T, data;
    std::cin >> T;
    while(T-->0){
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    int height= myTree.getHeight(root);
    std::cout<<height;
}

#endif /* BINARYSEARCHTREE_H_ */
