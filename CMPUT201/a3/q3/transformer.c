#include <stdio.h>
#include <string.h>

void read_image(int height, int width, int image[height][width][3]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d %d %d", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }
}

void f_image(int height, int width, int image[height][width][3]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int c = 0; c < 3; c++) {
                int tmp = image[i][j][c];
                image[i][j][c] = image[i][width - 1 - j][c];
                image[i][width - 1 - j][c] = tmp;
            }
        }
    }
}

void s_image(int height, int width, int image[height][width][3]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = image[i][j][0];
            int g = image[i][j][1];
            int b = image[i][j][2];

            int new_r = r * 393 / 1000 + g * 769 / 1000 + b * 189 / 1000;
            int new_g = r * 349 / 1000 + g * 686 / 1000 + b * 168 / 1000;
            int new_b = r * 272 / 1000 + g * 534 / 1000 + b * 131 / 1000;

            if (new_r > 255) new_r = 255;
            if (new_g > 255) new_g = 255;
            if (new_b > 255) new_b = 255;

            image[i][j][0] = new_r;
            image[i][j][1] = new_g;
            image[i][j][2] = new_b;
        }
    }
}

void print_image(int height, int width, int image[height][width][3]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d %d %d", image[i][j][0], image[i][j][1], image[i][j][2]);
            if (j < width - 1) printf(" ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int fun_f = 0;
    int fun_s = 0;
    
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            fun_f = 1;
        }
        if (strcmp(argv[i], "-f") == 0) {
            fun_s = 1;
        }
    }

    char size[3];
    int width, height, max;

    scanf("%s", size);
    scanf("%d %d", &width, &height);
    scanf("%d", &max);

    int image[height][width][3];
    read_image(height, width, image);

    if (fun_f) {
        f_image(height, width, image);
    }
    if (fun_s) {
        s_image(height, width, image);
    }
    
    printf("P3\n");
    printf("%d %d\n", width, height);
    printf("%d\n", max);
    print_image(height, width, image);

    return 0;
}