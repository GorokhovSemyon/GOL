#include "game_of_life.h"

void gameControl(char command, bool *Pause, bool *Exit, bool *Cursor,
                 int *SPEED_GAME, int *k_x, int *k_y, int **field) {
  switch (command) {
  case PAUSE: {
    if (*Pause == false)
      *Pause = true;
    else
      *Pause = false;
    break;
  }
  case EXIT:
      *Exit = true;
    break;
  default:
    break;
  }
  if (command >= '0' && command <= '9') {
    changeSpeedGame(command, SPEED_GAME);
  }
  cursorControl(command, Cursor, k_x, k_y, field);
}

void cursorControl(char command, bool *Cursor, int *k_x, int *k_y,
                   int **field) {
  switch (command) {
  case CURSOR_SWITCH: {
    if (*Cursor == false) {
      *Cursor = true;
      *k_x = WIDTH / 2;
      *k_y = HEIGHT / 2;
    } else if (*Cursor == true) {
      *Cursor = false;
      *k_x = -1;
      *k_y = -1;
    }
    break;
  }
  case CURSOR_SWITCH_UPPER: {
      if (*Cursor == false) {
          *Cursor = true;
          *k_x = WIDTH / 2;
          *k_y = HEIGHT / 2;
      } else if (*Cursor == true) {
          *Cursor = false;
          *k_x = -1;
          *k_y = -1;
      }
      break;
  }
  case CURSOR_UP: {
    if (*Cursor)
      if (*k_y > 0)
        (*k_y)--;
    break;
  }
  case CURSOR_UP_UPPER: {
      if (*Cursor)
          if (*k_y > 0)
              (*k_y)--;
      break;
  }
  case CURSOR_DOWN: {
    if (*Cursor)
      if (*k_y < HEIGHT - 1)
        (*k_y)++;
    break;
  }
  case CURSOR_DOWN_UPPER: {
      if (*Cursor)
          if (*k_y < HEIGHT - 1)
              (*k_y)++;
      break;
  }
  case CURSOR_LEFT: {
    if (*Cursor)
      if (*k_x > 0)
        (*k_x)--;
    break;
  }
  case CURSOR_LEFT_UPPER: {
      if (*Cursor)
          if (*k_x > 0)
              (*k_x)--;
      break;
  }
  case CURSOR_RIGHT: {
    if (*Cursor)
      if (*k_x < WIDTH - 1)
        (*k_x)++;
    break;
  }
  case CURSOR_RIGHT_UPPER: {
      if (*Cursor)
          if (*k_x < WIDTH - 1)
              (*k_x)++;
      break;
  }
  case ENTER_LIFE: {
    if (*Cursor) {
      field[*k_y][*k_x] = 1;
    }
    break;
  }
  case ENTER_LIFE_UPPER: {
      if (*Cursor) {
          field[*k_y][*k_x] = 1;
      }
      break;
  }
  case DELETE_LIFE: {
      if (*Cursor) {
        field[*k_y][*k_x] = 0;
      }
      break;
  }
  case DELETE_LIFE_UPPER: {
      if (*Cursor) {
          field[*k_y][*k_x] = 0;
      }
      break;
  }
  default:
      break;
  }
}

void changeSpeedGame(char speedMode, int *speedGame) {
  switch (speedMode) {
  case '1':
    *speedGame = 1600000;
    break;
  case '2':
    *speedGame = 800000;
    break;
  case '3':
    *speedGame = 400000;
    break;
  case '4':
    *speedGame = 200000;
    break;
  case '5':
    *speedGame = 100000;
    break;
  case '6':
    *speedGame = 50000;
    break;
  case '7':
    *speedGame = 25000;
    break;
  case '8':
    *speedGame = 6250;
    break;
  case '9':
    *speedGame = 3125;
    break;
  case '0':
    *speedGame = 1561;
    break;
  default:
    *speedGame = 100000;
  }
}

int changeSpeedGameScanf() {
  char speedMode;
  int speedGame;
  scanf("%c", &speedMode);
  changeSpeedGame(speedMode, &speedGame);
  return speedGame;
}

void enterHumanCoordinates(int **a, int n, int m) {
  bool Success = true;
  int x = 0;
  int y = 0;
  bool endOfEnter = false;
  char endOfCoordinates;
  zeroMatrix(a, n, m);
  while (endOfEnter != true && Success != false
    && scanf("%d%d%c", &x, &y, &endOfCoordinates) == 3) {
    Success = true;
    --x;
    --y;
    printw("%d %d\n", x, y);
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    printw("Out of frame\n");
    Success = false;
  }
  if (endOfCoordinates != END_OF_COORDINATES && endOfCoordinates != '.') {
    printw("Bad end of coordinates: '%c'\n", endOfCoordinates);
    Success = false;
  }
  if (Success)
    a[x][y] = 1;
  if (endOfCoordinates == '.')
    endOfEnter = true;
  }
}

int enterFileCoordinates(int **a, int n, int m) {
  char ch;
  int Success = false;
  int element;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (scanf("%d%c", &element, &ch) == 2 && (ch == '\n' || ch == ' ')) {
        a[i][j] = element;
        Success = true;
      } else {
        Success = false;
      }
    }
  return Success;
}

void zeroMatrix(int **a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
}

