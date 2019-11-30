NAME = pathfinder

LIB = ./libmx/libmx.a \

SRC = src/mx_parting.c \
		src/mx_create_topnode.c \
		src/mx_atoi.c \

OBJ = mx_parting.o \
		mx_create_topnode.o \
		mx_atoi.o \
		

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
