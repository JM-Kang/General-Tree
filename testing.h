/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:21:58 by JianMing                                 */
/*   Updated: 2017/12/11 13:59:25 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
#define TESTING_H

#include "struct.h"

Node	*InsertSon(Node*&, string);
Node	*InsertBrother(Node*&, string);
bool	FindFather(string, int, string&);
Node	*FindPos(Node*, string);
Node	*GetNewNode(string);
Node	*Backward(Node*&);
void	FreeNode(Node*&);

#endif
