#include <iostream>

//  Funcion para solicitar datos
void SolicitarInformacion();
//  Funcion para imprimir
void Imprimir(struct Album[]);
//  Funcion para CalcularAntiguedad
void CalcularAntiguedad(struct Album[], int);
//  Funcion cantidad de album donde la antiguedad mayor o igual 10
int CalcularCantAntiguedadAlbum(struct Album[]);
//  Funcion mostrar mensaje segun cantidad de antiguedad
void MostrarMensaje(int);
// Funcion buscar cantante
struct Album BuscarAlbumCantante(struct Album[], std::string);
// Mostrar informacion de album cantante
void MostrarInfAlbumCantante(struct Album);

struct Disquera
{
    std::string nombre;
    std::string pais;
};

struct Album
{
    std::string nombre_album;
    std::string nombre_cantante;
    std::string titulo_cancion[2];
    std::string numero_pista[2];
    float duracion_cancion[2];
    int anio_publicacion;
    int antiguedad;
    struct Disquera disquera;
    
} album[2];

int main(int argc, char *argv[])
{

    std::string cantante;
    SolicitarInformacion();
    CalcularAntiguedad(album, 2024);
    Imprimir(album);
    std::cout << "Cantidad de antiguedad de album mayores a 10 años: " << CalcularCantAntiguedadAlbum(album) << " \n";
    MostrarMensaje(CalcularCantAntiguedadAlbum(album));
    std::cout << "Ingresa el nombre del cantante para ver el album: ";
    std::cin >> cantante;
    MostrarInfAlbumCantante(BuscarAlbumCantante(album, cantante));

    return 0;
}

void SolicitarInformacion()
{

    for (int i = 0; i < 2; i++)
    {
        std::cout << "--------- Album " << i + 1 << " ---------\n";
        std::cout << "Ingrese el nombre del album " << i + 1 << ": ";
        std::cin >> album[i].nombre_album;
        std::cout << "Ingrese el nombre del cantante: ";
        std::cin >> album[i].nombre_cantante;

        for (int j = 0; j < 2; j++)
        {
            std::cout << "Ingrese el titulo de la cancion: ";
            std::cin >> album[i].titulo_cancion[j];
            std::cout << "Ingrese el numero de pista: ";
            std::cin >> album[i].numero_pista[j];
            std::cout << "Ingrese la duracion de la cancion min: ";
            std::cin >> album[i].duracion_cancion[j];
        }
        std::cout << "Ingrese el año publicacion del album: ";
        std::cin >> album[i].anio_publicacion;
        std::cout << "Ingrese el nombre de la disquera: ";
        std::cin >> album[i].disquera.nombre;
        std::cout << "Ingresa el nombre del pais de la disquera: ";
        std::cin >> album[i].disquera.pais;
    }
}

void Imprimir(struct Album album[])
{
    std::cout << " --------- Informacion de los album ingresados ------- \n ";
    for (int i = 0; i < 2; i++)
    {
        std::cout << "--------- Album " << i + 1 << " ---------\n";
        std::cout << "Nombre del album: " << album[i].nombre_album << '\n';
        std::cout << "Nombre del cantante: " << album[i].nombre_cantante << '\n';

        for (int j = 0; j < 2; j++)
        {
            std::cout << "Titulo de la cancion: " << album[i].titulo_cancion[j] << '\n';
            std::cout << "Numero de pista: " << album[i].numero_pista[j] << '\n';
            std::cout << "Duracion de la cancion: " << album[i].duracion_cancion[j] << " min." << '\n';
        }
        std::cout << " --------------- Informacion Disquera------------------- '\n'";
        std::cout << "Año publicacion del album: " << album[i].anio_publicacion << '\n';
        std::cout << "Antiguedad del album: " << album[i].antiguedad << " años \n";
        std::cout << "Nombre de la disquera: " << album[i].disquera.nombre << '\n';
        std::cout << "Pais de la disquera: " << album[i].disquera.pais << '\n';
    }

    std::cout << " --------------------------------------------------------- \n";
}

void CalcularAntiguedad(struct Album album[], int anio_actual)
{

    for (int i = 0; i < 2; i++)
    {
        album[i].antiguedad = anio_actual - album[i].anio_publicacion;
    }
}

int CalcularCantAntiguedadAlbum(struct Album album[])
{

    int cantidad = 0;
    for (int i = 0; i < 2; i++)
    {
        if (album[i].antiguedad >= 10)
        {
            cantidad++;
        }
    }

    return cantidad;
}

void MostrarMensaje(int cantidad)
{

    if (cantidad >= 1)
    {
        std::cout << "Puedes descargar el album de tu preferencia \n";
    }
    else
    {
        std::cout << "Lo siento, no hay album que descargar \n";
    }
}

struct Album BuscarAlbumCantante(struct Album album[], std::string cantante)
{
    struct Album album_cantante;

    for (int i = 0; i < 2; i++)
    {
        if (cantante == album[i].nombre_cantante)
        {

            album_cantante = album[i];
        }
    }
    return album_cantante;
}

void MostrarInfAlbumCantante(struct Album album_cantante)
{
    std::cout << "------ Resultado de Album de cantante: " << album_cantante.nombre_cantante << " ------- \n";
    std::cout << "Nombre del album: " << album_cantante.nombre_album << '\n';
    std::cout << "Nombre del cantante: " << album_cantante.nombre_cantante << '\n';

    for (int j = 0; j < 2; j++)
    {
        std::cout << "Titulo de la cancion: " << album_cantante.titulo_cancion[j] << '\n';
        std::cout << "Numero de pista: " << album_cantante.numero_pista[j] << '\n';
        std::cout << "Duracion de la cancion: " << album_cantante.duracion_cancion[j] << " min." << '\n';
    }
    std::cout << " --------------- Informacion Disquera------------------- '\n'";
    std::cout << "Año publicacion del album: " << album_cantante.anio_publicacion << '\n';
    std::cout << "Antiguedad del album: " << album_cantante.antiguedad << "\n";
    std::cout << "Nombre de la disquera: " << album_cantante.disquera.nombre << '\n';
    std::cout << "Pais de la disquera: " << album_cantante.disquera.pais << '\n';
}
