#include "Ventas.h"
#include "Productos.h"

#define SALTO 2

bool compararFecha(Sfecha f1, Sfecha f2);
void Burbuja(producto **prods, int inicio, int fin);
void intercambiar(producto **p1, producto **p2);


void ventas::posicionar(int i , char tipo)
{
    if(tipo=='r' || tipo=='R')
        detalle.seekg(sizeof(venta)*i , ios::beg);

    if(tipo=='w' || tipo=='W')
        detalle.seekp(sizeof(venta)*i , ios::beg);
}

bool ventas::asignar(cadena Fichero, cadena FicheroResumen)
{
    bool asignado = true;
    detalle.open(Fichero ,ios::in|ios::out|ios::binary);
    strcpy(ficheroresumen, FicheroResumen);
    strcpy(fichero, Fichero);

    if(detalle.fail()) //si el fichero no existe, debo crearlo
    {
        detalle.close();
        detalle.clear();

        detalle.open(Fichero , ios::out | ios::binary); // creamos el fichero
        detalle.close();

        detalle.open(Fichero , ios::in | ios::out | ios::binary);

        if(detalle.fail())
        {
            cout << "Error en la creacion del fichero" << endl;
            asignado = false;
        }
    }


    detalle.close();
    detalle.clear();

    return asignado;
}

void ventas::mostrarventas()
{
    venta ven;
    detalle.close();
    detalle.clear();
    detalle.open(fichero , ios::in|ios::binary);
    //posicionar(0,'r');
    //detalle.seekg(0 , ios::beg);

    detalle.read((char *)&ven,sizeof(ven)); //lectura anticipada

    while(!detalle.eof())
    {
        cout << "Fecha de venta: " << ven.fecha.dia << "/" << ven.fecha.mes << "/" << ven.fecha.anno << endl;
        cout << "Producto: " << ven.producto << endl; //Modificar esto para que salga el nombre del producto
        cout << "Unidades: " << ven.unidades << endl ;
        cout << "Importe: " << ven.importe << endl;
        cout << "____________________________________" << endl;
        //Muestro la venta
        detalle.read((char *)&ven , sizeof(ven));
    }
    detalle.close();
}

void ventas::anadirventa(int num)
{
    detalle.open(fichero, ios::in|ios::out|ios::binary);
   // posicionar(0 , 'r');
    bool encontrado = false;
    venta ven , vaux;
    int pos;

    ven.producto = num;
    cout << "Introduzca unidades vendidas: ";
    cin >> ven.unidades;

    cout << "Introduzca importe de la venta: " ;
    cin >> ven.importe;

    cout << "Introduzca fecha de la venta(dd/mm/yyyy): " << endl;
    cout << "Día: ";
    cin >> ven.fecha.dia;
    cout << "Mes: ";
    cin >> ven.fecha.mes;
    cout << "Anio: ";
    cin >> ven.fecha.anno;

    detalle.read((char *)&vaux , sizeof(vaux)); //Lectura anticipada
    pos=0; //inicializamos la variable pos (posicion)

    while(!encontrado && !detalle.eof())
    {
        if(compararFecha(vaux.fecha,ven.fecha))//true si vaux(lo que leemos de fichero) > ven (lo que introducimos por teclado)
            encontrado = true;
        else
        {
            pos++;
            detalle.read((char *)&vaux, sizeof(vaux));
        }
    }

    if(encontrado) //
    {
        cout << "Encontrado = true"<<endl;
        system("pause");
        posicionar(pos ,'w');
        detalle.write((char *)&ven , sizeof(ven));
    }
    else
    {
        cout << "Encontrado = false"<<endl;
        system("pause");
        //posicionar(pos,'w');
        //detalle.seekp(0,ios::end);
        detalle.write((char *)&ven , sizeof(ven));
    }



    /*detalle.seekg(0,ios::end);
    int posicion = detalle.tellg();

    posicionar(posicion-sizeof(venta) ,'w');*/

    //detalle.write((char *)&ven ,sizeof(ven));

    //detalle.read((char *)&vaux , sizeof(vaux)); // lectura anticipada

    //if()

    /*while(!encontrado && !detalle.eof())
    {
        if(ven.producto == num)
            encontrado = true;
        detalle.read((char *)&ven , sizeof(ven));
    }*/

    /*if(encontrado)
        cout << "Ya existe un producto con ese codigo" << endl;
    else
    {
        cout << "Introduzca unidades vendidas: ";
        cin >> pUnidades;

        cout << "\nIntroduzca importe de la venta: ";
        cin >> pImporte;

        cout << "\nIntroduzca fecha de la venta(dd/mm/yyyy): " << endl;
        cout << "Dia: " ;
        cin >> pFecha.dia;
        cout << "Mes: ";
        cin >> pFecha.mes;
        cout << "Anio: " ;
        cin >> pFecha.anno;*/

        //Ordenar segun la fecha introducida en el fichero


    detalle.close();
}



