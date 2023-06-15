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
    cout << "10: Consultar Curso" << endl;
    cout << "11: Inscribirse a Curso" << endl;
    cout << "12: Realizar Ejercicio" << endl;
    //cout << "13: Consultar Estadísticas" << endl;
    cout << "14: Suscribirse a Notificaciones" << endl;
    //cout << "15: Consulta de Notificaciones" << endl;
    //cout << "16: Eliminar Suscripciones" << endl;
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
                getline(cin >> ws, paisResi);
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
                    getline(cin >> ws, Instituto);
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
                    while (!idiomasDispo.count(iter)) {
                      cout << "Seleccione un idioma válido:" << endl;
                      getline(cin >> ws, iter);
                    }
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
                bool tipoUsuario = ControladorUsuario->obtenerTipo(usuarioSeleccionado);
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
                while(!cursosNoHabilitados.count(cursoSeleccionado)) {
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

            //Consultar curso
            case(10): {
                // Obtengo Cursos
                set<string> cursos = ControladorCurso->obtenerCursos();
                cout << "Seleccione un curso:" << cursos.size() << endl;
                string cursoSeleccionado = "";
                // imprimo nombre de los cursos
                for (string nombre : cursos) {
                    cout << "-" + nombre << endl;
                }
                getline(cin >> ws, cursoSeleccionado);
                while (!cursos.count(cursoSeleccionado)) {
                    cout << "Seleccione un curso válido:" << endl;
                    getline(cin >> ws, cursoSeleccionado);
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
                        cout << "   *Ejercicios: " << endl;
                        if (!leccion.obtenerEjercicios().empty()){
                          for (DTEjercicio ej : leccion.obtenerEjercicios()) {
                            cout << "       + ID: " << ej.getId() << endl;
                            cout << "           + Descripcion: "
                                 << ej.getDescripcionEjercicio() << endl;
                            cout << "           + Tipo: "
                                 << obtenerTipoEjercicio(ej.getTipoEjercicio())
                                 << endl;
                          }
                        }
                        else{
                          cout << "Sin Ejercicios. " << endl;
                        }
                    }
                }
                else{
                    cout << "Sin Lecciones. " << endl;
                }
                    
                cout << "   *Inscripciones: " << endl;
                if(!infocurso.getInscripciones().empty()){
                    for (DTInscripcion ins : infocurso.getInscripciones()) {
                        cout << "   -Nombre: " << ins.obtenerNombre() << endl;
                        cout << "   -Fecha : " << ins.obtenerFecha().getDia()
                             << "/" << ins.obtenerFecha().getMes() <<
                            "/"<< ins.obtenerFecha().getAnio() << endl;
                    }
                }
                else{
                    cout << "       Sin Inscripciones." << endl;
                }
            
                break;
            }
           
            //Inscribirse A Curso
            case 11: {
                system("clear");
                set<string> estudiantesDisponibles = ControladorUsuario->obtenerEstudiantes();
                string estudiante = "";
                cout << "Ingrese nickname estudiante: " << endl;
                getline(cin >> ws, estudiante);
                while (!estudiantesDisponibles.count(estudiante)) {
                    cout << "Seleccione un nickname existente:" <<endl;
                    getline(cin >> ws, estudiante);
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
                    while (!nombresCursos.count(cursoSeleccionado)) {
                        cout << "Seleccione un curso valido:" << endl;
                        getline(cin >> ws, cursoSeleccionado);
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
               break;
            }

            //Realizar Ejercicio
            case (12): {
                //se ingresa nombre de estudiante
                set<string> nicknamesSistema = ControladorUsuario->obtenerUsuarios();
                string nicknameEstudiante = "";
                cout << "Ingrese Nickname de Estudiante:" << endl;
                getline(cin >> ws, nicknameEstudiante);
                while (!nicknamesSistema.count(nicknameEstudiante)) {
                    cout << "Ingrese un nickname válido:" << endl;
                    getline(cin >> ws, nicknameEstudiante);
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
                    while (!noAprobados.count(nombreCurso)) {
                        cout << "Ingrese un curso válido:" << endl;
                        getline(cin >> ws, nombreCurso);
                    }

                    set<DTEjercicio> ejNoAprobados = ControladorCurso->obtenerEjerciciosPendientes(nombreCurso, nicknameEstudiante);
                    set<string> idEjercicios;
                    //se imprimen ejercicios pendientes
                    for (DTEjercicio ejercicio : ejNoAprobados) {
                        idEjercicios.insert(to_string(ejercicio.getId()));
                        cout << "**SELECCIONE UN EJERCICIO**:" << endl;
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

                    //imprimo el ejercicio seleccionado
                        cout << "       -Descripción: " << ejercicioAMostrar.getDescripcionEjercicio() << endl;
                        cout << "       -Consigna: " << ejercicioAMostrar.getConsignaEjercicio() << endl;
                        cout << "   " << endl;
                    
                    cout << "Ingrese su respuesta: " << endl;

                    string respuesta = "";
                    getline(cin >> ws, respuesta);
                    if(ControladorCurso->validarEjercicio(respuesta)){
                        cout << "RESPUESTA CORRECTA!" << endl;
                        cout << "   *Ejercicio Aprobado!" << endl;
                    }
                    else{
                        cout << "RESPUESTA INCORRECTA!" << endl;
                    }
                }
                else{
                    cout << "No hay cursos no aprobados disponibles." << endl;
                }
               break;
            }

            //suscribirse a notificaciones
            case 14: {
                set<string> usuarios = ControladorUsuario->obtenerUsuarios();
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
                set<string> idiomasDisponibles = ControladorUsuario->obtenerSubscripcionesPendientes(nicknameUsuario);
                set<string> idiomasASuscribirse;

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
                break;
            }
           
           //Salida
            case 18:{
                return 0;
            }

            //carga de datos
            case 17: {
                system("clear");
                set<string> col;
                col.insert("Ingles1");
                //AltaIdioma
                ControladorUsuario->agregarIdioma("Inglés");
                ControladorUsuario->agregarIdioma("Chino");
                //Alta profesor
                ControladorUsuario->ingresarDatosUsuario("joaco_", "joaco123",
                                                         "Joaquín", "ProfUser");
                ControladorUsuario->ingresarInstituto("Fing");
                ControladorUsuario->agregarEspecializacion("Inglés");
                ControladorUsuario->confirmarAltaProfesor();

                ControladorUsuario->ingresarDatosUsuario("profe_", "joaco123",
                                                        "Joaquín", "ProfUser");
                ControladorUsuario->ingresarInstituto("Fing");
                ControladorUsuario->agregarEspecializacion("Inglés");
                ControladorUsuario->confirmarAltaProfesor();

                //Alta cursoIngles1
                ControladorCurso->ingresarInfoCurso("Ingles1", "cursoDesc",
                                                    Principiante);
                ControladorCurso->asignarProfesor("joaco_");
                ControladorCurso->seleccionarIdioma("Inglés");
                ControladorCurso->confirmarAltaCurso();

                //agrego 1 leccion y 1 ejercicio a Ingles1.
                ControladorCurso->seleccionarCurso("Ingles1");
                ControladorCurso->ingresarInfoLeccion("Tema1",
                                                      "Objetivo1");
                ControladorCurso->confirmarAltaLeccion();
                ControladorCurso->seleccionarCurso("Ingles1");
                ControladorCurso->seleccionarLeccion("Tema1");
                ControladorCurso->ingresarInfoEjercicio("Traduzca");
                ControladorCurso->agregarDatosTraducir("frase", "phrase");
                ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

                //Habilito Curso Inglés 1
                ControladorCurso->confirmarHabilitacion("Ingles1");

                // Alta curso Chino
                ControladorCurso->ingresarInfoCurso("Chino", "cursoDesc",
                                                    Principiante);
                ControladorCurso->asignarProfesor("profe_");
                ControladorCurso->seleccionarIdioma("Chino");
                ControladorCurso->confirmarAltaCurso();

                // agrego 1 leccion y 1 ejercicio a Chino
                ControladorCurso->seleccionarCurso("Chino");
                ControladorCurso->ingresarInfoLeccion("Tema1", "Objetivo1");
                ControladorCurso->confirmarAltaLeccion();
                ControladorCurso->seleccionarCurso("Chino");
                ControladorCurso->seleccionarLeccion("Tema1");
                ControladorCurso->ingresarInfoEjercicio("Traduzca");
                ControladorCurso->agregarDatosTraducir("frase", "phrase");
                ControladorCurso->confirmarAltaEjercicio(TraducirFrase);

                // Habilito Curso Chino
                ControladorCurso->confirmarHabilitacion("Chino");

                //Alta Curso Ingles2
                ControladorCurso->ingresarInfoCurso("Ingles2", "cursoDesc",
                                                    Principiante);
                ControladorCurso->asignarProfesor("joaco_");
                ControladorCurso->seleccionarIdioma("Inglés");
                ControladorCurso->ingresarCursosPrevios(col);
                ControladorCurso->confirmarAltaCurso();

                //alta de estudiante
                ControladorUsuario->ingresarDatosUsuario("estudiante", "joaco123",
                                                         "Joaquín", "EstudianteDesc");
                DTFecha Fecha = DTFecha(10, 12, 2002);
                ControladorUsuario->ingresarDatosEstudiante("Uruguay", Fecha);
                ControladorUsuario->confirmarAltaEstudiante();
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