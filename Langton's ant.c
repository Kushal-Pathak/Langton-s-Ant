//Developed By Kushal Pathak
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define h 25
#define w 25
#define black 'X'
#define white ' '

char ant='^';
int x=12, y=12, dir=1, step=25;
float speed=0.1;
char matrix[h][w];

void init();
void display();
int turnRight();
int turnLeft();
void flipColor();
char color();
void setColor(char);
void moveForward();
void delay(float);
void turn();
void checkBoundary();
void menu();

void main(){
	system("cls");
	init();
	int i=0;
	char ch;
	menu();
	while(i<=step){
		display();
		printf("------------------Step %d------------------",i);
		turn();
		flipColor();
		moveForward();
		delay(speed);
		i++;
	}
	getch();
}
void turn(){
	if(color(x,y)==white) turnRight();
	else turnLeft();
}
void moveForward(){
	switch(dir){
		case 1: y--; checkBoundary(); break;
		case 2: x++; checkBoundary(); break;
		case 3: y++; checkBoundary(); break;
		case 4: x--; checkBoundary(); break;
	}
}

void flipColor(){
	if(color(x,y)==black) setColor(white);
	else setColor(black);
}
char color(){
	if(matrix[y][x]==black) return black;
	return white;
}
void setColor(char color){
	matrix[y][x]=color;
}
int turnRight(){
	switch(dir){
		case 1: dir = 2; ant='>'; break;
		case 2: dir = 3; ant='v'; break;
		case 3: dir = 4; ant='<'; break;
		case 4: dir = 1; ant='^';break;
	}
}
int turnLeft(){
	switch(dir){
		case 4: dir = 3; ant='v'; break;
		case 3: dir = 2; ant='>'; break;
		case 2: dir = 1; ant='^'; break;
		case 1: dir = 4; ant='<';break;
	}
}
void display(){
	system("cls");
	int i, j;
	for(i=0;i<h;i++){
		printf("\n");
		for(j=0;j<w;j++){
			if(i==y&&j==x) printf("%c ",ant);
			else printf("%c ",matrix[i][j]);
		}	
	}
	printf("\n");
}
void checkBoundary(){
	if(x>=w) x=0;
	if(x<0) x=w-1;
	if(y>=h) y=0;
	if(y<0) y=h-1;
}
void delay(float n){
	int i, j, k;
	for(i=0; i<100; i++){
		for(j=0; j<1000; j++)
			for(k=0; k<n*50; k++);
	}
}
void init(){
	int i, j;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++)
			matrix[i][j]=white;
	}
}
void menu(){
	printf("Langton's Ant by Kushal Pathak\n");
	printf("Enter speed (Eg: 50): ");
	scanf("%f",&speed);
	printf("Enter steps: ");
	scanf("%d",&step);
}
