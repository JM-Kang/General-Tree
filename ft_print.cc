/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:25:31 by JianMing                                 */
/*   Updated: 2017/12/13 20:54:30 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "testing.h"

//find the father of the node and print it out
void	searchFather(Node *node_father, ofstream &os, string name)
{
	if(node_father->num == 99)  //if first node of tree, then no father
		os << name <<" has no father" << endl;
	else
		os << name <<"'s father is "<< node_father->father->name << endl;
}


//search all the son of the node and print it out
void	searchAllson(Node *node, ofstream &os, string name)
{
	Node *temp = new Node;
	if(node->son->name == " ")  // no son
		os << name <<" has no sons" << endl;
	else
	{
		temp = node->son;   //has one son
		os << temp->name <<" is " << node->name<<"' son"<<endl;
	}
	while(temp->brother != NULL)  //has more than one son
	{
			temp = temp->brother;
			os << temp->name <<" is " << node->name<<"' son"<<endl;
	}	
}

//search all the brother of node and print it out
void	searchAllbrother(Node *node, ofstream &os, string name)
{
	Node *temp = new Node;
	if(node->num == 99)    //first node of the tree, no brother
		os<< name << " has no brothers" << endl;
	else   
	{
		temp = node->father;
		temp = temp->son;
		if(temp->name == node->name)
			os << temp->name <<" has no brothers" << endl;
		else
		{
			os << temp->name <<" is " << node->name<<"' brother"<<endl;
			while(temp->brother != NULL)   //more than one brother
			{
				temp = temp->brother;
				if(temp->name == node->name)   //the person in the middle, skip it
				{	
					if(temp->brother == NULL)
					break;
					temp = temp->brother;
				}
				os << temp->name <<" is " << node->name<<"' brother"<<endl;
			}
		}
	}
}


//search the oldest brother of the node and print it
void	searchOldest(Node *node, ofstream &os, string name)
{
	Node *temp = new Node;
	if(node->num == 99)   //first node of tree, the oldest 
		os << node->name << " is the oldest" << endl;
	else if(node->father->son->name == node->name) //no brother
		os << node->name <<" is the oldest brother"<<endl;
	else 
	{
		temp = node->father;
		temp = temp->son;
		if(temp->name != node->name)
			os << temp->name <<" is " << node->name<<"' the oldest brother"<<endl;
	}
}

//find the youngest brother of the node and print it
void	searchYoungest(Node *node, ofstream &os, string name)
{
	Node *temp = new Node;
	if(node->num == 99)   //first node of the tree, the oldest
		os << node->name << " is the youngest" << endl;
	else if(node->father->son->brother == NULL)    //the node is the youngest
		os << node->name <<" is "<< node->name<<"'s the youngest brother"<<endl;
	else    //find younger brothers
	{
		temp = node->father;
		temp = temp->son;
		while(temp->brother != NULL)
				temp = temp->brother;
		os << temp->name <<" is " << node->name<<"'s the youngest brother"<<endl;
	}
}

//goes to each question 
void	printSearch(int num, Node *root, ofstream &os, string name)
{
	if(num == 1)
		searchFather(root, os, name);
	else if(num == 2)
		searchAllson(root, os, name);
	else if(num == 3)
		searchAllbrother(root, os, name);
	else if(num == 4)
		searchOldest(root, os, name);
	else if(num == 5)
		searchYoungest(root, os, name);
}
