#include "include/Factory.h"
using namespace std;
/*
void casosDeUso() {
    cout << endl;
    cout << "Ingresar caso de uso"<< endl;
    cout << "1: Alta Curso";
}*/

int main() {
   // instancio Fabrica
    Factory* fabrica = fabrica.getInstancia();

    // instancio Controladores
    IControladorUsuario *ControladorUsuario=fabrica.getIControladorUsuario();
    IControladorCurso *ControladorCurso=fabrica.getIControladorCurso();
    
    bool continuarSesion = true;
    while(continuarSesion) {
        // opciones
        casosDeUso();
        //seteo un default
        int caso = 0;
        cin >> caso;
        // armo switch
        switch (caso) {
            case 1: {
                set<string> listadoProfesores = ControladorUsuario.obtenerProfesores();
                cout << "Seleccione un profesor" << endl;
                string profesorSeleccionado = "";
                // imprimo nombre de los profesores
                for (string nombre: listadoProfesores) {
                    cout << nombre << endl;
                }
                cin >> profesorSeleccionado;
                if (!(listadoProfesores.count(profesorSeleccionado))) {
                    cout >> "Seleccione un profesor valido" >> endl;
                    cin >> profesorSeleccionado;
                }
                string nombreCurso = "";
                string descripcion = "";
                int idDificultad = 1;
                
                // ingreso Datos
                cout >> "Ingrese Nombre curso" >> endl;
                cin >> nombreCurso;
                cout >> "Ingrese Descripcion curso" >> endl;
                cin >> descripcionCurso;
                cout >> "Seleccione Dificultad" >> endl;
                cout >> "1- Principiante" >> endl;
                cout >> "2- Intermedio" >> endl;
                cout >> "3- Avanzado" >> endl;
                cin >> idDificultad;
                EnumDificultad dificultad = Principiante;
                switch (idDificultad) {
                    case 1:
                        dificultad = Principiante;
                        break;
                    case 2:
                        dificultad = Medio;
                        break;
                    case 3:
                        dificultad = Avanzado;
                        break;
                }
                ControladorCurso.ingresarInfoCurso(nombreCurso, descripcionCurso, dificultad);

                //asignar profesor
                ControladorCurso->asignarProfesor(profesorSeleccionado);

                set<string> idiomas = ControladorUsuario->obtenerIdiomasProfesor(profesorSeleccionado);
                string idiomaSeleccionado = "";
                // imprimo nombre de los profesores
                for (string nombre: idiomas) {
                    cout << nombre << endl;
                }
                cin >> idiomaSeleccionado;
                if (!(idiomas.count(idiomaSeleccionado))) {
                    cout >> "Seleccione un profesor valido" >> endl;
                    cin >> idiomaSeleccionado;
                }
                ControladorCurso->seleccionarIdioma(idiomaSeleccionado);

                int agregarPrevias = 1;
                
                cout >> "Agregar cursos previos? Ingrese un numero" >> endl;
                cout >> "1- Si" >> endl;
                cout >> "2 -No" >> endl;
                
                cin >> agregarPrevias;

                if (agregarPrevias == 1) {
                    set<string> cursosHabilitados = controladorCurso->obtenerCursosHabilitados();
                    int seguirAgregando = 1;
                    set<string> cursosPrevios;
                    while (seguirAgregando==1){
                        string nombreCurso;
                        cout >> "Ingrese nombre del curso: " >>endl;
                        cin >> nombreCurso;
                        if (cursosHablitados.count(nombreCurso) && !cursosPrevios.count(nombreCurso)) {
                            cursosPrevios.insert(nombreCurso);
                        }
                        cout >> "Agregar otro? Ingrese un numero" >> endln;
                        cout >> "1- Si" >> endl;
                        cout >> "2- No" >> endl;
                        cin >> seguirAgregando;
                    }
                    ControladorCurso->ingresarCursosPrevios(cursosPrevios);
                }

                ControladorCurso->confirmarAltaCurso();
            }
        }
    }
    return 0;
}