# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:26:32 by sqian             #+#    #+#              #
#    Updated: 2016/07/30 23:43:28 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = eval_expr

SOURCE = *.c

all: $(TARGET)

$(TARGET):
	gcc -Werror -Wall -Wextra -o $(TARGET) $(SOURCE)

clean:
	/bin/rm -rf *.dSYM *.o

fclean: clean
	/bin/rm -rf $(TARGET)

re: fclean all

run:
	./$(TARGET) $(arg1) $(arg2) $(arg3)