bool allocate(int ***matrix, int n, int m) {
  bool Success = false;
  *matrix = (int **)malloc(n * m * sizeof(int) + n * sizeof(int *));
  if (*matrix != NULL)
      Success = true;
  int *ptr = (int *)(*matrix + n);
  for (int i = 0; i < n; i++)
    (*matrix)[i] = ptr + m * i;
  return Success;
}

int update(int ***matrix, int n, int m) {
  int **matrix_new;
  allocate(&matrix_new, n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      matrix_new[i][j] = check_life(*matrix, n, m, i, j);
  int changes_check = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (matrix_new[i][j] != (*matrix)[i][j])
        changes_check = 0;
  free(*matrix);
  *matrix = matrix_new;
  return !changes_check;
}

int check_life(int **matrix, int n, int m, int row, int column) {
  int **neighbors;
  allocate(&neighbors, 8, 2);
  int counter = -1;
  bool Success = false;
  for (int i = row - 1; i <= row + 1; i++) {
    for (int j = column - 1; j <= column + 1; j++) {
      if (i != row || j != column) {
        counter++;
        neighbors[counter][0] = i;
        neighbors[counter][1] = j;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    if (neighbors[i][0] < 0)
      neighbors[i][0] += n;
    if (neighbors[i][0] >= n)
      neighbors[i][0] -= n;
    if (neighbors[i][1] >= m)
      neighbors[i][1] -= m;
    if (neighbors[i][1] < 0)
      neighbors[i][1] += m;
  }
  counter = 0;
  for (int i = 0; i < 8; i++)
    counter += matrix[neighbors[i][0]][neighbors[i][1]];
  if (matrix[row][column] && (counter == 2 || counter == 3)) {
    Success = true;
  }
  if (!(matrix[row][column]) && counter == 3) {
    Success = true;
  }
  free(neighbors);
  return Success;
}

int countAlive(int **matrix, int n, int m) {
  int result = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      result += matrix[i][j];
  return result;
}

void printwField(int **A, int N, int M, int k_x, int k_y) {
  for (int x = 0; x <= WIDTH + 1; x++) {
    printw("%c", SYMBOL_BORT);
    if (x == WIDTH + 1)
      printw("\n");
  }
  for (int y = 0; y < N; y++) {
    printw("%c", SYMBOL_BORT_SIDE);
    for (int x = 0; x < M; x++) {
      if (A[y][x] != 1 && x == k_x && y == k_y)
        printw("%c", SYMBOL_K_DEATH);
      else if (A[y][x] == 1 && x == k_x && y == k_y)
        printw("%c", SYMBOL_K_LIVE);
      else if (A[y][x] == 1)
        printw("%c", SYMBOL_LIVE);
      else if (A[y][x] == 0)
        printw("%c", SYMBOL_DEATH);
    }
    printw("%c", SYMBOL_BORT_SIDE);
    if (y < M - 1)
      printw("\n");
  }
  for (int x = 0; x <= WIDTH + 1; x++) {
    printw("%c", SYMBOL_BORT);
    if (x == WIDTH + 1)
      printw("\n");
  }
}

void printfField(int **A, int N, int M) {
  for (int x = 0; x <= WIDTH + 1; x++) {
    printf("%c", SYMBOL_BORT);
    if (x == WIDTH + 1)
      printf("\n");
  }
  for (int y = 0; y < N; y++) {
    printf("%c", SYMBOL_BORT_SIDE);
    for (int x = 0; x < M; x++) {
      if (A[y][x] != 1) {
        printf("%c", SYMBOL_DEATH);
      } else {
        printf("%c", SYMBOL_LIVE);
      }
    }
    printf("%c", SYMBOL_BORT_SIDE);
    if (y < M - 1)
      printf("\n");
  }
  for (int x = 0; x <= WIDTH + 1; x++) {
    printf("%c", SYMBOL_BORT);
    if (x == WIDTH + 1)
      printf("\n");
  }
}

char* scan() {
    int c;
    char* string = malloc(sizeof(char));
    string[0]='\0';
    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++) {
        string = realloc(string, (i+2)*sizeof(char));
        string[i] = (char) c;
        string[i+1] = '\0';
    }
    return string;
}

char *fileToStr(char *path) {
    int size = 100;
    char *string = malloc(size * sizeof(char));
    FILE *file = fopen(path, "r");
    if (file != NULL) {
        char ch = '0';
        int cnt = 0;
        while (ch != EOF) {
            ch = fgetc(file);
            if (ch != EOF) {
                if (cnt >= size) {
                    string = realloc(string, cnt * 2);
                    size *= 2;
                }
                string[cnt] = ch;
                cnt++;
            }
        }
        fclose(file);
    } else {
        printf("Error with file's path\n");
        free(string);
        string = NULL;
    }
    return string;
}

int isIntNumber(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int charToInt(char ch) {
    return ch - 48;
}

void stringToMatrix(char *str, int **matrix) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(str[i] != '\0') {
        if (isIntNumber(str[i])) {
            matrix[j][k] = charToInt(str[i]);
            k++;
        } else if (str[i] == '\n') {
            j++;
            k = 0;
        }
        i++;
    }
}

bool inputCoordinatesFromFile(int **a, int n, int m) {
    bool success;
    char *file = scan();
    char *drawing = fileToStr(file);
    if (drawing != NULL) {
        free(file);
        stringToMatrix(drawing, a);
        free(drawing);
        success = true;
    } else
        success = false;
    return success;
}

void clean_stdin() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
