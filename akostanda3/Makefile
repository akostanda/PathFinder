NAME = pathfinder

LIB = ./libmx/libmx.a \

FILES_A = libmx.a \

HEADERS = pathfinder.h \

FILES = main \
		mx_allmin_ways \
		mx_allminways_list_creating \
		mx_allminways_matrix \
		mx_arrlen \
		mx_atoi_distance_error \
		mx_atoi_islands_error \
		mx_create_farr_node \
		mx_create_minwaynode \
		mx_create_poinnode \
		mx_count_dbl_words \
		mx_create_intnode \
		mx_create_topnode \
		mx_create_waynode \
		mx_del_intarr \
		mx_del_u \
		mx_del_uararr \
		mx_del_uarr \
		mx_file_to_arr \
		mx_get_int_index \
		mx_isalpha \
		mx_islands_name \
		mx_islands_way_length \
		mx_last_arr_el \
		mx_lines_error_checking \
		mx_lines_error_printing \
		mx_matrix_filling \
		mx_matrix_parsing \
		mx_matrix_width \
		mx_min_ways \
		mx_nonrepeating_matrix \
		mx_parsing_list_creating \
		mx_path_finder \
		mx_pop_front_parsing_list \
		mx_pop_front_tops \
		mx_pop_poinnode \
		mx_printerr \
		mx_push_back_farr \
		mx_push_back_minways \
		mx_push_back_tops \
		mx_push_back_ways \
		mx_sort_parsing_list \
		mx_str_dbl_split \
		mx_tops_error_checking \
		mx_tops_list_creating \
		mx_top_ways \
		mx_ways_list_creating \
		mx_ways_stopper \
		
INC_H = $(addprefix "inc/", $(HEADERS))

FILES_C = $(addsuffix ".c", $(FILES))

SRC_C = $(addprefix "src/", $(FILES_C))

FILES_O = $(addsuffix ".o", $(FILES))

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
		@make -C libmx install
		@cp $(SRC_C) .
		@cp $(INC_H) .
		@cp $(LIB) .
		@clang $(FLAGS) -c $(FILES_C)
		@clang $(FLAGS) $(FILES_O) $(FILES_A) -o $(NAME)
		@mkdir -p obj
		@cp $(FILES_O) obj/
		@rm -rf $(FILES_O)

uninstall: clean
		@make -C libmx  uninstall
		@rm -rf $(NAME)

clean:
		@make -C libmx clean
		@rm -rf $(FILES_C)
		@rm -rf $(FILES_A)
		@rm -rf $(HEADERS)
		@rm -rf obj

reinstall: uninstall install
