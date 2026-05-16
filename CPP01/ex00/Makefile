# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 03:37:18 by ssadi-ou          #+#    #+#              #
#    Updated: 2025/09/27 13:05:16 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= BraiiiiiiinnnzzzZ

SRCS	= main.cpp \
	  newZombie.cpp \
	  Zombie.cpp \
	  randomChump.cpp \

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(OBJS): *.hpp

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
