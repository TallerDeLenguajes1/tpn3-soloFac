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

void CargarProductos(Cliente ** p_usuario1, int CantidadProductos);

/*int CantidadPorPrecioUnitario();*/

int main(){
    Cliente * asiduo;
    
    asiduo = Interfaz();  //Consulta: Es mas recomendable hacer la reserva de memoria en el programa principal y tener siempre el puntero de la memoria reservada ahí?
                                //Esta bien que haga esto??? Devolver de esta manera el puntero?

    printf("%s", *asiduo->Productos->TipoProducto);

    return 0;
}

Cliente * Interfaz(){
    int NdeClientes;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &NdeClientes);

    Cliente * usuario = (Cliente *) malloc(sizeof(Cliente) * NdeClientes);      //Reserva de memoria para la cantidad total de clientes

    CargarClientes(&usuario, NdeClientes);

    return (usuario);
};

void CargarClientes(Cliente ** p_usuario, int NdeClientes){
    int ClienteID1, CantidadProductosAPedir;
    Cliente * p_aux = * p_usuario;  //declaro un puntero auxiliar para enviarlo a la funcion CargarProductos

    for (int i = 0; i < NdeClientes; i++)
    {  //------Cargo los datos del Cliente-------
        printf("Ingrese el ID de cliente Nro. %d: \n", i+1);
        scanf("%d", &(* p_usuario)[i].ClienteID);
        printf("El id del usuario es: %d\n", (* p_usuario)[i].ClienteID);
        printf("Ingrese el nombre del cliente #%d: \n");
        char *nom_aux = (char *) malloc(sizeof(char) * 100);    //v_aux para guardar el nombre saber la cantidad de caracteres y luego guardar el nombre del cliente
        scanf("%s", nom_aux);
        int tam_nombre = strlen(nom_aux);
        (* p_usuario)[i].NombreCliente = (char *) malloc(sizeof(char) * tam_nombre);
        strcpy((* p_usuario)[i].NombreCliente, nom_aux);
        free(nom_aux);

        printf("Ingrese la cantidad de Productos a Pedir: ");
        scanf("%d", &(* p_usuario)[i].CantidadProductosAPedir);

        //-------Cargo los datos del Producto del cliente generados aleatoriamente----

        (* p_usuario)[i].Productos = (Producto *) malloc(sizeof(Producto) * ((* p_usuario)[i].CantidadProductosAPedir));     //Reservo memoria para los Productos del Cliente
        int CantidadProductos = (* p_usuario)[i].CantidadProductosAPedir;
        Cliente * p_usuario1 = *p_usuario;

        CargarProductos(&p_usuario1, CantidadProductos);
        
    }
    

    getchar();
};

void CargarProductos(Cliente ** p_usuario1, int CantidadProductos){

    int aleatorio;

    for (int j = 0; j < CantidadProductos; j++)
    {
        aleatorio = rand() % 5;
        (* p_usuario1)[0].Productos[j].ProductoID = j + 1;
        (* p_usuario1)[0].Productos[j].Cantidad = 1 + rand() % 11;    // TL♥
        int tamanio = strlen(TiposProductos[aleatorio]);
        (* p_usuario1)[0].Productos[j].TipoProducto = (char *)malloc(sizeof(tamanio) * sizeof(char *)); //Consulta: Porque size of de tamanio si tamanio tiene la cantidad de caracteres, no seria lo mismo que poner tamanio directamente? porque cada char ocupa un byte?
        strcpy((* p_usuario1)[0].Productos[j].TipoProducto, TiposProductos[aleatorio]);
        (* p_usuario1)[0].Productos[j].PrecioUnitario = 10 + rand() % 91;
    }      
};

/*
int CantidadPorPrecioUnitario(){

};*/