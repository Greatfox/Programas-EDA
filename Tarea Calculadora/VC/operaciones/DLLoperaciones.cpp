#include "Windows.h"

float FAR PASCAL DLLsumar (float e, float a){
	float er;
	er=e+a;
	return er;
}

float FAR PASCAL DLLrestar(float e, float a){
	float er;
	er=e-a;
	return er;
}

float FAR PASCAL DLLmultiplicar (float e, float a){
	float er;
	er=e*a;
	return er;
}

float FAR PASCAL DLLdividir (float e, float a){
	float er;
	er=e/a;
	return er;
}
