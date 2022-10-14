NAME= cub3d

AR= ar rc
RM= rm -rf

CC= clang
CFLAGS= -Wall -Werror -Wextra -Ilibft -g3 -c
MFLAGS=  -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -framework OpenGL -framework AppKit
INC=	config.h

ODIR= obj

SRCS= init.c main.c parse.c parse_graphics.c parse_map.c to_rgb.c utils.c valid_edges.c \
	valid_inners.c valid_map.c parse_state.c game_handle.c draw.c draw2.c raycast.c raycast2.c \
	key_handler.c

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 

$(ODIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -Imlx $< -o $@

$(NAME): $(ODIR) $(OFIX)
	$(MAKE) -C ./libft
	$(CC) $(OFIX) $(MFLAGS) -lft -L./libft -o $(NAME)

all:	$(NAME)

$(ODIR):
		mkdir -p $(ODIR)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft
	
re:	clean all

.PHONY: all clean flcean re
