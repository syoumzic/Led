#pragma once

#define BUFFER_SIZE 1024

#include <Arduino.h>

template<typename ... Args>
String format(const char* format, Args ... args){
    char message[BUFFER_SIZE]; snprintf(message, BUFFER_SIZE, format, args...);
    return String(message);
}