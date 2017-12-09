#ifndef LIBRERIAS_H_INCLUDED
#define LIBRERIAS_H_INCLUDED

const unsigned N = 800;
struct Stack
{
	array<string,N>a;
	unsigned i = 0;
};

//-----------------
string accion, a;
bool mientras=true;
Stack ant,post;


void recuperarLaanteriorURL(Stack& pila);
void recuperarLaposteriorURL(Stack& pila);
void guardar(Stack&, string);
void desplegarOpciones();
void leerLinea();
char accionar(string x);
string mostrar(string accion);
void terminar();
void ejecutar();
unsigned length(const Stack& pila);
//-----------------
void Push(Stack&, string);
string Pop(Stack&);


void ejecutar()
{
    do
    {   desplegarOpciones();
	}while(mientras);

	system("PAUSE");
}

void guardar(Stack& pila,string texto)
{
    Push(pila,accion);
}
char accionar(string accion)
{
    if(accion =="e" or accion =="E")
    {
        cout<<"\nExit\n\n";
        terminar();
    }
    else if(accion =="b" or accion =="B")
    {
        cout<<"\nBack\n\n";
        if(length(ant)>0)
        {
             cout<<"Ir a la Url anterior:";
             recuperarLaanteriorURL(ant);

        }
       else
            cout<<"No hay URL anterior\n";

    }
    else if(accion =="f" or accion =="F")
    {
        cout<<"\nFordward\n\n";
        if(length(post)>0)
        {
            cout<<"\nIr a la Url posterior:";
            recuperarLaposteriorURL(post);

        }
        else
            cout<<"No hay URL posterior\n";
    }
    else
    {
        cout<<"\nGuardar\n\n";
        cout<<"\nGuardar:";
            guardar(ant,accion);
            mostrar(accion);
    }


}
void desplegarOpciones()
{

	cout << "Ingrese la accion o una URL:\n Back:     \"B\"\n Fordward: \"F\"\n Exit      \"E\"\n\n";
	leerLinea();


	accionar(accion);
}

void recuperarLaanteriorURL(Stack& pila)//definir
{
    a=Pop(ant);
    cout<<"  URL:www."<<a<<".com\n\n";

    Push( post, a);

}
void recuperarLaposteriorURL(Stack& pila)
{
    cout<<"  URL:www."<<Pop(post)<<".com\n\n";

}
void leerLinea()
{
	cin >> accion;
}
string mostrar(string url)
{
   cout<<"  URL:www."<<accion<<".com\n\n";
}

void terminar ()
{
    mientras=false;
}
//--------------
void Push(Stack& p, string x)
{
	p.a.at(p.i) = x;
	++p.i;
}
string Pop(Stack& p)
{
	--p.i;
	return p.a.at(p.i);
}
unsigned length(const Stack& s)
{
	return s.i;
}


#endif // LIBRERIAS_H_INCLUDED
