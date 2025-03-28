#include <stdio.h>
#include <stdlib.h>


int find(int row, int column, char *matrix, int row_g, int column_g) {
    int num_bomb = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            
            int n_i = row_g + i;
            int n_j = column_g + j;
            
            if (n_i >= 0 && n_i < row && n_j >= 0 && n_j < column) {
                if ((matrix[n_i * column + n_j]) == 'X') {
                    num_bomb++;
                }
            }
        }
    }
    return num_bomb;
}

int main() {
  int row, column;
    
  scanf("%d %d", &column, &row);
    
  int size = row * column;
    
  char *matrix = (char*) malloc(size * sizeof(char));

  int i = 0;

  while (i < size) {
      char ch;
      scanf(" %c", &ch);
      if (ch == 'X' || ch == 'O') {
          matrix[i++] = ch;
      } else continue;
  }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < column; c++) {
            printf("%c", matrix[r * column + c]);
        }
        printf("\n");
    }
        
  int row_g, column_g;

  while (scanf("%d %d", &column_g, &row_g) == 2) {
    if (row_g >= 0 && row_g < row && column_g >= 0 && column_g < column) {
        char cell = matrix[row_g * column + column_g];
      if (cell == 'X') {
        printf("Bomb!\n");
      } else {
        int bomb = find(row, column, matrix, row_g, column_g);
        printf("%d bombs\n", bomb);
	}
    }
  }

  free(matrix);
  return 0;
}
