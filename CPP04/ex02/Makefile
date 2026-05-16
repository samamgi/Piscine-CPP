# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 03:37:18 by ssadi-ou          #+#    #+#              #
#    Updated: 2026/01/26 23:24:28 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Polymorphism \

SRCS	= main.cpp \
	  Cat.cpp \
	  Dog.cpp \
	  AAnimal.cpp \
	  WrongAnimal.cpp \
	  WrongCat.cpp \
	  Brain.cpp \

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

all:	$(NAME)

$(OBJS): AAnimalClass.hpp DogClass.hpp CatClass.hpp WrongAnimalClass.hpp WrongCatClass.hpp BrainClass.hpp

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
