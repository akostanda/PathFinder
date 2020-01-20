#include "../inc/libmx.h"

// static void quicksort_condition(char **arr, int left, int right) {
//     int pivot = (right - left) / 2 + left;
//     int i;
//     int j;
//     int count = 0;
//     int newL = left;
//     int newR = right;

//     // while (newL <= newR) {
//         for (i = left; i <= right; i++) {
//             if (mx_strlen(arr[i]) > mx_strlen(arr[pivot]) || i == pivot) {
//                 newL = i;
//                 break;
//             }
//         }
//         for (j = right; j >= left; j--) {
//             if (mx_strlen(arr[j]) < mx_strlen(arr[pivot]) || j == pivot) {
//                 newR = j;
//                 break;
//             }
//         }
//         if (i == pivot && newR != pivot) {
//             newL = i;
//             pivot = newR;
//         }
//         else if (j == pivot && newL != pivot) {
//             newR = j;
//             pivot = newL;
//         }
//         if (newL != newR) {
//             mx_swap_str(&arr[newL], &arr[newR]);
//             count++;
//         }
//     //     newL++;
//     //     newR--;
//     // }
//     // newL = pivot + 1;
//     // newR = pivot - 1;
//     // if (left < newR)
//     //     count = count + mx_quicksort(arr, left, newR);
//     // if (newL < right)
//     //     count = count + mx_quicksort(arr, newL, right);
//     // return count;
// }

int mx_quicksort(char **arr, int left, int right) {
    int pivot = (right - left) / 2 + left;
    int i;
    int j;
    int count = 0;
    int newL = left;
    int newR = right;

    while (newL <= newR) {
        for (i = left; i <= right; i++) {
            if (mx_strlen(arr[i]) > mx_strlen(arr[pivot]) || i == pivot) {
                newL = i;
                break;
            }
        }
        for (j = right; j >= left; j--) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[pivot]) || j == pivot) {
                newR = j;
                break;
            }
        }
        if (i == pivot && newR != pivot) {
            newL = i;
            pivot = newR;
        }
        else if (j == pivot && newL != pivot) {
            newR = j;
            pivot = newL;
        }
        if (newL != newR) {
            mx_swap_str(&arr[newL], &arr[newR]);
            count++;
        }
        newL++;
        newR--;
    }
    newL = pivot + 1;
    newR = pivot - 1;
    if (left < newR)
        count = count + mx_quicksort(arr, left, newR);
    if (newL < right)
        count = count + mx_quicksort(arr, newL, right);
    return count;
}

int main() {
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
printf("%i\n",  mx_quicksort(arr, 0, 3));

    for (int k = 0; k < 4; k++) {

        printf("%s\n", arr[k]);

    }

    return 0;
}
// int main() {
//     char *arr[] =  {"666666", "333", "999999999", "1", "88888888", "4444", "55555", "7777777", "22"};

//     printf("%i\n",mx_quicksort(arr, 0, 8));
//     for (int k = 0; k < 9; k++) {
//         printf("%s ", arr[k]);
//     }
// return 0;
// }

