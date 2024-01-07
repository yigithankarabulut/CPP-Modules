#pragma once

#include <string>

typedef struct {
    float a, b;
} Data;

class Serializer {
public:
    static uintptr_t serialize(Data* data);
    static Data* deserialize(uintptr_t raw);
};
