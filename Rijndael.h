#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>



using namespace std;


class Rijndael{

	private:
		unsigned int iteraciones[176];  //guardamos las iteraciones
	
    	public:
		Rijndael();  
		~Rijndael();
		int k; //contador iteraciones
		int valorCajaS(int pos);  //devuelve el valor cajaS
		//void expandirClave(unsigned char *arrClave, unsigned char *mClaveExp);
		void expandirClave(unsigned char (*arrClave)[4], unsigned char *mClaveExp);
		void addRoundKey(int pos, unsigned char (*texto)[4], unsigned char *mClaveExp);
		void subBytes(unsigned char (*texto)[4]);
		void shiftRows(unsigned char (*texto)[4]);
		void mixColumns(unsigned char (*r)[4]);
		void encriptar(unsigned char (*texto)[4],unsigned char *mClaveExp);
		void mostrarIteraciones(); 
		unsigned int* devIteraciones(); 
};
