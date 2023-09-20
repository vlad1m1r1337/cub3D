NAME=cube3D

SRCDIR = src/
OBJDIR = obj/

SRCS = $(wildcard $(SRCDIR)*/*.c) $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread  -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror -g
LIBS =  -lmlx -framework OpenGL -framework AppKit

GREEN = \033[0;32m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "${GREEN}>>> RDY <<<${RESET}"

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
