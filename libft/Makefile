NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

SRC_FT_PUT = ft_putchar.c ft_putchar_fd.c \
 ft_putstr.c ft_putstr_fd.c \
 ft_putendl.c ft_putendl_fd.c \
 ft_putnbr.c ft_putnbr_fd.c

SRC_FT_STR = ft_strlen.c \
 ft_strdup.c \
 ft_strcpy.c ft_strncpy.c \
 ft_strcat.c ft_strncat.c ft_strlcat.c \
 ft_strchr.c ft_strrchr.c \
 ft_strstr.c ft_strnstr.c \
 ft_strcmp.c ft_strncmp.c \
 ft_atoi.c ft_itoa.c \
 ft_toupper.c ft_tolower.c \
 ft_strclr.c \
 ft_strequ.c ft_strnequ.c \

SRC_FT_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

SRC_FT_MEM = ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memccpy.c \
ft_memchr.c \
ft_memmove.c \
ft_memcmp.c \

SRC_FT_MALLOC = ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \

SRC_FT_F = ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c \

SRC_FT_LST = ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \

SRC_FT_ADD = ft_count.c ft_count_words.c ft_count_letters.c ft_is_space.c \

SRCS = $(SRC_FT_PUT) $(SRC_FT_STR) $(SRC_FT_IS) $(SRC_FT_MEM) $(SRC_FT_MALLOC) $(SRC_FT_F) $(SRC_FT_LST) $(SRC_FT_ADD) 

HEADER = -I libft.h

OBJECTS = ft_putchar.o ft_putchar_fd.o \
 ft_putstr.o ft_putstr_fd.o \
 ft_putendl.o ft_putendl_fd.o \
 ft_putnbr.o ft_putnbr_fd.o \
 ft_strlen.o \
 ft_strdup.o \
 ft_strcpy.o ft_strncpy.o \
 ft_strcat.o ft_strncat.o ft_strlcat.o \
 ft_strchr.o ft_strrchr.o \
 ft_strstr.o ft_strnstr.o \
 ft_strcmp.o ft_strncmp.o \
 ft_atoi.o ft_itoa.o \
 ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
 ft_toupper.o ft_tolower.o \
 ft_memset.o ft_bzero.o \
 ft_memcpy.o ft_memccpy.o \
 ft_memchr.o \
 ft_memmove.o \
 ft_memcmp.o \
 ft_memalloc.o ft_memdel.o \
 ft_strnew.o ft_strdel.o \
 ft_strclr.o \
 ft_striter.o ft_striteri.o \
 ft_strmap.o ft_strmapi.o \
 ft_strequ.o ft_strnequ.o \
 ft_strsub.o \
 ft_strjoin.o \
 ft_strtrim.o \
 ft_lstnew.o \
 ft_lstdelone.o ft_lstdel.o \
 ft_lstadd.o \
 ft_lstiter.o \
 ft_lstmap.o \
 ft_strsplit.o \
 ft_count.o ft_count_words.o ft_count_letters.o ft_is_space.o \

$(NAME): 
	@gcc $(FLAGS) $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJECTS) 
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
