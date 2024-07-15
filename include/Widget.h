#ifndef EZSTREAM_WIDGET_INTERFACE
#define EZSTREAM_WIDGET_INTERFACE

class Widget
{
protected:
    // supplied width and height of object
    int _width, _height;
    // supplied x and y position of the object
    int _x, _y;

    Widget(int x, int y, int width, int height);

public:
    virtual void render() = 0;
    virtual ~Widget() {}
};

#endif