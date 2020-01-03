NAME = pathfinder

LIB = ./libmx/libmx.a \

SRC = src/main.c \
		src/mx_allmin_ways.c \
		src/mx_allminways_list_creating.c \
		src/mx_allminways_matrix.c \
		src/mx_arrlen.c \
		src/mx_atoi.c \
		src/mx_atoi_error.c \
		src/mx_create_minwaynode.c \
		src/mx_create_poinnode.c \
		src/mx_count_dbl_words.c \
		src/mx_create_intnode.c \
		src/mx_create_topnode.c \
		src/mx_create_waynode.c \
		src/mx_del_intarr.c \
		src/mx_del_u.c \
		src/mx_del_uararr.c \
		src/mx_del_uarr.c \
		src/mx_file_to_arr.c \
		src/mx_islands_name.c \
		src/mx_islands_way_length.c \
		src/mx_last_arr_el.c \
		src/mx_matrix_filling.c \
		src/mx_matrix_parsing.c \
		src/mx_matrix_width.c \
		src/mx_min_ways.c \
		src/mx_nonrepeating_matrix.c \
		src/mx_path_finder.c \
		src/mx_pop_front_tops.c \
		src/mx_pop_poinnode.c \
		src/mx_printerr.c \
		src/mx_push_back_minways.c \
		src/mx_push_back_tops.c \
		src/mx_push_back_ways.c \
		src/mx_push_filter.c \
		src/mx_str_dbl_split.c \
		src/mx_swap_u.c \
		src/mx_tops_list_creating.c \
		src/mx_top_ways.c \
		src/mx_uarr_reverse.c \
		src/mx_ways_list_creating.c \
		src/mx_ways_stopper.c \


OBJ = main.o \
		mx_allmin_ways.o \
		mx_allminways_list_creating.o \
		mx_allminways_matrix.o \
		mx_arrlen.o \
		mx_atoi.o \
		mx_atoi_error.o \
		mx_create_minwaynode.o \
		mx_create_poinnode.o \
		mx_count_dbl_words.o \
		mx_create_intnode.o \
		mx_create_topnode.o \
		mx_create_waynode.o \
		mx_del_intarr.o \
		mx_del_u.o \
		mx_del_uararr.o \
		mx_del_uarr.o \
		mx_file_to_arr.o \
		mx_islands_name.o \
		mx_islands_way_length.o \
		mx_last_arr_el.o \
		mx_matrix_filling.o \
		mx_matrix_parsing.o \
		mx_matrix_width.o \
		mx_min_ways.o \
		mx_nonrepeating_matrix.o \
		mx_path_finder.o \
		mx_pop_front_tops.o \
		mx_pop_poinnode.o \
		mx_printerr.o \
		mx_push_back_minways.o \
		mx_push_back_tops.o \
		mx_push_back_ways.o \
		mx_push_filter.o \
		mx_str_dbl_split.o \
		mx_swap_u.o \
		mx_tops_list_creating.o \
		mx_top_ways.o \
		mx_uarr_reverse.o \
		mx_ways_list_creating.o \
		mx_ways_stopper.o \
		

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
		@make -C libmx install
		@clang $(FLAGS) -c $(SRC)
		@mkdir -p obj
		@cp $(OBJ) obj/.
		@clang $(FLAGS) -o $(NAME) $(OBJ) ./libmx/libmx.a
		@rm -rf $(OBJ)

uninstall: clean
		@make -C libmx  uninstall
		@rm -rf $(NAME)

clean:
		@make -C libmx clean
		@rm -rf obj

reinstall: all
