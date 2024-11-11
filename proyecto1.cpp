#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int year;

};

struct Vehiculos {
    string modelo;
    string marca;
    string placa;
    string color;
    int year;
    float kilometraje;
    string rentado;
    string motor;
    float precio_renta;
    string ced_cliente;
    Fecha fecha_rentado;

};

struct Cliente
 {
    int ci;
    string nombre;
    string apellido;
    string email;
    int cantidad_de_vehiculos_rentados;
    string direccion;
    string activo;

};

struct Repuestos 
{
    string modelo;
    string marca;
    string nombre;
    string modelo_carro;
    int year_carro;
    float precio;
    int existencias;

};

const int maxv = 200;

void CV(Vehiculos vehiculos[], int &cantidadv) {
    const string ArchivoTexto = "vehiculos.csv";
    ifstream archivoTexto(ArchivoTexto);
    if (!archivoTexto){
        cerr << "No se pudo abrir." << endl;
        return;
    }
    Vehiculos vehi;
    string l;

    getline(archivoTexto, l);

    while (getline(archivoTexto, l) && cantidadv < maxv) {
        stringstream ss(l);
        string cam;
        
        getline(ss, vehi.modelo, ',');
        getline(ss, vehi.marca, ',');
        getline(ss, vehi.placa, ',');
        getline(ss, vehi.color, ',');

        getline(ss, cam, ',');
        try {
            vehi.year = stoi(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'year': " << endl;
            continue;
        }
        getline(ss, cam, ',');
        try {
            vehi.kilometraje = stof(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'kilometraje': " << endl;
            continue;
        }
        getline(ss, vehi.rentado, ',');
        getline(ss, vehi.motor, ',');

        getline(ss, cam, ',');
        try {
             vehi.precio_renta = stof(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en precio_renta: " << endl;
            continue;
        }

        getline(ss, vehi.ced_cliente, ',');

        getline(ss, cam, '/');
        try {
            vehi.fecha_rentado.dia = stoi(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'fecha_rentado.dia': "  << endl;
            continue;
        }

         getline(ss, cam, '/');
        try {
            vehi.fecha_rentado.mes = stoi(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'fecha_rentado.mes': " << endl;
            continue;
        }

        getline(ss, cam, ',');
        try {
            vehi.fecha_rentado.year = stoi(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'fecha_rentado.year': " << endl;
            continue;
        }

        vehiculos[cantidadv++] = vehi;
    }
     archivoTexto.close();
    cout << "Datos leidos desde el archivo exitosamente." << endl;
} 

const int maxr=200;
   void cargarR(Repuestos r[], int &cantidadR){
    const string ArchivoTexto="repuestos.csv";
    ifstream archivoTexto(ArchivoTexto);
    if (!archivoTexto)

    {
        cerr<< "No se pudo abrir el archivo. "<< endl;
        return;
    }
    Repuestos repuesto;
    string l;

    getline(archivoTexto, l);

     while (getline(archivoTexto, l)&& cantidadR<maxr)
    {
        stringstream ss(l);
        string cam;

        getline (ss, repuesto.modelo,',');
        getline (ss, repuesto.marca, ',');
        getline (ss, repuesto.nombre, ',');
        getline (ss, repuesto.modelo_carro, ',');

        getline (ss, cam, ',');
        try
        {
            repuesto.year_carro= stoi(cam);
        }
        catch(const invalid_argument &e)
        {
            cerr << "error en year carro " << '\n';
            continue;
        }
                getline(ss, cam, ',');
        try {
            repuesto.precio = stof(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en 'precio': " << cam << " no es un número válido." << endl;
            continue;
        }

        getline(ss, cam, ',');
        try {
            repuesto.existencias = stoi(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en 'existencias': " << cam << " no es un número válido." << endl;
            continue;
        }
     }

    archivoTexto.close();
    cout << "Datos leidos correctamente. "<< endl;
}
const int maxcli = 200;

void cargarC(Cliente c[], int &cantidadC) {
    const string ArchivoTexto = "clientes.csv";
    ifstream archivoTexto(ArchivoTexto);
    if (!archivoTexto) {
        cerr << "No se pudo abrir el archivo de texto." << endl;
        return;
    }
        
    Cliente cli;
    string l;

    getline(archivoTexto, l);

    while (getline(archivoTexto, l) && cantidadC < maxcli) {
        stringstream ss(l);
        string cam;

        getline(ss, cam, ',');
        try {
            cli.ci = stoi(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en 'ci': "  << endl;
            continue;
        }   
    
  getline(ss, cli.nombre, ',');
        getline(ss, cli.apellido, ',');
        getline(ss, cli.email, ',');

        getline(ss, cam, ',');
        try {
            cli.cantidad_de_vehiculos_rentados = stoi(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en cantidad_de_vehiculos_rentados: " << endl;
            continue;
        }

        getline(ss, cli.direccion, ',');

        getline(ss, cli.activo, ',');


        c[cantidadC++] = cli;
    }

    archivoTexto.close();
    cout << "Datos cargados desde el archivo cvs." << endl;
}
