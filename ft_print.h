/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.h                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/11/28 19:27:59 by JianMing                                 */
/*   Updated: 2017/12/06 19:04:45 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
#define FT_PRINT_H

#include "struct.h"

bool	treeEmpty(Node*&, ofstream);
void	inorder(Node*&, ofstream&);

#endif
