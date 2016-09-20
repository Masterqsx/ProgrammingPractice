# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:26:32 by sqian             #+#    #+#              #
#    Updated: 2016/07/27 10:31:08 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_display_file

SOURCE = *.c

all: $(TARGET)

$(TARGET):
	gcc -Werror -Wall -Wextra -L. -lft -o $(TARGET) -g $(SOURCE)

clean:
	/bin/rm -rf *.dSYM *.o

fclean: clean
	/bin/rm -rf $(TARGET)

re: fclean all

run:
	./$(TARGET) $(arg1) $(arg2) $(arg3)
