#include<iostream> //Faris Qanit
#include<stdio.h>  //20/462180/PA/20152
#include<math.h>
#include<graphics.h>

using namespace std;

float xvmin, xvmax, yvmin, yvmax;
float xwmin, xwmax, ywmin, ywmax; 

typedef struct coordinate { 
    float x,y;
}coord;

void drawwindow() {
    line(150,100,450,100);
	line(450,100,450,350);
	line(450,350,150,350);
	line(150,350,150,100);
}

void WV(float xw,float yw,int &xv,int &yv) {
	xwmin=-1; xwmax=4; ywmin=-2.5; ywmax=2.5; //window
    xvmin=50; xvmax=550; yvmin=50; yvmax=550; //viewport
    
	//xv=xvmin+round((xw-xwmin)*(xvmax-xvmin)/(xwmax-xwmin));
    //yv=yvmax-round((yw-ywmin)*(yvmax-yvmin)/(ywmax-ywmin));
}

void segitiga(coord p[3]) { // Untuk membuat bentuk segitiga
    line(p[0].x, p[0].y, p[1].x, p[1].y);
    line(p[1].x, p[1].y, p[2].x, p[2].y);
    line(p[2].x, p[2].y, p[0].x, p[0].y);
}
void ResetGambar() { // Untuk kembali ke bentuk awal
	setcolor(WHITE);
	int XT,YT,XI,YI;
	xvmin=50; xvmax=550; yvmin=50; yvmax=550; 
	
	WV(-1,0,XT,YT);
    WV(4,0,XI,YI);
	line(XT,YT,XI,YI);
	
	WV(1.5,-2.5,XT,YT);
    WV(1.5,2.5,XI,YI);
    line(XT,YT,XI,YI);
    
	rectangle(xvmin,yvmin,xvmax,yvmax); // Membuat viewport
	
	coord p[3];
	p[0].x = 400; p[0].y = 130;
	p[1].x = 415; p[1].y = 180;
	p[2].x = 470; p[2].y = 180;
	segitiga(p);
}


void Rotasi(coord p[3], float s) {
	coord r[3];
	int xp,yp,x,y; xp=300; yp=300;
	for(int i=0;i<3;i++) {
		x = p[i].x;
		y = p[i].y;
	    r[i].x = xp+round((x-xp)*cos((360-s)*M_PI/180) - (y-yp)*sin((360-s)*M_PI/180));
	    r[i].y = yp+round((x-xp)*sin((360-s)*M_PI/180) + (y-yp)*cos((360-s)*M_PI/180));
	    p[i].x = r[i].x;
	    p[i].y = r[i].y;
	}
	setcolor(YELLOW);
	segitiga(p);
}

void Skala(coord p[3], float sc) {
	coord skala[3];
	int xp,yp,x,y; xp=300; yp=300;
	for(int i=0;i<3;i++) {
		x = p[i].x;
		y = p[i].y;
	    skala[i].x = xp+round(sc*(x-xp));
	    skala[i].y = yp+round(sc*(y-yp));
	}
	setcolor(LIGHTRED);
	segitiga(skala);
}

void Shearx(coord p[3], float shx) {
	coord sh[3];
	int yp,x,y; yp=300;
	for(int i=0;i<10;i++) {
		x = p[i].x;
		y = p[i].y;
	    sh[i].x = x + shx*(y-yp);
	    sh[i].y = y;
	}
	setcolor(CYAN);
	segitiga(sh);
}

void Sheary(coord p[3], float shy) {
	coord sh[3];
	int xp,x,y; xp=300; 
	for(int i=0;i<3;i++) {
		x = p[i].x;
		y = p[i].y;
	    sh[i].x = x;
	    sh[i].y = shy*(x-xp) + y;
	}
	setcolor(LIGHTGREEN);
	segitiga(sh);
}


int main() {
	int menu; char ulang; float input;
	initwindow(600,600,"N",50,50,false,true);
    
    ResetGambar(); //Membuat tampilan awal
	
	coord p[3];
	p[0].x = 400; p[0].y = 130;
	p[1].x = 415; p[1].y = 180;
	p[2].x = 470; p[2].y = 180;

	// Switch case untuk memilih transformasi yang akan dilakukan
	do {
	    cout<<"--------------------------------------"<<endl<<
	        "        Transformasi Geometri 2D        "<<
			"\n--------------------------------------"<<
            "\n1 - Rotasi"<<
            "\n2 - Skala"<<
            "\n3 - Shear X"<<
            "\n4 - Shear Y"<<
            "\n5 - Reset Gambar"<<
		    "\n6 - Keluar"<<endl;
        cout<<"Pilih menu ke : ";
	    cin>>menu;
	    cout<<endl;
	    switch (menu) {
		    case 1 :
		        cout<<"Masukkan sudut rotasi: "; 
		            cin>>input;
			    Rotasi(p,input);
		        do{
		        	cout<<"Ulangi? (Y or N)"; 
		            cin>>ulang;
		            switch(ulang) {
		            	case 'y':
		            	case 'Y':
		            		Rotasi(p,input);
					}
				} while(ulang == 'Y' or ulang == 'y');
                    cout<<endl; break;
		    case 2 :
			    cout<<"Masukkan skala: "; 
		            cin>>input;
		        Skala(p,input);
		        cout<<endl; break;
            case 3 :
        	    cout<<"Masukkan shear x: "; 
		            cin>>input;
		        Shearx(p,input);
				cout<<endl; break;
		    case 4 :
			    cout<<"Masukkan shear y: "; 
		            cin>>input;
		        Sheary(p,input);
	            cout<<endl; break;
		    case 5 :
			    cleardevice(); // Isi windwow dihapus
				ResetGambar(); // Ke tampilan awal lagi
				break;
		    case 6 : return 0; break;
		    default : cout<<"Input salah";
        }
        cout<<endl;
	} while (menu != 6);
	
	getch();
	closegraph();
}

