#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

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
 const int maxr = 200;
  const int maxcli = 200; 
  Vehiculos vehiculos[maxv]; 
  Cliente clientes[maxcli]; 
  Repuestos repuestos[maxr];

  int cantidadv = 0; 
  int cantidadC = 0;
   int cantidadR = 0;//preferi unir esto para poder ver los errores mas facilmente

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

  
void cargarR(Repuestos repuestos[], int &cantidadR) {
    const string ArchivoTexto = "repuestos.csv";
    ifstream archivoTexto(ArchivoTexto);
    if (!archivoTexto) {
        cerr << "No se pudo abrir el archivo de repuestos." << endl;
        return;
    }
    Repuestos repuesto;
    string l;

    getline(archivoTexto, l);

    while (getline(archivoTexto, l) && cantidadR < maxr) {
        stringstream ss(l);
        string cam;

        getline(ss, repuesto.modelo_carro, ',');
        getline(ss, repuesto.marca, ',');
        getline(ss, repuesto.nombre, ',');
        getline(ss, repuesto.modelo, ',');

        getline(ss, cam, ',');
        try {
            repuesto.year_carro = stoi(cam);
        } catch(const invalid_argument &e) {
            cerr << "Error en 'year_carro': " << endl;
            continue;
        }
        getline(ss, cam, ',');
        try {
            repuesto.precio = stof(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en 'precio': " << cam << " no es un numero valido." << endl;
            continue;
        }

        getline(ss, cam, ',');
        try {
            repuesto.existencias = stoi(cam);  
        } catch (const invalid_argument &e) {
            cerr << "Error en 'existencias': " << cam << " no es un numero valido." << endl;
            continue;
        }

        repuestos[cantidadR++] = repuesto;
    }
    archivoTexto.close();
    cout << "Datos de repuestos leidos correctamente." << endl;
}

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
void guardarVehiculos() {
    ofstream archivo("vehiculos.csv");
    for (int i = 0; i < cantidadv; i++) {
        archivo << vehiculos[i].modelo << "," << vehiculos[i].marca << "," << vehiculos[i].placa << "," 
                << vehiculos[i].color << "," << vehiculos[i].year << "," << vehiculos[i].kilometraje << ","
                << vehiculos[i].rentado << "," << vehiculos[i].motor << "," << vehiculos[i].precio_renta << ","
                << vehiculos[i].ced_cliente << "," << vehiculos[i].fecha_rentado.dia << "/"
                << vehiculos[i].fecha_rentado.mes << "/" << vehiculos[i].fecha_rentado.year << "\n";
    }
    archivo.close();
    cout << "Datos de vehiculos guardados correctamente.\n";
}

void guardarClientes() {
    ofstream archivo("clientes.csv");
    for (int i = 0; i < cantidadC; i++) {
        archivo << clientes[i].ci << "," << clientes[i].nombre << "," << clientes[i].apellido << ","
                << clientes[i].email << "," << clientes[i].cantidad_de_vehiculos_rentados << ","
                << clientes[i].direccion << "," << clientes[i].activo << "\n";
    }
    archivo.close();
    cout << "Datos de clientes guardados correctamente.\n";
}

void guardarRepuestos() {
    ofstream archivo("repuestos.csv");
    for (int i = 0; i < cantidadR; i++) {
        archivo << repuestos[i].modelo << "," << repuestos[i].marca << "," << repuestos[i].nombre << ","
                << repuestos[i].modelo_carro << "," << repuestos[i].year_carro << ","
                << repuestos[i].precio << "," << repuestos[i].existencias << "\n";
    }
    archivo.close();
    cout << "Datos de repuestos guardados correctamente.\n";
}
void insertarVehiculo() {
    if (cantidadv < maxv) {
        Vehiculos vehi;
        cout << "Ingrese modelo: ";
        cin >> vehi.modelo;
        cout << "Ingrese marca: ";
        cin >> vehi.marca;
        cout << "Ingrese placa: ";
        cin >> vehi.placa;
        cout << "Ingrese color: ";
        cin >> vehi.color;
        cout << "Ingrese año: ";
        cin >> vehi.year;
        cout << "Ingrese kilometraje: ";
        cin >> vehi.kilometraje;
        cout << "Está rentado? (si/no): ";
        cin >> vehi.rentado;
        cout << "Ingrese motor: ";
        cin >> vehi.motor;
        cout << "Ingrese precio de renta: ";
        cin >> vehi.precio_renta;
        cout << "Ingrese cédula del cliente: ";
        cin >> vehi.ced_cliente;
        cout << "Ingrese fecha de renta (dia mes año): ";
        cin >> vehi.fecha_rentado.dia >> vehi.fecha_rentado.mes >> vehi.fecha_rentado.year;

        vehiculos[cantidadv++] = vehi;
        cout << "Vehiculo insertado correctamente." << endl;
    } else {
        cout << "No hay espacio para mas vehículos." << endl;
    }
    guardarVehiculos();
}

void insertarCliente() {
    if (cantidadC < maxcli) {
        Cliente cli;
        cout << "Ingrese cedula: ";
        cin >> cli.ci;
        cout << "Ingrese nombre: ";
        cin >> cli.nombre;
        cout << "Ingrese apellido: ";
        cin >> cli.apellido;
        cout << "Ingrese email: ";
        cin >> cli.email;
        cout << "Cantidad de vehiculos rentados: ";
        cin >> cli.cantidad_de_vehiculos_rentados;
        cout << "Ingrese direccion: ";
        cin >> cli.direccion;
        cout << "Está activo? (si/no): ";
        cin >> cli.activo;

        clientes[cantidadC++] = cli;
        cout << "Cliente insertado correctamente." << endl;
    } else {
        cout << "No hay espacio para mas clientes." << endl;
    }
    guardarClientes();
}

void insertarRepuesto() {
    if (cantidadR < maxr) {
        Repuestos rep;
        cout << "Ingrese modelo: ";
        cin >> rep.modelo;
        cout << "Ingrese marca: ";
        cin >> rep.marca;
        cout << "Ingrese nombre del repuesto: ";
        cin >> rep.nombre;
        cout << "Ingrese modelo de carro: ";
        cin >> rep.modelo_carro;
        cout << "Ingrese year de carro: ";
        cin >> rep.year_carro;
        cout << "Ingrese precio: ";
        cin >> rep.precio;
        cout << "Ingrese existencias: ";
        cin >> rep.existencias;

        repuestos[cantidadR++] = rep;
        cout << "Repuesto insertado correctamente." << endl;
    } else {
        cout << "No hay espacio para mas repuestos." << endl;
    }
    guardarRepuestos();
}
string normalizarPlaca(string placa) { 
 placa.erase(remove_if(placa.begin(), placa.end(), ::isspace), placa.end());
 transform(placa.begin(), placa.end(), placa.begin(), ::toupper); return placa; }

void modificarVehiculo(Vehiculos vehiculos[], int cantidadv) {
     string placa; cout << "Ingrese la placa del vehículo a modificar: ";
      cin >> placa; placa = normalizarPlaca(placa); 
     bool encontrado = false; for (int i = 0; i < cantidadv; i++) 
     { string placaVehiculo = normalizarPlaca(vehiculos[i].placa); 
     if (placaVehiculo == placa) { encontrado = true; cout << "Vehiculo encontrado, ingrese los nuevos datos.\n"; cout << "Nuevo modelo: ";
     cin >> vehiculos[i].modelo;
     cout << "Nueva marca: ";
     cin >> vehiculos[i].marca; 
     cout << "Nuevo color: "; cin >> vehiculos[i].color; cout << "Nuevo year: ";
     cin >> vehiculos[i].year; cout << "Nuevo kilometraje: ";
      cin >> vehiculos[i].kilometraje; cout << "Nuevo estado de renta (si/no): "; 
      cin >> vehiculos[i].rentado;
     cout << "Nuevo motor: ";
     cin >> vehiculos[i].motor;
     cout << "Nuevo precio de renta: ";
     cin >> vehiculos[i].precio_renta;
     cout << "Nuevo cliente (cédula): "; 
     cin >> vehiculos[i].ced_cliente;
     cout << "Vehículo modificado correctamente." << endl; 
    break; }
    } if (!encontrado) { cout << "No se encontró el vehículo con esa placa." << endl; }
       guardarVehiculos();}

void modificarCliente() {
    int ci;
    cout << "Ingrese la cedula del cliente a modificar: ";
    cin >> ci;

    bool encontrado = false;
    for (int i = 0; i < cantidadC; i++) {
        if (clientes[i].ci == ci) {
            encontrado = true;
            cout << "Cliente encontrado, ingrese los nuevos datos.\n";
            cout << "Nuevo nombre: ";
            cin >> clientes[i].nombre;
            cout << "Nuevo apellido: ";
            cin >> clientes[i].apellido;
            cout << "Nuevo email: ";
            cin >> clientes[i].email;
            cout << "Nueva cantidad de vehiculos rentados: ";
            cin >> clientes[i].cantidad_de_vehiculos_rentados;
            cout << "Nueva dirección: ";
            cin >> clientes[i].direccion;
            cout << "Nuevo estado (activo/inactivo): ";
            cin >> clientes[i].activo;
            cout << "Cliente modificado correctamente." << endl;
            break;
        }
        guardarClientes();
    }

    if (!encontrado) {
        cout << "No se encontro el cliente con esa cedula." << endl;
    }
    guardarClientes();
}

void modificarRepuesto() {
    string modelo;
    cout << "Ingrese el modelo del repuesto a modificar: ";
    cin >> modelo;

    bool encontrado = false;
    for (int i = 0; i < cantidadR; i++) {
        if (repuestos[i].modelo == modelo) {
            encontrado = true;
            cout << "Repuesto encontrado, ingrese los nuevos datos.\n";
            cout << "Nuevo modelo: ";
            cin >> repuestos[i].modelo;
            cout << "Nueva marca: ";
            cin >> repuestos[i].marca;
            cout << "Nuevo nombre del repuesto: ";
            cin >> repuestos[i].nombre;
            cout << "Nuevo modelo de carro: ";
            cin >> repuestos[i].modelo_carro;
            cout << "Nuevo year de carro: ";
            cin >> repuestos[i].year_carro;
            cout << "Nuevo precio: ";
            cin >> repuestos[i].precio;
            cout << "Nuevas existencias: ";
            cin >> repuestos[i].existencias;
            cout << "Repuesto modificado correctamente." << endl;
            break;
        }
       
    }

    if (!encontrado) {
        cout << "No se encontro el repuesto con ese modelo." << endl;
    }
     guardarRepuestos();
}
void eliminarVehiculo() {
    string placa;
    cout << "Ingrese la placa del vehiculo a eliminar: ";
    cin >> placa;

    bool encontrado = false;
    for (int i = 0; i < cantidadv; i++) {
        if (vehiculos[i].placa == placa) {
            encontrado = true;
            for (int j = i; j < cantidadv - 1; j++) {
                vehiculos[j] = vehiculos[j + 1];
            }
            cantidadv--;
            cout << "Vehiculo eliminado correctamente." << endl;
            break;
        }
       
    }

    if (!encontrado) {
        cout << "No se encontro el vehiculo con esa placa." << endl;
    }
     guardarVehiculos();
    
}

void eliminarCliente() {
    int ci;
    cout << "Ingrese la cedula del cliente a eliminar: ";
    cin >> ci;

    bool encontrado = false;
    for (int i = 0; i < cantidadC; i++) {
        if (clientes[i].ci == ci) {
            encontrado = true;
            for (int j = i; j < cantidadC - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            cantidadC--;
            cout << "Cliente eliminado correctamente." << endl;
            break;
        }
       
    }
    if (!encontrado) {
        cout << "No se encontro el cliente con esa cedula." << endl;
    }
    guardarClientes();}

 void eliminarRepuesto() {
    string modelo;
    cout << "Ingrese el modelo del repuesto a eliminar: ";
    cin >> modelo;

    bool encontrado = false;
    for (int i = 0; i < cantidadR; i++) {
        if (repuestos[i].modelo == modelo) {
            encontrado = true;
            for (int j = i; j < cantidadR - 1; j++) {
                repuestos[j] = repuestos[j + 1];
            }
            cantidadR--;
            cout << "Repuesto eliminado correctamente." << endl;
            break;
        }
       
    }

    if (!encontrado) {
        cout << "No se encontro el repuesto con ese modelo." << endl;
    }
    guardarRepuestos();
}

void gestionarAccion(int archivoSeleccionado) {
    int opcion;
    do {
        cout << "Elija una opcion:\n";
        cout << "1. Cargar datos\n";
        cout << "2. Insertar datos\n";
        cout << "3. Modificar datos\n";
        cout << "4. Eliminar datos\n";
        cout << "5. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (archivoSeleccionado == 1) {
                    CV(vehiculos, cantidadv);
                    for (int i = 0; i < cantidadv; ++i) { 
                        const Vehiculos &vehi = vehiculos[i];
                        cout << "Modelo: " << vehi.modelo << ", Marca: " << vehi.marca
                             << ", Placa: " << vehi.placa << ", Color: " << vehi.color
                             << ", year: " << vehi.year << ", Kilometraje: " << vehi.kilometraje
                             << ", Rentado: " << vehi.rentado << ", Motor: " << vehi.motor
                             << ", Precio renta: " << vehi.precio_renta
                             << ", Cedula Cliente: " << vehi.ced_cliente
                             << ", Fecha rentado: " << vehi.fecha_rentado.dia << "/"
                             << vehi.fecha_rentado.mes << "/" << vehi.fecha_rentado.year << endl;
                    }
                } else if (archivoSeleccionado == 2) {
                    cargarC(clientes, cantidadC);
                    for (int i = 0; i < cantidadC; ++i) {
                        const Cliente &cli = clientes[i];
                        cout << "CI: " << cli.ci << ", Nombre: " << cli.nombre 
                             << ", Apellido: " << cli.apellido << ", Email: " << cli.email 
                             << ", Cantidad Vehiculos Rentados: " << cli.cantidad_de_vehiculos_rentados 
                             << ", Direccion: " << cli.direccion 
                             << ", Activo: " << cli.activo << endl;
                    }
                } else if (archivoSeleccionado == 3) {
                    cargarR(repuestos, cantidadR);
                    for (int i = 0; i < cantidadR; ++i) {
                        const Repuestos &repuesto = repuestos[i];
                        cout << "Modelo: " << repuesto.modelo << ", Marca: " << repuesto.marca 
                             << ", Nombre: " << repuesto.nombre << ", Modelo Carro: " << repuesto.modelo_carro 
                             << ", year Carro: " << repuesto.year_carro << ", Precio: " << repuesto.precio 
                             << ", Existencias: " << repuesto.existencias << endl;
                    }
                }
                break;

            case 2:
                if (archivoSeleccionado == 1) insertarVehiculo();
                else if (archivoSeleccionado == 2) insertarCliente();
                else if (archivoSeleccionado == 3) insertarRepuesto();
                break;
            case 3:
                if (archivoSeleccionado == 1) modificarVehiculo(vehiculos, cantidadv);
                else if (archivoSeleccionado == 2) modificarCliente();
                else if (archivoSeleccionado == 3) modificarRepuesto();
                break;
            case 4:
                if (archivoSeleccionado == 1) eliminarVehiculo();
                else if (archivoSeleccionado == 2) eliminarCliente();
                else if (archivoSeleccionado == 3) eliminarRepuesto();
                break;
            case 5:
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 5);
}

void mostrarMenuPrincipal() {
    cout << "\nSeleccione el archivo que desea modificar:\n";
    cout << "1. Vehiculos\n";
    cout << "2. Clientes\n";
    cout << "3. Repuestos\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
}


int main (){
   
    int archivoSeleccionado;
    do {
        mostrarMenuPrincipal();
        cin >> archivoSeleccionado;
        if (archivoSeleccionado >= 1 && archivoSeleccionado <= 3) {
            gestionarAccion(archivoSeleccionado);
        } else if (archivoSeleccionado == 4) {
            cout << "Saliendo...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (archivoSeleccionado != 4);
    return 0;
}