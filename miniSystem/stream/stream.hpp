#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>

template <typename DataType>
class StreamIf
{
public:
    bool readable;
    bool writable;

    virtual void write(const std::vector<DataType> &src) = 0;
    virtual void read(std::vector<DataType> &dst) = 0;
};

template <typename DataType>
class Stream
{
private:
    StreamIf<DataType> *sif = nullptr;

public:
    Stream(StreamIf<DataType> *sif);
    Stream() {}
    ~Stream() {}

    void init(StreamIf<DataType> *sif)
    {
        this->sif = sif;
    }

    bool isReadable();
    bool isWritable();

    friend Stream<DataType> &operator<<(Stream<DataType> &stream, const std::vector<DataType> &src)
    {
        if (stream.sif)
            stream.sif->write(src);

        return stream;
    }

    friend Stream<DataType> &operator>>(Stream<DataType> &stream, std::vector<DataType> &dst)
    {
        if (stream.sif)
            stream.sif->read(dst);

        return stream;
    }
};