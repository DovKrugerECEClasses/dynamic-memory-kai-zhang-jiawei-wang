/*
    Author: Kai Zhang
    Stevens Institute of Technology
*/

#include <iostream>
#include "Color.hh"
#include<cmath>
#include<string>
using namespace std;

class Bitmap{
private:
     int length;
     int width;
public:
    Bitmap(int a, int b){
        length=a;
        width=b;
        //char map[a][b]={};
    }

    char map[30][20]={};

    int sign(double a){
        if (a>0)
            return 1;
        else if (a<0)
            return -1;
        else
            return 0;
    }

    void line(int x0, int y0, int x1, int y1, Color c){
       char c1;
        if(c.red == 255 )
             c1 = 'R';
        else
             c1='B';
        double deltax = x1 - x0;
        double deltay = y1 - y0;
        double deltaerr = abs(deltay / deltax);
        double error = 0.0; // No error at start
        int y = y0;
        for (int x = x0; x <= x1; x++ )
        {
            map[x][y] = c1;
            error = error + deltaerr;
            if (error >= 0.5) {
                y = y + sign(deltay) * 1;
                error = error - 1.0;
            }
        }
    }

    void horizLine(int x0, int x1, int y0, Color c){
        char c1;
        int y = y0;
        if(c.green == 0 )
            c1 = 'K';
        else if (c.red == 0 )
                c1 = 'G';
        else
            c1 = 'W';
        for(int x = x0; x<=x1; x++){
            map[x][y]= c1;
        }
    }

    void vertLine(int x0, int y0, int y1, Color c){
        char c1;
        int x = x0;
        if(c.red == 255 )
            c1 = 'W';
        else
            c1 = 'G';
        for(int y = y0; y<=y1; y++){
            map[x][y]= c1;
        }

    }

    void fillRect(int x, int y, int w, int h, Color c){
        int y0 = y;
        for(int i = 0; i<h; i++){
            int x0 = x;
            //int y0 = y;
            int x1 = x0+w-1;
            horizLine(x0, x1, y0, c);
            y0++;
        }
        //horizLine(x0, int x1, int y0, Color c)
    }

    void drawRect(int x, int y, int w, int h, Color c){
        int y0 = y;
        int x0 = x;
        int x1 = x+w-1;
        horizLine(x0, x1, y0, c);
        y0 = y+h;
        horizLine(x0, x1, y0, c);
        x0 = x;
        y0 = y;
        int y1 = y+h;
        vertLine(x0, y0, y1, c);
        x0= x + w-1;
        vertLine(x0, y0, y1, c);
        /*for(int i = 0; i<h; i++){
            int x0 = x;
            //int y0 = y;
            int x1 = x0+w-1;
            horizLine(x0, x1, y0, c);
            y0++;
        }*/
        //horizLine(x0, int x1, int y0, Color c)
    }

    friend ostream& operator <<(ostream& s, const Bitmap& b){
        for (int i = 0; i < 30; i++) {
            cout<<'\n';
            for (int j = 0; j < 20; j++) {
                cout << b.map[i][j];
            }
        }
    }
};
int main() {

    Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA

    // top left pixel = (0,0)

    Color RED(255,0,0); // all red, no green, no blue (fully opaque)

    Color BLUE(0,255,0);

    Color GREEN(0,0,255);

    Color WHITE(255,255,255);

    Color BLACK(0,0,0);


    b.line(0,0,   19,19, RED);

    b.line(0,5,   29,10, BLUE); //Bresenham algorithm

    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm



    // https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm

    //TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm

    b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19

    b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
    b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3

    b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
/*
    b.ellipse(15,0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
*/
    cout << b;

}