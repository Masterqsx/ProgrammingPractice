# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 12:51:58 by sqian             #+#    #+#              #
#    Updated: 2016/07/21 12:53:41 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Werror -Wall 
TARGET = test
SOURCE2 = test.c

$(TARGET):$(SOURCE2)
	$(CC) $(CFLAGS) -g $(SOURCE2) -o $@

clean:
	rm -rf *.dSYM *.~ $(TARGET)
