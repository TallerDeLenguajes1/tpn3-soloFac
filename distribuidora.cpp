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

Cliente * Interfaz(int * num);

void CargarClientes(Cliente ** p_usuario, int NdeClientes);

void CargarProductos(Cliente ** p_usuario, int NdeClientes);

void mostrarClientes(Cliente p_cliente[]);

float CantidadPorPrecioUnitario(Producto P);



int main(){
    
    time_t t;
    srand((unsigned) time(&t));

    int NdeClientes;

    Cliente * p_cliente;   //declaro una variable para recibir la direccion del puntero cliente
    
    p_cliente = Interfaz(&NdeClientes);

    CargarClientes(&p_cliente, NdeClientes);
    
    CargarProductos(&p_cliente, NdeClientes);

    mostrarClientes(p_cliente);

    return 0;
}



Cliente * Interfaz(int * NdeClientes){  //Realizo ademas la reserva.

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", NdeClientes);

    Cliente * usuario;

    usuario = (Cliente *) malloc(sizeof(Cliente) * (* NdeClientes));      //Reserva de memoria para la cantidad total de clientes

    return usuario;
};



void CargarClientes(Cliente ** p_usuario, int NdeClientes){

    for (int i = 0; i < NdeClientes; i++) //------Cargo los datos del Cliente-------
    {
        printf("Ingrese el ID de cliente Nro. %d: \n", i+1);
        scanf("%d", &(* p_usuario)[i].ClienteID);
        printf("El id del usuario es: %d\n", (* p_usuario)[i].ClienteID);
        printf("Ingrese el nombre del cliente #%d: \n", i+1);
        char * nom_aux = (char *) malloc(sizeof(char) * 100);
        scanf("%s", nom_aux);
        int tam_nombre = strlen(nom_aux);
        (* p_usuario)[i].NombreCliente = (char *) malloc(sizeof(char) * tam_nombre);
        strcpy((* p_usuario)[i].NombreCliente, nom_aux);
        free(nom_aux);

        printf("Ingrese la cantidad de Productos a Pedir: ");
        scanf("%d", &(* p_usuario)[i].CantidadProductosAPedir);
    }
};

void CargarProductos(Cliente ** p_usuario, int NdeClientes){

    for (int i = 0; i < NdeClientes; i++)
    {
        int CantidadProductos = (* p_usuario)[i].CantidadProductosAPedir;
        (* p_usuario)[i].Productos = (Producto *) malloc(sizeof(Producto) * CantidadProductos);     //Reservo memoria para los Productos del Cliente

        for (int j = 0; j < CantidadProductos; j++)
        {
            float precio_unitario = 10 + rand() % 91;
            int aleatorio = rand() % 5;
            (* p_usuario)[i].Productos[j].ProductoID = j + 1;
            (* p_usuario)[i].Productos[j].Cantidad = 1 + rand() % 11;    // TL♥
            int tamanio = strlen(TiposProductos[aleatorio]);
            (* p_usuario)[i].Productos[j].TipoProducto = (char *)malloc(sizeof(tamanio));
            strcpy((* p_usuario)[i].Productos[j].TipoProducto, TiposProductos[aleatorio]);
            (* p_usuario)[i].Productos[j].PrecioUnitario = precio_unitario;
        }
    }
    
};

void mostrarClientes(Cliente p_cliente[]){
    
    for (int i = 0; i < 2; i++)
    {
        Producto * P = p_cliente[i].Productos;

        float total = 0, costoProductos;

        printf("\nCliente: %s \n\n", p_cliente[i].NombreCliente);

        for (int j = 0; j < p_cliente[i].CantidadProductosAPedir; j++)
        {
            printf("ID: %d \n", P[j].ProductoID);
            printf("Cantidad: %d \n", P[j].Cantidad);
            printf("Producto: %s \n", P[j].TipoProducto);
            printf("Precio: %f \n", P[j].PrecioUnitario);
            costoProductos = CantidadPorPrecioUnitario(P[j]);
            printf("----------------- \n");
            total = total + costoProductos;
        }

        printf("Total a pagar: $%f\n\n", total);
    }
    
}


float CantidadPorPrecioUnitario(Producto P){
    return P.Cantidad * P.PrecioUnitario;
};