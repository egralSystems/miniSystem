#include "stream.hpp"

template <typename DataType>
Stream<DataType>::Stream(StreamIf<DataType> *sif)
{
    this->sif = sif;
}

template <typename DataType>
bool Stream<DataType>::isReadable()
{
    return sif->readable;
}

template <typename DataType>
bool Stream<DataType>::isWritable()
{
    return sif->writable;
}