NAME = pathfinder

LIB = ./libmx/libmx.a \

SRC = src/mx_atoi.c \
		src/mx_count_dbl_words.c \
		src/mx_create_topnode.c \
		src/mx_create_waynode.c \
		src/mx_file_to_arr.c \
		src/mx_matrix_filling.c \
		src/mx_parting.c \
		src/mx_push_back_tops.c \
		src/mx_push_back_ways.c \
		src/mx_str_dbl_split.c \
		src/mx_allmin_ways.c \

OBJ = mx_atoi.o \
		mx_count_dbl_words.o \
		mx_create_topnode.o \
		mx_create_waynode.o \
		mx_file_to_arr.o \
		mx_matrix_filling.o \
		mx_parting.o \
		mx_push_back_tops.o \
		mx_push_back_ways.o \
		mx_str_dbl_split.o \
		mx_allmin_ways.o \

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
		@cd libmx && make install
		@clang $(FLAGS) -c $(SRC)
		@mkdir -p obj
		@cp $(OBJ) obj/.
		@ar -rc $(NAME) $(OBJ)
		@rm -rf $(OBJ)

uninstall: clean
		@cd libmx && make uninstall
		@rm -rf $(NAME)

clean:
		@cd libmx && make clean
		@rm -rf obj

reinstall: all
