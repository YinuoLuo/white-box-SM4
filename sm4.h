#define u8 unsigned char
#define u32 unsigned long
u32 functionB(u32 b); //The function B of checking the S-box
u32 loopLeft(u32 a, short length); //The shift of circle left
u32 functionL1(u32 a); //Linear transformation L
u32 functionL2(u32 a); //Linear transformation L'
u32 functionT(u32 a, short mode); //The transformation T
void extendFirst(u32 MK[], u32 K[]); //The first step of the key extension algorithm
void extendSecond(u32 RK[], u32 K[]); //The second step of the key extension algorithm
void getRK(u32 MK[], u32 K[], u32 RK[]); //The algorithm of generating round keys
void iterate32(u32 X[], u32 RK[]); //Iterative algorithm
void reverse(u32 X[], u32 Y[]); //The function of reversing the order
void encryptSM4(u32 X[], u32 RK[], u32 Y[]); //Encryption algorithm
void decryptSM4(u32 X[], u32 RK[], u32 Y[]); //Decryption algorithm
