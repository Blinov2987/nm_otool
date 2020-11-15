FT_NM_NAME = ft_nm
FT_OTOOL_NAME = ft_otool

CC = gcc
FLAGS = -Wall -Wextra -Werror

FT_OTOOL_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
FT_NM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)

FT_OTOOL_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

FT_NM_INCLUDES = \
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

FT_NM_HEADERS_LIST =		\
	args.h					\
	constants.h				\
	errors.h				\
	file_info.h				\
	headers.h				\
	nm.h					\

FT_NM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(FT_NM_HEADERS_LIST))

FT_OTOOL_HEADERS_LIST =		\
	args.h					\
    constants.h				\
    errors.h				\
    file_info.h				\
    headers.h				\
    nm.h					\

FT_OTOOL_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(FT_OTOOL_HEADERS_LIST))

FT_NM_SOURCES_DIRECTORY = ./srcs/nm-otool/

FT_NM_SOURCES_LIST =	\
	args_finder.c		\
	args_helper_00.c	\
	errors_00.c			\
	errors_01.c			\
	free_utils.c		\
	nm_main.c			\
	print_otool_output.c\
	print_output_00.c	\
	print_output_01.c	\
	sorters.c			\
	taste_magic.c		\
	walker_32_00.c		\
	walker_32_01.c		\
	walker_64_00.c		\
	walker_64_01.c		\
	walker_fat_00.c		\
	walker_fat_01.c		\
	walker_fat_64_00.c		

FT_NM_SOURCES = $(addprefix $(FT_NM_SOURCES_DIRECTORY), $(FT_NM_SOURCES_LIST))

FT_OTOOL_SOURCES_DIRECTORY = ./srcs/nm-otool/

FT_OTOOL_SOURCES_LIST =	\
	args_finder.c		\
	args_helper_00.c	\
	errors_00.c			\
	errors_01.c			\
	free_utils.c		\
	otool_main.c		\
	print_otool_output.c\
	print_output_00.c	\
	print_output_01.c	\
	sorters.c			\
	taste_magic.c		\
	walker_32_00.c		\
	walker_32_01.c		\
	walker_64_00.c		\
	walker_64_01.c		\
	walker_fat_00.c		\
	walker_fat_01.c		\
	walker_fat_64_00.c		

FT_OTOOL_SOURCES = $(addprefix $(FT_OTOOL_SOURCES_DIRECTORY), $(FT_OTOOL_SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/

FT_NM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)FT_NM/
FT_NM_OBJECTS_LIST = $(patsubst %.c, %.o, $(FT_NM_SOURCES_LIST))
FT_NM_OBJECTS	= $(addprefix $(FT_NM_OBJECTS_DIRECTORY), $(FT_NM_OBJECTS_LIST))

FT_OTOOL_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)FT_OTOOL/
FT_OTOOL_OBJECTS_LIST = $(patsubst %.c, %.o, $(FT_OTOOL_SOURCES_LIST))
FT_OTOOL_OBJECTS	= $(addprefix $(FT_OTOOL_OBJECTS_DIRECTORY), $(FT_OTOOL_OBJECTS_LIST))

.PHONY: all clean fclean re

CREAT = \033[0;32m
IMPORTANT =\033[1;36m
DELETE = \033[0;31m
EOC = \033[0m

all: $(FT_NM_NAME) $(FT_OTOOL_NAME)

$(FT_NM_NAME): $(FT_PRINTF) $(FT_NM_OBJECTS_DIRECTORY) $(FT_NM_OBJECTS)
	@$(CC) $(FLAGS) $(FT_NM_INCLUDES) $(FT_NM_OBJECTS) -o $(FT_NM_NAME) $(FT_NM_LIBRARIES)
	@echo "$(CREAT)objects were created! >>>$(EOC)"
	@echo "$(IMPORTANT)FT_NM was created! >>>$(EOC)"

$(FT_OTOOL_NAME): $(FT_PRINTF) $(FT_OTOOL_OBJECTS_DIRECTORY) $(FT_OTOOL_OBJECTS)
	@$(CC) $(FLAGS) $(FT_OTOOL_INCLUDES) $(FT_OTOOL_OBJECTS) -o $(FT_OTOOL_NAME) $(FT_OTOOL_LIBRARIES)
	@echo "$(CREAT)objects were created! >>>$(EOC)"
	@echo "$(IMPORTANT)FT_OTOOL was created! >>>$(EOC)"

$(FT_NM_OBJECTS_DIRECTORY):
	@mkdir -p $(FT_NM_OBJECTS_DIRECTORY)
	@echo "$(CREAT)$(FT_NM_OBJECTS_DIRECTORY) was created! >>>$(EOC)"

$(FT_NM_OBJECTS_DIRECTORY)%.o : $(FT_NM_SOURCES_DIRECTORY)%.c $(FT_NM_HEADERS)
	@$(CC) $(FLAGS) -c $(FT_NM_INCLUDES) $< -o $@
	@echo "$(CREAT)>.. please wait ... objects creating..>>$(EOC)"

$(FT_OTOOL_OBJECTS_DIRECTORY):
	@mkdir -p $(FT_OTOOL_OBJECTS_DIRECTORY)
	@echo "$(CREAT)$(FT_OTOOL_OBJECTS_DIRECTORY) was created! >>>$(EOC)"

$(FT_OTOOL_OBJECTS_DIRECTORY)%.o : $(FT_OTOOL_SOURCES_DIRECTORY)%.c $(FT_OTOOL_HEADERS)
	@$(CC) $(FLAGS) -c $(FT_OTOOL_INCLUDES) $< -o $@
	@echo "$(CREAT)>.. please wait ... objects creating..>>$(EOC)"

$(FT_PRINTF):
	@echo "$(CREAT)Creating $(FT_PRINTF) >>>$(EOC)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(DELETE)>>> $(OBJECTS_DIRECTORY) was deleted ..............   >>>$(EOC)"
	@echo "$(DELETE)>>> object files were deleted ............. >>>$(EOC)"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) fclean
	@echo "$(DELETE)>>> $(FT_PRINTF) was deleted >>$(EOC)"
	@rm -f $(FT_NM_NAME)
	@rm -f $(FT_OTOOL_NAME)
	@echo "$(DELETE)>>> $(FT_NM_NAME) was deleted ................    >>>$(EOC)"
	@echo "$(DELETE)>>> $(FT_OTOOL_NAME) was deleted ................    >>>$(EOC)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
