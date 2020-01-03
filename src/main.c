#include "../inc/pathfinder.h"

int main(int argc, char **argv) {

    if (argc == 2) {
        mx_path_finder(argv[1]);
    }
    else {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    
    system("leaks -q pathfinder");
    return 0;
}
