/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 18:55:09 by JianMing                                 */
/*   Updated: 2017/12/10 01:18:10 by JianMing                                 */
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
	Node		*ca;
//	int			j = 0;
//	int			temp = 0;

	c_cin.open("data.txt");
	os.open("statement.txt");

//	while(c_cin)
//	{
		int i = 0;
		int n = 1;
		int j = 0;
		int temp = 0;
		ca = new Node(c_cin);
		temp = ca->num[0] + 1;
		while(ca->name[i] != "\0")
		{
			while(temp == 0)
			{
				j++;
				temp = ca->num[j];
				if(temp != 0)
				{
					tree = FindPos(tree, ca->Son_Father[n]);
					cout << tree->info;
					n++;
				}
			}
			if(ca->num[j] >= temp)
				InsertSon(tree, ca->name[i]);
			else 
				InsertBrother(tree, ca->name[i]);
			temp--;
			i++;
		}
		//	if(!temp && ca->num[j++])
		//	{	
		//		Backward(tree, ca->num[i] - 1);
		//		j++;
		//		temp = ca->num[j];
		//	}
		
		inorder(tree, os);
	//	if(!treeEmpty(tree, c_out);
	//		printInfo(tree, c_out);
	//	FreeNode(tree);
	delete ca;
//	}
	c_cin.close();
	os.close();
	return (0);
}
