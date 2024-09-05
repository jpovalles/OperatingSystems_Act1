
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Definir los registros
vector<string> ICR; // Instruction Counter Register
int ACC = 0; // Registro Acumulador
string MAR;// Memory Address Register
string MDR; // Memory Data Register
vector<string> UC;  // Unidad de Control
int PC = 0;  // Program Counter
int ALU = 0;
unordered_map<string, int> memoria; // Simulación de la memoria

vector<string> split(const std::string& cadena) {
    vector<string> resultado;
    string tempo = "";
    int i = 0;
    while (i < cadena.size()) {
        if (cadena[i] == ' ') {
            if (!tempo.empty()) {
                resultado.push_back(tempo);
                tempo = ""; 
            }
        }else {
            tempo += cadena[i];
        }
        i++;
    }if (!tempo.empty()) {
        resultado.push_back(tempo);
    }

    return resultado;
}

vector <vector<string>>guardarinstrucciones(const string& nombreArchivo){
    vector<vector<string>> resultado;
    ifstream archivo(nombreArchivo);
    string linea;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            vector<string> instruccion = split(linea);
            resultado.push_back(instruccion);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << std::endl;
    }
    return resultado;
}
void pause(int PC , int ALU,int ACC, string MAR, string MDR,vector<string> UC,vector<string> ICR,unordered_map<string, int> memoria){
    string optionP;
    int optionF;
    string dirM;
    do{
        cout << "1. Buscar en una direccion de memoria\n";
        cout << "2. Mostrar Registro ICR\n";
        cout << "3. Mostrar Registro MDR\n";
        cout << "4. Mostrar Registro MAR\n";
        cout << "5. Mostrar Registro PC\n";
        cout << "6. Mostrar Registro ALU\n";
        cout << "7. Mostrar Registro ACC\n";
        cout << "8. Mostrar Registro UC\n";
        cout << "9. Salir\n";
        cout << "Elige una opción: ";
        getline(cin, optionP);
        optionF = optionP[0] - '0';
        switch(optionF) {
            case 1:
                cout << "Ingresa la Direccion de memoria: ";
                getline (cin, dirM);
                if(memoria.find(dirM) != memoria.end()) {
                    cout << endl <<"El Dato es: "<< memoria[dirM] << endl;
                } else {
                    cout << "DIRRECCION INVALIDA" << endl;
                }
                break;
            case 2:
                cout << "ICR: ";
                for (int j = 0 ; j < ICR.size(); j++){
                    cout << UC[j] << " ";
                }
                cout << endl;
                break;
            case 3:
                cout << "MDR: " << MDR << endl;                
                break;
            case 4:
                cout << "MAR: " << MAR << endl;
            
                break;
            case 5:
                cout << "PC: " << PC << endl;
                break;
            case 6:
                cout << "ALU: " << ALU << endl;              
                break;
            case 7:
                cout << "ACC: " << ACC << endl;
                break;
            case 8:
                cout << "UC: ";
                for (int j = 0 ; j < UC.size(); j++){
                    cout << UC[j] << " ";
                }
                cout << endl;
                break;
            case 9:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }while(optionF != 9);
}

void ejecutarInstrucciones(vector<vector<string>>& instrucciones,int PC , int ALU,unordered_map<string, int> memoria) {
    for (int i = 0 ; i < instrucciones.size(); i++) {
        PC = i+1;
        MAR = to_string(i);
        MDR = ""; for(int m = 0 ; m < instrucciones[i].size(); m++){ MDR+= instrucciones[i][m];}
        ICR = instrucciones[i];
        UC = ICR;
        if (UC[0]=="SET"){
            memoria[UC[1]] = stoi(UC[2]);
            MAR = UC[1];
            MDR = UC[2];

        } else if (UC[0] == "LDR"){
            MAR = UC[1];
            MDR = to_string(memoria[UC[1]]);
            ACC = stoi(MDR);
        } else if (UC[0] == "ADD"){
            if (UC[3] == "NULL" && UC[2] == "NULL"){
                ALU = ACC;
                MAR = UC[1];
                MDR = to_string(memoria[UC[1]]); 
                ACC = stoi(MDR);
                ALU += ACC;
                ACC = ALU;
            } else if (UC[3] == "NULL") {
                MAR = UC[1];
                MDR = to_string(memoria[UC[1]]);
                ACC = stoi(MDR);
                ALU = ACC;
                MAR = UC[2];
                MDR = to_string(memoria[UC[2]]);
                ACC = stoi(MDR);
                ALU += ACC;
                ACC = ALU;
            }else{
                MAR = UC[1];
                MDR = to_string(memoria[MAR]);
                ACC = stoi(MDR);
                ALU = ACC;
                MAR = UC[2];
                MDR = to_string(memoria[MAR]);
                ACC = stoi(MDR);
                ALU += ACC;
                ACC = ALU;
                MAR = UC[3];
                MDR = to_string(ACC);
                memoria[MAR] = stoi(MDR);
            }
        } else if (UC[0] == "INC") {
            MAR = UC[1];
            MDR = to_string(memoria[MAR]);
            ALU = stoi(MDR) + 1;
            MDR = to_string(ALU);
            memoria[MAR] = stoi(MDR);
            
        } else if (UC[0] == "DEC") {
            MAR = UC[1];
            MDR = to_string(memoria[MAR]);
            ALU = stoi(MDR) - 1;
            MDR = to_string(ALU);
            memoria[MAR] = stoi(MDR);
        } else if (UC[0] == "STR") {
            MAR = UC[1];
            MDR = to_string(ACC);
            memoria[MAR] = stoi(MDR);

        } else if (ICR[0] == "SHW") {
            if (UC[0] == "ACC") {
                cout << "ACC: " << ACC << endl;
            } else if (UC[0] == "ICR") {
                cout << "ICR: ";
                for (int j = 0 ; j < ICR.size(); j++){
                    cout << UC[j] << " ";
                }
                cout << endl;
                
            } else if (UC[0] == "MAR") {
                cout << "MAR: " << MAR << endl;
            } else if (UC[0] == "MDR") {
                cout << "MDR: " << MDR << endl;
            } else if (UC[0] == "UC") {
                cout << "UC: ";
                for (int j = 0 ; j < UC.size(); j++){
                    cout << UC[j] << " ";
                }
                cout << endl;
            } else {
                MAR = UC[1];
                cout << MAR << ": " << memoria[UC[1]] << endl;
            }
        } else if (UC[0] == "PAUSE"){
            pause(PC,ALU,ACC,MAR,MDR,UC,ICR,memoria);
        } else if (UC[0] == "END"){
            break;
        }
    }
}




void cicloBasico(){
    int ban = 1;
    string opcion;
    int com;
    vector<vector<string>> instrucciones = guardarinstrucciones("programa.txt");
    do{
        cout << "1. Ejecutar programa" << endl;
        cout << "2. Salir" << endl;
        cout << "INGRESE LA OPCION DESEADA: ";
        getline(cin, opcion);
        com = opcion[0] - '0';
        switch (com){
        case 1 :
            ejecutarInstrucciones(instrucciones,PC,ALU,memoria);
            break;
        case 2:
            ban = 0;
            break;
        default:
            break;
        }
        
    } while (ban == 1);
}

int main() {
    cicloBasico();
    return 0;
}