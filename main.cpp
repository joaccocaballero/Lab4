#include "include/Factory.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

void casosDeUso() {
    cout << endl;
    cout << "Ingresar caso de uso" << endl;
    cout << "1: Alta de Usuario" << endl;
    cout << "2: Consulta de Usuario" << endl;
    cout << "3: Alta de Idioma" << endl;
    cout << "4: Consultar Idiomas" << endl;
    cout << "5: Alta de Curso" << endl;
    //cout << "6: Agregar Lección" << endl;
    //cout << "7: Agregar Ejercicio" << endl;
    //cout << "8: Habilitar Curso" << endl;
    //cout << "9: Eliminar Curso" << endl;
    //cout << "10: Consultar Curso" << endl;
    //cout << "11: Inscribirse a Curso" << endl;
    //cout << "11: Realizar Ejercicio" << endl;
    //cout << "12: Consultar Estadísticas" << endl;
    //cout << "13: Suscribirse a Notificaciones" << endl;
    //cout << "14: Consulta de Notificaciones" << endl;
    //cout << "15: Eliminar Suscripciones" << endl;
    cout << "16: Salir" << endl;
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
            case 5: {
                set<string> listadoProfesores = ControladorUsuario->obtenerProfesores();
                cout << "Seleccione un profesor:" << endl;
                string profesorSeleccionado = "";
                // imprimo nombre de los profesores
                for (string nombre: listadoProfesores) {
                    cout << nombre << endl;
                }
                cin >> profesorSeleccionado;
                if (!(listadoProfesores.count(profesorSeleccionado))) {
                    cout << "Seleccione un profesor valido:" << endl;
                    cin >> profesorSeleccionado;
                }
                string nombreCurso = "";
                string descripcion = "";
                int idDificultad = 1;
                
                // ingreso Datos
                cout << "Ingrese Nombre curso:" << endl;
                cin >> nombreCurso;
                cout << "Ingrese Descripcion curso:" << endl;
                cin >> descripcion;
                cout << "Seleccione Dificultad:" << endl;
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

                cout << "Seleccione el idioma del curso:" << endl;
                set<string> idiomas = ControladorUsuario->obtenerIdiomasProfesor(profesorSeleccionado);
                string idiomaSeleccionado = "";
                // imprimo nombre de los idiomas
                for (string nombre: idiomas) {
                    cout << "-"+nombre << endl;
                }
                cin >> idiomaSeleccionado;
                ControladorCurso->seleccionarIdioma(idiomaSeleccionado);

                int agregarPrevias = 1;

                cout << "Desea agregar cursos previos? Ingrese un numero:" << endl;
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
                        // imprimo nombre de los cursos previos
                        for (string nombre : cursosHabilitados) {
                          cout << "-" + nombre << endl;
                        }
                        cin >> nombreCurso;
                        cursosPrevios.insert(nombreCurso);
                        do{
                          cout << "Desea Agregar otro? Ingrese un numero:"
                               << endl;
                          cout << "1- Si" << endl;
                          cout << "2- No" << endl;
                          cin >> seguirAgregando;
                          if(seguirAgregando==1){
                            string nombreCurso;
                            cout << "Ingrese nombre del curso: " << endl;
                            // imprimo nombre de los cursos previos
                            for (string nombre : cursosHabilitados) {
                              cout << "-" + nombre << endl;
                            }
                            cin >> nombreCurso;
                            cursosPrevios.insert(nombreCurso);
                          }
                        }
                        while(seguirAgregando==1);
                    }
                    ControladorCurso->ingresarCursosPrevios(cursosPrevios);
                }
                ControladorCurso->confirmarAltaCurso();
                break;
            }
            
            //AltaUsuario
            case 1: {
                string Nickname = "";
                string Contrasenia = "";
                string Nombre = "";
                string Descripcion = "";

                // ingreso datos usuario
                cout << "Ingrese Nickname del Usuario:" << endl;
                cin >> Nickname;
                cout << "Ingrese una contraseña:" << endl;
                cin >> Contrasenia;
                cout << "Ingrese Nombre del Usuario:" << endl;
                cin >> Nombre;
                cout << "Ingrese Descripcion del Usuario:" << endl;
                cin >> Descripcion;

                ControladorUsuario->ingresarDatosUsuario(Nickname, Contrasenia,
                                                         Nombre, Descripcion);

                int tipoUsuario = 0;
                // Profesor o Estudiante
                cout << "Seleccione Tipo de Usuario:" << endl;
                cout << "1- Estudiante..." <<  endl;
                cout << "2- Profesor..." << endl;
                cin >> tipoUsuario;

                bool existeUsuario = true;

                if (tipoUsuario == 1) {
                    string paisResi = "";
                    int Anio = 0;
                    int Mes = 0;
                    int Dia = 0;
                    // Ingreso Datos Estudiante
                    cout << "Ingrese Pais de Residencia:" << endl;
                    cin >> paisResi;
                    cout << "Ingrese Año de Nacimiento:" << endl;
                    cin >> Anio;
                    cout << "Ingrese Mes de Nacimiento:" << endl;
                    cin >> Mes;
                    cout << "Ingrese Dia de Nacimiento:" << endl;
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
                    cout << "Ingrese Instituto del Profesor:" << endl;
                    cin >> Instituto;
                    ControladorUsuario->ingresarInstituto(Instituto);
                    cout << "Ingrese Idioma que desea que se especialice:"<< endl;
                    // Obtengo Idiomas Disponibles
                    set<string> idiomasDispo = ControladorUsuario->obtenerIdiomasDisponibles();
                    
                    // imprimo nombre de los idiomas
                    set<string> idiomasSelec = {};
                    for (string nombre : idiomasDispo) {
                        cout << "-"+nombre << endl;
                    }
                    string iter = "";
                    cin >> iter;
                    idiomasSelec.insert(iter);
                    int Agregar = 0;
                    cout << "Desea agregar mas idiomas?" << endl;
                    cout << "1- Si " << endl;
                    cout << "2- No " << endl;
                    cin >> Agregar;
                    while (Agregar == 1) {
                        cout << "Ingrese Idioma que desea que se especialice:"
                             << endl;
                        // imprimo nombre de los idiomas
                        for (string nombre : idiomasDispo) {
                          cout << "-" + nombre << endl;
                        }
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
                }else {
                    cout << "Usuario creado exitosamente!" << endl;
                }
                break;
            }

            //Consultar Usuario
            case 2: {
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                cout << "Seleccione un usuario" << endl;
                std::set<string>::iterator it;
                for (it= usuarios.begin(); it!=usuarios.end(); ++it) {
                    string elem = *it;
                    cout << "-"+elem << endl;
                }
                string usuarioSeleccionado = "";
                cin >> usuarioSeleccionado;
                ControladorUsuario->obtenerInfoUsuario(usuarioSeleccionado);
                break;
            }
            //AltaIdioma
            case 3: {
                bool seIngresaNuevo = false;
                while (seIngresaNuevo == false) {
                    string nuevoIdioma = "";
                    bool flagNuevoIdioma = false;
                    cout << "Ingrese nuevo Idioma:" << endl;
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
                break;
            }
            
            // Consultar Idiomas
            case 4: {
                std::set<string> idiomasDisponibles = ControladorUsuario->obtenerIdiomasDisponibles();
                cout << "Los idiomas disponibles son los siguientes." << endl;
                std::set<string>::iterator it;
                for (it= idiomasDisponibles.begin(); it!=idiomasDisponibles.end(); ++it) {
                    string elem = *it;
                    cout << "-"+elem << endl;
                }
            }
            case 16:{
                return 0;
            }
               
            default:{
                cout << "" << endl;
                cout << "Ingrese una opción correcta..." << endl;
            } 
        }


    }
    return 0;
}