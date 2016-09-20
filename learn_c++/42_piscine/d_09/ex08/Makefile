# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 12:51:58 by sqian             #+#    #+#              #
#    Updated: 2016/07/22 10:43:18 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Werror -Wall -Wextra 
TARGET = test
SOURCE1 = ft_*.c

$(TARGET):$(SOURCE1)
	$(CC) $(CFLAGS) -g $(SOURCE1)  -o $@

clean:
	rm -rf *.dSYM *.~ $(TARGET)
