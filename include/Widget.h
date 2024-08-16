#ifndef EZSTREAM_WIDGET_INTERFACE
#define EZSTREAM_WIDGET_INTERFACE

class Widget
{
protected:
    int _width, _height; // supplied width and height of object
    int _x, _y; // supplied x and y position of the object

    Widget(int x, int y, int width, int height);

public:
    virtual void render() = 0;
    virtual ~Widget() {}
};

#endif