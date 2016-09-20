# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:26:32 by sqian             #+#    #+#              #
#    Updated: 2016/07/31 18:51:32 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = rush-2

SOURCE = *.c

all: $(TARGET)

$(TARGET):
	gcc -Werror -Wall -Wextra -o $(TARGET) $(SOURCE)

clean:
	/bin/rm -rf *.dSYM *.o

fclean: clean
	/bin/rm -rf $(TARGET)

re: fclean all



