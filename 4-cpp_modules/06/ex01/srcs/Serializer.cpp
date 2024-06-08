#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &)
{
}

Serializer &Serializer::operator=(const Serializer &)
{
    return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
    if (ptr == NULL)
        return (0);
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    if (raw == 0)
        return (NULL);
    return (reinterpret_cast<Data *>(raw));
}
