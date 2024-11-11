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
