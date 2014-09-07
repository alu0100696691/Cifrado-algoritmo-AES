Cifrado-algoritmo-AES
=====================

C++ y Qt. Algoritmo de cifrado AES(Rijndael)


Objetivo: Implementar el algoritmo Rijndael
Desarrollo:
1. Implementa el cifrado en bloque para bloques y claves de 128 bits (que se representan como matrices de estado
de 4x4 bytes):
• Expansión de la clave obteniendo 10 subclaves a partir de la clave original usando la constante de iteración
• Etapa inicial: AddRoundKey entre el bloque de entrada y la clave original
• 9 Iteraciones de:
1. SubBytes — usando la S-Caja
2. ShiftRow
3. MixColumn — multiplicando una matriz por los cuatro bytes de cada columna, operando con bytes.
4. AddRoundKey — con la subclave correspondiente a la iteración
•
Etapa final:
1. SubBytes
2. ShiftRows
3. AddRoundKey  con la última subclave


Ejemplo:


Clave: 000102030405060708090a0b0c0d0e0f

Bloque de Texto Original: 00112233445566778899aabbccddeeff


R0 (Subclave = 000102030405060708090a0b0c0d0e0f) = 00102030405060708090a0b0c0d0e0f0
R1 (Subclave = d6aa74fdd2af72fadaa678f1d6ab76fe) = 89d810e8855ace682d1843d8cb128fe4
R2 (Subclave = b692cf0b643dbdf1be9bc5006830b3fe) = 4915598f55e5d7a0daca94fa1f0a63f7
R3 (Subclave = b6ff744ed2c2c9bf6c590cbf0469bf41) = fa636a2825b339c940668a3157244d17
R4 (Subclave = 47f7f7bc95353e03f96c32bcfd058dfd) = 247240236966b3fa6ed2753288425b6c
R5 (Subclave = 3caaa3e8a99f9deb50f3af57adf622aa) = c81677bc9b7ac93b25027992b0261996
R6 (Subclave = 5e390f7df7a69296a7553dc10aa31f6b) = c62fe109f75eedc3cc79395d84f9cf5d
R7 (Subclave = 14f9701ae35fe28c440adf4d4ea9c026) = d1876c0f79c4300ab45594add66ff41f
R8 (Subclave = 47438735a41c65b9e016baf4aebf7ad2) = fde3bad205e5d0d73547964ef1fe37f1
R9 (Subclave = 549932d1f08557681093ed9cbe2c974e) = bd6e7c3df2b5779e0b61216e8b10b689
R10 (Subclave = 13111d7fe3944a17f307a78b4d2b30c5) = 69c4e0d86a7b0430d8cdb78070b4c55a


Bloque de Texto Cifrado : 69c4e0d86a7b0430d8cdb78070b4c55a
