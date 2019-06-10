#ifndef BUFFDISP_H
#define BUFFDISP_H

#include <internal/platform.h>
#include <internal/array2d.h>
#include <utility>
#include <set>

class BufferedDisplay : public DisplayStrategy {

    Array2D<uchar> charBuffer;
    Array2D<ushort> attrBuffer;
    std::set<std::pair<int, int>> changes;
    int lastX, lastY;
    bool needsFlush;
    bool cursorMoved;

protected:

    void initBuffer();

    void setCaretPosition(int x, int y);
    void screenWrite(int x, int y, ushort *buf, int len);
    void flushScreen();

    virtual void lowlevelWriteChar(int x, int y, uchar character, ushort attr) = 0;
    virtual void lowlevelMoveCursor(int x, int y) = 0;
    virtual void lowlevelFlush() = 0;

};

#endif
