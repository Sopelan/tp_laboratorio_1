void setStatus(Product productArray[],int arrayLenght,int value)
{
    int i;
    for(i = 0; i < arrayLenght ; i++)
    {
        productArray[i].status = value;
    }
}
int findEmptyPlace(Product productArray[],int arrayLenght)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(productArray[i].status == LIBRE)
        {
            return i;
        }
    }
    return OCUPADO;
}
int findProductByCode(Product productArray[],int arrayLenght,int code)
{
    int i;
    for(i = 0 ; i < arrayLenght ; i++)
    {
       if(productArray[i].code == code && productArray[i].status == OCUPADO)
       {
           return i;
       }
    }
    return LIBRE;
}
float getCheaperPrice(Product productArray[],int arrayLenght)
{
    int i;
    float cheaperPrice = LIBRE;
    for(i = 0 ; i < arrayLenght; i++)
    {
        if(productArray[i].status == OCUPADO)
        {
            cheaperPrice = productArray[i].price;
            break;
        }
    }
    if(cheaperPrice == LIBRE)
        return LIBRE;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(productArray[i].status == OCUPADO)
        {
            if(productArray[i].price < cheaperPrice)
            {
                cheaperPrice = productArray[i].price;
            }
        }
    }
    return cheaperPrice;
}
float getAveragePrice(Product productArray[],int arrayLenght)
{
    int i;
    float suma;
    float promedio = 0;
    float resultado;
    for(i = 0 ; i < arrayLenght ; i++)
    {
        if(productArray[i].status == OCUPADO)
        {
            suma = productArray[i].price + suma;
            promedio = promedio + 1;
        }
    }
    if(promedio == 0)
    {
        return LIBRE;
    }
    resultado = suma/promedio;
    return resultado;

}
void orderArrayByDescription(Product productArray[],int arrayLenght)
{
        int j;
        int i;
        Product auxiliar;
        for(i=0; i < arrayLenght - 1; i++)
        {
            if(productArray[i].status == LIBRE)
            {
                continue;
            }
            for(j=i+1; j < arrayLenght; j++)
            {
                if(productArray[i].status == LIBRE)
                {
                    continue;
                }
                if(strcmp(productArray[j].description,productArray[i].description)>0)
                {
                    auxiliar = productArray[j];
                    productArray[j] = productArray[i];
                    productArray[i] = auxiliar;
                }
                else if(productArray[j].qty < productArray[i].qty)
                {
                    auxiliar = productArray[j];
                    productArray[j] = productArray[i];
                    productArray[i] = auxiliar;
                }
            }
        }

}
