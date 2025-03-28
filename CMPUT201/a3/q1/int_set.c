#include <stdio.h>
#include <stdlib.h>

int x[1000], x_size = 0;
int y[1000], y_size = 0;

// check function
int check(int arr[], int *size, int val) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == val) {
            return 1;
            }
    }
    return 0;
}

// add function
void add(int arr[], int *size, int val) {
    if (!check(arr, size, val)) {
            arr[*size] = val;
            (*size)++;
    }
}

// remove function
void removen(int arr[], int *size, int val) {
    for (int i = 0; i < *size; i++) {
            if (arr[i] == val) {
                for (int j = i; j < *size - 1; j++) {
                    arr[j] = arr[j+1];
                }
                (*size)--;
                return;
        }
    }
}
// print sort
void print_p(int arr[], int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_u() {
    int tep[1000], tmp_size = 0;
        for (int i = 0; i < x_size; i++) {
            add(tep, &tmp_size, x[i]);
        }
        for (int i = 0; i < y_size; i++) {
            add(tep, &tmp_size, y[i]);
        }
        print_p(tep, tmp_size);
}

void print_i() {
    int tmp[1000], tmp_size = 0;
    for (int i = 0; i < x_size; i++) {
        if (check(y, &y_size, x[i])) {
            add(tmp, &tmp_size, x[i]);
        }
    }
    print_p(tmp, tmp_size);
}

int main() {
    char sign, targ;
    int num;

    
    while (scanf(" %c", &sign) != EOF) {
        if (sign == 'a') {
            scanf(" %c %d", &targ, &num);
            if (targ == 'x') {
                add(x, &x_size, num);
            }
            if (targ == 'y') {
                add(y, &y_size, num);
            }
        }
        if (sign == 'r') {
            scanf(" %c %d", &targ, &num);
            if (targ == 'x') {
                removen(x, &x_size, num);
            }
            if (targ == 'y') {
                removen(y, &y_size, num);
            }
        }
            if (sign == 'p') {
            scanf(" %c", &targ);
            if (targ == 'x') {
                print_p(x, x_size);
            }
            if (targ == 'y') {
                print_p(y, y_size);
            }
        }
        if (sign == 'u') {
            print_u();
        }
        if (sign == 'i') {
            print_i();
        }
        if (sign == 'q') break;
    }
    return 0;
}
