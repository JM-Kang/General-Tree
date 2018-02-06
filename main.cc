/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 18:55:09 by JianMing                                 */
/*   Updated: 2017/12/13 21:10:48 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_print.h"
#include "testing.h"

int	main(void)
{
	ifstream	c_cin;
	ofstream	os;
	Node		*tree;
	string		name = " ";
	int			FatherNum = 0;
	int			num[10];
	
	c_cin.open("data1.txt");
	os.open("statement1.txt");
	tree = NULL;
	int i = 0;    //the index of son  
	int j = 0;	  //the index of temporary num arrays
	int temp = 0; //countdown the num of son
	int	n = 0;	  //represt the name of person	

	c_cin >> name;
	c_cin >> num[i];
	c_cin >> n;
	os << name << " ";
	
	Node *node_father = new Node;	//hold the father address
	Node *temPtr = new Node;		//hold the initial tree address
	temPtr = InsertSon(tree, name, node_father, n);
	temp = num[j];
	i++;
	
	if(FindFather("data1.txt", j, FatherNum))
		node_father = FindPos(tree, FatherNum);    //find the first person who has father address

	while(c_cin)
	{
		c_cin >> name;
		c_cin >> num[i];
		c_cin >> n;
		os << name << " ";
		while(temp == 0)	//if no more son, find the next person who has son
		{
			j++;
			temp = num[j];
			if(temp != 0)       
				if(FindFather("data1.txt", j, FatherNum))   //find the next father address
				{
					node_father = FindPos(temPtr, FatherNum);
					tree = node_father;
				}
		}	
		if(temp == num[j])   //if first son of the father, add to son subtree
			InsertSon(tree, name, node_father, n);
		else 				//the rest sons add to brother subtree if any
			InsertBrother(tree, name, node_father, n);
		temp--;
		i++;
		name = "";
	}
	os << endl;
	
	int k = 0;       //counter for the questions
	int num_type = 0;  //point to which question
	while(k < 5)
	{
		cout << "What question you want to ask?" <<endl;
		cin >> num_type;
		cout << "What person you want to ask?"<< endl; 
		cin >> name;
		if(searchNum("data1.txt", name, FatherNum)) //find the num represent person 
			node_father = FindPos(temPtr, FatherNum); //find the person address
		printSearch(num_type, node_father, os, name); //go to each question
		k++;
	}
	os << endl;
	FreeNode(tree);
	c_cin.close();

	os.close();
	return (0);
}
