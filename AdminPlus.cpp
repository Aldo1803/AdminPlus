#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void createClient(string nombre, string rfc, string direccion, string telefono) {
    ofstream myFile("clients.txt", ios::app);
    myFile << nombre << "," << rfc << "," << direccion << "," << telefono << endl;
    myFile.close();

    cout << "CLIENTE AGREGADO";



}

void getClients() {
    ifstream myFile("clients.txt");
    string myText;
    cout << "Clientes\n" << "*******" << endl;
    while (getline(myFile, myText)) {
        cout << myText << endl;

    }
    cout << "***********" << endl;

    myFile.close();

}

void deleteClient() {
    ifstream myFile("clients.txt");
    ofstream temp("temp.txt");
    vector<string> clients;
    int contador = 0;
    int cliente;
    string myText;
    cout << "Clientes" << "*******" << endl;
    while (getline(myFile, myText)) {

        cout << contador << "*" << myText << endl;
        clients.push_back(myText);
        contador++;

    }
    cout << "Seleccionar cliente a borrar" << endl;
    cin >> cliente;
    while (getline(myFile, myText)) {
        if (myText != clients[cliente]) {
            temp << myText << endl;
        }
    }

    myFile.close();
    temp.close();
    remove("clients.txt");
    rename("temp.txt", "clients.txt");



}

void createProduct(string nombre, string descripcion, double precio) {
    ofstream myFile("products.txt", ios::app);
    myFile << nombre << "," << descripcion << "," << precio << endl;
    myFile.close();

    cout << "PRODUCTO AGREGADO";



}

void getProducts() {
    ifstream myFile("products.txt");
    string myText;
    cout << "Productos\n" << "*******" << endl;
    while (getline(myFile, myText)) {

        cout << myText << endl;

    }
    cout << "************" << endl;
    myFile.close();

}

void deleteProduct() {
    ifstream myFile("products.txt");
    ofstream temp("temp.txt");
    vector<string> clients;
    int contador = 0;
    int cliente;
    string myText;
    cout << "PRODUCTOS" << "*******" << endl;
    while (getline(myFile, myText)) {

        cout << contador << "*" << myText << endl;
        clients.push_back(myText);
        contador++;

    }
    cout << "Seleccionar producto a borrar" << endl;
    cin >> cliente;
    while (getline(myFile, myText)) {
        if (myText != clients[cliente]) {
            temp << myText << endl;
        }
    }

    myFile.close();
    temp.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");



}




int main() {
    int seleccion = 0;
    while (seleccion != 7) {

        cout << "\nADMIN PLUS" << endl << "***********************" << endl;
        cout << "1 Agregar cliente\n" << "2 Eliminar cliente\n" <<
            "3 Ver clientes\n" <<
            "4 Agregar producto\n" << "5 Eliminar producto\n" <<
            "6 Ver productos\n" << "7 Salir" <<
            endl;
        cin >> seleccion;

        if (seleccion == 1) {
            string nombre, rfc, direccion, telefono;
            cin.ignore();
            cout << "Nombre: " << endl;
            getline(cin, nombre);
            cout << "RFC: " << endl;
            getline(cin, rfc);
            cout << "Direccion: " << endl;
            getline(cin, direccion);
            cout << "Telefono: " << endl;
            getline(cin, telefono);

            createClient(nombre, rfc, direccion, telefono);



        }
        else if (seleccion == 2) {
            deleteClient();

        }
        else if (seleccion == 3) {

            getClients();

        }
        else if (seleccion == 4) {
            string nombre, descripcion;
            double precio;
            cin.ignore();
            cout << "Nombre: " << endl;
            getline(cin, nombre);
            cout << "Descripcion: " << endl;
            getline(cin, descripcion);
            cout << "Precio: " << endl;
            cin >> precio;
            createProduct(nombre, descripcion, precio);
        }
        else if (seleccion == 5) {
            deleteProduct();

        }
        else if (seleccion == 6) {
            getProducts();
        }
        else if (seleccion == 7) {
            cout << "Gracias por usar ADMIN PLUS";
        }
        else {
            cout << "Seleccion no valida";
        }

    }




}