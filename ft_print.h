/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.h                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:27:59 by JianMing                                 */
/*   Updated: 2017/12/13 17:21:13 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
#define FT_PRINT_H

#include "struct.h"

void	printSearch(int, Node*, ofstream&, string);
void	searchFather(Node*, ofstream&, string);
void	searchAllson(Node*, ofstream&, string);
void	searchAllbrother(Node*, ofstream&, string);
void	searchOldestr(Node*, ofstream&, string);
void	searchYoungestr(Node*, ofstream&, string);
void	inorder(Node*&, ofstream&);

#endif
