#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    double x0=0;
    double y0=0;
    PenStyle style = { 1, "white" }; //  initialized
for (string line; getline(input, line); ) {
    Vector<string>result=stringSplit(line," ");
    if("penup"==toLowerCase(result[0])){
    style.color="white";
    }
    if("pendown"==toLowerCase(result[0])){
    style.color="black";
    }
    if("moveabs"==toLowerCase(result[0])){
        double x=stringToReal(result[1]);
        double y=stringToReal(result[2]);
        drawLine(x0,y0,x,y,style);
    }
    if("moverel"==toLowerCase(result[0])){
        double x=x0+stringToReal(result[1]);
        double y=y0+stringToReal(result[2]);
        drawLine(x0,y0,x,y,style);
    }
    if("penwitdh"==toLowerCase(result[0])){
        double width=stringToReal(result[1]);
        style.width=width;
    }
    if("pencolor"==toLowerCase(result[0])){
       style.color=result[1];
    }
}
}
