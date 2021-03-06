#ifndef LAB_2_PNMIMAGE_H
#define LAB_2_PNMIMAGE_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <fstream>

using byte = unsigned char;

class PNMImage {
private:
    struct Point {
        double x;
        double y;
        Point& operator=(const Point& other) = default;
    };
    struct Rect {
        Point A, B, C, D;
    };

    std::vector<byte> Buffer;
    std::vector<byte> ImageData;
    uint64_t Size, Width, Height, ColourDepth;
    uint8_t Type;
    struct Point start, end;
    struct Rect line;

    void drawPoint(int, int, double, byte, double);

    double opacity(double x, double y);

public:

    static std::vector<byte> ReadBinary(const char*, uint64_t);

    static void WriteBinary(const char*, const std::vector<byte>&);

    explicit PNMImage(const char*);

    void Export(const char*);

    void Invert();

    void Mirror(int);

    void Rotate(int direction);

    bool isGrey();

    bool isColor();

    void drawThickLine(double, double, double, double, byte, double, double);
};


#endif
