NAME	=	libft.a

AR= ar rc
CC= gcc
CFLAGS= -Wall -Werror -Wextra -c -g
RLIB=	ranlib
RM= rm -rf

INC= libft.h get_next_line.h

ODIR= libobjects

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
		get_next_line_utils.c abs.c free_tab.c \


OBJS= $(SRCS:.c=.o)

OFIX= $(addprefix $(ODIR)/, $(OBJS)) 	


all: $(NAME)

$(NAME): $(ODIR) $(OFIX)
		$(AR) $(NAME) $(OFIX)
		$(RLIB) $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OFIX) $(ODIR)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re
