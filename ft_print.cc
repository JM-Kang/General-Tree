/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:25:31 by JianMing                                 */
/*   Updated: 2017/12/11 09:19:10 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "testing.h"

bool	treeEmpty(Node *&tree, ofstream &os)
{
	if(tree == NULL)
	{
		os << "This is empty tree" << endl << endl;
		return (true);
	}
	else
		return (false);
}

void	inorder(Node *&node, ofstream &os)
{
	if(node == NULL)
		return;
	inorder(node->son, os);
	os << node->name << " ";
	inorder(node->brother, os);
	return;
}
