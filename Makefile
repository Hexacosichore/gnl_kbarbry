# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 16:10:23 by kbarbry           #+#    #+#              #
#    Updated: 2021/11/08 17:39:54 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		=	\033[0m
BPurple		=	\033[1;35m
BGreen		=	\033[1;32m
UYellow		=	\033[3;33m

PART_1		=	get_next_line.c \
				get_next_line_utils.c

OBJ			=	${PART_1:.c=.o}

OBJ_BONUS	=	${BONUS_PART:.c=.o}

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I.
NAME		=	get_next_line.a

all:		${NAME}

%.o:%.c get_next_line.h
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "${BPurple}[OBJ_FILE CREATED] :${RESET} ${<:.c=.o}${BGreen}\033[46G[✔]"

${NAME}:	${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "\n================================================"
	@echo "\n${BGreen}[DONE] ${RESET}all object files has been cleaned.${BGreen}\033[46G[✔]"

fclean: clean
	@rm -f ${NAME}
	@echo "${BGreen}[DONE] ${RESET}libft.a has been cleaned.${BGreen}\033[46G[✔]"
	@echo "\n${UYellow}\033[15G[EVERYTHING IS CLEAN]${RESET}\n"
	@echo "================================================\n"

bonus: ${NAME} ${OBJ} ${OBJ_BONUS}
	@ar rcs ${NAME} ${OBJ} ${OBJ_BONUS}
	@echo "\n${UYellow}\033[17G[BONUS ARE READY]${RESET}\n"
	@echo "================================================\n"

re:		fclean all
	@echo "\n${UYellow}\033[17G[LIBFT IS READY]${RESET}\n"
	@echo "================================================\n"

.PHONY: clean fclean all re