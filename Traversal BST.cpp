#include <iostream>
using namespace std;
struct bst
{
	int data;
	bst *left;
	bst *right;
};
bst*root = NULL;
void insert()
{
	cout << "Enter node data " << endl;
	bst *newnode = new bst;
	cin >> newnode->data;
	newnode->left = newnode->right = NULL;
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		bst *temp = root;
		while (temp != NULL)
		{
			if (newnode->data < temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					break;
				}
				else
				{
					temp = temp->left; // left aur neechay jao 

				}

			}
			else if (newnode->data > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					break;
				}
				else
				{
					temp = temp->right; // right aur neechay jao 

				}

			}
			else
			{
				cout << "DUPLICATE DATA " << endl;
				break;
			}

		}
	}
}
void inorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 

		inorder(temp->left);                      // 1
		cout << temp->data << " ";             // 2
		inorder(temp->right);                     // 3
	}

}
void preorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 
		cout << temp->data << " ";
		preorder(temp->left);
		preorder(temp->right);
	}

}
void postorder(bst *temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{// inorder                               // preorder : 2,1,3  //post: 1,3,2 

		postorder(temp->left);
		postorder(temp->right);
		cout << temp->data << " ";
	}

}
int main()
{
	int x,z;
	cout << "How many nodes you want to enter:" << endl;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		insert();
	}
	cout << "In which order you want to show data:" << endl;
	cout << "1) Preorder 2) Inorder 3) Post order" << endl;
	cin >> z;
	if (z == 1)
	{
		preorder(root);
	}
	else if (z == 2)
	{
		inorder(root);
	}
	else if (z == 3)
	{
		postorder(root);
	}
	system("pause");
}

