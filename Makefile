NAME = pathfinder

LIB = ./libmx/libmx.a \

SRC = src/mx_allmin_ways.c \
		src/mx_allminways_list_creating.c \
		src/mx_allminways_matrix.c \
		src/mx_arrlen.c \
		src/mx_atoi.c \
		src/mx_create_minwaynode.c \
		src/mx_create_poinnode.c \
		src/mx_count_dbl_words.c \
		src/mx_create_intnode.c \
		src/mx_create_topnode.c \
		src/mx_create_waynode.c \
		src/mx_del_intarr.c \
		src/mx_del_lu.c \
		src/mx_del_luararr.c \
		src/mx_del_luarr.c \
		src/mx_file_to_arr.c \
		src/mx_islands_name.c \
		src/mx_islands_way_length.c \
		src/mx_last_arr_el.c \
		src/mx_luarr_reverse.c \
		src/mx_matrix_filling.c \
		src/mx_matrix_parsing.c \
		src/mx_matrix_width.c \
		src/mx_min_ways.c \
		src/mx_nonrepeating_matrix.c \
		src/mx_pop_front_tops.c \
		src/mx_pop_poinnode.c \
		src/mx_push_back_minways.c \
		src/mx_push_back_tops.c \
		src/mx_push_back_ways.c \
		src/mx_push_filter.c \
		src/mx_str_dbl_split.c \
		src/mx_swap_lu.c \
		src/mx_tops_list_creating.c \
		src/mx_top_ways.c \
		src/mx_ways_list_creating.c \
		src/mx_ways_stopper.c \


OBJ = mx_allmin_ways.o \
		mx_allminways_list_creating.o \
		mx_allminways_matrix.o \
		mx_arrlen.o \
		mx_atoi.o \
		mx_create_minwaynode.o \
		mx_create_poinnode.o \
		mx_count_dbl_words.o \
		mx_create_intnode.o \
		mx_create_topnode.o \
		mx_create_waynode.o \
		mx_del_intarr.o \
		mx_del_lu.o \
		mx_del_luararr.o \
		mx_del_luarr.o \
		mx_file_to_arr.o \
		mx_islands_name.o \
		mx_islands_way_length.o \
		mx_last_arr_el.o \
		mx_luarr_reverse.o \
		mx_matrix_filling.o \
		mx_matrix_parsing.o \
		mx_matrix_width.o \
		mx_min_ways.o \
		mx_nonrepeating_matrix.o \
		mx_pop_front_tops.o \
		mx_pop_poinnode.o \
		mx_push_back_minways.o \
		mx_push_back_tops.o \
		mx_push_back_ways.o \
		mx_push_filter.o \
		mx_str_dbl_split.o \
		mx_swap_lu.o \
		mx_tops_list_creating.o \
		mx_top_ways.o \
		mx_ways_list_creating.o \
		mx_ways_stopper.o \
		

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
