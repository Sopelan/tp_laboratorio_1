#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret = 0;
    char nombre[128];
    char sueldo[128];
    char id[128];
    char horasTrabajadas[128];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        while(!feof(pFile))
        {
             Employee* retorno;

             fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

             retorno = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
             if(retorno != NULL)
             {
                 ll_add(pArrayListEmployee, retorno);
                 ret++;
             }
        }
         return ret;
    }
    else
    {
        printf("no se cargo ningun archivo\n");
    }




}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
