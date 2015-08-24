#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
 
typedef struct{

	int x;
	int y;

}Coordinates;

Coordinates p[10000];

int compareX(const void* a, const void* b){
    Coordinates *p1 = (Coordinates *)a,  *p2 = (Coordinates *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b){
    Coordinates *p1 = (Coordinates *)a,   *p2 = (Coordinates *)b;
    return (p1->y - p2->y);
}

void createMatrix(){

	int n=10000;
	
	for(int i=0;i<n;i++){
		p[i].x=i*i;
		p[i].y=i*2*i;
	}
	
}

float getDistance(int x1, int x2, int y1, int y2){

	float dist = 0;
	
	int xdiff = x2-x1;
	int ydiff = y2-y1;
	
	dist = sqrt((xdiff*xdiff) + (ydiff*ydiff));
	
	return dist;

}
 
 
float searchClosest(Coordinates p[], int n){
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (getDistance(p[i].x, p[j].x, p[i].y, p[j].y) < min)
                min = getDistance(p[i].x, p[j].x, p[i].y, p[j].y);
    return min;
}
 
 
float getMid(Coordinates mp[], int size, float d){
    float min = d;
 
    qsort(p, size, sizeof(Coordinates), compareY);
 
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (p[j].y - p[i].y) < min; ++j)
            if (getDistance(mp[i].x, mp[j].x, mp[i].y, mp[j].y) < min)
                min = getDistance(mp[i].x, mp[j].x, mp[i].y, mp[j].y);
 
    return min;
}
 
float getPair(Coordinates p[], int n){
    if (n <= 3)
        return searchClosest(p, n);
 
    int mid = n/2;
    Coordinates midpt = p[mid];
 
    float left = getPair(p, mid);
    float right = getPair(p + mid, n-mid);
 
    float d = (left < right)? left : right;
 
    Coordinates mp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(p[i].x - midpt.x) < d)
            mp[j] = p[i], j++;
 
    return min(d, getMid(mp, j, d) );
}
 
int main(){


	createMatrix();
     int n = sizeof(p) / sizeof(p[0]);
     qsort(p, n, sizeof(Coordinates), compareX);
     float dist = getPair(p, n);
     cout << "The smallest distance is " << dist << endl;
     return 0;
}


