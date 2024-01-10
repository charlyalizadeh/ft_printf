NAME=libftprintf.a
SRCS= srcs/check_specifier.c  srcs/format_dec.c      srcs/format_specifier.c  srcs/precision.c \
	  srcs/flags.c            srcs/format_int.c      srcs/format_str.c        srcs/width.c \
	  srcs/format_char.c      srcs/format_pointer.c  srcs/ft_printf.c
OBJS=$(subst srcs,objs,$(subst .c,.o,$(SRCS)))
INCLUDES=includes
FLAGS=-Wall -Wextra -Werror
CC=cc

$(NAME): $(OBJS)
	cp lib/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS): objs/%.o: srcs/%.c
	$(CC) -c $< -o $@ $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

build:
	mkdir -p objs/
