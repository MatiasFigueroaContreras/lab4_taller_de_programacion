/*
    Descripcion de la clase FordFulkersonData:
    Esta clase tendra la informacion referente a un nodo
    que esta conectado con otro, ademas se agrega informacion
    necesaria para que el algoritmo de Ford-Fulkerson
    funcione de manera más rapida.
*/
class FordFulkersonData
{
private:
public:
    int node; // Nodo al cual va la arista
    int capacity; // Capacidad de la conexion
    int pos; // Posicion en la que se encontrara la arista en la representacion del grafo
    int posReverseDirection; // Posicion en la que se encontrara la arista en direccion contraria en la representacion del grafo
    FordFulkersonData();
    ~FordFulkersonData();
};
