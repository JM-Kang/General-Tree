/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.cc                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/04 11:08:01 by JianMing                                 */
/*   Updated: 2017/12/07 20:32:25 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

Node::Node()
{
	name[0] = " ";
	num[0] = 0;
	Son_Father[0] = " ";
	son = NULL;
	brother = NULL;
	father = NULL;
}

Node::Node(ifstream &cin)
{
	int	i = 0;
	int j = 0;
	while(cin)
	{
		cin >> name[i];
		cin >> num[i];
		if(num[i] != 0)
		{
			Son_Father[j] = name[i];
			j++;
		}
		i++;
	}
}
