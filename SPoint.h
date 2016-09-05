#ifndef FSPOINT_h
#define FSPOINT_h
struct SPoint{
	short x; //以左上角为原点，横轴为x
	short y; //纵轴为y
	SPoint(short a = 0, short b  = 0 ) :x(a), y(b){}
};
#endif