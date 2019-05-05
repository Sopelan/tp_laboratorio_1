

//#ifdef _WIN32
#include <windows.h>
//#endif // _WIN32

//#define __unix__
void clear(void)
{
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif
}
void mySleep(int ms)
{
    #ifdef __unix__
        usleep(ms*1000);
    #else
        //sleep(ms);
         //usleep(ms*1000);
    #endif
}
void showDate(void)
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
    puts(buffer);

}
void greet(void)
{
    printf("Game of Fifteen\n");
    //mySleep(2000);
    showDate();
    system("pause");
    clear();

}
void init(int board[DIM][DIM])
{
    int i;
    int j;
    int n = 0;
    int multiplicacion = (DIM * DIM);
    int array[multiplicacion];
    int temp;
    int d = DIM;
    for(i = 0 ; i < multiplicacion ; i++)
    {
        array[i] = i;

    }

    for(i = 0 ; i < multiplicacion ; i++)
    {
        for(j = i + 1 ; j < multiplicacion - 1 ; j++ )
        {
            if(getNumeroAleatorio(0,1,0))
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
           }

        }
    }
    n = 0;
    for(i = 0 ; i < d ; i++)
    {
        for(j = 0 ; j < d ; j++)
        {
            board[i][j] = array[n];
            n = n + 1;
        }
    }
}
void draw(int board[DIM][DIM], int moveCount)
{
    int i;
    int j;
    printf("_____________________________________________________________________\n");
    printf("movimientos: %3d \n",moveCount);
    printf("_____________________________________________________________________\n");
    for(i = 0 ; i < DIM ; i++ )
    {
        for(j = 0 ; j < DIM ; j++ )
        {
            if(board[i][j] == 0)
            {
                printf("|__");
            }
            if(board[i][j] > 0)
            {
                printf("|%2d",board[i][j]);
            }
        }
        printf("|\n\n");
    }
}
int move(int tile, int board[DIM][DIM])
{
    int i;
    int j;
    int x;
    int y;
    int array;
    for(i = 0 ; i < DIM ; i++)
    {
        for(j = 0 ; j < DIM ; j++)
        {
            if(board[i][j] == 0)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    for(i = 0 ; i < DIM ; i++)
    {
        for(j = 0 ; j < DIM ; j++)
        {
            if(tile == board[i][j])
            {
                if (((x == (i - 1)) && (j == y)) ||  ((x == (i + 1)) && (j == y)) ||
                ((i == x) && (y == (j - 1))) || ((i == x) && (y == (j + 1))))
               {
                    board[i][j] = 0;
                    board[x][y] = tile;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int won(int board[DIM][DIM])
{
    int i;
    int j;
    int lastmove =  (DIM * DIM) - 1;
    int array = 0;
    for(i = 0 ; i < DIM ; i++)
    {
        for(j = 0 ; i < DIM ; j++)
        {
            array++;

            if(board[i][j] != array)
            {
                return 0;
                break;
            }
            if (array == lastmove)
            {
                return 1;
                break;

            }
        }
    }
}
