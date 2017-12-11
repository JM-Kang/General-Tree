/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 18:55:09 by JianMing                                 */
/*   Updated: 2017/12/11 09:41:13 by JianMing                                 */
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

	string		name;
	int			num[10];


	c_cin.open("data.txt");
	os.open("statement.txt");

	tree = NULL;
	int i = 0;
	int j = 0;
	int temp = 0;
		
	while(c_cin)
	{
		c_cin >> name;
		c_cin >> num[i];
		if(i == 0)				//set first num to temp
			temp = num[j];
		while(temp == 0)	//if temp = 0, find next num
		{
			j++;
			temp = num[j];
			if(temp)        //if temp has value, find father and then find father position
			{
				name = FindFather("data.txt", j);
				tree = FindPos(tree, name);
				cout << tree->name << " ";
			}	 
		}
		if(i == 0 || temp == num[j]) //first node and subtree's first node place to son subtree
			InsertSon(tree, name);
		else   						// rest nodes place into brother subtree
			InsertBrother(tree, name);
		
		temp--;
		i++;
	}
	//	inorder(tree, os);
	//	if(!treeEmpty(tree, c_out);
	//		printInfo(tree, c_out);
	//	FreeNode(tree);
	c_cin.close();
	os.close();
	return (0);
}
