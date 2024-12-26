#include "sortPixelQueue.hpp"
#include "PixelQueue.hpp"
#include "List.hpp"
#include "RGBPixelXY.hpp"

// Constructor
sortPixelQueue::sortPixelQueue() {}

// Destructor
sortPixelQueue::~sortPixelQueue() {}

// Función para ordenar los píxeles desde una cola a una lista ordenada
List<RGBPixelXY> sortPixelQueue::sortPixels(Queue& queue) {
    List<RGBPixelXY> sortedList;  // Crea una lista vacía para almacenar los píxeles ordenados

    // Procesa todos los píxeles en la cola
    while (!queue.isEmpty()) {
        RGBPixelXY currentPixel = queue.peek();  // Obtiene el siguiente píxel de la cola sin eliminarlo
        queue.dequeue();  // Elimina el píxel de la cola

        // Determina la posición correcta en la lista ordenada
        unsigned int position = 0;  // Comienza desde el inicio de la lista

        // Recorre la lista ordenada para encontrar la posición correcta
        for (typename List<RGBPixelXY>::Node* currentNode = sortedList.getHead(); currentNode != nullptr; currentNode = currentNode->next) {
            if (currentPixel.getSumRGB() <= currentNode->data.getSumRGB()) {
                break;  // Detiene cuando se encuentra la posición correcta
            }
            ++position;  // Avanza a la siguiente posición
        }

        // Inserta el píxel en la posición correcta de la lista ordenada
        sortedList.insertAtPosition(position, currentPixel);
    }

    return sortedList;  // Devuelve la lista ordenada de píxeles
}
