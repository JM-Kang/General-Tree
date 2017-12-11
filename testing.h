/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:21:58 by JianMing                                 */
/*   Updated: 2017/12/11 09:22:05 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
#define TESTING_H

#include "struct.h"

Node	*InsertSon(Node*&, string);
Node	*InsertBrother(Node*&, string);
string	FindFather(string, int);
Node	*FindPos(Node*, string);
Node	*GetNewNode(string);
Node	*Backward(Node*&, int);
void	FreeNode(Node*&);

#endif
