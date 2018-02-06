/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:21:58 by JianMing                                 */
/*   Updated: 2017/12/13 13:47:27 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
#define TESTING_H

#include "struct.h"

Node	*InsertSon(Node*&, string, Node*&, int);
Node	*InsertBrother(Node*&, string, Node*&, int);
bool	FindFather(string, int, int&);
bool	searchNum(string, string, int&);
Node	*FindPos(Node*, int);
Node	*GetNewNode(string, int, Node*&);
Node	*Backward(Node*&);
void	FreeNode(Node*&);

#endif
