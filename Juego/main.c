#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define IZQUIERDA 75
#define DERECHA 77

char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};
char avion_12[]={' ',' ','*','*','*',' ',' ',0};
char avion_13[]={' ','*',' ','*',' ','*',' ',0};

char explosion_11[]={' ',' ',' ','*',' ',' ',' ',0};
char explosion_12[]={' ',' ','*','*','*',' ',' ',0};
char explosion_13[]={' ',' ',' ','*',' ',' ',' ',0};

char explosion_r1[]={' ',' ','*','*','*',' ',' ',0};
char explosion_r2[]={' ','*','*','*','*','*',' ',0};
char explosion_r3[]={' ',' ','*','*','*',' ',' ',0};

char borraravion[]={' ',' ',' ',' ',' ',' ',' ',0};


int num_vidas = 3;
int corazones = 3;
int ix = 40;
int iy = 19;

int y = 8 , x = 12;
int yy = 12 , xx = 17;
int x1 = 58 , y1 = 6;
int x2 = 70 , y2 = 9;
int x3 = 46 , y3 = 7;
int x4 = 35 , y4 = 11;
int i,v;

int repeticion = 0 , nivel = 1;
bool condicion = false;

void gotoxy(int x , int y)
{

     HANDLE hCon;
     COORD dwPos;

     dwPos.X = x;
     dwPos.Y = y;
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);


     SetConsoleCursorPosition(hCon,dwPos);

}
 void vidas(int vi)
{
       gotoxy(1,1);  printf("vidas %d",vi);
}
void Barra_salud(int n)
{

     gotoxy(72,1); printf(" ");
     gotoxy(73,1); printf(" ");
     gotoxy(74,1); printf(" ");

     for(v = 0 ; v < n ; v++)
     {
         gotoxy(72+v,1);
         printf("%c",3);
           }


     }
     void Explosion(void)
     {

         gotoxy(ix,iy); puts(explosion_11);
         gotoxy(ix,iy+1); puts(explosion_12);
         gotoxy(ix,iy+2); puts(explosion_13);

         Sleep(380);

         gotoxy(ix,iy); puts(explosion_r1);
         gotoxy(ix,iy+1); puts(explosion_r2);
         gotoxy(ix,iy+2); puts(explosion_r3);

         Sleep(380);


           gotoxy(ix,iy); puts(avion_11);
         gotoxy(ix,iy+1); puts(avion_12);
         gotoxy(ix,iy+2); puts(avion_13);

         }

    void jugar(void)
    {
       //rutina de los asteroides



       gotoxy(x,y); printf("%c",2);
       gotoxy(xx,yy); printf("%c",2);
       gotoxy(x1,y1); printf("%c",2);
       gotoxy(x2,y2); printf("%c",2);
       gotoxy(x3,y3); printf("%c",2);

       Sleep(70);

       gotoxy(x,y); printf(" ");
       gotoxy(xx,yy); printf(" ");
       gotoxy(x1,y1); printf(" ");
       gotoxy(x2,y2); printf(" ");
       gotoxy(x3,y3); printf(" ");

       if(y > 20)
       {

            y = 4;
            x = rand() % 70 +6;

            if(y == 4)
            condicion = false;
            }

             if(yy > 20)
       {

            yy = 4;
            xx = rand() % 70 +6;
            }

             if(y1 > 20)
       {

            y1 = 4;
            x1 = rand() % 70 +6;
            }

             if(y2 > 20)
       {

       y2 = 4;
            x2 = rand() % 70 +6;
            }

             if(y3 > 20)
       {

       y3 = 4;
            x3 = rand() % 70 +6;
            }

            //rutina para mover avion

            if(kbhit())
            {
                 unsigned char tecla = getch();

                 switch (tecla)

                {
                   case IZQUIERDA:

                        if(ix > 4)
                        {
                            gotoxy(ix,iy); puts(borraravion);
                            gotoxy(ix,iy+1); puts(borraravion);
                            gotoxy(ix,iy+2); puts(borraravion);

                            ix -=2;

                            gotoxy(ix,iy); puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13);
                             }
                        break;

                        case DERECHA:

                             if(ix < 70)
                             {
                              gotoxy(ix,iy); puts(borraravion);
                            gotoxy(ix,iy+1); puts(borraravion);
                            gotoxy(ix,iy+2); puts(borraravion);

                            ix +=2;

                            gotoxy(ix,iy); puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13);
                             }
                        break;

                }


            }

            //rutina para golpe de asteroides

            if( (x > ix && x<ix + 6 && y == iy-1) || (xx > ix && xx<ix + 6 && yy == iy-1) ||
            (x1 > ix && x1<ix + 6 && y1 == iy-1) || (x2 > ix && x2<ix + 6 && y2 == iy-1) )
            {
                corazones --;
                Barra_salud(corazones);
                printf("\a");
                }
                            gotoxy(ix,iy); puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13);

            if(!corazones)
            {

                 num_vidas--;
                 vidas(num_vidas) ;
                 Explosion();
                 corazones = 3;


                     Barra_salud(corazones);
                         }


                         //rutina para cambio de nivel

                         if(!condicion)
                         {
                            repeticion ++;
                            condicion = true;


                         }

                         if( repeticion == 8)
                         {
                          nivel++;
                          gotoxy(35,1); printf("NIVEL %i",nivel);

                          gotoxy(ix,iy); puts(borraravion);
                          gotoxy(ix,iy+1); puts(borraravion);
                          gotoxy(ix,iy+2); puts(borraravion);
                          iy -=2;

                           gotoxy(ix,iy); puts(avion_11);
                          gotoxy(ix,iy+1); puts(avion_12);
                          gotoxy(ix,iy+2); puts(avion_13);

                          repeticion = 0;

                         }




       y++;
       yy++;
       y1++;
       y2++;
       y3++;



         }




     int main()

     {

         vidas(num_vidas);
         Barra_salud(corazones);
         gotoxy(35,1); printf("NIVEL %i",nivel);

         gotoxy(ix,iy); puts(avion_11);
         gotoxy(ix,iy+1); puts(avion_12);
         gotoxy(ix,iy+2); puts(avion_13);


         while(num_vidas > 0 && nivel <= 6)
         jugar();

         gotoxy(20,15); printf("GAME OVER");

         Sleep(1000);
         getch();
         return 0;



         }
