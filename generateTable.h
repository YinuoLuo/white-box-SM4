#include"sm4.h"
//#define u8 unsigned char
//#define u32 unsigned long

void ga(u8 a[256], u8 a_inv[256]);
void gS_4(u8 S1_f4a[32][4][256], u8 S1_f4a_inv[32][4][256], u8 S1_f4[32][4][256]);
void gS2_4(u8 S1_f4a[32][4][256], u8 S1_f4a_inv[32][4][256], u8 S1_f4[32][4][256]);
void M8_1(u8 a[8][8], u8 b[8], u8 ab[8]);
void inv8(u8 a[8][8], u8 a_inv[8][8]);
void M8_8(u8 a[8][8], u8 b[8][8], u8 ab[8][8]);
void M128_1(u8 a[128][8], u8 b[8], u8 c[128]);
void M128_8(u8 a[128][8], u8 b[8][8], u8 c[128][8]);
void M128_128(u8 a[128][128], u8 b[128], u8 c[128]);
void M8(u8 a[8][8], int n, u8 b[8][8]);
void getP128(u8 P[64][128][128], u8 P_inv[64][128][128]);
void getP_b(u8 P_b[64][17][128]);
void getP8(u8 F8[16][8][8], u8 G8[16][8][8], u8 STypeI_OP[32][16][8][8], u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8]);
void getP8w(u8 F8[16][8][8], u8 G8[16][8][8], u8 STypeI_OP[32][16][8][8], u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8]);
void generateOI(u8 STypeI_OP[32][16][8][8], u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8], u8 STypeI_OP_b[32][16][8], u8 STypeI_IP_b[32][16][8], u8 STypeII_OP_b[32][16][8], u8 STypeII_IP_b[32][16][8]);
void gOI128(u8 STypeI_OP[32][16][8][8], u8 STypeI_OP_b[32][16][8], u8 STypeI_O[32][128][128], u8 STypeI_O_b[32][128]);
void getA(u8 A_1[128][128], u8 A_2[128][128], u8 A_3[128][128], u8 A_13[128][128]);
void getA_b(u32 RK[32], u8 A_1_b[128], u8 A_2_b[32][128], u8 A_3_b[128], u8 A_13_b[31][128]);
void getTypeI_c(u8 F8[16][8][8], u8 A_1[128][128], u8 A_1_b[128], u8 P[64][128][128], u8 P_b[64][17][128], u8 TypeI_c[16][256][16]);
void getTypeII_c(u8 P_inv0[128][128], u8 P_b0[17][128], u8 STypeI_O0[128][128], u8 STypeI_O_b0[128], u8 TypeII_c[16][256][16]);
void getTypeI_a(u8 S1_f4a_inv1[4][256], u8 P1[128][128], u8 P_b1[17][128], u8 A_2[128][128], u8 A_2_b0[128], u8 STypeI_IP0[16][8][8], u8 STypeI_IP_b0[16][8], u8 TypeI_a0[16][256][16]);
void getTypeII_a(u8 P_inv1[128][128], u8 P_b1[17][128], u8 STypeII_O0[128][128], u8 STypeII_O_b0[128], u8 TypeII_a0[16][256][16]);
void getTypeI_b(u8 S2_f4a_inv1[4][256], u8 P2[128][128], u8 P_b2[17][128], u8 A_13[128][128], u8 A_13_b0[128], u8 STypeII_IP0[16][8][8], u8 STypeII_IP_b0[16][8], u8 TypeI_b0[16][256][16]);
void getTypeII_b(u8 P_inv2[128][128], u8 P_b2[17][128], u8 STypeI_O1[128][128], u8 STypeI_O_b1[128], u8 TypeII_b0[16][256][16]);
void getTypeI_d(u8 S2_l4a_inv31[4][256], u8 A_3[128][128], u8 A_3_b[128], u8 STypeII_IP31[16][8][8], u8 STypeII_IP_b31[16][8], u8 TypeI_d[16][256][16], u8 G8[16][8][8]);
void Wencrypt(u32 X[4], u32 MK[4], u8 wY[16]);














