int obtenerMaximo(int x, int y, int z)
{
    int Maximo;

    if(x > y && x > z)
    {
        Maximo = x;
    }
    if(y > x && y > z)
    {
        Maximo = y;
    }
    if(z > x && z > y)
    {
        Maximo = z;
    }

    return Maximo;
}

