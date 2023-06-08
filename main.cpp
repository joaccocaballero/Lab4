#include "include/Factory.h"
#include <iostream>
#include <string>
using namespace std;

void casosDeUso() {
    cout << endl;
    cout << "Ingresar caso de uso"<< endl;
    cout << "1: Alta de Curso";
    cout << "2: Alta de Usuario";
    cout << "3: Alta de Idioma";
}

int main() {
   // instancio Fabrica
    Factory * fabrica = fabrica->getInstancia();

    // instancio Controladores
    IControladorUsuario *ControladorUsuario= fabrica->getIControladorUsuario();
    IControladorCurso *ControladorCurso= fabrica->getIControladorCurso();
    
    bool continuarSesion = true;
    while(continuarSesion) {
        // opciones
        casosDeUso();
        //seteo un default
        int caso = 0;
        cin >> caso;
        // armo switch
        switch (caso) {
            //AltaCurso
            case 1: {
                set<string> listadoProfesores = ControladorUsuario->obtenerProfesores();
                cout << "Seleccione un profesor" << endl;
                string profesorSeleccionado = "";
                // imprimo nombre de los profesores
                for (string nombre: listadoProfesores) {
                    cout << nombre << endl;
                }
                cin >> profesorSeleccionado;
                if (!(listadoProfesores.count(profesorSeleccionado))) {
                    cout << "Seleccione un profesor valido" << endl;
                    cin >> profesorSeleccionado;
                }
                string nombreCurso = "";
                string descripcion = "";
                int idDificultad = 1;
                
                // ingreso Datos
                cout << "Ingrese Nombre curso" << endl;
                cin >> nombreCurso;
                cout << "Ingrese Descripcion curso" << endl;
                cin >> descripcion;
                cout << "Seleccione Dificultad" << endl;
                cout << "1- Principiante" << endl;
                cout << "2- Intermedio" << endl;
                cout << "3- Avanzado" << endl;
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
                ControladorCurso->ingresarInfoCurso(nombreCurso, descripcion, dificultad);

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
                    cout << "Seleccione un profesor valido" << endl;
                    cin >> idiomaSeleccionado;
                }
                ControladorCurso->seleccionarIdioma(idiomaSeleccionado);

                int agregarPrevias = 1;

                cout << "Agregar cursos previos? Ingrese un numero" << endl;
                cout << "1- Si" << endl;
                cout << "2 -No" << endl;

                cin >> agregarPrevias;

                if (agregarPrevias == 1) {
                    set<string> cursosHabilitados = ControladorCurso->obtenerCursosHabilitados();
                    int seguirAgregando = 1;
                    set<string> cursosPrevios;
                    while (seguirAgregando==1){
                        string nombreCurso;
                        cout << "Ingrese nombre del curso: " << endl;
                        cin >> nombreCurso;
                        if (cursosHabilitados.count(nombreCurso) && !cursosPrevios.count(nombreCurso)) {
                            cursosPrevios.insert(nombreCurso);
                        }
                        cout << "Agregar otro? Ingrese un numero" << endl;
                        cout << "1- Si" << endl;
                        cout << "2- No" << endl;
                        cin >> seguirAgregando;
                    }
                    ControladorCurso->ingresarCursosPrevios(cursosPrevios);
                }

                ControladorCurso->confirmarAltaCurso();
            }
            
            //AltaUsuario
            case 2: {
                string Nickname = "";
                string Contrasenia = "";
                string Nombre = "";
                string Descripcion = "";

                // ingreso datos usuario
                cout << "Ingrese Nickname del Usuario" << endl;
                cin >> Nickname;
                cout << "Ingrese una contraseña" << endl;
                cin >> Contrasenia;
                cout << "Ingrese Nombre del Usuario" << endl;
                cin >> Nombre;
                cout << "Ingrese Descripcion del Usuario" << endl;
                cin >> Descripcion;

                ControladorUsuario->ingresarDatosUsuario(Nickname, Contrasenia,
                                                         Nombre, Descripcion);

                int tipoUsuario = 0;
                // Profesor o Estudiante
                cout << "Seleccione Tipo de Usuario" << endl;
                cout << "1- Estudiante" <<  endl;
                cout << "2- Profesor" << endl;
                cin >> tipoUsuario;

                bool existeUsuario = true;

                if (tipoUsuario == 1) {
                    string paisResi = "";
                    int Anio = 0;
                    int Mes = 0;
                    int Dia = 0;
                    // Ingreso Datos Estudiante
                    cout << "Ingrese Pais de Residencia" << endl;
                    cin >> paisResi;
                    cout << "Ingrese Año de Nacimiento" << endl;
                    cin >> Anio;
                    cout << "Ingrese Mes de Nacimiento" << endl;
                    cin >> Mes;
                    cout << "Ingrese Dia de Nacimiento" << endl;
                    cin >> Dia;
                    DTFecha Fecha = DTFecha(Dia, Mes, Anio);
                    ControladorUsuario->ingresarDatosEstudiante(paisResi,
                                                                Fecha);
                    // confirmo alta
                    existeUsuario =
                        ControladorUsuario->confirmarAltaEstudiante();
                } else if (tipoUsuario == 2) {
                    // Ingresa Instituto
                    string Instituto = "";
                    cout << "Ingrese Instituto del Profesor" << endl;
                    cin >> Instituto;
                    ControladorUsuario->ingresarInstituto(Instituto);

                    // Obtengo Idiomas Disponibles
                    set<string> idiomasDispo =
                        ControladorUsuario->obtenerIdiomasDisponibles();
                    // imprimo nombre de los profesores
                    set<string> idiomasSelec = {};
                    for (string nombre : idiomasDispo) {
                        cout << nombre << endl;
                    }
                    cout << "Ingrese Idioma que desea que se especialice"
                         << endl;
                    string iter = "";
                    cin >> iter;
                    idiomasSelec.insert(iter);
                    int Agregar = 0;
                    cout << "Desea agregar mas idiomas?" << endl;
                    cout << "1- Si " << endl;
                    cout << "2- No " << endl;
                    cin >> Agregar;
                    while (Agregar == 1) {
                        cout << "Ingrese Idioma que desea que se especialice"
                             << endl;
                        cin >> iter;
                        idiomasSelec.insert(iter);
                        cout << "Desea agregar mas idiomas?" << endl;
                        cout << "1- Si " << endl;
                        cout << "2- No " << endl;
                        cin >> Agregar;
                    }
                    // Agrego especializaciones
                    for (string Nombreidioma : idiomasSelec) {
                        ControladorUsuario->agregarEspecializacion(
                            Nombreidioma);
                    }
                    // Se da de alta profesor
                    existeUsuario = ControladorUsuario->confirmarAltaProfesor();
                }
                if (!existeUsuario) {
                    cout
                        << "El nickname ya se encuentra registrado, elija otro!"
                        << endl;
                }
            }
        
            //AltaIdioma
            case 3: {
                bool seIngresaNuevo = false;
                while (seIngresaNuevo = false) {
                    string nuevoIdioma = "";
                    bool flagNuevoIdioma = false;
                    cout << "Ingrese nuevo Idioma" << endl;
                    cin >> nuevoIdioma;
                    // Me fijo si existe idioma
                    flagNuevoIdioma =
                        ControladorUsuario->agregarIdioma(nuevoIdioma);
                    if (flagNuevoIdioma) {
                        cout << "Idioma ingresado correctamente." << endl;
                        seIngresaNuevo = true;
                    } else {
                        cout << "El idioma ingresado ya existe, ingrese otro."
                             << endl;
                    }
                }
            }
        }
    }
    return 0;
}