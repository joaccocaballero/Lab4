#include "include/Factory.h"
#include <iostream>
#include <string>
#include <set>

#include "include/DTProfesor.h"
#include "./include/DTEstudiante.h"
using namespace std;

void casosDeUso() {
    cout << endl;
    cout << "Ingresar caso de uso" << endl;
    cout << "1: Alta de Usuario" << endl;
    cout << "2: Consulta de Usuario" << endl;
    cout << "3: Alta de Idioma" << endl;
    cout << "4: Consultar Idiomas" << endl;
    cout << "5: Alta de Curso" << endl;
    cout << "6: Agregar Lección" << endl;
    cout << "7: Agregar Ejercicio" << endl;
    cout << "8: Habilitar Curso" << endl;
    //cout << "9: Eliminar Curso" << endl;
    //cout << "10: Consultar Curso" << endl;
    //cout << "11: Inscribirse a Curso" << endl;
    //cout << "11: Realizar Ejercicio" << endl;
    //cout << "12: Consultar Estadísticas" << endl;
    //cout << "13: Suscribirse a Notificaciones" << endl;
    //cout << "14: Consulta de Notificaciones" << endl;
    //cout << "15: Eliminar Suscripciones" << endl;
    cout << "16: Cargar datos genéricos" <<endl;
    cout << "17: Salir" << endl;
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
            //AltaUsuario
            case 1: {
              system("clear");
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
              getline(cin >> ws, Nombre);
              cout << "Ingrese Descripcion del Usuario:" << endl;
              getline(cin >> ws, Descripcion);

              ControladorUsuario->ingresarDatosUsuario(Nickname, Contrasenia,
                                                       Nombre, Descripcion);

              int tipoUsuario = 0;
              // Profesor o Estudiante
              cout << "Seleccione Tipo de Usuario:" << endl;
              cout << "1- Estudiante..." << endl;
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
                ControladorUsuario->ingresarDatosEstudiante(paisResi, Fecha);
                // confirmo alta
                existeUsuario = ControladorUsuario->confirmarAltaEstudiante();
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
                system("clear");
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                cout << "Seleccione un usuario" << endl;
                std::set<string>::iterator it;
                for (it= usuarios.begin(); it!=usuarios.end(); ++it) {
                    string elem = *it;
                    cout << "-"+elem << endl;
                }
                string usuarioSeleccionado = "";
                cin >> usuarioSeleccionado;
                bool tipoUsuario = ControladorUsuario->obtenerTipo(usuarioSeleccionado );
                if (tipoUsuario == true) {
                    DTEstudiante infoEstu = ControladorUsuario->obtenerInfoEstudiante(usuarioSeleccionado);
                    cout << "Nombre: " + infoEstu.getNombre() << endl; 
                    cout << "Descripcion: " + infoEstu.getDescripcion() << endl; 
                    cout << "Pais: " + infoEstu.getPaisResidencia() << endl; 
                } else {
                    DTProfesor infoProfe = ControladorUsuario->obtenerInfoProfesor(usuarioSeleccionado);
                    cout << "Nombre: " + infoProfe.getNombre() << endl;
                    cout << "Descripcion: " + infoProfe.getDescripcion() << endl;
                    set<string> idiomas = infoProfe.getIdiomas();
                    cout << "Idiomas: "<< endl;
                    for (it= idiomas.begin(); it!=idiomas.end(); ++it) {
                        string elem = *it;
                        cout << "-"+elem << endl;
                    }
                    cout << "Instituto: " + infoProfe.getInstituto() << endl; 
                } 
                break;
            }
            //AltaIdioma
            case 3: {
                system("clear");
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
                system("clear");
                std::set<string> idiomasDisponibles =
                    ControladorUsuario->obtenerIdiomasDisponibles();
                cout << "Los idiomas disponibles son los siguientes:" << endl;
                std::set<string>::iterator it;
                for (it = idiomasDisponibles.begin();
                     it != idiomasDisponibles.end(); ++it) {
                    string elem = *it;
                    cout << "-" + elem << endl;
                }
                break;
            }

            // AltaCurso
            case 5: {
                system("clear");
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
                getline(cin >> ws, nombreCurso);
                cout << "Ingrese Descripcion curso:" << endl;
                getline(cin >> ws, descripcion);
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
                        getline(cin >> ws, nombreCurso);
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
                            getline(cin >> ws, nombreCurso);
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

            //AgregarLeccion
            case 6: {
                system("clear");
                set<string> cursosNoHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                cout << "Seleccione un curso:" << endl;
                string cursoSeleccionado = "";
                //imprimo nombre de los cursos
                for (string nombre : cursosNoHabilitados) {
                    cout << "-"+nombre << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                if (!(cursosNoHabilitados.count(cursoSeleccionado))) {
                    cout << "Seleccione un curso valido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                }
                ControladorCurso->seleccionarCurso(cursoSeleccionado);
                string temaLeccion = "";
                string objetivoLeccion = "";
                int agregar = 0;
                // ingreso Datos
                cout << "Ingrese tema de la lección:" << endl;
                getline(cin >> ws, temaLeccion);
                cout << "Ingrese objetivo de la lección:" << endl;
                getline(cin >> ws, objetivoLeccion);
                ControladorCurso->ingresarInfoLeccion(temaLeccion,
                                                      objetivoLeccion);
                ControladorCurso->confirmarAltaLeccion();
                break;
            }

            //AgregarEjercicio
            case 7: {
                system("clear");
                //Obtengo Cursos No Habilitados
                 set<string> cursosNoHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                 cout << "Seleccione un curso:" << endl;
                 string cursoSeleccionado = "";
                 // imprimo nombre de los cursos
                 for (string nombre : cursosNoHabilitados) {
                    cout << "-" + nombre << endl;
                 }
                 getline(cin >> ws, cursoSeleccionado);
                 while(!cursosNoHabilitados.count(cursoSeleccionado)){
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                 }
                 ControladorCurso->seleccionarCurso(cursoSeleccionado);

                //Obtengo lecciones
                 set<string> leccionesCurso = ControladorCurso->obtenerLecciones();
                 cout << "Seleccione una lección:" << endl;
                 string leccionSeleccionada = "";
                 // imprimo nombre de las lecciones
                 for (string nombre : leccionesCurso) {
                    cout << "-" + nombre << endl;
                 }
                 getline(cin >> ws, leccionSeleccionada);
                 while (!leccionesCurso.count(leccionSeleccionada)) {
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, leccionSeleccionada);
                 }
                 ControladorCurso->seleccionarLeccion(leccionSeleccionada);

                 //Ingreso descripcion ejercicio
                 string descripcion = "";
                 cout << "Ingrese descripción del ejercicio:";
                 getline(cin >> ws, descripcion);
                 ControladorCurso->ingresarInfoEjercicio(descripcion);
                 int tipoId;
                 
                 //Selecciono Tipo ejercicio
                 cout << "Seleccione el tipo de ejercicio a agregar:" << endl;
                 cout << "1- Completar Palabras" << endl;
                 cout << "2- Traducir" << endl;
                 EnumEjercicios tipo;
                 cin >> tipoId;
                 switch (tipoId) {
                    case 1: {
                        tipo = CompletarPalabras;
                        string frase = "";
                        string solucion = "";
                        cout << "Ingrese frase a completar:" << endl;
                        getline(cin >> ws, frase);
                        cout << "Ingrese solución ejercicio";
                        getline(cin >> ws, solucion);
                        ControladorCurso->agregarDatosCompletar(frase, solucion);
                        break;
                    }
                    case 2:{
                        tipo = TraducirFrase;
                        string frase = "";
                        string traduccion = "";
                        cout << "Ingrese frase a traducir:" << endl;
                        getline(cin >> ws, frase);
                        cout << "Ingrese frase traducida:";
                        getline(cin >> ws, traduccion);
                        ControladorCurso->agregarDatosTraducir(frase, traduccion);
                        break;
                    }
                    default:
                        cout << "Seleccione una opción correcta"
                             << endl;
                        break;
                 }
                 ControladorCurso->confirmarAltaEjercicio(tipo);
                break;
            }

            //Habilitar Curso
            case 8: {
                system("clear");
                //se lista todos los cursos no habilitados
                cout << "Seleccione un curso:" << endl;
                set<string> noHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                string cursoSeleccionado = "";
                for (string curso: noHabilitados){
                    cout << "-"+curso << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                bool fueHabilitado = ControladorCurso->confirmarHabilitacion(cursoSeleccionado);
                // se avisa si el curso fue habilitado 
                if( fueHabilitado == true){
                    cout << "El curso fue habilitado" << endl;
                }else{
                    cout << "El curso no pudo ser habilitado" << endl;
                }
                break;
            }

            case 11: {
                system('clear');
                set<string> estudiantesDisponibles = ControladorUsuario->obtenerEstudiantes();
                string estudiante = "";
                cout << "Ingrese nickname estudiante: " << cin;
                getLine(cin >> ws, estudiante);
                while(estudiantesDisponibles.count(estudiante)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getLine(cin >> ws, estudiante);
                }
                set<string> cursosDisponibles = ControladorCurso->obtenerCursosDisponibles(estudiante);
                string cursoSeleccionado = "";
                cout << "Seleccione nombre del curso: " << endl;
                for (string curso: cursosDisponibles){
                    cout << "- " + curso << endl;
                }
                getLine(cin >> ws, cursoSeleccionado);
                while(cursosDisponibles.count(cursoSeleccionado)) {
                    cout << "Seleccione un curso valido:" <<endl;
                    getLine(cin >> ws, cursoSeleccionado);
                }
                bool fueInscripto = ControladorCurso->confirmarInscripcion(estudiante, cursoSeleccionado);
            }

           //Salida
            case 17:{
                return 0;
            }

            //carga de datos
            case 16: {
                system("clear");
                set<string> col;
                col.insert("Inglés 1");
                ControladorUsuario->agregarIdioma("Inglés");
                ControladorUsuario->ingresarDatosUsuario("joaco_", "joaco123",
                                                         "Joaquín", "ProfUser");
                ControladorUsuario->ingresarInstituto("Fing");
                ControladorUsuario->agregarEspecializacion("Inglés");
                ControladorUsuario->confirmarAltaProfesor();
                ControladorCurso->ingresarInfoCurso("Ingles1", "cursoDesc",
                                                    Principiante);
                ControladorCurso->asignarProfesor("joaco_");
                ControladorCurso->seleccionarIdioma("Inglés");
                ControladorCurso->confirmarAltaCurso();

                ControladorCurso->ingresarInfoCurso("Inglés2", "cursoDesc",
                                                    Principiante);
                ControladorCurso->asignarProfesor("joaco_");
                ControladorCurso->seleccionarIdioma("Inglés");
                ControladorCurso->ingresarCursosPrevios(col);
                ControladorCurso->confirmarAltaCurso();

                break;
            }

            //Default   
            default:{
                cout << "" << endl;
                cout << "Ingrese una opción correcta..." << endl;
            } 
        }


    }
    return 0;
}