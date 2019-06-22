#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

        printf("Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        FILE* fp;
        int tam;
        fp = fopen(path,"r");
        if(fp == NULL)
        {
            printf("El archivo no pudo ser abierto\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("El archivo fue abierto exitosamente\n");
            tam = parser_EmployeeFromText(fp,pArrayListEmployee);
            printf("Cargo un total de %d empleados\n",tam);
            fclose(fp);
        }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    printf("Cargar los datos de los empleados desde el archivo data.csv (modo binario\n");
    FILE* fp;
    int tam;
    fp = fopen(path,"rb");
    if(fp == NULL)
    {
        printf("El archivo no pudo ser abierto\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("El archivo fue abierto exitosamente\n");
        tam = parser_EmployeeFromBinary(fp,pArrayListEmployee);
        printf("Cargo un total de %d empleados\n",tam);
        fclose(fp);
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    printf("Alta de empleado\n");
    int i = 0;
    int id;
    int flag = 0;
    Employee* aux = employee_new();
    Employee* auxEmp;

    while(!employee_pedirNombre(aux,aux->nombre))
        continue;
    while(!employee_pedirHorasTrabajadas(aux,&aux->horasTrabajadas))
        continue;
    while(!employee_pedirSueldo(aux,&aux->sueldo))
        continue;
    while(flag == 0)
    {
        auxEmp = employee_new();
        auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
        id = 1 + i;
        if(auxEmp != NULL)
        {
            if(id != auxEmp->id)
            flag = 1;
        }
        else
        {
            flag = 1;
        }
        i++;
    }
    employee_setId(aux,id);
    printEmployee(aux);
    ll_add(pArrayListEmployee,aux);
    printf("El id %d fue agregado\n",id);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    printf("Modificar datos de empleado\n");
    int tam;
    Employee* auxEmp;
    Employee emp;
    Employee* aux = NULL;
    int i;
    int id;
    int j;
    char idAux[120];
    int option;
    tam = ll_len(pArrayListEmployee);
    getStringNumero("Escribi el id que queres modificar\n",idAux);
    id = atoi(idAux);
    for(i = 0 ; i<tam ; i++)
    {
        auxEmp = employee_new();
        auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmp->id == id)
        {
            aux = employee_new();
            aux = auxEmp;
            emp = *aux;
            j = i;
            break;
        }
    }
    if(aux == NULL)
    {
        printf("No se encuentra el id\n");
        return 0;
    }
    do{
    option = getValidInt("Que queres modificar\n1.Nombre\n2.Horas de trabajo\n3.Sueldo\n4.Salis de modificar\n","Tiene que ser un numero\n",1,4);
    printEmployee(&emp);
    switch(option)
    {
        case 1:
          if(!employee_pedirNombre(&emp,emp.nombre))
                break;
            break;
        case 2:
            if(!employee_pedirHorasTrabajadas(&emp,&(emp.horasTrabajadas)))
                break;
            break;
        case 3:
            if(!employee_pedirSueldo(&emp,&(emp.sueldo)))
                break;
            break;
        case 4:
            printf("Salir\n");
            break;


    }
    }while(option != 4);
    printEmployee(&emp);

    option = getValidInt("Estas seguro\n1.Si\n2.No\n","Tiene que ser numeros",1,2);
    if(option == 1)
    {
        *aux = emp;
    }
    printf("El id %d fue modificado\n",j);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    printf("Baja de empleado\n");
    int tam;
    Employee* auxEmp;
    Employee* aux;
    int i;
    int id;
    char idAux[120];
    int j;
    tam = ll_len(pArrayListEmployee);
    getStringNumero("Escribi el id que queres modificar\n",idAux);
    id = atoi(idAux);
    for(i = 0 ; i<tam ; i++)
    {
        auxEmp = employee_new();
        auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmp->id == id)
        {
            aux = auxEmp;
            j = i;
            break;
        }
    }
    if(aux == NULL)
    {
        printf("No se encuentra el id\n");
        return 0;
    }
    ll_remove(pArrayListEmployee,j);
    printf("El id %d fue borrado\n",j);
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    printf("Listar empleados\n");
    if(pArrayListEmployee != NULL)
    {
        Employee* auxEmp = NULL;
        int len;
        int i;
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            print();
            for(i = 0 ; i < len ; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
                printEmployee(auxEmp);
            }
        }
        else
        {
            printf("No hay empleado para mostrar\n");
            return 0;
        }

    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    printf("Ordenar empleados\n");
    int option;
    int option2;
    option = getValidInt("Ordenar por:\n1.id\n2.Nombre\n3.Horas trabajadas\n4.sueldo\n","tiene que ser un numero\n",1,4);
    switch(option)
    {
        case 1:
            option2 = getValidInt("Ordenar de forma\n1.ascendente\n0.descendente\n","tiene que ser un numero\n",0,1);
            ll_sort(pArrayListEmployee,ordenarPorId,option2);
            break;
        case 2:
            option2 = getValidInt("Ordenar de forma\n1.ascendente\n0.descendente\n","tiene que ser un numero\n",0,1);
            ll_sort(pArrayListEmployee,ordenarPorNombre,option2);
            break;
        case 3:
            option2 = getValidInt("Ordenar de forma\n1.ascendente\n0.descendente\n","tiene que ser un numero\n",0,1);
            ll_sort(pArrayListEmployee,ordenarPorHoras,option2);
            break;
        case 4:
            option2 = getValidInt("Ordenar de forma\n1.ascendente\n0.descendente\n","tiene que ser un numero\n",0,1);
            ll_sort(pArrayListEmployee,ordenarPorSueldo,option2);
            break;

    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    printf("Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    printf("Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    return 1;
}

