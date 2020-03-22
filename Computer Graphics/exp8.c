#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#define N 3
#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

void DrawCordinates()
{
    line(320, 0, 320, 640);
    line(0, 240, 640, 240);
}

Void DrawLine(int mat[][N])
{
    line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
}

void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    clrscr();
    initgraph(&gd, &gm, "C:\\TurboC3\\bgi");
    int mat[N][N] = {{100, 100, 1},
                     {200, 200, 1},
                     {1, 1, 1}};
    int res[N][N];
    int i, j, sx, sy, tx, ty, x;

    do
    {
        clrscr();
        printf("\n****************MENU***************\n");
        printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n6.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            clrscr();
            initgraph(&gd, &gm, "c:\\turboc3\\bgi");
            DrawCordinates();
            DrawLine(mat);
            printf("\nEnter translation vectors (tx,ty):");
            scanf("%d%d", &tx, &ty);
            int trans[N][N] = {{1, 0, 0},
                               {0, 1, 0},
                               {tx, ty, 1}};
            multiply(mat, trans, res)
                setcolor(RED);
            DrawLine(res);
            getch();
            closegraph();
            break;
        case 2:
            clrscr();
            initgraph(&gd, &gm, "c:\\turboc3\\bgi");
            DrawCordinates();
            DrawLine(mat);
            printf("\nEnter rotation  angle:");
            scanf("%d", &x);
            int rot[N][N] = {{COS(x), SIN(x), 0},
                             {-SIN(x), COS(x), 0},
                             {0, 0, 1}};
            multiply(mat, rot, res)
                setcolor(RED);
            DrawLine(res);
            getch();
            closegraph();
            break;
        case 3:
            clrscr();
            initgraph(&gd, &gm, "c:\\turboc3\\bgi");
            DrawCordinates();
            DrawLine(mat);
            printf("\nEnter scaling vectors (sx,sy):");
            scanf("%d%d", &sx, &sy);
            int scale[N][N] = {{sx, 0, 0},
                               {0, sy, 0},
                               {0, 0, 1}};
            multiply(mat, scale, res)
                setcolor(RED);
            DrawLine(res);
            getch();
            closegraph();
            break;
        case 4:
            clrscr();
            initgraph(&gd, &gm, "c:\\turboc3\\bgi");
            DrawCordinates();
            DrawLine(mat);
            printf("\n1.Y-axis\n2.X-axis\n3.exit\n");
            scanf("%d", &c1);
            switch (c1)
            {
            case 1:
                //code
                setcolor(RED);
                DrawLine();
                getch();
                break;
            case 2:
                //code
                setcolor(RED);
                DrawLine();
                getch();
                break;
            case 3:
                break;
            }
            closegraph();
            break;
        case 5:
            clrscr();
            initgraph(&gd, &gm, "c:\\turboc3\\bgi");
            DrawCordinates();
            DrawLine(mat);
            //code
            closegraph();
            break;
        case 6:
            exit(0);
        }
    } while (choice != 7);

    return 0;
}