void ventas::resumirfichero()
{
    Sfecha ultimaventa;
    int unidades_actualizado , importe_actualizado;
    fstream prod;
    venta vaux;
    producto pro;

    detalle.open(fichero,ios::in|ios::binary);
    prod.open(ficheroresumen , ios::in|ios::out|ios::binary);

    prod.seekg(0,ios::end);
    int tamanoprod = prod.tellg()/sizeof(producto); //con esto calculamos el numero de productos que tenemos
    cout << tamanoprod << endl;
    system("pause");
    prod.seekg(0,ios::beg);

    unidades_actualizado = 0;
    importe_actualizado = 0;
    ultimaventa.dia = 0;
    ultimaventa.mes = 0;
    ultimaventa.anno = 0;

    prod.read((char *)&pro , sizeof(producto)); //Lectura anticipada del fichero de productos
    int i=0;

    while(!prod.eof())
    {
        posicionar(0,'r');
        detalle.read((char *)&vaux ,sizeof(venta)); //Lectura anticipada del fichero de ventas
        while(!detalle.eof())
        {
            if(vaux.producto == pro.producto)
            {
                pro.importe+=vaux.importe;
                pro.unidades+=vaux.unidades;
                if(compararFecha(vaux.fecha,pro.ultimaventa)) //true si vaux.fecha > pro.ultimaventa
                {
                    pro.ultimaventa.dia = vaux.fecha.dia;
                    pro.ultimaventa.mes = vaux.fecha.mes;
                    pro.ultimaventa.anno = vaux.fecha.anno;
                }
            }
        }

        prod.seekp(tamanoprod*i , ios::beg);
        prod.write((char *)&pro ,sizeof(pro));
        i++;
    }

    detalle.close();
    prod.close();


    ///Otra forma intentada

    /*detalle.read((char *)&vaux , sizeof(venta));

    for(int i=1 ; i<=tamanoprod ; i++)
    {
        while(!detalle.eof())
        {
            if(vaux.producto = i)
            {
                importe_actualizado+=vaux.importe;
                unidades_actualizado+=vaux.unidades;
                if(compararFecha(vaux.fecha , ultimaventa))//true si vaux.fecha > ultimaventa
                {
                    ultimaventa.dia = vaux.fecha.dia;
                    ultimaventa.mes = vaux.fecha.mes;
                    ultimaventa.anno = vaux.fecha.anno;
                }
            }

            prod.read((char *)&pro , sizeof(producto));
            detalle.read((char *)&vaux,sizeof(venta));
        }
    }*/

    /*detalle.read((char *)&vaux , sizeof(venta));

    //Tenemos que recorrer el fichero de ventas tantas veces como productos distintos tengamos

    while(!detalle.eof())
    {

    }

    for(int i=0 ; j<tamaño ; i++)
    {
       // posicionar(i,'r');

       if(vaux.producto == i)
       {

       }
        unidades_actualizado+=vaux.unidades;
        importe_actualizado+=vaux.importe;
    }

    while(!detalle.eof())
    {

    }
*/
    //detalle.close();
}

void ventas::estadisticas(int tipo, int annoini , int annofin)
{
    ifstream prods(ficheroresumen, ios::binary);    //Abrir el resumen
    prods.seekg(0, ios::end);   //ir al final

    int Ntabla = SALTO;
    producto **tabla = new producto*[Ntabla];   //Crear tabla dinamica de punteros a producto con el tamaño de la cantidad de productos totales

    if(tabla == NULL)
    {
        cout << "ERROR al reservar memoria.\n";
    }
    else
    {
        prods.seekg(0, ios::beg);   //Volver al principio del archivo
        int i = 0;  //Variable de contador

        do
        {
            tabla[i] = new producto;
            prods.read((char *) tabla[i], sizeof(producto));    //Cargar los datos

            if(!prods.eof())
            {
                if((*tabla[i]).tipo == tipo &&
                  annoini <= (*tabla[i]).ultimaventa.anno &&   //Si cumple las condiciones avanza el contador, para que no sea remplazada
                  annofin >= (*tabla[i]).ultimaventa.anno)
                {
                    i++;

                    if(i == Ntabla)
                    { //Ampliar SALTO Elementos
                        producto **tablaNueva = new producto*[Ntabla+SALTO];

                        if(tablaNueva == NULL)
                        {
                            cout << "ERROR al reservar memoria.\n";
                            //Aqui podría ir al final del fichero para evitar que el bucle continue
                        }
                        else
                        {
                            for(int j = 0; j < Ntabla; j++)
                                tablaNueva[j] = tabla[j];

                            delete [] tabla;
                            tabla = tablaNueva;
                            Ntabla += SALTO;
                        }
                    }
                }
                else
                    delete tabla[i];
            }
        }while(!prods.eof());
        i--;    //La ultima lectura no fue remplazada o está vacia

        Burbuja(tabla, 0, i);   //Ordena de menor a mayor, porque la voy a leer al reves

        cout << "-------------->Mejor producto<--------------\n\n";
        for(;i >= 0; i--){
            cout << "Fecha de venta: " << (*tabla[i]).ultimaventa.dia <<"/"<< (*tabla[i]).ultimaventa.mes <<"/"<< (*tabla[i]).ultimaventa.anno <<"\n"
                 << "Producto: " << (*tabla[i]).nombre <<"\n"   //El nombre del producto
                 << "Unidades: " << (*tabla[i]).unidades <<"\n"
                 << "Importe: " << (*tabla[i]).importe <<"\n";
            cout << "______________________________________________\n\n";
        }
        delete [] tabla;
    }

    prods.close();
}


bool compararFecha(Sfecha f1, Sfecha f2) //devuelve true si f1 > f2
{
    return f1.anno > f2.anno || (f1.anno == f2.anno && f1.mes > f2.mes )|| (f1.anno == f2.anno && f1.mes == f2.mes && f1.dia > f2.dia);
}

void Burbuja(producto **prods ,int inicio, int fin)
{
    int pos,ele;
    for (pos=inicio; pos<fin; pos++)
        for (ele=fin; ele>pos; ele--)
            if((*prods[ele-1]).importe > (*prods[ele]).importe)
                {
                    cout << "antes: " <<prods[ele-1]->importe<<"\n";
                    intercambiar(&prods[ele-1], &prods[ele]);//Función genérica que tendrá que ser implementada
                    cout << "despues: " <<prods[ele-1]->importe<<"\n";
                }
}

void intercambiar(producto **p1, producto **p2)
{
    producto *aux;

    aux = *p1;
    *p1=*p2;
    *p2=aux;
}
