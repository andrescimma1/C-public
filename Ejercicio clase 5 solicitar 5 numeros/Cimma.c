int obtenerMaximo(int x, int maximo)
{
    if(x > maximo)
        {
            maximo = x;
        }
    if(maximo > x)
        {
            x = maximo;
        }

    return maximo;
}

int obtenerMinimo(int x, int minimo)
{
    if(x < minimo)
        {
            minimo = x;
        }
    if(minimo < x)
        {
            x = minimo;
        }

    return minimo;
}
