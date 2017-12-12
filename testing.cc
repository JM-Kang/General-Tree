/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:18:50 by JianMing                                 */
/*   Updated: 2017/12/11 16:21:56 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

Node	*InsertSon(Node *&root, string name)
{
	if(root == NULL)                 //insert node
		root = GetNewNode(name);
	else		    				 //insert first son if he has
	{
//		Node *temp = new Node;
//		temp = root->son;
		root->son = InsertSon(root->son, name);
//		temp->father = root;
	}
	return (root);
}

Node	*InsertBrother(Node *&root, string name)
{
	if(root == NULL)
		root = GetNewNode(name);
	else
	{
//		Node *temp = new Node;
//		temp = root->brother;;
		root->brother = InsertBrother(root->brother, name);
//		temp->father = root;
	}
	return (root);
}

bool	FindFather(string filename, int i, string &name)
{
	ifstream c_in;
	c_in.open("data.txt");

	int j = 0;
	int num = 0;

	while(c_in)
	{
		c_in >> name;
		if(j == i)
			return (true);
		c_in >> num;
		j++;
	}
	return (false);
}

Node	*FindPos(Node *root, string name)
{		
	Node *temp = new Node;
	temp = root;

	if(temp == NULL)
		return (temp);
	if(temp->name == name)
		return (temp);
	temp = FindPos(temp->son, name);
//	temp = FindPos(temp->brother, name);
	return (temp);
}

Node	*Backward(Node *&root)
{
	if(root->father == NULL)
		return (root);
	else	
		root = Backward(root->father);
	return (root);
}

Node	*GetNewNode(string name)
{
	Node *newNode = new Node;
	newNode->name = name;
	newNode->son = newNode->brother = NULL;
	return (newNode);
}

void	FreeNode(Node *&leaf)
{
	if(leaf != NULL)
	{
		FreeNode(leaf->son);
		FreeNode(leaf->brother);
		delete leaf;
	}
}
