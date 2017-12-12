/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 18:55:09 by JianMing                                 */
/*   Updated: 2017/12/11 16:19:16 by JianMing                                 */
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
	string		FatherName = " ";
	int			num[10];

	c_cin.open("data.txt");
	os.open("statement.txt");

	tree = NULL;
	int i = 0;
	int j = 0;
	int temp = 0;

	string str = " ";
	while(i<4)
	{
		c_cin >> name;
		c_cin >> num[i];
		if(i == 0)				//set first num to temp
		{
			temp = num[j] + 1;
			str = name;
		}
	/*	while(temp == 0)	//if temp = 0, find next num
		{
			j++;
			temp = num[j];
			if(temp)        //if temp has value, find father and then find father position
			{
				if(FindFather("data.txt", j, FatherName))
				{
					tree = FindPos(tree, FatherName);
					cout << tree->name << " ";
				}
			}	 
		}(
*/	//	if(i == 0)
	//		tree = InsertSon(tree, name);
	//	else if(
		if(i == 0 || temp == num[j])
			tree = InsertSon(tree, name);
		else   						// rest nodes place into brother subtree
			tree = InsertBrother(tree, name);
		temp--;
		i++;
	}
	tree = Backward(tree);
	cout << tree->name;
	inorder(tree, os);
	//	if(!treeEmpty(tree, c_out);
	//		printInfo(tree, c_out);
	//	FreeNode(tree);
	c_cin.close();
	os.close();
	return (0);
}
