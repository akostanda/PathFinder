#include "../inc/pathfinder.h"

static void minways_filter(t_minways **list,
                                unsigned int **minwaymat, const int width) {
    t_minways *pl = *list;
    int count = 0;

    while (pl != NULL) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < width; j++) {
                if (pl->minwaymat[i][j] != minwaymat[i][j])
                    count++;
            }
        }
        if (count == 0)
            return;
        count = 0;
        pl = pl->next;
    }
    mx_push_back_minways(list, minwaymat, width);
}

void mx_push_filter(t_minways **list,
                                unsigned int **minwaymat, const int width) {
    t_minways *pl = *list;

    if (pl == NULL) {
        mx_push_back_minways(list, minwaymat, width);
        return;
    }
    minways_filter(list, minwaymat, width);
}
