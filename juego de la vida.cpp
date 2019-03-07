#include <stdio.h>
#include <conio.h>
#include <windows.h>

int mundo[40][80]={0};
int mundoalter[40][80]={0};
int mundocopia[40][80];

int filmap,colmap,f,c;
char tecla;
int band=0;
bool prueba=false;
int generacion=1;

int celulas=0;
int nnacidos;
int nmuertos;

int i,j;

void gotoxy(int, int);
void instrucciones();
void marco();
void universo();
void copimundobase();
void restaurarmundo();
void muerte();
void vida();
void revision();
void run();
void addcel();
void delcel();
void borrardatos();
void movimiento();

int main()
{	
	universo();
	gotoxy(0,0);
	
	while (tecla!='z')
	{		
		movimiento();
	}
	
	gotoxy(0,46);
}


void gotoxy(int gox, int goy)
{
	HANDLE hcon = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X=gox;
	dwpos.Y=goy;
	SetConsoleCursorPosition (hcon,dwpos);
}


void instrucciones()
{
	gotoxy(56,42);
	printf("W: arriba");
	gotoxy(56,43);
	printf("S: abajo");
	gotoxy(70,42);
	printf("A: izquierda");
	gotoxy(70,43);
	printf("D: derecha");
	gotoxy(85,42);
	printf("P: agregar celula");
	gotoxy(85,43);
	printf("O: eliminar celula");
	gotoxy(8,41);
	printf("Generacion: %i",generacion);
	gotoxy(25,43);
	printf("V: ejecutar simulacion");
	gotoxy(25,42);
	printf("C: detener simulacion");
	gotoxy(25,41);
	printf("K: restaurar");
	gotoxy(107,43);
	printf("Z: salir");
	gotoxy(107,42);
	printf("J: borrar checkpoint");
	gotoxy(138,43);
	printf("Hecho por: Jose Vasquez");
	
}


void marco()
{
	for (i=0;i<160;i++)
	{
		gotoxy(i,40);
		printf("%c",205);
	}
	
	for (j=0;j<40;j++)
	{
		gotoxy(160,j);
		printf("%c",186);
	}
	
	gotoxy(160,40);
	printf("%c",188);
	
	gotoxy(8,42);
	printf("nacidos: %i\n\tmuertos: %i",nnacidos,nmuertos);
	
	instrucciones();
	
	gotoxy(0,0);
}

void universo()
{
	marco();
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			printf("%c ",mundo[filmap][colmap]);
		}
		printf("\n");
	}
}


void copimundobase()
{
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			mundocopia[filmap][colmap]=mundo[filmap][colmap];
		}
	}
	prueba=true;
}


void restaurarmundo()
{
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			mundo[filmap][colmap]=mundocopia[filmap][colmap];
		}
	}
	
	nnacidos=0;
	nmuertos=0;
	generacion=0;
	system("cls");
	
	universo();
}


void muerte()
{
	
	
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			if (mundoalter[filmap][colmap]==2)
			{
				mundo[filmap][colmap]=0;
				nmuertos+=1;
			}
		}
	}
	
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			mundoalter[filmap][colmap]=0;
		}
	}
	
}


void vida()
{
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			if (mundoalter[filmap][colmap]==3)
			{
				mundo[filmap][colmap]=49;
				nnacidos++;
			}
		}
	}
}


void revision()
{
			if (mundo[filmap-1][colmap-1]==49)
			{
				band++;
			}
			
			if (mundo[filmap-1][colmap]==49)
			{
				band++;
			}
				
			if (mundo[filmap-1][colmap+1]==49)
			{
				band++;
			}
				
			if (mundo[filmap][colmap-1]==49)
			{
				band++;
			}
				
			if (mundo[filmap][colmap+1]==49)
			{
				band++;
			}
				
			if (mundo[filmap+1][colmap-1]==49)
			{
				band++;
			}
				
			if (mundo[filmap+1][colmap]==49)
			{
				band++;
			}
				
			if (mundo[filmap+1][colmap+1]==49)
			{
				band++;
			}
}


void run()
{
	if(prueba==false)
	{
	copimundobase();
	}
	
	while (tecla!='c')
	{
		
		for (filmap=0;filmap<40;filmap++)
		{
			for(colmap=0;colmap<80;colmap++)
			{
				if (mundo[filmap][colmap]==0)
				{
					band=0;
								
					revision();
				
					if (band==3)
					{
						mundoalter[filmap][colmap]=3;
					}
				}
		
		
				if (mundo[filmap][colmap]==49)
				{
					band=0;
				
					revision();
				
					if (band>=4 xor band<=1)
					{
						mundoalter[filmap][colmap]=2;
					}
				}	
			}
		}
	
		vida();
		muerte();
		universo();
		generacion++;
		movimiento();
	}
}


void addcel()
{
	
	filmap=f;
	
	colmap=c/2;
	
	if (mundo[filmap][colmap]==0)
	{
	mundo[filmap][colmap]=49;
	
	celulas++;
	
	universo();
	}
	
}


void delcel()
{
	filmap=f;
	
	colmap=c/2;
	
	if (mundo[filmap][colmap]==49)
	{
		
	mundo[filmap][colmap]=0;
	
	celulas--;
	if (celulas <0)
	celulas=0;
	
	universo();
	}
}


void borrardatos()
{
	for (filmap=0;filmap<40;filmap++)
	{
		for(colmap=0;colmap<80;colmap++)
		{
			mundo[filmap][colmap]={0};
			mundocopia[filmap][colmap]={0};
		}
	}
	
	nnacidos=0;
	nmuertos=0;
	generacion=0;
	prueba=false;
	system("cls");
	
	universo();
}


void movimiento()
{
		if (kbhit())
		{	
			tecla=getch();
		
			switch(tecla)
			{
				case 'a':
				{
					c-=2;
					if (c<0)
					c=0;break;
				}
				case 'd':
				{
					c+=2;
					if (c>158)
					c=158;break;
				}
				case 's':
				{
					f++;
					if (f>39)
					f=39;break;
				}
				case 'w':
				{
					f--;
					if (f<0)
					f=0;break;
				}
				
				case 'p':
				{
					addcel();break;
				}
				case 'o':
				{
					delcel();break;
				}
				case 'v':
				{
					if (celulas>4)
					{
					run();
					}
					break;
				}
				
				case 'k':
				{
					restaurarmundo();break;	
				}
				
				case 'j':
				{
					borrardatos();break;	
				}
			
			}
			
			gotoxy(c,f);
		}
	
}
