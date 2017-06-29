# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 18:50:57 by jcasino           #+#    #+#              #
#    Updated: 2017/05/09 19:50:40 by jcasino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc

AR			= ar -rc

C_FLAGS = -Wall -Wextra -Werror

SRC_DIR	= ./

INC_DIR	=	./includes/

OBJ_DIR = ./obj/

#** Memory Functions **


C_FILES	= ft_bzero.c \
			ft_memalloc.c		\
			ft_memccpy.c		\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memset.c			\


#** I/O Functions **


C_FILES	+= ft_putchar_fd.c\
			ft_putchar.c				\
			ft_putendl_fd.c			\
			ft_putendl.c				\
			ft_putnbr_fd.c			\
			ft_putnbr_just.c		\
			ft_putnbr.c					\
			ft_putstr_fd.c			\
			ft_putstr.c					\



#** String Functions **


C_FILES	+= ft_isalnum.c \
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_islower.c			\
			ft_isprint.c			\
			ft_isspace.c			\
			ft_isupper.c			\
			ft_numwords.c			\
			ft_strcat.c				\
			ft_strchr.c				\
			ft_strclr.c				\
			ft_strcmp.c				\
			ft_strcpy.c				\
			ft_strcspn.c			\
			ft_strdel.c				\
			ft_strdup.c				\
			ft_strdupn.c			\
			ft_strequ.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strjoin.c			\
			ft_strlcat.c			\
			ft_strlen.c				\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strncat.c			\
			ft_strncmp.c			\
			ft_strncpy.c			\
			ft_strnequ.c			\
			ft_strnew.c				\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strsplit.c			\
			ft_strstr.c				\
			ft_strsub.c				\
			ft_strtrim.c			\
			ft_tolower.c			\
			ft_toupper.c			\


#** get_next_line **


C_FILES += get_next_line.c	\



#** List Functions **


C_FILES	+= ft_lstadd.c 	\
			ft_lstaddend.c	 	\
			ft_lstcount.c			\
			ft_lstdel.c				\
			ft_lstdelone.c		\
			ft_lstcount.c			\
			ft_lstdel.c				\
			ft_lstdelone.c		\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_lstnew.c				\


#** Converstions Functions **


C_FILES	+= ft_atoi.c	\
			ft_itoa.c				\


#** ft_printf Functions **


C_FILES += ft_itoa_uintmax.c 		\
			ft_printf.c								\
			manage_flags.c						\
			manage_length.c						\
			manage_specifier.c				\
			manage_width_precision.c	\
			print_base.c							\
			print_binary_none.c				\
			print_helper.c						\
			print_int.c								\
			print_pointer.c						\
			print_string.c


SOURCES=$(addprefix $(C_FILES))

INCLUDES=$(addprefix -I, $(INC_DIR))

OBJECTS=$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(C_FILES)))



# COLORS
RESET=		\033[0m
DARK=		\033[1;32m
RED=		\033[31m
GREEN=		\033[32m
YELLOW=		\033[33m
BLUE=		\033[34m
MAGENTA=	\033[35m
CYAN=		\033[36m
WHITE=		\033[37m
BOLDBLACK=	\033[1m\033[30m
BOLDRED=	\033[1m\033[31m
BOLDWHITE=	\033[1m\033[37m

default : all

test : $(NAME)
		$(MAKE) -C ./test/ re
		./test/test.out

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS)
		@echo "$(CYAN)Archiving object files...$(DARK)"
		@$(AR) $(NAME) $(OBJECTS)
		@echo "$(GREEN)Done. $(RESET)"
		@echo "$(CYAN)Indexing... $(DARK)"
		@ranlib $(NAME)
		@echo "$(GREEN)Done.$(RESET)"
		@echo "$(GREEN)libft.a now available $(DARK)"

build:
		@mkdir obj

$(OBJ_DIR) :
		@echo "$(CYAN)Creating build directory...$(DARK)"
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREEN)Done.$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
				@$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDES)


fclean : clean
		@echo "$(CYAN)Removing $(NAME)...$(DARK)"
		@rm -rf $(NAME)
		@echo "$(GREEN)Done. $(RESET)"

clean :
		@echo "$(CYAN)Cleaning last build... $(DARK)"
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)Done."

re : fclean all

.PHONY : clean fclean re test
