#ifndef BBALLCOURT
#define BBALLCOURT

#include "mat.h"

class BBallCourt
{
    public:
        BBallCourt();
        virtual ~BBallCourt();
        void drawBBallCourt(mat4& mv);
        int courtLength;
        int courtWidth;


    protected:

    private:
        void drawDude(mat4& mv);
        void drawCheer(mat4& mv);
        void drawBackBoard(mat4& mv);
        void drawCourt(mat4& mv);
        void drawBleachers(mat4& mv);
        void drawOnBackBoard(mat4& mv);
        void drawG(mat4& mv, vec4 color);
        void drawO(mat4& mv, vec4 color);
        void drawZ(mat4& mv, vec4 color);
        void drawA(mat4& mv, vec4 color);
        void drawS(mat4& mv, vec4 color);
        void drawCourtLines(mat4& mv);
        void drawSeats(mat4& mv);
        void makeBleachers(mat4& mv, int length, int width, int yLevel, int seatLength, const vec4& color);
};

#endif // BBALLCOURT_H_INCLUDED
