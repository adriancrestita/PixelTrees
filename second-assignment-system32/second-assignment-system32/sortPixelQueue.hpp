#ifndef SORTPIXELQUEUE_HPP
#define SORTPIXELQUEUE_HPP

#include "Queue.hpp"
#include "List.hpp"
#include "RGBPixelXY.hpp"

// Clase que maneja la ordenación de los píxeles en una lista
class sortPixelQueue {
public:
    // Constructor
    sortPixelQueue();

    // Destructor
    ~sortPixelQueue();

    // Función para ordenar los píxeles desde una cola a una lista ordenada
    List<RGBPixelXY> sortPixels(Queue& queue);
};

#endif // SORTPIXELQUEUE_HPP
