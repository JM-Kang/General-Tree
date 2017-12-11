/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:18:50 by JianMing                                 */
/*   Updated: 2017/12/11 09:40:51 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

Node	*InsertSon(Node *&root, string name)
{
	if(root == NULL)                 //insert node
		root = GetNewNode(name);
	else		    				 //insert first son if he has
		root->son = InsertSon(root->son, name);
	return (root);
}

Node	*InsertBrother(Node *&root, string name)
{
	if(root == NULL)
		root = GetNewNode(name);
	else		    				 
		root->brother = InsertBrother(root->brother, name);
	return (root);
}

string	FindFather(string filename, int i)
{
	ifstream c_in;
	c_in.open("data.txt");

	int j = 0;
	int num = 0;
	string str;

	while( j != i)
	{
		c_in >> str;
		c_in >> num;
		j++;
	}
	return (str);
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

Node	*Backward(Node *&root, int num)
{
	root = root->father;
	num--;
	if(num)
		Backward(root, num);
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
