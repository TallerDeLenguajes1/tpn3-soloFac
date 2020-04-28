#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct{
    int ProductoID;         //Numerado en ciclo iterativo
    int Cantidad;           // entre 1 y 10
    char *TipoProducto;     // Algún valor del arreglo TiposProductos
    float PrecioUnitario;   // entre 10 - 100
}Producto;

typedef struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable  // “CantidadProductosAPedir”
}Cliente;

Cliente * Interfaz();

void CargarClientes(Cliente ** p_usuario, int NdeClientes);

void CargarProductos(Cliente ** p_usuario1, int CantidadProductos, int i);

/*int CantidadPorPrecioUnitario();*/

int main(){
    Cliente * asiduo;   //declaro una variable para recibir la direccion del puntero cliente
    
    asiduo = Interfaz();  //Consulta: Es mas recomendable hacer la reserva de memoria en el programa principal y tener siempre el puntero de la memoria reservada ahí?
                                //Esta bien que haga esto??? Devolver de esta manera el puntero?

    printf("Los productos del primer cliente son \n");
    printf("Precio unitario: %d", (* asiduo).Productos[0].PrecioUnitario);

    asiduo--;
    printf("El nombre del cliente es: ");
    printf("%s", asiduo->NombreCliente);

    scanf("%c");

    return 0;
}



Cliente * Interfaz(){       //Consulta: Se coloca "*" para indiciar que se devuelve una variable del tipo Cliente puntero?
    int NdeClientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &NdeClientes);  

    Cliente * usuario = (Cliente *) malloc(sizeof(Cliente) * NdeClientes);      //Reserva de memoria para la cantidad total de clientes
    //aqui cuando hago esta reserva de memoria para usuario cuando termina la funcion esto queda reservado, y cuando devuelva el puntero a main y lo libere desde ahi ya queda liberado
    CargarClientes(&usuario, NdeClientes);


    // printf("Los productos del primer cliente son \n");
    // printf("Precio unitario: %d\n", usuario[0].Productos[0].PrecioUnitario);
    // printf("Tipo de producto: %s\n", usuario->Productos->TipoProducto);

    return usuario;
};



void CargarClientes(Cliente ** p_usuario, int NdeClientes){
    int ClienteID1, CantidadProductosAPedir;
    Cliente * p_usuario1 = *p_usuario;  //declaro un puntero auxiliar para enviarlo a la funcion CargarProductos

    for (int i = 0; i < NdeClientes; i++)
    {  //------Cargo los datos del Cliente-------
        printf("Ingrese el ID de cliente Nro. %d: \n", i+1);
        scanf("%d", &(* p_usuario)->ClienteID);
        printf("El id del usuario es: %d\n", (* p_usuario)->ClienteID);
        printf("Ingrese el nombre del cliente #%d: \n", i+1);
        char *nom_aux = (char *) malloc(sizeof(char) * 100);    //v_aux para guardar el nombre saber la cantidad de caracteres y luego guardar el nombre del cliente
        scanf("%s", nom_aux);
        int tam_nombre = strlen(nom_aux);
        (* p_usuario)->NombreCliente = (char *) malloc(sizeof(char) * tam_nombre);
        strcpy((* p_usuario)->NombreCliente, nom_aux);
        free(nom_aux);

        printf("Ingrese la cantidad de Productos a Pedir: ");
        scanf("%d", &(* p_usuario)->CantidadProductosAPedir);

        //-------Cargo los datos del Producto del cliente generados aleatoriamente----

        int CantidadProductos = (* p_usuario)[i].CantidadProductosAPedir;
        (* p_usuario)[i].Productos = (Producto *) malloc(sizeof(Producto) * CantidadProductos);     //Reservo memoria para los Productos del Cliente

        CargarProductos(&p_usuario1, CantidadProductos, i);
        
    }
    
    //* p_usuario = * p_usuario - NdeClientes;
};

void CargarProductos(Cliente ** p_usuario1, int CantidadProductos, int i){

    for (int j = 0; j < CantidadProductos; j++)
    {
        int precio_unitario = 10 + rand() % 91;
        int aleatorio = rand() % 5;
        (* p_usuario1)[i].Productos[j].ProductoID = j + 1;
        (* p_usuario1)[i].Productos[j].Cantidad = 1 + rand() % 11;    // TL♥
        int tamanio = strlen(TiposProductos[aleatorio]);
        (* p_usuario1)[i].Productos[j].TipoProducto = (char *)malloc(sizeof(tamanio)); //Consulta: Esta bien que hecha la reserva de memoria en este caso?
        strcpy((* p_usuario1)[i].Productos[j].TipoProducto, TiposProductos[aleatorio]);
        (* p_usuario1)[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
        ((*p_usuario1)[i].Productos+j);
    }      
};

/*
int CantidadPorPrecioUnitario(){

};*/