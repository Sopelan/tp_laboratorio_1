//id, nombre, empleo,edad,horasTrabajadas
typedef struct{
    int id;
    char nombre[50];
    char empleo[50];
    int edad;
    int horasTrabajadas;
}eEmpleado;
void prinTodo(int option);
eEmpleado* empleadoNew();
int setId(eEmpleado* empleado , int id);
int getId(eEmpleado* empleado , int* id);
int setNombre(eEmpleado* empleado , char* nombre);
int getNombre(eEmpleado* empleado , char* nombre);
int setEmpleo(eEmpleado* empleado , char* empleo);
int getEmpleo(eEmpleado* empleado , char* empleo);
int setEdad(eEmpleado* empleado , int edad);
int getEdad(eEmpleado* empleado , int* edad);
int setHorasTrabajadas(eEmpleado* empleado , int horasTrabajadas);
int getHorasTrabajadas(eEmpleado* empleado , int* horasTrabajadas );
