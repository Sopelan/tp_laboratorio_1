

int initEmployees(Employee list[], int len)
{
    int i;
    for(i = 0 ; i < len ; i++)
    {
        list[i].isEmpty = LIBRE;
        list[i].id =  i + 1;
    }
    return 0;
}
int addEmployee(Employee list[], int len)
{
    char name[128];
    char lastName[128];
    float salary;
    int sector;
    int emptyPlace;
    char auxSalary[128];
    char auxSector[128];
    emptyPlace = findEmptyPlace(list,len);
    if(emptyPlace == OCUPADO)
    {
        printf("esta lleno\n");
        return 0;
    }
    if(!getStringLetras("cual es tu nombre?\n" , name))
    {
        printf("tiene que contener letras\n");
        return 0;
    }
    if(!getStringLetras("cual es tu apellido\n",lastName))
    {
        printf("tiene que contener letras\n");
        return 0;
    }
    if(!getStringNumero("cual es el salario?\n",auxSalary))
    {
        printf("tiene que contener numeros\n");
        return 0;
    }
    salary = atof(auxSalary);
    if(!getStringNumero("cual es el sector?\n",auxSector))
    {
        printf("tiene que contener numeros\n");
        return 0;
    }
    sector = atoi(auxSector);
    strcpy(list[emptyPlace].name , name);
    strcpy(list[emptyPlace].lastName , lastName);
    list[emptyPlace].salary = salary;
    list[emptyPlace].sector = sector;
    list[emptyPlace].isEmpty = OCUPADO;

    return 0;
}
int findEmployeeById(Employee list[], int len , char mensaje[])
{
    int id;
    char auxId[128];
    int i;
    if(findFullPlace(list,len) == LIBRE)
    {
        printf("no hay empleados\n");
        return OCUPADO;
    }
    if(!getStringNumero(mensaje , auxId))
    {
        printf("tiene que contener numeros\n");
        return OCUPADO;
    }
    id = atoi(auxId);
    for(i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].id == id)
        {
            return i;
        }
    }
    return -4;
}
int removeEmployee(Employee list[], int len)
{
    int indice;
    indice = findEmployeeById(list, len, "que empleado queres dar de baja?\n");
    if(indice == -4)
    {
        printf("ese id no existe\n");
        return 0;
    }
    if(indice > -1)
    {
        list[indice].isEmpty = LIBRE;
        printf("ese id fue dado de baja\n");
    }


    return -1;
}
int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    Employee persona;
    switch(order)
    {
    case 1:
        for(i = 0 ; i < len - 1; i++)
        {
            for(j = i + 1  ; j < len ; j++)
            {
                if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
                {
                    if(list[i].sector < list[j].sector )
                    {
                        persona = list[i];
                        list[i] = list[j];
                        list[j] = persona;
                    }
                    else if(list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].lastName,list[j].lastName ) < 0)
                        {
                            persona = list[i];
                            list[i] = list[j];
                            list[j] = persona;
                        }

                    }

                }
            }
        }
        break;
    case 2:
        for(i = 0 ; i < len -1 ; i++)
        {
            for(j = i + 1 ; j < len ; j++)
            {
                if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
                {
                    if(list[i].sector > list[j].sector )
                    {
                        persona = list[i];
                        list[i] = list[j];
                        list[j] = persona;
                    }
                    else if(list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].lastName,list[j].lastName ) > 0)
                        {
                             persona = list[i];
                            list[i] = list[j];
                            list[j] = persona;
                        }

                    }

                }
            }
        }
        break;
    default:

        return -4;
        break;
    }
    return 0;

}
int printEmployees(Employee list[], int len)
{
    int i;
    int opcion;
    char opciones[128];
    float salario = 0;
    float divido = 0;
    float promedio;
    float superaPromedio;
    if(findFullPlace(list,len) == LIBRE)
    {
        printf("no hay empleados\n");
        return 0;
    }
    if(!getStringNumero("ordena de forma:\n1.ascedente\n2.descedente\n" , opciones))
    {
        printf("decbe contener solo numeros\n");
        return 0;
    }
    opcion = atoi(opciones);
    if(sortEmployees(list, len, opcion) == -4)
    {
        printf("numero incorrecto\n");
        return 0;
    }
    for(i = 0 ; i < len ; i++ )
    {
        if(list[i].isEmpty == OCUPADO)
        {
            salario = list[i].salary + salario;
            divido = divido + 1;
        }
    }
    promedio = salario/divido;
    printf("\n%10s\t%10s\t%10s\t%10s\t%10s\n","id","apellido","nombre","sector","salario");
    for(i = 0 ; i < len ; i++ )
    {
        if(list[i].isEmpty == OCUPADO)
            printf("%10d\t%10s\t%10s\t%10d\t%10f\n",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
    }
    printf("\nempleados superando el promedio de todos los salarios\n");
    for(i = 0 ; i < len ; i++ )
    {
        if(list[i].isEmpty == OCUPADO)
        {
            if(list[i].salary >= promedio)
            {
                printf("%10d\t%10s\t%10s\t%10d\t%10f\n",list[i].id,list[i].lastName,list[i].name,list[i].sector,list[i].salary);
                superaPromedio = superaPromedio + 1;
            }
        }
    }
    printf("\nla suma de los salarios de los empleados: %f\n",salario);
    printf("el promedio de los salarios de los empleados: %f\n",promedio);
    printf("la cantidad de empleado que superan el promedio de todos los salarios: %f\n",superaPromedio);
    return 0;
}
int findEmptyPlace(Employee list[],int len)
{
    int i;
    for(i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty == LIBRE)
        {
            return i;
        }
    }
    return OCUPADO;
}
int findFullPlace(Employee list[],int len)
{
    int i;

    for(i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty == OCUPADO )
        {
            return OCUPADO;
        }
    }
    return LIBRE;
}
int modifyEmployees(Employee list[], int len)
{
    int indice;
    char name[128];
    char lastName[128];
    float salary;
    int sector;
    char auxSalary[128];
    char auxSector[128];
    if(findFullPlace(list,len) == LIBRE)
    {
        printf("no hay empleados\n");
        return 0;
    }
    indice = findEmployeeById(list, len, "que empleado queres modificar?\n");
    if(indice == OCUPADO)
    {
        printf("ese id no existe\n");
        return 0;
    }
    if(!getStringLetras("cual es el nuevo nombre?\n" , name))
    {
        printf("tiene que contener letras\n");
        return 0;
    }
    if(!getStringLetras("cual es el nuevo apellido\n",lastName))
    {
        printf("tiene que contener letras\n");
        return 0;
    }
    if(!getStringNumero("cual es el nuevo salario?\n",auxSalary))
    {
        printf("tiene que contener numeros\n");
        return 0;
    }
    salary = atof(auxSalary);
    if(!getStringNumero("cual es el nuevo sector?\n",auxSector))
    {
        printf("tiene que contener numeros\n");
        return 0;
    }
    sector = atoi(auxSector);
    strcpy(list[indice].name , name);
    strcpy(list[indice].lastName , lastName);
    list[indice].salary = salary;
    list[indice].sector = sector;
    list[indice].isEmpty = OCUPADO;
    printf("ahi se hizo la modificacion\n");
    return 0;
}
