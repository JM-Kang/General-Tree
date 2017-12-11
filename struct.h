/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:04:10 by JianMing                                 */
/*   Updated: 2017/12/07 17:34:02 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string	name[20];
	int		num[20];
	string	Son_Father[20];
	string	info;
	Node	*son;
	Node	*brother;
	Node	*father;
	Node();
	Node(ifstream&);
};
#endif
