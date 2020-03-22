#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#define N 3
#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

int mat[N][N] = {{100, 200, 1},
		     {150, 150, 1},
		     {200, 200, 1}};
int temp1[N][N],temp2[N][N];

int res[N][N],trans[N][N],rot[N][N],scale[N][N];
int i, j, sx, sy, tx, ty, x, choice, c1;

int trans[N][N] = {{1, 0, 0},
			       {0, 1, 0},
			       {0, 0, 1}};

int rot[N][N] = {{1, 0, 0},
			     {0, 1, 0},
			     {0, 0, 1}};

int scale[N][N] = {{1, 0, 0},
			       {0, 1, 0},
			       {0, 0, 1}};


void DrawCordinates();
void DrawLines(int mat[][N]);
void multiply(int mat1[][N],int mat2[][N],int res[][N]);

void DrawCordinates()
{
    line(320, 0, 320, 640);
    line(0, 240, 640, 240);
}

void DrawLine(int mat[][N])
{
    line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
    line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
    line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);
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

void main()
{
    int gd = DETECT, gm;
    clrscr();
    initgraph(&gd, &gm, "C:\\TurboC3\\bgi");

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
	    trans[2][0] = tx;
	    trans[2][1] = ty;
	    multiply(mat, trans, res);
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

	    trans[2][0] = -150;
	    trans[2][1] = -150;
	    multiply(mat, trans, temp1);

	    rot[0][0] = COS(x);
	    rot[0][1] = SIN(x);
	    rot[1][0] = -SIN(x);
	    rot[1][1] = COS(x);
	    multiply(temp1, rot, temp2);

	    trans[2][0] = 150;
	    trans[2][1] = 150;
	    multiply(temp2, trans, res);

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
	    scale[0][0] = sx;
	    scale[1][1] = sy;

	    multiply(mat, scale, res);
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
		DrawLine(res);
		getch();
		break;
	    case 2:
		//code
		setcolor(RED);
		DrawLine(res);
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
	}
    } while (choice != 6);

}
