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

/*int CostoTotal();*/

int main(){
    Cliente * asiduo;
    
    asiduo = Interfaz();  //Consulta: Es mas recomendable hacer la reserva de memoria en el programa principal y tener siempre el puntero de la memoria reservada ahí?
                                //Esta bien que haga esto??? Devolver de esta manera el puntero?

    

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

    for (int i = 0; i < NdeClientes; i++)
    {  //Cargo los datos del Cliente
        printf("Ingrese el ID de cliente Nro. %d: \n", i+1);
        scanf("%d", &(* p_usuario)[i].ClienteID);
        printf("El id del usuario es: %d\n", (* p_usuario)[i].ClienteID);
        //printf("Ingrese el nombre: \n");
        //(* p_usuario)[i].NombreCliente = (char *) malloc(sizeof(char) * 100);
        //scanf("%s", &(((* p_usuario)[i].NombreCliente[0]);
        /*(* p_usuario)[i].NombreCliente = getchar();*/
        printf("Ingrese la cantidad de Productos a Pedir: ");
        scanf("%d", &(* p_usuario)[i].CantidadProductosAPedir);
    //Cargo los datos del Producto del cliente generados aleatoriamente
        //Consulta: Deberia separar para que el producto sea agregado en otra funcion?
        (* p_usuario)[i].Productos = (Producto *) malloc(sizeof(Producto) * ((* p_usuario)[i].CantidadProductosAPedir));     //Reservo memoria para el Producto del Cliente
        int aleatorio;
        
        for (int j = 0; j < (* p_usuario)[i].CantidadProductosAPedir; j++)
        {
            aleatorio = rand() % 5;
            (* p_usuario)[i].Productos->ProductoID = i+1;
            (* p_usuario)[i].Productos->Cantidad = 1 + rand() % 11;    //Amo TL
            int tamanio = strlen(TiposProductos[aleatorio]);
            (* p_usuario)[i].Productos->TipoProducto = (char *)malloc(sizeof(tamanio)); //Consulta: Porque size of de tamanio si tamanio tiene la cantidad de caracteres, no seria lo mismo que poner tamanio directamente? porque cada char ocupa un byte?
            strcpy((* p_usuario)[i].Productos->TipoProducto, TiposProductos[aleatorio]);
            (* p_usuario)[i].Productos->PrecioUnitario = 10 + rand() % 91;
            (* p_usuario)[i].Productos[j];
        }
            printf("Cantidad Productos A Pedir son %d \n", (* p_usuario)[i].CantidadProductosAPedir);
            printf("Tipo de producto: %s \n", (* p_usuario)[i].Productos->TipoProducto);
    }
    

    getchar();
};
/*
int CostoTotal(){

};*/