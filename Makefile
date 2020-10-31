NAME = ft_nm

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)

INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./ft_lftprintf/includes/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_DIRECTORY = ./ft_lftprintf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

HEADERS_DIRECTORY = ./includes/

HEADERS_LIST =				\
	nm.h					\

HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))


SOURCES_DIRECTORY = ./srcs/nm/

SOURCES_LIST =	main.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)

#$(OBJECTS_DIRECTORY):


$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	mkdir -p $(OBJECTS_DIRECTORY)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(FT_PRINTF):
	@echo "$(CREAT)Creating $(FT_PRINTF) >>>$(EOC)"
	$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	$(MAKE) -sC $(FT_PRINTF_DIRECTORY) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
