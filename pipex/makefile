NAME = pipex
NAME_BUS = pipex_bonus

CC = cc
RM = @rm -rf
FLAGS = -Wall -Wextra -Werror

FILE_MN = mandatory/pipex.c
FILE_BUS = bonus/pipex_bonus.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c

PATH_SRC = ./src/
PATH_MAN = $(PATH_OBJ_MND)/mandatory/
FILE_SE = ft_split.c parsing.c  utile.c exection.c norm.c

FILE_S = $(FILE_SE) $(FILE_MN)
FILE_SRC = $(addprefix $(PATH_SRC), $(FILE_S))

PATH_OBJ_MND = ./objects_mnd/
OBJCT_FIL_SRC = $(FILE_S:.c=.o)
FILE_OBJ_MND = $(addprefix $(PATH_OBJ_MND), $(OBJCT_FIL_SRC))

PATH_B = $(PATH_OBJ_BUS)/bonus/
FILE_BNS = $(FILE_SE) $(FILE_BUS)
FILE_BN = $(addprefix $(PATH_SRC), $(FILE_BNS))

PATH_GNL = $(PATH_B)/gnl/

PATH_OBJ_BUS = ./objects_bus/
OBJCT_FIL_BUS = $(FILE_BNS:.c=.o)
FILE_OBJ_BUS = $(addprefix $(PATH_OBJ_BUS), $(OBJCT_FIL_BUS))

all : $(NAME)

$(NAME) : $(FILE_OBJ_MND) pipex.h
		$(CC) $(FLAGS) $(FILE_OBJ_MND) -o $(NAME)

$(PATH_OBJ_MND)%.o : $(PATH_SRC)%.c pipex.h
		@mkdir -p $(PATH_OBJ_MND)
		@mkdir -p $(PATH_MAN)
		$(CC) $(FLAGS) -c $< -o $@


bonus : $(NAME_BUS)

$(NAME_BUS) : $(FILE_OBJ_BUS) pipex.h
		$(CC) $(FLAGS) $(FILE_OBJ_BUS) -o $(NAME_BUS)

$(PATH_OBJ_BUS)%.o : $(PATH_SRC)%.c pipex.h
		@mkdir -p $(PATH_OBJ_BUS)
		@mkdir -p $(PATH_B)
		@mkdir -p $(PATH_GNL)
		$(CC) $(FLAGS) -c $< -o $@


clean :
		$(RM) $(PATH_OBJ_BUS) $(PATH_OBJ_MND)

fclean : clean
		$(RM) $(NAME) $(NAME_BUS)
re : fclean all
