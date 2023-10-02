NAME = cub3D
SRCDIR = src/
OBJDIR = obj/

SRCBDIR = srcb/
OBJBDIR = objb/

MLX_DIR = ./mlx
MLX  = $(MLX_DIR)/libmlx.a

SRCS = $(wildcard $(SRCDIR)*/*.c) $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

SRCSB = $(wildcard $(SRCBDIR)*/*.c) $(wildcard $(SRCBDIR)*.c)
OBJSB = $(patsubst $(SRCBDIR)%.c, $(OBJBDIR)%.o, $(SRCSB))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS =  -lmlx -framework OpenGL -framework AppKit -L$(MLX_DIR)

GREEN = \033[0;32m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "${GREEN}>>> RDY <<<${RESET}"

$(MLX):
	@make -sC $(MLX_DIR)

bonus:
	@make OBJS="$(OBJSB)" SRCDIR="$(SRCBDIR)" OBJDIR="$(OBJBDIR)" all

clean:
	@rm -rf $(OBJBDIR)
	@rm -rf $(OBJDIR)
	@$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(MLX)

re: fclean all

rb: fclean bonus

.PHONY: all clean fclean re bonus
