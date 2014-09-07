#include "Rijndael.h"

int main(){  

	unsigned int* iter;
	unsigned char mClaveExp[176]; // contendra la expansion de clave	
	unsigned char clave[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f}; //clave    
   	unsigned char arrTexto[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff}; // texto a cifrar    
	char resp;
	unsigned char texto[4][4]; // matriz 4x4 texto a cifrar
	unsigned char mClave[4][4]; //matriz 4x4 clave
	
	system("clear");
                 	
	cout << "********************************************************************************************"<< endl;
	cout << "*                                      RIJNDAEL                                    *" << endl;
	cout << "********************************************************************************************" << endl << endl;
	
	cout << "CLAVE: ";
	for (int i = 0; i < 16; i++){
		printf(" %02x ",clave[i]);
	} 
	cout << "\nTEXTO: ";
	for (int i = 0; i < 16; i++){
		printf(" %02x ",arrTexto[i]);
	}
  
	cout << "\nDESEA MODIFICAR LOS DATOS:(S/N):";
	cin >> resp;
	cin.clear(); //limpiamos buffer
	fflush(stdin);

	if(resp == 's' || resp == 'S') { 	

	cout << "CLAVE EN HEXADECIMAL: ";
	for(int i = 0; i < 16; i++){	
	
		scanf("%02x",&clave[i]);
	}
	cin.clear(); //limpiamos buffer
	fflush(stdin);
 
	cout << "TEXTO EN HEXAMECIMAL: ";
	for(int i = 0; i < 16; i++){
		scanf("%02x",&arrTexto[i]);
	}
 	cin.clear();  //limpiamos buffer
	fflush(stdin);
    	}
	
	cout << "\n\n********************************************************************************************"<< endl;
	
	for (int i = 0; i < 4; i++){
	    for (int j = 0; j < 4; j++){
            	mClave[j][i] = clave[i*4 + j]; // convierte clave a cifrar en una matriz 4X4
            }
    	}
	
	for (int i = 0; i < 4; i++){
	    for (int j = 0; j < 4; j++){
            	texto[j][i] = arrTexto[i*4 + j]; // texto a cifrar en una matriz 4X4
            }
    	}

    	Rijndael aes; 
	aes.expandirClave(mClave, mClaveExp);  //expandir la clave y guardarla en un array
    	aes.encriptar(texto, mClaveExp);  //ciframos el texto
    	cout << "\n\n\n********************************************************************************************"<< endl;
    	
    	for (int i = 0; i < 4; i++){
	    for (int j = 0; j < 4; j++){
	        printf(" %02x ",texto[j][i]); 
	    }
    	}
    	cout << "\n********************************************************************************************"<< endl;
    	cout << "\n\n\n\n";
	//iter = A.devIteraciones();
	//printf(" %02x ",iter[0]);
        
}
