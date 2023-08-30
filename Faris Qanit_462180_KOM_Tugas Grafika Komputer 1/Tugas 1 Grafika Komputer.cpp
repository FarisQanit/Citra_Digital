#include <graphics.h>
#include <iostream>
#include <ctime>
 
int main(){
    double x,y,x1,y1,x2,y2,dx,dy,m;
    int line=0;
    int warna=0;
    int i,gd=DETECT,gm;
    initwindow(1000,1000);
    srand(time(NULL));
    //initgraph(&gd, &gm, "C:\\TC\\BGI");  
    setbkcolor(WHITE);
    while (line <= 100) {
        
            x1 = rand() % (250);
            x2 = rand() % (250);
            y1 = rand() % (250);
            y2 = rand() % (250);
            warna = 4+rand() % (7);

        dx=abs(x2-x1);
        dy=abs(y2-y1);
        
        if(dx>=dy)
            m=dx;
        else
            m=dy;
        
        dx=dx/m;
        dy=dy/m;
        
        x=x1;
        y=y1;
        
        i=1;
        while(i<=m){
            putpixel(x,y,warna);
                x=x+dx;
                y=y+dy;
                i=i+1;
                delay(5);
       } 
    line++;
    }
   closegraph();
}

