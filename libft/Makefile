# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 19:15:33 by emadriga          #+#    #+#              #
#    Updated: 2022/04/27 22:33:22 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Header files
INCLUDES_FILES =	libft.h

# Source files
SRC_FILES	=		ft_atof.c					\
					ft_atoi.c					\
					ft_bzero.c					\
					ft_calloc.c					\
					ft_free.c					\
					ft_isalnum.c				\
					ft_isalpha.c				\
					ft_isascii.c				\
					ft_isdigit.c				\
					ft_isprint.c				\
					ft_isspace.c				\
					ft_itoa.c					\
					ft_lstadd_back.c			\
					ft_lstadd_front.c			\
					ft_lstclear.c				\
					ft_lstdelone.c				\
					ft_lstiter.c				\
					ft_lstlast.c				\
					ft_lstmap.c					\
					ft_lstnew.c					\
					ft_lstsize.c				\
					ft_memccpy.c				\
					ft_memchr.c					\
					ft_memcmp.c					\
					ft_memcpy.c					\
					ft_memmove.c				\
					ft_memset.c					\
					ft_putchar_fd.c				\
					ft_putendl_fd.c				\
					ft_putnbr_fd.c				\
					ft_putnbr_fd_base.c			\
					ft_putstr_fd.c				\
					ft_split.c					\
					ft_strchr.c					\
					ft_strcmp.c					\
					ft_strdup.c					\
					ft_strjoin.c				\
					ft_strjoin_freedouble.c		\
					ft_strlcat.c				\
					ft_strlcpy.c				\
					ft_strlen.c					\
					ft_strmapi.c				\
					ft_strncmp.c				\
					ft_strnstr.c				\
					ft_strrchr.c				\
					ft_strreplace.c				\
					ft_strreplaceat.c			\
					ft_strtrim.c				\
					ft_substr.c					\
					ft_tolower.c				\
					ft_toupper.c				\
					get_array_size.c			\
					get_next_line.c				\
					megafree.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

# Name of the Library
NAME	= libft.a

# Compiling flags
FLAGS	= -Wall -Wextra -Werror

# compiler
GCC		= clang

# Folders
INC_DIR = ./
SRC_DIR = ./src/
OBJ_DIR = ./obj/

# Paths
INCLUDES = $(addprefix $(INC_DIR), $(INCLUDES_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule
all:		obj $(NAME)

# Compile last modifications
obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES)
	@$(GCC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

# Compile as library
$(NAME):	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\033[1;34m[INFO]\033[0m Library [$(NAME)] created!"

# clean rule
clean:
			@rm -Rf $(OBJ_DIR)
			@echo "\033[1;34m[INFO]\033[0m Objects removed!"
# fclean rule
fclean:		clean
			@rm -f $(NAME)
			@echo "\033[1;34m[INFO]\033[0m Library removed!"

# mynorm rule
mynorm:
	norminette $(SRC_DIR) $(INC_DIR)

# re rule
re:			fclean all

# phony
.PHONY:		all clean fclean re
