#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

void listarColores(eColor listcolores[], int lencolores);

#endif // COLOR_H_INCLUDED
