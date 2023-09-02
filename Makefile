NAME = cube3D

SRCDIR = src/
OBJDIR = obj/

SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread  -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -g
LIBS =  -lmlx -framework OpenGL -framework AppKit

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -c $< -o $@

$(OBJDIR):
	@$(shell mkdir -p $(dir $(OBJS)))

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "${GREEN}>>> RDY <<<${RESET}"

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re