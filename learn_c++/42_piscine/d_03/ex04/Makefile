# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqian <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 12:51:58 by sqian             #+#    #+#              #
#    Updated: 2016/07/14 09:26:44 by sqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Werror -Wall 
TARGET = test
SOURCE1 = ft_*.c
SOURCE2 = test.c

$(TARGET):$(SOURCE1) $(SOURCE2)
	$(CC) $(CFLAGS) -g $(SOURCE1) $(SOURCE2) -o $@
