/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:18:50 by JianMing                                 */
/*   Updated: 2017/12/10 01:40:00 by JianMing                                 */
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

Node	*FindPos(Node *root, string father)
{		
	Node *temp = new Node;
	temp = root;

	if(temp == NULL)
		return (temp);
//	if(temp->info == father)
//	{
//		cout << temp->info;
//		return (temp);
//	}
	temp->son = FindPos(temp->son, father);
	temp->son = root->father;
//	temp = FindPos(temp->brother, father);
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
	newNode->info = name;
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

//	{
	//	Node *temp = NULL;
	//	temp = root->brother;
	//	temp->father = root;
//		root->brother = Insert(root->brother, name, NumSon, cur_son);
//	}
//	{
///		Node *temp = new Node;
//		temp = root->son;
//		temp->father = root;
