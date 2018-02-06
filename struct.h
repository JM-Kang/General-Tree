/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:04:10 by JianMing                                 */
/*   Updated: 2017/12/13 11:22:21 by JianMing                                 */
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
	string	name;
	int		num;
	Node	*son;
	Node	*brother;
	Node	*father;
};
#endif
