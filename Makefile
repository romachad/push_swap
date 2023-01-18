NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_FILES = main check_input check_size error
HEADERS_FILES = push_swap libft
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
HEADERS = $(addprefix $(HEADERS_DIR), $(addsuffix .h, $(HEADERS_FILES)))
SRCS_DIR = srcs/
OBJS_DIR = objs/
HEADERS_DIR = headers/
LIB_DIR = libs/

all:
	make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJS) libs
	$(CC) $(CFLAGS) $(SRCS) libs/libft.a -o $(NAME)

$(HEADERS):
	ln libft/headers/libft.h $(HEADERS_DIR)

libs: $(HEADERS)
	make -C ./libft
	@mkdir -p $(LIB_DIR)
	mv ./libft/libft.a $(LIB_DIR)

clean:
	make clean -C ./libft
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf libs
	rm -rf $(HEADERS_DIR)libft.h
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
