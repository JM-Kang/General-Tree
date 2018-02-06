/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:18:50 by JianMing                                 */
/*   Updated: 2017/12/13 21:10:56 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

//add son to the left subtree
Node	*InsertSon(Node *&root, string name, Node *&node_father, int num)
{
	if(root == NULL)
		root = GetNewNode(name, num, node_father);
	else
		root = InsertSon(root->son, name, node_father, num);
	return (root);
}

//add son to the right subtree
Node	*InsertBrother(Node *&root, string name, Node *&node_father, int num)
{
	if(root == NULL)
		root = GetNewNode(name, num, node_father);
	else
		root = InsertBrother(root->brother, name, node_father, num);
	return (root);
}

//find the number that represent father by using arrays of index
bool	FindFather(string filename, int j, int &n)
{
	ifstream c_in;
	c_in.open("data1.txt");

	int i = 0;
	int num = 0;
	string name = " ";

	while(c_in)
	{
		c_in >> name;
		c_in >> num;
		c_in >> n;
		if(j == i)   //number is found
			return (true);
		i++;
	}
	return (false);
}

//find the number the that represent father by using father name
bool	searchNum(string filename, string str, int &n)
{
	ifstream c_in;
	c_in.open("data1.txt");

	int i = 0;
	int num = 0;
	string name = " ";

	while(c_in)
	{
		c_in >> name;
		c_in >> num;
		c_in >> n;
		if(str == name)  //number is found
			return (true);
		i++;
	}
	return (false);
}

//find the position that the node has by using recurison
Node	*FindPos(Node *root, int num)
{		
	if(root == NULL || root->num == num)
		return (root);
	else if(num < root->num)
		return FindPos(root->son, num);
	else return FindPos(root->brother, num);
}

//create new node
Node	*GetNewNode(string name, int n, Node *&node_father)
{
	Node *newNode = new Node;
	newNode->name = name;
	newNode->num = n;
	newNode->father = node_father;
	newNode->son = newNode->brother = NULL;
	return (newNode);
}

//free the tree
void	FreeNode(Node *&leaf)
{
	if(leaf != NULL)
	{
		FreeNode(leaf->son);
		FreeNode(leaf->brother);
		delete leaf;
	}
}
