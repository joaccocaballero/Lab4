#include "include/Factory.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <limits>

#include "include/DTProfesor.h"
#include "./include/DTEstudiante.h"
using namespace std;

void clearInputBuffer() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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
    cout << "9: Eliminar Curso" << endl;
    cout << "10: Consultar Curso" << endl;
    cout << "11: Inscribirse a Curso" << endl;
    cout << "12: Realizar Ejercicio" << endl;
    cout << "13: Consultar Estadísticas" << endl;
    cout << "14: Suscribirse a Notificaciones" << endl;
    cout << "15: Consulta de Notificaciones" << endl;
    cout << "16: Eliminar Suscripciones" << endl;
    cout << "17: Cargar datos genéricos" <<endl;
    cout << "18: Salir" << endl;
}

string obtenerDificultad(EnumDificultad d){
    switch (d){
    case 0:
        return "Principiante";
        break;
    case 1:
        return "Medio";
        break;
    case 2:
        return "Avanzado";
        break;
    }
}

string obtenerTipoEjercicio(EnumEjercicios e) {
    switch (e) {
    case 0:
        return "Traducir";
        break;
    case 1:
        return "Completar Palabras";
        break;
    }
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
        clearInputBuffer();
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
              system("clear");
              cout << "Ingrese una contraseña:" << endl;
              cin >> Contrasenia;
              system("clear");
              cout << "Ingrese Nombre del Usuario:" << endl;
              getline(cin >> ws, Nombre);
              system("clear");
              cout << "Ingrese Descripcion del Usuario:" << endl;
              getline(cin >> ws, Descripcion);
              system("clear");

              ControladorUsuario->ingresarDatosUsuario(Nickname, Contrasenia,
                                                       Nombre, Descripcion);

              int tipoUsuario = 0;
              // Profesor o Estudiante
              cout << "Seleccione Tipo de Usuario:" << endl;
              cout << "1- Estudiante..." << endl;
              cout << "2- Profesor..." << endl;
              cin >> tipoUsuario;

              bool existeUsuario = true;
              system("clear");
              if (tipoUsuario == 1) {
                string paisResi = "";
                int Anio = 0;
                int Mes = 0;
                int Dia = 0;
                // Ingreso Datos Estudiante
                cout << "Ingrese Pais de Residencia:" << endl;
                getline(cin >> ws, paisResi);
                system("clear");
                cout << "Ingrese Año de Nacimiento:" << endl;
                cin >> Anio;
                system("clear");
                cout << "Ingrese Mes de Nacimiento:" << endl;
                cin >> Mes;
                system("clear");
                cout << "Ingrese Dia de Nacimiento:" << endl;
                cin >> Dia;
                system("clear");
                DTFecha Fecha = DTFecha(Dia, Mes, Anio);
                ControladorUsuario->ingresarDatosEstudiante(paisResi, Fecha);
                // confirmo alta
                existeUsuario = ControladorUsuario->confirmarAltaEstudiante();
                } else if (tipoUsuario == 2) {
                    // Ingresa Instituto
                    string Instituto = "";
                    cout << "Ingrese Instituto del Profesor:" << endl;
                    getline(cin >> ws, Instituto);
                    system("clear");
                    ControladorUsuario->ingresarInstituto(Instituto);
                    cout << "Ingrese Idioma que desea que se especialice:"<< endl;
                    // Obtengo Idiomas Disponibles
                    set<string> idiomasDispo = ControladorUsuario->obtenerIdiomasDisponibles();
                    
                    // imprimo nombre de los idiomas
                    set<string> idiomasSelec = {};
                    string iter = "";
                    for (string nombre : idiomasDispo) {
                      cout << "-" + nombre << endl;
                    }
                    getline(cin >> ws, iter);
                    system("clear");
                    while (!idiomasDispo.count(iter)) {
                      cout << "Seleccione un idioma válido:" << endl;
                      getline(cin >> ws, iter);
                      system("clear");
                    }
                    idiomasSelec.insert(iter);
                    int Agregar = 0;
                    system("clear");
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
                        getline(cin >> ws,iter);
                        while (!idiomasDispo.count(iter)) {
                          cout << "Seleccione un curso valido:" << endl;
                          getline(cin >> ws, iter);
                        }
                        
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
                clearInputBuffer();
                break;
            }

            //Consultar Usuario
            case 2: {
                system("clear");
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                if(!usuarios.empty()){
                    cout << "Seleccione un usuario" << endl;
                    std::set<string>::iterator it;
                    for (it= usuarios.begin(); it!=usuarios.end(); ++it) {
                        string elem = *it;
                        cout << "-"+elem << endl;
                    }
                    string usuarioSeleccionado = "";
                    cin >> usuarioSeleccionado;
                    bool tipoUsuario = ControladorUsuario->obtenerTipo(usuarioSeleccionado);
                    system("clear");
                    cout << "DATOS DE USUARIO:" << endl;
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
                            cout << "   -"+elem << endl;
                        }
                        cout << "Instituto: " + infoProfe.getInstituto() << endl; 
                    } }
                else {
                    cout << "No se encontraron Usuarios existentes en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }
            
            //AltaIdioma
            case 3: {
                system("clear");
                bool seIngresaNuevo = false;
                bool seCancela = false;
                while ((seIngresaNuevo == false) && (seCancela == false)) {
                    string nuevoIdioma = "";
                    bool flagNuevoIdioma = false;
                    cout << "Ingrese nuevo Idioma:" << endl;
                    getline(cin >> ws, nuevoIdioma);
                    // Me fijo si existe idioma
                    flagNuevoIdioma =
                        ControladorUsuario->agregarIdioma(nuevoIdioma);
                    if (flagNuevoIdioma) {
                        cout << "Idioma ingresado correctamente." << endl;
                        seIngresaNuevo = true;
                    } else {
                        int opcion = 0;
                        cout << "El idioma ingresado ya existe, ingrese otro o cancele la acción:" << endl;
                        cout << "1- Ingresar nuevo idioma" << endl;
                        cout << "2- Cancelar acción" << endl;
                        cin >> opcion;
                        if(opcion == 2){
                            seCancela= true;
                        }
                    }
                }
                clearInputBuffer();
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
                clearInputBuffer();
                break;
            }

            // AltaCurso
            case 5: {
                system("clear");
                set<string> listadoProfesores = ControladorUsuario->obtenerProfesores();
                if(!listadoProfesores.empty()){
                cout << "Seleccione un profesor:" << endl;
                string profesorSeleccionado = "";
                // imprimo nombre de los profesores
                for (string nombre: listadoProfesores) {
                    cout << nombre << endl;
                }
                cin >> profesorSeleccionado;
                system("clear");
                if (!(listadoProfesores.count(profesorSeleccionado))) {
                    cout << "Seleccione un profesor valido:" << endl;
                    cin >> profesorSeleccionado;
                    system("clear");
                }
                string nombreCurso = "";
                string descripcion = "";
                int idDificultad = 1;
                
                // ingreso Datos
                cout << "Ingrese Nombre curso:" << endl;
                getline(cin >> ws, nombreCurso);
                system("clear");
                cout << "Ingrese Descripcion curso:" << endl;
                getline(cin >> ws, descripcion);
                system("clear");
                cout << "Seleccione Dificultad:" << endl;
                cout << "1- Principiante" << endl;
                cout << "2- Intermedio" << endl;
                cout << "3- Avanzado" << endl;
                cin >> idDificultad;
                system("clear");
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
                    default:
                        cout << "Seleccione una opción correcta"
                             << endl;
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
                getline(cin >> ws, idiomaSeleccionado);
                system("clear");
                ControladorCurso->seleccionarIdioma(idiomaSeleccionado);

                int agregarPrevias = 1;

                cout << "Desea agregar cursos previos? Ingrese un numero:" << endl;
                cout << "1- Si" << endl;
                cout << "2 -No" << endl;

                cin >> agregarPrevias;
                system("clear");
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
                        system("clear");
                        cursosPrevios.insert(nombreCurso);
                        do{
                          cout << "Desea Agregar otro? Ingrese un numero:"
                               << endl;
                          cout << "1- Si" << endl;
                          cout << "2- No" << endl;
                          cin >> seguirAgregando;
                          system("clear");
                          if(seguirAgregando==1){
                            string nombreCurso;
                            cout << "Ingrese nombre del curso: " << endl;
                            // imprimo nombre de los cursos previos
                            for (string nombre : cursosHabilitados) {
                              cout << "-" + nombre << endl;
                            }
                            getline(cin >> ws, nombreCurso);
                            system("clear");
                            cursosPrevios.insert(nombreCurso);
                          }
                        }
                        while(seguirAgregando==1);
                    }
                    ControladorCurso->ingresarCursosPrevios(cursosPrevios);
                }
                ControladorCurso->confirmarAltaCurso();
                int agregarLecciones;
                cout << "Desea agregar una leccion?"<<endl;
                cout << "1- Si" << endl;
                cout << "2- No" << endl;
                cin >> agregarLecciones;
                system("clear");
                while (agregarLecciones == 1){
                    ControladorCurso->seleccionarCurso(nombreCurso);
                    string temaLeccion = "";
                    string objetivoLeccion = "";
                    int agregar = 0;
                    // ingreso Datos
                    cout << "Ingrese tema de la lección:" << endl;
                    getline(cin >> ws, temaLeccion);
                    system("clear");
                    cout << "Ingrese objetivo de la lección:" << endl;
                    getline(cin >> ws, objetivoLeccion);
                    system("clear");
                    ControladorCurso->ingresarInfoLeccion(temaLeccion,
                                                        objetivoLeccion);
                    ControladorCurso->confirmarAltaLeccion();
                    int agregarEjs;
                    cout << "Desea agregar un ejercicio?"<<endl;
                    cout << "1- Si" << endl;
                    cout << "2- No" << endl;
                    cin >> agregarEjs;
                    system("clear");
                    while (agregarEjs == 1) {
                        ControladorCurso->seleccionarLeccion(temaLeccion);
                        string descripcion = "";
                        cout << "Ingrese descripción del ejercicio:";
                        getline(cin >> ws, descripcion);
                        system("clear");
                        ControladorCurso->ingresarInfoEjercicio(descripcion);
                        int tipoId;
                        
                        //Selecciono Tipo ejercicio
                        cout << "Seleccione el tipo de ejercicio a agregar:" << endl;
                        cout << "1- Completar Palabras" << endl;
                        cout << "2- Traducir" << endl;
                        EnumEjercicios tipo;
                        cin >> tipoId;
                        system("clear");
                        switch (tipoId) {
                            case 1: {
                                tipo = CompletarPalabras;
                                string frase = "";
                                string solucion = "";
                                cout << "Ingrese frase a completar:" << endl;
                                getline(cin >> ws, frase);
                                system("clear");
                                cout << "Ingrese solución ejercicio";
                                getline(cin >> ws, solucion);
                                system("clear");
                                ControladorCurso->agregarDatosCompletar(frase, solucion);
                                break;
                            }
                            case 2:{
                                tipo = TraducirFrase;
                                string frase = "";
                                string traduccion = "";
                                cout << "Ingrese frase a traducir:" << endl;
                                getline(cin >> ws, frase);
                                system("clear");
                                cout << "Ingrese frase traducida:";
                                getline(cin >> ws, traduccion);
                                system("clear");
                                ControladorCurso->agregarDatosTraducir(frase, traduccion);
                                break;
                            }
                            default:
                                cout << "Seleccione una opción correcta"
                                    << endl;
                                break;
                        }
                        cout << "Desea agregar otro ejercicio? " << endl;
                        cout << "1- Si" << endl;
                        cout << "2- No" << endl;
                        cin >> agregarEjs;
                    }
                    cout << "Desea agregar otra leccion? " << endl;
                    cout << "1- Si" << endl;
                    cout << "2- No" << endl;
                    cin >> agregarLecciones;
                    system("clear");
                }}
                else {
                    cout << "No se han encontrado Profesores en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }

            //AgregarLeccion
            case 6: {
                system("clear");
                set<string> cursosNoHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                if(!cursosNoHabilitados.empty()){
                cout << "Seleccione un curso:" << endl;
                string cursoSeleccionado = "";
                //imprimo nombre de los cursos
                for (string nombre : cursosNoHabilitados) {
                    cout << "-"+nombre << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                system("clear");
                while(!cursosNoHabilitados.count(cursoSeleccionado)) {
                    cout << "Seleccione un curso valido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                    system("clear");
                }
                ControladorCurso->seleccionarCurso(cursoSeleccionado);
                string temaLeccion = "";
                string objetivoLeccion = "";
                int agregar = 0;
                // ingreso Datos
                cout << "Ingrese tema de la lección:" << endl;
                getline(cin >> ws, temaLeccion);
                system("clear");
                cout << "Ingrese objetivo de la lección:" << endl;
                getline(cin >> ws, objetivoLeccion);
                system("clear");
                ControladorCurso->ingresarInfoLeccion(temaLeccion,
                                                      objetivoLeccion);
                ControladorCurso->confirmarAltaLeccion();
                int agregarEjs;
                cout << "Desea agregar un ejercicio?"<<endl;
                cout << "1- Si" << endl;
                cout << "2- No" << endl;
                cin >> agregarEjs;
                system("clear");
                while (agregarEjs == 1) {
                    ControladorCurso->seleccionarLeccion(temaLeccion);
                    string descripcion = "";
                    cout << "Ingrese descripción del ejercicio:";
                    getline(cin >> ws, descripcion);
                    system("clear");
                    ControladorCurso->ingresarInfoEjercicio(descripcion);
                    int tipoId;
                    
                    //Selecciono Tipo ejercicio
                    cout << "Seleccione el tipo de ejercicio a agregar:" << endl;
                    cout << "1- Completar Palabras" << endl;
                    cout << "2- Traducir" << endl;
                    EnumEjercicios tipo;
                    cin >> tipoId;
                    system("clear");
                    switch (tipoId) {
                        case 1: {
                            tipo = CompletarPalabras;
                            string frase = "";
                            string solucion = "";
                            cout << "Ingrese frase a completar:" << endl;
                            getline(cin >> ws, frase);
                            system("clear");
                            cout << "Ingrese solución ejercicio";
                            getline(cin >> ws, solucion);
                            system("clear");
                            ControladorCurso->agregarDatosCompletar(frase, solucion);
                            break;
                        }
                        case 2:{
                            tipo = TraducirFrase;
                            string frase = "";
                            string traduccion = "";
                            cout << "Ingrese frase a traducir:" << endl;
                            getline(cin >> ws, frase);
                            system("clear");
                            cout << "Ingrese frase traducida:";
                            getline(cin >> ws, traduccion);
                            system("clear");
                            ControladorCurso->agregarDatosTraducir(frase, traduccion);
                            break;
                        }
                        default:
                            cout << "Seleccione una opción correcta"
                                << endl;
                            break;
                    }
                    cout << "Desea agregar otro ejercicio? " << endl;
                    cout << "1- Si" << endl;
                    cout << "2- No" << endl;
                    cin >> agregarEjs;
                }
                }
                else{
                    cout << "No se han encontrado Cursos en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }

            //AgregarEjercicio
            case 7: {
                system("clear");
                //Obtengo Cursos No Habilitados
                 set<string> cursosNoHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                 if(!cursosNoHabilitados.empty()){
                 cout << "Seleccione un curso:" << endl;
                 string cursoSeleccionado = "";
                 // imprimo nombre de los cursos
                 for (string nombre : cursosNoHabilitados) {
                    cout << "-" + nombre << endl;
                 }
                 getline(cin >> ws, cursoSeleccionado);
                 system("clear");
                 while(!cursosNoHabilitados.count(cursoSeleccionado)){
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                    system("clear");
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
                 system("clear");
                 while (!leccionesCurso.count(leccionSeleccionada)) {
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, leccionSeleccionada);
                    system("clear");
                 }
                 ControladorCurso->seleccionarLeccion(leccionSeleccionada);

                 //Ingreso descripcion ejercicio
                 string descripcion = "";
                 cout << "Ingrese descripción del ejercicio:";
                 getline(cin >> ws, descripcion);
                 system("clear");
                 ControladorCurso->ingresarInfoEjercicio(descripcion);
                 int tipoId;
                 
                 //Selecciono Tipo ejercicio
                 cout << "Seleccione el tipo de ejercicio a agregar:" << endl;
                 cout << "1- Completar Palabras" << endl;
                 cout << "2- Traducir" << endl;
                 EnumEjercicios tipo;
                 cin >> tipoId;
                 system("clear");
                 switch (tipoId) {
                    case 1: {
                        tipo = CompletarPalabras;
                        string frase = "";
                        string solucion = "";
                        cout << "Ingrese frase a completar:" << endl;
                        getline(cin >> ws, frase);
                        system("clear");
                        cout << "Ingrese solución ejercicio";
                        getline(cin >> ws, solucion);
                        system("clear");
                        ControladorCurso->agregarDatosCompletar(frase, solucion);
                        break;
                    }
                    case 2:{
                        tipo = TraducirFrase;
                        string frase = "";
                        string traduccion = "";
                        cout << "Ingrese frase a traducir:" << endl;
                        getline(cin >> ws, frase);
                        system("clear");
                        cout << "Ingrese frase traducida:";
                        getline(cin >> ws, traduccion);
                        system("clear");
                        ControladorCurso->agregarDatosTraducir(frase, traduccion);
                        break;
                    }
                    default:
                        cout << "Seleccione una opción correcta"
                             << endl;
                        break;
                 }
                 ControladorCurso->confirmarAltaEjercicio(tipo);
                 }
                 else {
                    cout << "No se encontraron Cursos no habilitados en el Sistema" << endl;
                 }
                 clearInputBuffer();
                break;
            }

            //Habilitar Curso
            case 8: {
                system("clear");
                //se lista todos los cursos no habilitados
                cout << "Seleccione un curso:" << endl;
                set<string> noHabilitados = ControladorCurso->obtenerCursosNoHabilitados();
                if(!noHabilitados.empty()){
                string cursoSeleccionado = "";
                for (string curso: noHabilitados){
                    cout << "-"+curso << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                system("clear");
                bool fueHabilitado = ControladorCurso->confirmarHabilitacion(cursoSeleccionado);
                // se avisa si el curso fue habilitado 
                if( fueHabilitado == true){
                    cout << "El curso fue habilitado" << endl;
                }else{
                    cout << "El curso no pudo ser habilitado" << endl;
                }
                }
                else{
                    cout << "No se han encontrado Cursos no habilitados en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
                
            }
            //Eliminar Curso
            case 9:{
                system("clear");
                set<string> cursos = ControladorCurso->obtenerCursos();
                if(!cursos.empty()){
                cout << "Seleccione el curso a eliminar:" << endl;
                string cursoSeleccionado = "";
                // imprimo nombre de los cursos
                for (string nombre : cursos) {
                    cout << "-" + nombre << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                system("clear");
                while (!cursos.count(cursoSeleccionado)) {
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                    system("clear");
                }                
                ControladorCurso->confirmarEliminacion(cursoSeleccionado);
                cout << "Ha sido eliminado el curso: "<< cursoSeleccionado << endl;
                }else {
                    cout << "No se han encontrado Cursos en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }
            //Consultar curso
            case(10): {
                // Obtengo Cursos
                system("clear");
                 set<string> cursos = ControladorCurso->obtenerCursos();
                 if(!cursos.empty()){
                cout << "Seleccione un curso:" << cursos.size() << endl;
                string cursoSeleccionado = "";
                // imprimo nombre de los cursos
                for (string nombre : cursos) {
                    cout << "-" + nombre << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                system("clear");
                while (!cursos.count(cursoSeleccionado)) {
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
                    system("clear");
                }
                DTCurso infocurso = ControladorCurso->obtenerInfoCurso(cursoSeleccionado);

                //imprimo datos del curso
                cout << "INFORMACION DEL CURSO:" << endl;
                cout << "   *Nombre: " << infocurso.getNombreCurso() << endl;
                cout << "   *Descripción: " << infocurso.getDescripcionCurso() << endl;
                cout << "   *Dificultad: " << obtenerDificultad(infocurso.getDificultad()) << endl;
                cout << "   *Idioma: " << infocurso.getIdioma() << endl;
                cout << "   *Profesor: " << infocurso.getProfesor() << endl;
                std::string hab = (infocurso.getHabilitacion()) ? "Habilitado" : "No Habilitado";
                cout << "   *Habilitación: " << hab << endl;
                cout << "   *Lecciones: " << endl;
                if (!infocurso.getLecciones().empty()){
                    for (DTLeccion leccion : infocurso.getLecciones()) {
                        cout << "   + Tema: " << leccion.obtenerTema() << endl;
                        cout << "       + Objetivo: " << leccion.obtenerObjetivo()
                             << endl;
                        cout << "           *Ejercicios: " << endl;
                        if (!leccion.obtenerEjercicios().empty()){
                          for (DTEjercicio ej : leccion.obtenerEjercicios()) {
                            cout << "               + ID: " << ej.getId() << endl;
                            cout << "               + Descripcion: "
                                 << ej.getDescripcionEjercicio() << endl;
                            cout << "               + Tipo: "
                                 << obtenerTipoEjercicio(ej.getTipoEjercicio())
                                 << endl;
                          }
                        }
                        else{
                          cout << "     Sin Ejercicios. " << endl;
                        }
                    }
                }
                else{
                    cout << "       Sin Lecciones. " << endl;
                }
                    
                cout << "   *Inscripciones: " << endl;
                if(!infocurso.getInscripciones().empty()){
                    for (DTInscripcion ins : infocurso.getInscripciones()) {
                        cout << "        -Nombre: " << ins.obtenerNombre() << endl;
                        cout << "        -Fecha : " << ins.obtenerFecha().getDia()
                             << "/" << ins.obtenerFecha().getMes() <<
                            "/"<< ins.obtenerFecha().getAnio() << endl;
                    }
                }
                else{
                    cout << "       Sin Inscripciones." << endl;
                }
                } else {
                    cout << "No se han encontrado Cursos en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }
           
            //Inscribirse A Curso
            case 11: {
                system("clear");
                set<string> estudiantesDisponibles = ControladorUsuario->obtenerEstudiantes();
                if(!estudiantesDisponibles.empty()){
                string estudiante = "";
                cout << "Ingrese nickname estudiante: " << endl;
                getline(cin >> ws, estudiante);
                system("clear");
                while (!estudiantesDisponibles.count(estudiante)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getline(cin >> ws, estudiante);
                    system("clear");
                }
                set<DTCursoDisponible> cursosDisponibles = ControladorCurso->obtenerCursosDisponibles(estudiante);
                set<string> nombresCursos;
                string cursoSeleccionado = "";
                if(!cursosDisponibles.empty()){
                    cout << "Seleccione nombre del curso: " << endl;
                    for (DTCursoDisponible curso : cursosDisponibles) {
                        nombresCursos.insert(curso.getNombre());
                        int cantLecc = curso.getLecciones();
                        int cantEjer = curso.getEjercicios();
                        cout << "- Nombre: " + curso.getNombre() << endl;
                        cout << "   * Descripción: " + curso.getDescripcion()
                             << endl;
                        cout << "   * Dificultad: "
                             << obtenerDificultad(curso.getDificultad())
                             << endl;
                        cout << "   * Idioma: " + curso.getIdioma() << endl;
                        cout << "   * Profesor: " << curso.getProfesor()
                             << endl;
                        cout << "   * Cant. de Lecciones: " << cantLecc << endl;
                        cout << "   * Cant. de Ejercicios: " << cantEjer
                             << endl;
                    }
                    getline(cin >> ws, cursoSeleccionado);
                    system("clear");
                    while (!nombresCursos.count(cursoSeleccionado)) {
                        cout << "Seleccione un curso valido:" << endl;
                        getline(cin >> ws, cursoSeleccionado);
                        system("clear");
                    }
                    bool fueInscripto = ControladorCurso->confirmarInscripcion(
                        estudiante, cursoSeleccionado);
                    if (fueInscripto) {
                        cout << "Inscripcion realizada con éxito." << endl;
                    } else {
                        cout << "No se ha podido realizar la inscripción."
                             << endl;
                    }
                } 
                else{
                    cout << "No hay cursos disponibles para inscripción." << endl;
                }
                }
                else{
                    cout << "No se han encontrado Cursos en el Sistema" << endl;
                }
                clearInputBuffer();
               break;
            }

            //Realizar Ejercicio
            case (12): {
                //se ingresa nombre de estudiante
               system("clear");
               set<string> nicknamesSistema =
                   ControladorUsuario->obtenerUsuarios();
                if(!nicknamesSistema.empty()){
                string nicknameEstudiante = "";
                cout << "Ingrese Nickname de Estudiante:" << endl;
                getline(cin >> ws, nicknameEstudiante);
               system("clear");
                while (!nicknamesSistema.count(nicknameEstudiante)) {
                    cout << "Ingrese un nickname válido:" << endl;
                    getline(cin >> ws, nicknameEstudiante);
                    system("clear");
                }

                //se lista los cursos aun no aprobados
                set<string> noAprobados = ControladorUsuario->obtenerCursosNoAprobados(nicknameEstudiante);
                if(!noAprobados.empty()){
                    cout << "Seleccione un curso:" << endl;
                    for (string nombre : noAprobados) {
                    cout << "-" + nombre << endl;
                    }
                    string nombreCurso = "";
                    getline(cin >> ws, nombreCurso);
                        system("clear");
                    while (!noAprobados.count(nombreCurso)) {
                        cout << "Ingrese un curso válido:" << endl;
                        getline(cin >> ws, nombreCurso);
                            system("clear");
                    }

                    set<DTEjercicio> ejNoAprobados = ControladorCurso->obtenerEjerciciosPendientes(nombreCurso, nicknameEstudiante);
                    set<string> idEjercicios;
                    //se imprimen ejercicios pendientes
                        system("clear");
                        if(!ejNoAprobados.empty()){
                            cout << "**SELECCIONE UN EJERCICIO**:" << endl;
                    for (DTEjercicio ejercicio : ejNoAprobados) {
                        idEjercicios.insert(to_string(ejercicio.getId()));
                        cout << "   *ID: " << ejercicio.getId() << endl;
                        cout << "       -Tipo: " << obtenerTipoEjercicio(ejercicio.getTipoEjercicio())<< endl;
                        cout << "       -Descripción: " << ejercicio.getDescripcionEjercicio() << endl;
                        cout << "       -Consigna: " << ejercicio.getConsignaEjercicio() << endl;
                        cout << "   " << endl;
                    }
                    string ejSeleccionado;
                    getline(cin >> ws, ejSeleccionado);
                    while (!idEjercicios.count(ejSeleccionado)) {
                        cout << "Ingrese un ejercicio válido:" << endl;
                        getline(cin >> ws, ejSeleccionado);
                    }
                    DTEjercicio ejercicioAMostrar = ControladorCurso->seleccionarEjercicio(stoi(ejSeleccionado));
                        system("clear");
                    //imprimo el ejercicio seleccionado
                        cout << "   *EJERCICIO: " << ejercicioAMostrar.getId() << endl;
                        cout << "       -Descripción: " << ejercicioAMostrar.getDescripcionEjercicio() << endl;
                        cout << "       -Consigna: " << ejercicioAMostrar.getConsignaEjercicio() << endl;
                        cout << "   " << endl;
                    
                    cout << "Ingrese su respuesta: " << endl;

                    string respuesta = "";
                    getline(cin >> ws, respuesta);
                    if(ControladorCurso->validarEjercicio(respuesta)){
                            system("clear");
                        cout << "RESPUESTA CORRECTA!" << endl;
                        cout << "   *Ejercicio Aprobado!" << endl;
                    }
                    else{
                            system("clear");
                        cout << "RESPUESTA INCORRECTA!" << endl;
                    }
                }
                else{
                        cout << "No hay ejercicios pendientes para este curso." << endl;
                    }
                }
                else{
                    cout << "No hay cursos no aprobados disponibles." << endl;
                }
                }else {
                    cout << "No se han encontrado Usuarios en el Sistema" << endl; 
                }
                clearInputBuffer();
               break;
            }

            //Consultar Estadisticas
            case 13: {
                    string sopcion;
                    cout << "Seleccione una opción:" << endl;
                    cout << "1- Consultar estadística de Estudiante. "<< endl;
                    cout << "2- Consultar estadística de Profesor. " << endl;
                    cout << "3- Consultar estadística de Curso. " << endl;
                    getline(cin >> ws, sopcion);
                    int opcion = std::stoi(sopcion);
                    switch(opcion) {
                        case 1:{
                            //imprime todos los nicknames
                            set<string> NickEstudiantes = ControladorUsuario->obtenerEstudiantes();
                            if(!NickEstudiantes.empty()){
                            std::set<string>::iterator it;
                            cout << "Seleccione un Estudiante: "<< endl;
                            for (it= NickEstudiantes.begin(); it!=NickEstudiantes.end(); ++it) {
                                string elem = *it;
                                cout << "-"+elem << endl;
                            }

                            //selecciona el nickname
                            string estudiante;
                            getline(cin >> ws, estudiante);
                            system("clear");
                            while (!NickEstudiantes.count(estudiante)) {
                                cout << "Seleccione un nickname existente:" <<endl;
                                getline(cin >> ws, estudiante);
                                system("clear");
                            }
                            set<DTEstadisticaEstudiante> estadisticas = ControladorUsuario->obtenerEstadisticaEstudiante(estudiante);
                            //recorre el set e imprime
                            cout << "Estadisticas del estudiante: " << estudiante << endl;
                            for (DTEstadisticaEstudiante est: estadisticas) {
                                cout << "   Curso: " << est.getNombreCurso() << endl;
                                cout << "   Avance: " << est.getAvance() << endl;
                                cout << "   " << endl;
                            }
                            }else{
                                cout << "No se han encontrado Estudiantes en el Sistema" << endl;
                            }
                            clearInputBuffer();
                            break;
                        }
                        case 2:{
                            //imprime nicknames de profesores
                            set<string> NickProfesores = ControladorUsuario->obtenerProfesores();
                            if(!NickProfesores.empty()){
                            std::set<string>::iterator it;
                            cout << "Seleccione un Profesor: "<< endl;
                            for (it= NickProfesores.begin(); it!=NickProfesores.end(); ++it) {
                                string elem = *it;
                                cout << "-"+elem << endl;
                            }
                            string profesor;
                            getline(cin >> ws, profesor);
                            system("clear");
                            while (!NickProfesores.count(profesor)) {
                                cout << "Seleccione un nickname existente:" <<endl;
                                getline(cin >> ws, profesor);
                                system("clear");
                            }
                            set<DTEstadisticaProfesor> estadisticas = ControladorCurso->obtenerEstadisticasProfesor(profesor);
                            cout << "Estadisticas del profesor: " << profesor << endl;
                            for (DTEstadisticaProfesor pro: estadisticas) {
                                cout << "   Curso: " << pro.getNombreCurso() << endl;
                                cout << "   Promedio: " << pro.getPromedio() << endl;
                                cout << "   " << endl;
                            }}
                            else{
                                cout << "No se han encontrado Profesores en el Sistema" << endl;
                            }
                            clearInputBuffer();
                            break;
                        }
                        case 3:{
                            //imprime todos los cursos
                            set<string> NombreCursos = ControladorCurso->obtenerCursosHabilitados();
                            if(!NombreCursos.empty()){
                            std::set<string>::iterator it;
                            cout << "Seleccione un Curso: "<< endl;
                            for (it= NombreCursos.begin(); it!=NombreCursos.end(); ++it) {
                                string elem = *it;
                                cout << "-"+elem << endl;
                            }
                            string curso;
                            getline(cin >> ws, curso);
                            system("clear");
                            while (!NombreCursos.count(curso)) {
                                cout << "Seleccione un curso existente:" <<endl;
                                getline(cin >> ws, curso);
                                system("clear");
                            }
                            DTEstadisticaCurso estadisticas = ControladorCurso->obtenerEstadisticaCurso(curso);
                            cout << "Estadisticas del curso: " << curso << endl;
                            cout << "   Curso: " << estadisticas.getNombreCurso() << endl;
                            cout << "   Promedio: " << estadisticas.getAvance() << endl;
                            cout << "   " << endl;
                            }else {
                                cout << "No se han encontrado Cursos en el Sistema" << endl;
                            }
                            clearInputBuffer();
                            break;
                        }
                        default:{
                            cout << "" << endl;
                            cout << "Ingrese una opción correcta..." << endl;
                        }
                        clearInputBuffer();
                    break;
                    }
                    clearInputBuffer();
                break;
            }
                    

            //suscribirse a notificaciones
            case 14: {
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                if(!usuarios.empty()){
                string nicknameUsuario;
                cout << "Seleccione un nickname:" <<endl;
                for (string nickname: usuarios){
                    cout << "-"+nickname << endl;
                }
                getline(cin >> ws, nicknameUsuario);
                system("clear");
                while (!usuarios.count(nicknameUsuario)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getline(cin >> ws, nicknameUsuario);
                }
                system("clear");
                set<string> idiomasDisponibles = ControladorUsuario->obtenerSubscripcionesPendientes(nicknameUsuario);
                set<string> idiomasASuscribirse;

                if(idiomasDisponibles.size() == 0) {
                    cout<<"No hay idiomas para suscribirse"<< endl;
                    break;
                }

                cout << "Seleccione un idioma:" <<endl;
                for (string idioma: idiomasDisponibles){
                    cout << "-"+idioma << endl;
                }
                bool agregar = true;
                while (agregar) {
                    string idiomaSeleccionado;
                    cin >> idiomaSeleccionado;
                    while (!idiomasDisponibles.count(idiomaSeleccionado)) {
                        cout << "Seleccione un idioma existente:" <<endl;
                        getline(cin >> ws, idiomaSeleccionado);
                    }
                    idiomasASuscribirse.insert(idiomaSeleccionado);
                    cout << "Desea agregar otro idioma?" << endl;
                    cout << "1-Si" << endl;
                    cout << "2-No" << endl;
                    int agregarOtro;
                    cin >> agregarOtro;
                    agregar = (agregarOtro == 1);
                }
                bool exito = ControladorUsuario->suscribirUsuario(nicknameUsuario, idiomasASuscribirse);
                if(exito){
                    cout << "Suscripciones realizadas con exito" << endl;
                }else {
                    cout << "Error al suscribirse" << endl;
                }
                }else {
                    cout << "No se han encontrado Cursos en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }
           
           //Consulta de Notificaciones
            case 15: {
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                if(!usuarios.empty()){
                string nicknameUsuario;
                cout << "Seleccione un nickname:" <<endl;
                for (string nickname: usuarios){
                    cout << "-"+nickname << endl;
                }
                getline(cin >> ws, nicknameUsuario);
                while (!usuarios.count(nicknameUsuario)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getline(cin >> ws, nicknameUsuario);
                }
                system("clear");
                vector<DTNotificacion> notificaciones = ControladorUsuario->obtenerNotificaciones(nicknameUsuario);
                if (notificaciones.size() > 0) {
                    cout << "Notificaciones" << endl;
                    for (DTNotificacion notificacion: notificaciones){
                        cout << "Curso: "+ notificacion.getNombreCurso() << endl;
                        cout << "Idioma: "+ notificacion.getNombreIdioma() << endl;
                        cout << "--------------"<< endl;
                    } 
                }else {
                    cout << "No hay notificaciones" << endl;
                }}
                    else{
                        cout << "No se han encontrado Usuarios en el Sistema" << endl;
                    }
                
                clearInputBuffer();
                break;
            }

            //Eliminar Suscripciones
            case 16: {
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
                if(!usuarios.empty()){
                string nicknameUsuario;
                cout << "Seleccione un nickname:" <<endl;
                for (string nickname: usuarios){
                    cout << "-"+nickname << endl;
                }
                getline(cin >> ws, nicknameUsuario);
                while (!usuarios.count(nicknameUsuario)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getline(cin >> ws, nicknameUsuario);
                }
                set<string> idiomasSuscritos = ControladorUsuario->obtenerSubscripciones(nicknameUsuario);
                set<string> idiomasADesuscribirse;

                if(idiomasSuscritos.size() == 0) {
                    cout<<"No hay suscripciones para borrar"<< endl;
                    break;
                }

                cout << "Seleccione un idioma:" <<endl;
                for (string idioma: idiomasSuscritos){
                    cout << "-"+idioma << endl;
                }
                bool agregar = true;
                while (agregar) {
                    string idiomaSeleccionado;
                    cin >> idiomaSeleccionado;
                    while (!idiomasSuscritos.count(idiomaSeleccionado)) {
                        cout << "Seleccione un idioma existente:" <<endl;
                        getline(cin >> ws, idiomaSeleccionado);
                    }
                    idiomasADesuscribirse.insert(idiomaSeleccionado);
                    cout << "Desea agregar otro idioma?" << endl;
                    cout << "1-Si" << endl;
                    cout << "2-No" << endl;
                    int agregarOtro;
                    cin >> agregarOtro;
                    agregar = (agregarOtro == 1);
                }
                //llamar a borrar suscripciones
                bool res = ControladorUsuario->removerSuscripciones(nicknameUsuario, idiomasADesuscribirse);
                if(res) {
                    cout << "Se ha desuscrito con exito!" <<endl;
                }else cout << "Error al desuscribirse" <<endl;
                } else {
                    cout << "No se han encontrado Usuarios en el Sistema" << endl;
                }
                clearInputBuffer();
                break;
            }
           
           //Salida
            case 18:{
                return 0;
            }

            //carga de datos
            case 17: {
                system("clear");
                //AltaIdioma
                ControladorUsuario->agregarIdioma("Ingles");
                ControladorUsuario->agregarIdioma("Aleman");
                ControladorUsuario->agregarIdioma("Portugues");

                //Alta Estudiantes
                    //U1
                    ControladorUsuario->ingresarDatosUsuario("jpidiom", "asdfg123 ", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.");
                    DTFecha Fecha1 = DTFecha(15, 7, 1995);
                    ControladorUsuario->ingresarDatosEstudiante("Argentina", Fecha1);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U2
                    ControladorUsuario->ingresarDatosUsuario("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.");
                    DTFecha Fecha2 = DTFecha(28, 2, 1998);
                    ControladorUsuario->ingresarDatosEstudiante("Ecuador", Fecha2);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U3
                    ControladorUsuario->ingresarDatosUsuario("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.");
                    DTFecha Fecha3 = DTFecha(10, 11, 1994);
                    ControladorUsuario->ingresarDatosEstudiante("Peru", Fecha3);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U4
                    ControladorUsuario->ingresarDatosUsuario("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas.");
                    DTFecha Fecha4 = DTFecha(22, 4, 1997);
                    ControladorUsuario->ingresarDatosEstudiante("Chile", Fecha4);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U5
                    ControladorUsuario->ingresarDatosUsuario("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.");
                    DTFecha Fecha5 = DTFecha(3, 9, 1996);
                    ControladorUsuario->ingresarDatosEstudiante("Uruguay", Fecha5);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U6
                    ControladorUsuario->ingresarDatosUsuario("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.");
                    DTFecha Fecha6 = DTFecha(12, 1, 1999);
                    ControladorUsuario->ingresarDatosEstudiante("Argentina", Fecha6);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U7
                    ControladorUsuario->ingresarDatosUsuario("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.");
                    DTFecha Fecha7 = DTFecha(25, 6, 1993);
                    ControladorUsuario->ingresarDatosEstudiante("Colombia", Fecha7);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U8
                    ControladorUsuario->ingresarDatosUsuario("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.");
                    DTFecha Fecha8 = DTFecha(8, 12, 1997);
                    ControladorUsuario->ingresarDatosEstudiante("Uruguay", Fecha8);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U9
                    ControladorUsuario->ingresarDatosUsuario("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.");
                    DTFecha Fecha9 = DTFecha(17, 3, 1995);
                    ControladorUsuario->ingresarDatosEstudiante("Chile", Fecha9);
                    ControladorUsuario->confirmarAltaEstudiante();

                    //U10
                    ControladorUsuario->ingresarDatosUsuario("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme.");
                    DTFecha Fecha10 = DTFecha(2, 8, 1998);
                    ControladorUsuario->ingresarDatosEstudiante("Bolivia", Fecha10);
                    ControladorUsuario->confirmarAltaEstudiante();

                //Alta profesores
                    //U11
                    ControladorUsuario->ingresarDatosUsuario("langMaster", "P4s512",
                                                            "Marta Grecia", "Soy una profesora apasionada por los idiomas.");
                    ControladorUsuario->ingresarInstituto("Instituto de Idiomas Moderno");
                    ControladorUsuario->agregarEspecializacion("Ingles");
                    ControladorUsuario->agregarEspecializacion("Portugues");
                ControladorUsuario->agregarIdioma("Ingles");
                ControladorUsuario->agregarIdioma("Aleman");
                ControladorUsuario->agregarIdioma("Portugues");

               

                    //U12
                    ControladorUsuario->ingresarDatosUsuario("linguaPro", "Pess23",
                                                            "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas.");
                    ControladorUsuario->ingresarInstituto("Centro Global ");
                    ControladorUsuario->agregarEspecializacion("Ingles");
                    ControladorUsuario->agregarEspecializacion("Aleman");
                    ControladorUsuario->agregarEspecializacion("Portugues");
                ControladorUsuario->confirmarAltaProfesor();

                    //U13
                    ControladorUsuario->ingresarDatosUsuario(
                        "talkExpert", "Secret1", "Laura Perez",
                        "Soy una profesora entusiasta del aprendizaje de idiomas.");
                    ControladorUsuario->ingresarInstituto("Instituto de Idiomas Vanguardia ");
                    ControladorUsuario->agregarEspecializacion("Aleman");
                    ControladorUsuario->confirmarAltaProfesor();

                    // U14
                    ControladorUsuario->ingresarDatosUsuario(
                        "lingoSensei", "Secure2", "Franco Lopez",
                        "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos.");
                    ControladorUsuario->ingresarInstituto("Centro de Idiomas");
                    ControladorUsuario->agregarEspecializacion("Portugues");
                    ControladorUsuario->confirmarAltaProfesor();

                    // U15
                    ControladorUsuario->ingresarDatosUsuario(
                        "wordMaestro", "Passw0", "Ana Morales",
                        "Soy una profesora comprometida en desarrollo de habilidades idiomaticas.");
                    ControladorUsuario->ingresarInstituto("Instituto de Idiomas Progreso");
                    ControladorUsuario->agregarEspecializacion("Ingles");
                    ControladorUsuario->confirmarAltaProfesor();

                //Alta de curso
                    //Alta C1
                    ControladorCurso->ingresarInfoCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.",Principiante);
                    ControladorCurso->asignarProfesor("langMaster");
                    ControladorCurso->seleccionarIdioma("Ingles");
                    ControladorCurso->confirmarAltaCurso();

                    //Alta C2
                    ControladorCurso->ingresarInfoCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.",Principiante);
                    ControladorCurso->asignarProfesor("langMaster");
                    ControladorCurso->seleccionarIdioma("Ingles");
                    ControladorCurso->confirmarAltaCurso();

                    //Alta C3
                    ControladorCurso->ingresarInfoCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.",Medio);
                    ControladorCurso->asignarProfesor("linguaPro");
                    ControladorCurso->seleccionarIdioma("Ingles");
                    //Ingreo Previas C3
                    set<string> previasC3;
                    previasC3.insert("Ingles para principiantes");
                    ControladorCurso->ingresarCursosPrevios(previasC3);
                    ControladorCurso->confirmarAltaCurso();

                    //Alta C4
                    ControladorCurso->ingresarInfoCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.",Avanzado);
                    ControladorCurso->asignarProfesor("linguaPro");
                    ControladorCurso->seleccionarIdioma("Ingles");
                    // Ingreso Previas C4
                    set<string> previasC4;
                    previasC4.insert("Ingles para principiantes");
                    previasC4.insert("Ingles intermedio: mejora tu nivel");
                    ControladorCurso->ingresarCursosPrevios(previasC4);
                    ControladorCurso->confirmarAltaCurso();

                    //Alta C5
                    ControladorCurso->ingresarInfoCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.",Medio);
                    ControladorCurso->asignarProfesor("linguaPro");
                    ControladorCurso->seleccionarIdioma("Portugues");
                    ControladorCurso->confirmarAltaCurso();
                   
                    //Alta C6
                    ControladorCurso->ingresarInfoCurso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.",Avanzado);
                    ControladorCurso->asignarProfesor("lingoSensei");
                    ControladorCurso->seleccionarIdioma("Portugues");
                    // Ingreso Previas C5
                    set<string> previasC5;
                    previasC5.insert("Portugues intermedio");
                    ControladorCurso->ingresarCursosPrevios(previasC5);
                    ControladorCurso->confirmarAltaCurso();

                    // Alta Leccion en C1
                    // L1
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->ingresarInfoLeccion("Saludos y Presentaciones", "Aprender a saludar y despedirse");
                ControladorCurso->confirmarAltaLeccion();
                    //L2
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->ingresarInfoLeccion("Artículos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
                    ControladorCurso->confirmarAltaLeccion();

                //Alta Leccion C2
                    //L3
                    ControladorCurso->seleccionarCurso("Curso de ingles basico");
                    ControladorCurso->ingresarInfoLeccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
                    ControladorCurso->confirmarAltaLeccion();
                    //L4
                    ControladorCurso->seleccionarCurso("Curso de ingles basico");
                    ControladorCurso->ingresarInfoLeccion("Presente Simple", "Aprender el uso del presente simple");
                    ControladorCurso->confirmarAltaLeccion();

                //Alta Leccion C3
                    //L5
                    ControladorCurso->seleccionarCurso("Ingles intermedio: mejora tu nivel");
                    ControladorCurso->ingresarInfoLeccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes");
                    ControladorCurso->confirmarAltaLeccion();

                //Alta Leccion C4
                    //L6
                    ControladorCurso->seleccionarCurso("Curso avanzado de ingles");
                    ControladorCurso->ingresarInfoLeccion("Uso de modales avanzados", "Explorar el uso de los modales complejos.");
                    ControladorCurso->confirmarAltaLeccion();

                //Alta Leccion C5
                    //L7
                    ControladorCurso->seleccionarCurso("Portugues intermedio");
                    ControladorCurso->ingresarInfoLeccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas.");
                    ControladorCurso->confirmarAltaLeccion();

            // Alta Ejercicios
                    //E1
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->seleccionarLeccion("Saludos y Presentaciones");
                    ControladorCurso->ingresarInfoEjercicio("Presentaciones");
                    ControladorCurso->agregarDatosTraducir("Mucho gusto en conocerte", "Nice to meet you");
                ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

                    //E2
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->seleccionarLeccion("Saludos y Presentaciones");
                    ControladorCurso->ingresarInfoEjercicio("Presentaciones formales");
                    ControladorCurso->agregarDatosTraducir("Please --- me to introduce ---", "allow, myself");
                    ControladorCurso->confirmarAltaEjercicio(CompletarPalabras);

                    //E3
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->seleccionarLeccion("Artículos y Plurales");
                    ControladorCurso->ingresarInfoEjercicio("Plurales regulares");
                    ControladorCurso->agregarDatosTraducir("I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
                    ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

                    //E4
                    ControladorCurso->seleccionarCurso("Ingles para principiantes");
                    ControladorCurso->seleccionarLeccion("Artículos y Plurales");
                    ControladorCurso->ingresarInfoEjercicio("Sustantivos contables en plural");
                    ControladorCurso->agregarDatosTraducir("Can I have --- water, please?", "some");
                    ControladorCurso->confirmarAltaEjercicio(CompletarPalabras);

                    //E5
                    ControladorCurso->seleccionarCurso("Curso de ingles basico");
                    ControladorCurso->seleccionarLeccion("Actividades Cotidianas");
                    ControladorCurso->ingresarInfoEjercicio("Actividades diarias");
                    ControladorCurso->agregarDatosTraducir("Wake ---", "up");
                    ControladorCurso->confirmarAltaEjercicio(CompletarPalabras);

                    //E6
                    ControladorCurso->seleccionarCurso("Ingles intermedio: mejora tu nivel");
                    ControladorCurso->seleccionarLeccion("Conversaciones cotidianas");
                    ControladorCurso->ingresarInfoEjercicio("Consultas de la hora");
                    ControladorCurso->agregarDatosTraducir("Q:Do you --- the time?, A: Yes, it is half --- 4 ", "have, past");
                    ControladorCurso->confirmarAltaEjercicio(CompletarPalabras);
                    
                    //E7
                    ControladorCurso->seleccionarCurso("Curso avanzado de ingles");
                    ControladorCurso->seleccionarLeccion("Uso de modales avanzados");
                    ControladorCurso->ingresarInfoEjercicio("Dar consejos o expresar obligacion");
                    ControladorCurso->agregarDatosTraducir("You should visit that museum", "Deberias visitar ese museo");
                    ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

                    //E8
                    ControladorCurso->seleccionarCurso("Portugues intermedio");
                    ControladorCurso->seleccionarLeccion("Lectura y comprension de textos");
                    ControladorCurso->ingresarInfoEjercicio("Imperativo");
                    ControladorCurso->agregarDatosTraducir("Fale comigo", "Habla conmigo");
                    ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

            //Habilitaciones
                    //Habilito Curso C1
                    ControladorCurso->confirmarHabilitacion("Ingles para principiantes");
                    //Habilito Curso C3
                    ControladorCurso->confirmarHabilitacion("Ingles intermedio: mejora tu nivel");
                    //Habilito Curso C4
                    ControladorCurso->confirmarHabilitacion("Curso avanzado de ingles");
                    //Habilito Curso C5
                    ControladorCurso->confirmarHabilitacion("Portugues intermedio");
            
            //Inscripciones
                    //N1
                    ControladorCurso->confirmarInscripcion("jpidiom", "Ingles para principiantes");
                    //N2
                    ControladorCurso->confirmarInscripcion("jpidiom", "Ingles intermedio: mejora tu nivel");
                    //N3
                    ControladorCurso->confirmarInscripcion("jpidiom", "Curso avanzado de ingles");
                    //N4
                    ControladorCurso->confirmarInscripcion("marsilva", "Ingles para principiantes");
                    //N5
                    ControladorCurso->confirmarInscripcion("pero12", "Ingles para principiantes");
                    //N6
                    ControladorCurso->confirmarInscripcion("laugu", "Ingles para principiantes");
                    //N7
                    ControladorCurso->confirmarInscripcion("laugu", "Portugues intermedio");
                    //N8
                    ControladorCurso->confirmarInscripcion("carlo22", "Portugues intermedio");
                    

            //Ejercicios Aprobados
                    //N1 E1
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "jpidiom");
                    ControladorCurso->seleccionarEjercicio(stoi("1"));
                    ControladorCurso->validarEjercicio("Nice to meet you");
                    
                    //N1 E2
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "jpidiom");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("allow, myself");

                    //N1 E3
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "jpidiom");
                    ControladorCurso->seleccionarEjercicio(stoi("1"));
                    ControladorCurso->validarEjercicio("Tengo dos hermanos y tres hermanas");

                    //N1 E4
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "jpidiom");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("some");

                    //N2 E6
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles intermedio: mejora tu nivel", "jpidiom");
                    ControladorCurso->seleccionarEjercicio(stoi("1"));
                    ControladorCurso->validarEjercicio("have, past");

                    //N4 E1
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "marsilva");
                    ControladorCurso->seleccionarEjercicio(stoi("1"));
                    ControladorCurso->validarEjercicio("Nice to meet you");

                    //N4 E2
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "marsilva");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("allow, myself");

                    //N5 E1
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "pero12");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("Nice to meet you");

                    //N5 E2
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "pero12");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("allow, myself");

                    //N5 E4
                    ControladorCurso->obtenerEjerciciosPendientes("Ingles para principiantes", "pero12");
                    ControladorCurso->seleccionarEjercicio(stoi("2"));
                    ControladorCurso->validarEjercicio("some");

                    cout << "Datos genéricos cargados correctamente!" << endl;
                break;
            }

            //Default   
            default:{
                cout << "" << endl;
                cout << "Ingrese una opción correcta..." << endl;
            } 
                
        }
        if (continuarSesion) {
            std::cout << "       " <<endl;;
            std::cout << "________________________________________________" << endl;;
            std::cout << "Presione Enter para volver al menú principal...";
            clearInputBuffer();
        }
                
        }
        if (continuarSesion) {
            std::cout << "       " <<endl;;
            std::cout << "________________________________________________" << endl;;
            std::cout << "Presione Enter para volver al menú principal...";
            clearInputBuffer();
        }
    return 0;

    }
