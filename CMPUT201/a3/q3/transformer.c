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
            int R = image[i][j][0];
            int G = image[i][j][1];
            int B = image[i][j][2];

            float r = (float)R;
            float g = (float)G;
            float b = (float)B;

            int newR = (int)(r * 0.393f + g * 0.769f + b * 0.189f);
            int newG = (int)(r * 0.349f + g * 0.686f + b * 0.168f);
            int newB = (int)(r * 0.272f + g * 0.534f + b * 0.131f);

            if (newR > 255) newR = 255;
            if (newG > 255) newG = 255;
            if (newB > 255) newB = 255;

            image[i][j][0] = newR;
            image[i][j][1] = newG;
            image[i][j][2] = newB;
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
        if (strcmp(argv[i], "-s") == 0) {
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