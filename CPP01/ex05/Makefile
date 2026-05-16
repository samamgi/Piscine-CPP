# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 03:37:18 by ssadi-ou          #+#    #+#              #
#    Updated: 2025/09/28 01:26:29 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harl

SRCS	= main.cpp \
		  Harl.cpp \


OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(OBJS): Harl.hpp

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
