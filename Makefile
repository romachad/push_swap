NAME = push_swap
NAME_B = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMMON_FILES = check_input check_size error common_utils is_sorted fake_push fake_rotate fake_reverse_rotate fake_swap
SRCS_FILES = main push swap rotate reverse_rotate sort_3 mid_number push_30pct sort_5 from_b_to_a utils fake_b_to_a simulation
BONUS_FILES = main reader get_next_line
HEADERS_FILES = push_swap libft
COMMON = $(addprefix $(C_DIR), $(addsuffix .c, $(COMMON_FILES)))
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
OBJS_C = $(addprefix $(OBJS_C_DIR), $(addsuffix .o, $(COMMON_FILES)))
OBJS_B = $(addprefix $(OBJS_B_DIR), $(addsuffix .o, $(BONUS_FILES)))
BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
HEADERS = $(addprefix $(HEADERS_DIR), $(addsuffix .h, $(HEADERS_FILES)))
C_DIR = common_src/
SRCS_DIR = srcs/
BONUS_DIR = bonus/
OBJS_DIR = objs/
OBJS_C_DIR = objs_common/
OBJS_B_DIR = objs_bonus/
HEADERS_DIR = headers/
LIB_DIR = libs/

all:
	make $(NAME)
	make $(NAME_B)

bonus: $(HEADERS) $(OBJS_C) $(OBJS_B) libs
	make $(NAME_B)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_C_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(OBJS_C_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_B_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(OBJS_B_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJS) $(OBJS_C) libs
	$(CC) $(CFLAGS) $(COMMON) $(SRCS) libs/libftprintf.a libs/libft.a -o $(NAME)

$(NAME_B): $(HEADERS) $(OBJS_C) $(OBJS_B) libs
	$(CC) $(CFLAGS) $(COMMON) $(BONUS) libs/libft.a -o $(NAME_B)

$(HEADERS):
	ln libft/headers/libft.h $(HEADERS_DIR)
	ln printf/srcs/ft_printf.h $(HEADERS_DIR)

libs: $(HEADERS)
	make -C ./libft
	@mkdir -p $(LIB_DIR)
	mv ./libft/libft.a $(LIB_DIR)
	make -C ./printf
	mv ./printf/libftprintf.a $(LIB_DIR)

clean:
	make clean -C ./libft
	make clean -C ./printf
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_C_DIR)
	rm -rf $(OBJS_B_DIR)

fclean: clean
	rm -rf libs
	rm -rf $(HEADERS_DIR)libft.h
	rm -rf $(HEADERS_DIR)ft_printf.h
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
