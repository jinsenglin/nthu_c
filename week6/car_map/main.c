#include <stdio.h>
#define MAP_SIZE 12
#define CAR_SIZE 3
/* #define ONLINE_JUDGE */

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);

void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];
void blocks_read(void);
void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];
void jewels_read(void);
void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'O', 'O', '@'}, {'O', 'O', 'O'}, {'O', 'O', '@'}};
int car_row = 3, car_col = 4;
int car_direction;
int car_earnings;
void car_rotate90(void);
void car_put_on_map(void);
void car_move(void);

int main(void)
{
    int ch;

    blocks_read();

    jewels_read();

#ifndef ONLINE_JUDGE
    freopen("actions.txt", "r", stdin);
#endif

    while ((ch=getchar()) != EOF) {

        if (ch=='R') {

            car_rotate90();
        }

        if (ch=='F') {

            car_move();
        }

        map_reset();

        blocks_put_on_map();

        jewels_put_on_map();

        car_put_on_map();

#ifndef ONLINE_JUDGE
        map_show();
#endif
    }


    printf("Earnings: %d\n", car_earnings);

    printf("Position: row=%d, col=%d\n", car_row, car_col);

    char dirs[] = "RDLU";

    printf("Direction: %c\n", dirs[car_direction]);


    return 0;
}
void blocks_read(void)
{
    int n, i;
    int row, col;
#ifndef ONLINE_JUDGE
    freopen("blocks.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        blocks[row][col] = 1;
    }
}
void jewels_read(void)
{
    int n, i;
    int row, col;
#ifndef ONLINE_JUDGE
    freopen("jewels.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        jewels[row][col] = 1;
    }
}
void blocks_put_on_map(void)
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            if (blocks[i][j])

                map[i][j] = '#';
        }
    }
}
void jewels_put_on_map()
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            if (jewels[i][j])

                map[i][j] = '$';
        }
    }
}
void map_reset(void)
{
    int i, j;
    
    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            map[i][j] = '.';
        }
    }
    //橫向
    for (i=0; i<MAP_SIZE; i++) {

        map[i][0] = 'H';

        map[i][MAP_SIZE-1] = 'H';
    }
    //橫向
    for (j=0; j<MAP_SIZE; j++) {

        map[0][j] = 'H';

        map[MAP_SIZE-1][j] = 'H';
    }
}

void map_show(void)
{
    int i, j;

    for (i=0; i<MAP_SIZE; i++) {

        for (j=0; j<MAP_SIZE; j++) {

            printf("%c", map[i][j]);

        }
        printf("\n");
    }

}
void car_put_on_map(void)
{
    int i, j;
    for (i=0; i<CAR_SIZE; i++) {

        for (j=0; j<CAR_SIZE; j++) {

            map[i+car_row][j+car_col] = car[i][j];
        }
    }
}

void car_rotate90(void)
{
    /* your code */
    //轉換車頭"燈"的方向


}

void car_move(void)
{
    /* your code */
    // 車頭朝右：(1,0)
    // 車頭朝左：(-1,0)
    // 車頭朝上：(0,1)
    // 車頭朝下：(0,-1)
}
