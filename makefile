# **************************************************************************** #
#                                                                              #
#                                                                              #
#    makefile                                                                  #
#                                                                              #
#    By: JianMing <jason.kang1106@gmail.com>                                   #
#                                                                              #
#    Created: 2017/11/26 20:46:22 by JianMing                                  #
#    Updated: 2017/11/26 20:50:42 by JianMing                                  #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = *.o
SRCS = *.cc
HEADER = *.h

all: $(NAME)
	g++ $(OBJS) -o $(NAME)

$(NAME): $(SORCS) $(HEADER)
	g++ -Wall -c $(SRCS)

clean:
	rm -rf $(OBJS)
	rm -rf statement.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all
