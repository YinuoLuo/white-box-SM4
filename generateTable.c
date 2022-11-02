#include"sm4.h"
#include<stdio.h>
#include<stdlib.h>


//Generate nonlinear affine transformation and its inverse 
void ga(u8 a[256],u8 a_inv[256])
{
	
	for (int i = 0; i < 256; i++)
	{
		l:a[i] = rand() % 256;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				goto l;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		a_inv[a[i]] = i;
	}

}


//Generate S2 box and nonlinear transformation
void gS_4(u8 S1_f4a[32][4][256], u8 S1_f4a_inv[32][4][256], u8 S1_f4[32][4][256])
{
	 u8 Sbox[256] = {
   //0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f
	0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05,//0
	0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99,//1
	0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62,//2
	0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6,//3
	0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8,//4
	0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35,//5
	0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87,//6
	0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e,//7
	0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1,//8
	0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3,//9
	0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f,//a
	0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51,//b
	0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8,//c
	0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0,//d
	0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84,//e
	0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48//f
	 };
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ga(S1_f4a[i][j], S1_f4a_inv[i][j]);
			for (int k = 0; k < 256; k++)
			{
				S1_f4[i][j][k] = S1_f4a[i][j][Sbox[k]];
			}
		}
	}
}



//Generate S2 box and nonlinear transformation
void gS2_4(u8 S2_f4a[32][4][256], u8 S2_f4a_inv[32][4][256], u8 S2_f4[32][4][256])
{
	 u8 Sbox[256] = {
	0xd6,0x90,0xe9,0xfe,0xcc,0xe1,0x3d,0xb7,0x16,0xb6,0x14,0xc2,0x28,0xfb,0x2c,0x05,
	0x2b,0x67,0x9a,0x76,0x2a,0xbe,0x04,0xc3,0xaa,0x44,0x13,0x26,0x49,0x86,0x06,0x99,
	0x9c,0x42,0x50,0xf4,0x91,0xef,0x98,0x7a,0x33,0x54,0x0b,0x43,0xed,0xcf,0xac,0x62,
	0xe4,0xb3,0x1c,0xa9,0xc9,0x08,0xe8,0x95,0x80,0xdf,0x94,0xfa,0x75,0x8f,0x3f,0xa6,
	0x47,0x07,0xa7,0xfc,0xf3,0x73,0x17,0xba,0x83,0x59,0x3c,0x19,0xe6,0x85,0x4f,0xa8,
	0x68,0x6b,0x81,0xb2,0x71,0x64,0xda,0x8b,0xf8,0xeb,0x0f,0x4b,0x70,0x56,0x9d,0x35,
	0x1e,0x24,0x0e,0x5e,0x63,0x58,0xd1,0xa2,0x25,0x22,0x7c,0x3b,0x01,0x21,0x78,0x87,
	0xd4,0x00,0x46,0x57,0x9f,0xd3,0x27,0x52,0x4c,0x36,0x02,0xe7,0xa0,0xc4,0xc8,0x9e,
	0xea,0xbf,0x8a,0xd2,0x40,0xc7,0x38,0xb5,0xa3,0xf7,0xf2,0xce,0xf9,0x61,0x15,0xa1,
	0xe0,0xae,0x5d,0xa4,0x9b,0x34,0x1a,0x55,0xad,0x93,0x32,0x30,0xf5,0x8c,0xb1,0xe3,
	0x1d,0xf6,0xe2,0x2e,0x82,0x66,0xca,0x60,0xc0,0x29,0x23,0xab,0x0d,0x53,0x4e,0x6f,
	0xd5,0xdb,0x37,0x45,0xde,0xfd,0x8e,0x2f,0x03,0xff,0x6a,0x72,0x6d,0x6c,0x5b,0x51,
	0x8d,0x1b,0xaf,0x92,0xbb,0xdd,0xbc,0x7f,0x11,0xd9,0x5c,0x41,0x1f,0x10,0x5a,0xd8,
	0x0a,0xc1,0x31,0x88,0xa5,0xcd,0x7b,0xbd,0x2d,0x74,0xd0,0x12,0xb8,0xe5,0xb4,0xb0,
	0x89,0x69,0x97,0x4a,0x0c,0x96,0x77,0x7e,0x65,0xb9,0xf1,0x09,0xc5,0x6e,0xc6,0x84,
	0x18,0xf0,0x7d,0xec,0x3a,0xdc,0x4d,0x20,0x79,0xee,0x5f,0x3e,0xd7,0xcb,0x39,0x48
	 };

	u8 Sbox_inv[256];
	for (int i = 0; i < 256; i++)
	{
		Sbox_inv[Sbox[i]] = i;
	}
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ga(S2_f4a[i][j], S2_f4a_inv[i][j]);
			for (int k = 0; k < 256; k++)
			{
				S2_f4[i][j][k] = S2_f4a[i][j][Sbox_inv[k]];
			}
		}
	}

}








// generate IO matrix and its auxiliary functions

//[8,8] matrix multiplication by [8,1] vector operation

void M8_1(u8 a[8][8], u8 b[8], u8 ab[8])
{
	for (int i = 0; i < 8; i++)
	{
		ab[i] = 0;
		for (int k = 0; k < 8; k++)
		{
			ab[i] = ab[i] ^ (a[i][k] * b[k]);
		}
	}
}


//[8,8] matrix inverse
void inv8(u8 a[8][8], u8 a_inv[8][8])
{
	u8 al[256];
	u8 al_inv[256];
	u8 x[8];
	u8 y[8] = { 0,0,0,0,0,0,0,0 };
	u8 a_i[8];

	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			x[j] = (i >> (7 - j)) & 1;
		}
		M8_1(a, x, y);
		al[i] = y[0] * 128 + y[1] * 64 + y[2] * 32 + y[3] * 16 + y[4] * 8 + y[5] * 4 + y[6] * 2 + y[7];

	}
	for (int i = 0; i < 256; i++)
	{
		al_inv[al[i]] = i;
	}

	a_i[0] = al_inv[128];
	a_i[1] = al_inv[64];
	a_i[2] = al_inv[32];
	a_i[3] = al_inv[16];
	a_i[4] = al_inv[8];
	a_i[5] = al_inv[4];
	a_i[6] = al_inv[2];
	a_i[7] = al_inv[1];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			a_inv[i][j] = (a_i[j] >> (7 - i)) & 1;
		}
	}

}


//[8,8] matrix multiplication by [8,8] matrix operations
void M8_8(u8 a[8][8], u8 b[8][8], u8 ab[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ab[i][j] = 0;
			for (int k = 0; k < 8; k++)
			{
				ab[i][j] = ab[i][j] ^ (a[i][k] * b[k][j]);
			}
		}
	}
}


//[128,8] matrix multiplied by [8,1] matrix operation
void M128_1(u8 a[128][8], u8 b[8], u8 c[128])
{
	for (int i = 0; i < 128; i++)
	{
		c[i] = 0;
		for (int j = 0; j < 8; j++)
		{
			c[i] = c[i] ^ (a[i][j] * b[j]);
		}
	}
}


//[128,8] matrix multiplied by [8,8] matrix operation
void M128_8(u8 a[128][8], u8 b[8][8], u8 c[128][8])
{
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < 8; k++)
			{
				c[i][j] = c[i][j] ^ (a[i][k] * b[k][j]);
			}
		}
	}
}


//[128,128] multiplied by [128,1] matrix operation
void M128_128(u8 a[128][128], u8 b[128], u8 c[128])
{
	for (int i = 0; i < 128; i++)
	{
		c[i] = 0;
		for (int j = 0; j < 128; j++)
		{
			c[i] = c[i] ^ (a[i][j] * b[j]);
		}
	}
}


//Matrix multiplication
void M8(u8 a[8][8], int n, u8 b[8][8])
{
	u8 c[8][8];
	if (n == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i == j)
					b[i][j] = 1;
				else
					b[i][j] = 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				b[i][j] = a[i][j];
				c[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < n-1; i++)
		{
			M8_8(a, c, b);
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					c[i][j] = b[i][j];
				}
			}
		}
	}
}





// Affine coding assignment
//128_128 random affine transformation matrix and its inverse assignment
void getP128(u8 P[64][128][128],u8 P_inv[64][128][128])
{

	/*
	
Enter the following code on the command line of Matlab software to generate the matrix of random affine transformation:

fid=fopen('e:\p.txt','a+');
for i=1:1000
a=randsrc(128,128)/2+1/2;
b=gf(a,1);
if det(b)==0
continue
else
c=inv(b);
for i1=1:128
    for j1=1:128
        fprintf(fid,'%e ',a(i1,j1));
    end
end
fprintf(fid,'\n');
cx=c.x;
d=double(cx);
for i2=1:128
    for j2=1:128
        fprintf(fid,'%e ',d(i2,j2));
    end
end
fprintf(fid,'\n');
end
end
fclose(fid);
	
	*/

	FILE* fp;
	errno_t err;
	float af;
	if ((err = fopen_s(&fp, "E:\\p.txt", "r")) != 0)
	{
		printf("Failed to open file p£¡Please See ReadMe and generate this file.\n");
		exit(1);
	}
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 128; k++)
			{
				fscanf_s(fp, "%e", &af);
				P[i][j][k] = (unsigned int)(af);
			}
		}
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 128; k++)
			{
				fscanf_s(fp, "%e", &af);
				P_inv[i][j][k] = (unsigned int)(af);
			}
		}
	}
	fclose(fp);
	
}

//128-bit random affine transform constant assignment
void getP_b(u8 P_b[65][17][128])
{
	for (int i = 0; i < 65; i++)
	{
		for (int i2 = 0; i2 < 16; i2++)
		{
			for (int j = 0; j < 128; j++)
			{
				P_b[i][i2][j] = rand() % 2;
			}
		}
	}
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			P_b[i][16][j] = 0;
			for (int k = 0; k < 16; k++)
			{
				P_b[i][16][j] = P_b[i][16][j] ^ (P_b[i][k][j]);
			}
		}
	}
	
}


//[8,8] random affine transformation matrix assignment
void getP8(u8 F8[16][8][8], u8 G8[16][8][8], u8 STypeI_OP[32][16][8][8],u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8])
{

	/*
	
Enter the following code on the command line of Matlab software to generate the matrix of random affine transformation

fid=fopen('e:\p8.txt','a+');
for i=1:10000
a=randsrc(8,8)/2+1/2;
b=gf(a,1);
if det(b)==0
continue
else
c=inv(b);
for i1=1:8
    for j1=1:8
        fprintf(fid,'%e ',a(i1,j1));
    end
end
fprintf(fid,'\n');
cx=c.x;
d=double(cx);
for i2=1:8
    for j2=1:8
        fprintf(fid,'%e ',d(i2,j2));
    end
end
fprintf(fid,'\n');
end
end
fclose(fid);

	*/

	FILE* fp;
	errno_t err;
	float af;
	u8 F8_inv[16][8][8];
	u8 G8_inv[16][8][8];

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (j == k)
				{
					F8[i][j][k] = 1;
					G8[i][j][k] = 1;
				}
				else
				{
					F8[i][j][k] = 0;
					G8[i][j][k] = 0;
				}
			}
		}
	}

	if ((err = fopen_s(&fp, "E:\\p8.txt", "r")) != 0)
	{
		printf("Failed to open file p8£¡Please See ReadMe and generate this file.\n");
		exit(1);
	}





	/*for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				F8[i][j][k] = (unsigned int)(af);
			}
		}
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				F8_inv[i][j][k] = (unsigned int)(af);
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				G8[i][j][k] = (unsigned int)(af);
			}
		}
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				G8_inv[i][j][k] = (unsigned int)(af);
			}
		}
	}

	*/


	for (int i = 0; i < 32; i++)
	{
		for (int i1 = 4; i1 < 16; i1++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeI_OP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeI_IP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeII_OP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeII_IP[i][i1][j][k] = (unsigned int)(af);
				}
			}

		}
	}
	fclose(fp);

}


//[8,8] random affine transformation matrix assignment(With external code)
void getP8w(u8 F8[16][8][8], u8 G8[16][8][8], u8 STypeI_OP[32][16][8][8], u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8])
{

	/*


Enter the following code on the command line of Matlab software to generate the matrix of random affine transformation

fid=fopen('e:\p8.txt','a+');
for i=1:10000
a=randsrc(8,8)/2+1/2;
b=gf(a,1);
if det(b)==0
continue
else
c=inv(b);
for i1=1:8
	for j1=1:8
		fprintf(fid,'%e ',a(i1,j1));
	end
end
fprintf(fid,'\n');
cx=c.x;
d=double(cx);
for i2=1:8
	for j2=1:8
		fprintf(fid,'%e ',d(i2,j2));
	end
end
fprintf(fid,'\n');
end
end
fclose(fid);

	*/

	FILE* fp;
	errno_t err;
	float af;
	u8 F8_inv[16][8][8];
	u8 G8_inv[16][8][8];


	if ((err = fopen_s(&fp, "E:\\p8.txt", "r")) != 0)
	{
		printf("Failed to open file p8£¡Please See ReadMe and generate this file.\n");
		exit(1);
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				F8[i][j][k] = (unsigned int)(af);
			}
		}
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				F8_inv[i][j][k] = (unsigned int)(af);
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				G8[i][j][k] = (unsigned int)(af);
			}
		}
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				fscanf_s(fp, "%e", &af);
				G8_inv[i][j][k] = (unsigned int)(af);
			}
		}
	}

	for (int i = 0; i < 32; i++)
	{
		for (int i1 = 4; i1 < 16; i1++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeI_OP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeI_IP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeII_OP[i][i1][j][k] = (unsigned int)(af);
				}
			}
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					fscanf_s(fp, "%e", &af);
					STypeII_IP[i][i1][j][k] = (unsigned int)(af);
				}
			}

		}
	}
	fclose(fp);

}




//Generate the O and I matrices and constants for SM4
void generateOI(u8 STypeI_OP[32][16][8][8], u8 STypeI_IP[32][16][8][8], u8 STypeII_OP[32][16][8][8], u8 STypeII_IP[32][16][8][8], u8 STypeI_OP_b[32][16][8], u8 STypeI_IP_b[32][16][8], u8 STypeII_OP_b[32][16][8],u8 STypeII_IP_b[32][16][8])
{
	
	//Since I*S*O is equivalent to S, our aim here is to verify the correctness of our white-box SM4, so the identity transformations are used instead of the O and I transformations

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int m = 0; m < 8; m++)
			{
				for (int n = 0; n < 8; n++)
				{
					if (m == n)
					{
						STypeI_OP[i][j][m][n] = 1;
						STypeI_IP[i][j][m][n] = 1;
						STypeII_OP[i][j][m][n] = 1;
						STypeII_IP[i][j][m][n] = 1;
					}
					else
					{
						STypeI_OP[i][j][m][n] = 0;
						STypeI_IP[i][j][m][n] = 0;
						STypeII_OP[i][j][m][n] = 0;
						STypeII_IP[i][j][m][n] = 0;
					}
				}
				STypeI_OP_b[i][j][m] = 0;
				STypeI_IP_b[i][j][m] = 0;
				STypeII_OP_b[i][j][m] = 0;
				STypeII_IP_b[i][j][m] = 0;
			}
		}
	}




}


//O and I matrices of [8,8] construct O and I matrices of [128,128]
void gOI128(u8 STypeI_OP[32][16][8][8], u8 STypeI_OP_b[32][16][8], u8 STypeI_O[32][128][128], u8 STypeI_O_b[32][128])
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 128; k++)
			{
				STypeI_O[i][j][k] = 0;
			}
			STypeI_O_b[i][j] = 0;
		}
	}

	for (int i = 0; i < 32; i++)
	{
		for (int i1 = 0; i1 < 8; i1++)
		{
			for (int i2 = 0; i2 < 8; i2++)
			{
				for (int j = 0; j < 16; j++)
				{
					STypeI_O[i][j * 8 + i1][j * 8 + i2] = STypeI_OP[i][j][i1][i2];
				}
			}
		}

		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				STypeI_O_b[i][j * 8 + k] = STypeI_OP_b[i][j][k];
			}
		}
	}

}


//Generate A-type matrix 1, 2, 3, 13
void getA(u8 A_1[128][128], u8 A_2[128][128], u8 A_3[128][128],u8 A_13[128][128])
{
	u8 E32[32][32];
	u8 L32[32][32];
	u8 C8[8][8];
	u8 A8[8][8];
	u8 B8[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == j)
			{
				C8[i][j] = 1;
				A8[i][j] = 1;
			}
			else
			{
				C8[i][j] = 0;
				A8[i][j] = 0;
			}
			B8[i][j] = 0;
		}
	}
	A8[0][2] = 1;
	A8[1][3] = 1;
	A8[2][4] = 1;
	A8[3][5] = 1;
	A8[4][6] = 1;
	A8[5][7] = 1;
	
	B8[0][2] = 1;
	B8[1][3] = 1;
	B8[2][4] = 1;
	B8[3][5] = 1;
	B8[4][6] = 1;
	B8[5][7] = 1;
	B8[6][0] = 1;
	B8[7][1] = 1;

	C8[6][0] = 1;
	C8[7][1] = 1;

	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_1[i][j] = 0;
			A_2[i][j] = 0;
			A_3[i][j] = 0;
			A_13[i][j] = 0;
		}
	}

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (i == j)
				E32[i][j] = 1;
			else
				E32[i][j] = 0;
			L32[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			L32[i][j] = A8[i][j];
			L32[i][j+8] = B8[i][j];
			L32[i][j+16] = B8[i][j];
			L32[i][j+24] = C8[i][j];
			L32[i+8][j] = C8[i][j];
			L32[i+8][j + 8] = A8[i][j];
			L32[i+8][j + 16] = B8[i][j];
			L32[i+8][j + 24] = B8[i][j];
			L32[i+16][j] = B8[i][j];
			L32[i+16][j + 8] = C8[i][j];
			L32[i+16][j + 16] = A8[i][j];
			L32[i+16][j + 24] = B8[i][j];
			L32[i+24][j] = B8[i][j];
			L32[i+24][j + 8] = B8[i][j];
			L32[i+24][j + 16] = C8[i][j];
			L32[i+24][j + 24] = A8[i][j];
		}
	}

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			A_1[i][32 + j] = E32[i][j];
			A_1[i][64 + j] = E32[i][j];
			A_1[i][96 + j] = E32[i][j];
			A_1[i + 32][j] = E32[i][j];
			A_1[i + 32][j+32] = E32[i][j];
			A_1[i + 32][j+64] = E32[i][j];
			A_1[i + 32][j+96] = E32[i][j];
			A_1[i + 64][j] = E32[i][j];
			A_1[i + 64][j+64] = E32[i][j];
			A_1[i + 96][j] = E32[i][j];
			A_1[i + 96][j+96] = E32[i][j];

			A_2[i][j] = E32[i][j];
			A_2[i + 32][j + 32] = E32[i][j];
			A_2[i + 64][j + 32] = E32[i][j];
			A_2[i + 64][j + 64] = E32[i][j];
			A_2[i + 96][j + 32] = E32[i][j];
			A_2[i + 96][j + 96] = E32[i][j];
			A_2[i + 32][j] = L32[i][j];

			A_3[i][j] = E32[i][j];
			A_3[i][j + 64] = E32[i][j];
			A_3[i][j + 96] = E32[i][j];
			A_3[i + 32][j] = E32[i][j];
			A_3[i + 32][j + 64] = E32[i][j];
			A_3[i + 64][j] = E32[i][j];
			A_3[i + 64][j + 96] = E32[i][j];
			A_3[i + 96][j] = E32[i][j];
			A_3[i + 96][j + 32] = E32[i][j];

			A_13[i][j] = E32[i][j];
			A_13[i][j + 32] = E32[i][j];
			A_13[i][j + 64] = E32[i][j];
			A_13[i][j + 96] = E32[i][j];
			A_13[i + 32][j + 32] = E32[i][j];
			A_13[i + 64][j + 64] = E32[i][j];
			A_13[i + 96][j + 32] = E32[i][j];
			A_13[i + 96][j + 64] = E32[i][j];
			A_13[i + 96][j + 96] = E32[i][j];
		}
	}

}


//A-type matrix constants (with key) assignment
void getA_b(u32 RK[32], u8 A_1_b[128], u8 A_2_b[32][128], u8 A_3_b[128], u8 A_13_b[31][128])
{

	u8 k[32][32];

	for (int i = 0; i < 128; i++)
	{
		A_1_b[i] = 0;
		A_3_b[i] = 0;
	}
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_2_b[i][j] = 0;
		}
	}
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_13_b[i][j] = 0;
		}
	}

	
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			k[i][j] = (RK[i] >> (31 - j)) & 1;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		A_1_b[i] = 0;
		A_3_b[i] = 0;
	}
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_2_b[i][j] = 0;
		}
	}
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_13_b[i][j] = 0;
		}
	}

	for (int i = 0; i < 32; i++)
	{

		A_1_b[i] = k[0][i];
		A_1_b[i + 32] = k[0][i];

		A_3_b[i] = k[31][i];
		A_3_b[i + 32] = k[31][i];
		A_3_b[i + 64] = k[31][i];

		for (int j = 0; j < 32; j++)
		{
			A_2_b[j][i+64] = k[j][i];
			A_2_b[j][i + 96] = k[j][i];
		}

		for (int j1 = 0; j1 < 31; j1++)
		{
			A_13_b[j1][i] = k[j1 + 1][i];
			A_13_b[j1][i + 32] = k[j1][i] ^ k[j1 + 1][i];
			A_13_b[j1][i + 96] = k[j1][i];
		}
	}

}








// The function of generating lookup tables
//Generate TypeI_c type lookup table
void getTypeI_c(u8 F8[16][8][8], u8 A_1[128][128], u8 A_1_b[128], u8 P[64][128][128], u8 P_b[65][17][128], u8 TypeI_c[16][256][16])
{
	u8 x[8];
	u8 SIF[8];
	u8 SIFA[128];
	u8 SIFAk[128];
	u8 SIFAkP[128];
	u8 SIr[128];
	u8 I_cA[16][128][8];
	u8 A_1_b16[16][128];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_1_b16[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		A_1_b16[15][i] = A_1_b[i];
		for (int j = 0; j < 15; j++)
		{
			A_1_b16[15][i] = A_1_b16[15][i] ^ A_1_b16[j][i];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				I_cA[i][j][k] = A_1[j][i * 8 + k];
			}
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				x[k] = (j >> (7-k))&1;
			}
			M8_1(F8[i], x, SIF);
			M128_1(I_cA[i], SIF, SIFA);
			for (int k = 0; k < 128; k++)
			{
				SIFAk[k] = SIFA[k] ^ A_1_b16[i][k];
			}
			M128_128(P[0], SIFAk, SIFAkP);
			for (int k = 0; k < 128; k++)
			{
				SIr[k] = SIFAkP[k] ^ P_b[0][i][k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeI_c[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}

}


//Generate TypeII_c lookup table
void getTypeII_c(u8 P_inv0[128][128], u8 P_b0[17][128], u8 STypeI_O0[128][128], u8 STypeI_O_b0[128], u8 TypeII_c[16][256][16])
{
	u8 x[8];
	
	u8 SIIb[128];
	u8 SIIPb[128];
	u8 SIIPbO[128];
	u8 SIr[128];
	u8 II_cP[16][128][8];

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				II_cP[i][j][k] = P_inv0[j][i * 8 + k];
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				x[k] = (j >> (7 - k)) & 1;
			}


			for (int k = 0; k < 8; k++)
			{
				SIIb[k] = x[k] ^ P_b0[16][i*8+k];
			}

			M128_1(II_cP[i], SIIb, SIIPb);
			
			M128_128(STypeI_O0, SIIPb, SIIPbO);

			for (int k = 0; k < 128; k++)
			{
				SIr[k] = SIIPbO[k] ^ STypeI_O_b0[k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeII_c[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}

}


//Generate TypeI_a lookup table
void getTypeI_a(u8 S1_f4a_inv1[4][256], u8 P1[128][128], u8 P_b1[17][128], u8 A_2[128][128], u8 A_2_b0[128], u8 STypeI_IP0[16][8][8], u8 STypeI_IP_b0[16][8],u8 TypeI_a0[16][256][16])
{
	u8 x[8];
	u8 O[8];
	u8 Ob[8];
	u8 AOb[128];
	u8 AObk[128];
	u8 PAObk[128];
	u8 SIr[128];
	u8 I_aA[16][128][8];
	u8 A_2_b16[16][128];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_2_b16[i][j] = rand()%2;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		A_2_b16[15][i] = A_2_b0[i];
		for (int j = 0; j < 15; j++)
		{
			A_2_b16[15][i] = A_2_b16[j][i] ^ A_2_b16[15][i];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				I_aA[i][j][k] = A_2[j][i * 8 + k];
			}
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (i < 4)
					x[k] = (S1_f4a_inv1[i][j] >>( 7-k))&1;
				else
					x[k] = (j >> (7 - k)) & 1;
			}

			M8_1(STypeI_IP0[i], x, O);
			for (int k = 0; k < 8; k++)
			{
				Ob[k] = O[k] ^ STypeI_IP_b0[i][k];
			}

			M128_1(I_aA[i], Ob, AOb);
			for (int k = 0; k < 128; k++)
			{
				AObk[k] = AOb[k] ^ A_2_b16[i][k];
			}
			M128_128(P1, AObk, PAObk);
			for (int k = 0; k < 128; k++)
			{
				SIr[k] = PAObk[k] ^ P_b1[i][k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeI_a0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}
}


//Generate TypeII_a lookup table
void getTypeII_a(u8 P_inv1[128][128], u8 P_b1[17][128], u8 STypeII_O0[128][128], u8 STypeII_O_b0[128], u8 TypeII_a0[16][256][16])
{
	u8 x[8];

	u8 SIIb[128];
	u8 SIIPb[128];
	u8 SIIPbO[128];
	u8 SIr[128];
	u8 II_aP[16][128][8];

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				II_aP[i][j][k] = P_inv1[j][i * 8 + k];
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				x[k] = (j >> (7 - k)) & 1;
			}


			for (int k = 0; k < 8; k++)
			{
				SIIb[k] = x[k] ^ P_b1[16][i * 8 + k];
			}

			M128_1(II_aP[i], SIIb, SIIPb);

			M128_128(STypeII_O0, SIIPb, SIIPbO);

			for (int k = 0; k < 128; k++)
			{
				SIr[k] = SIIPbO[k] ^ STypeII_O_b0[k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeII_a0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}





}


//Generate TypeI_b lookup table
void getTypeI_b(u8 S2_f4a_inv1[4][256], u8 P2[128][128], u8 P_b2[17][128], u8 A_13[128][128], u8 A_13_b0[128], u8 STypeII_IP0[16][8][8], u8 STypeII_IP_b0[16][8], u8 TypeI_b0[16][256][16])
{
	u8 x[8];
	u8 O[8];
	u8 Ob[8];
	u8 AOb[128];
	u8 AObk[128];
	u8 PAObk[128];
	u8 SIr[128];
	u8 II_aA[16][128][8];
	u8 A_13_b16[16][128];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			A_13_b16[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		A_13_b16[15][i] = A_13_b0[i];
		for (int j = 0; j < 15; j++)
		{
			A_13_b16[15][i] = A_13_b16[15][i] ^ A_13_b16[j][i];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				II_aA[i][j][k] = A_13[j][i * 8 + k];
			}
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (i < 4)
					x[k] = (S2_f4a_inv1[i][j]  >>( 7-k))&1;
				else
					x[k] = (j >> (7 - k)) & 1;
			}

			M8_1(STypeII_IP0[i], x, O);
			for (int k = 0; k < 8; k++)
			{
				Ob[k] = O[k] ^ STypeII_IP_b0[i][k];
			}

			M128_1(II_aA[i], Ob, AOb);
			for (int k = 0; k < 128; k++)
			{
				AObk[k] = AOb[k] ^ A_13_b16[i][k];
			}
			M128_128(P2, AObk, PAObk);
			for (int k = 0; k < 128; k++)
			{
				SIr[k] = PAObk[k] ^ P_b2[i][k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeI_b0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}

}


//Generate TypeII_b lookup table
void getTypeII_b(u8 P_inv2[128][128], u8 P_b2[17][128], u8 STypeI_O1[128][128], u8 STypeI_O_b1[128], u8 TypeII_b0[16][256][16])
{
	u8 x[8];

	u8 SIIb[128];
	u8 SIIPb[128];
	u8 SIIPbO[128];
	u8 SIr[128];
	u8 II_aP[16][128][8];

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				II_aP[i][j][k] = P_inv2[j][i * 8 + k];
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				x[k] = (j >> (7 - k)) & 1;
			}


			for (int k = 0; k < 8; k++)
			{
				SIIb[k] = x[k] ^ P_b2[16][i * 8 + k];
			}

			M128_1(II_aP[i], SIIb, SIIPb);

			M128_128(STypeI_O1, SIIPb, SIIPbO);

			for (int k = 0; k < 128; k++)
			{
				SIr[k] = SIIPbO[k] ^ STypeI_O_b1[k];
			}
			for (int k = 0; k < 16; k++)
			{
				TypeII_b0[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}

}


//Generate TypeI_d lookup table
void getTypeI_d(u8 S2_l4a_inv31[4][256], u8 A_3[128][128], u8 A_3_b[128], u8 STypeII_IP31[16][8][8], u8 STypeII_IP_b31[16][8], u8 TypeI_d[16][256][16], u8 G8[16][8][8])
{
	u8 x[8];
	u8 O[8];
	u8 Ob[8];
	u8 AOb[128];
	u8 AObk[128];
	u8 GAObk[128];
	u8 G[16][8];
	u8 GA[16][8];
	u8 SIr[128];
	u8 II_aA[16][128][8];
	u8 A_3_b16[16][128];
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			A_3_b16[j][i] = rand() % 2;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		A_3_b16[15][i] = A_3_b[i];
		for (int j = 0; j < 15; j++)
		{
			A_3_b16[15][i] = A_3_b16[j][i]^A_3_b16[15][i];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				II_aA[i][j][k] = A_3[j][i * 8 + k];
			}
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (i < 4)
					x[k] = (S2_l4a_inv31[i][j]  >> (7-k))&1;
				else
					x[k] = (j >> (7 - k)) & 1;
			}

			M8_1(STypeII_IP31[i], x, O);
			for (int k = 0; k < 8; k++)
			{
				Ob[k] = O[k] ^ STypeII_IP_b31[i][k];
			}

			M128_1(II_aA[i], Ob, AOb);
			for (int k = 0; k < 128; k++)
			{
				AObk[k] = AOb[k] ^ A_3_b16[i][k];
			}

			for (int k = 0; k < 16; k++)
			{
				for (int aa = 0; aa < 8; aa++)
				{
					G[k][aa] = AObk[k * 8 + aa];
				}
			}
			for (int k = 0; k < 16; k++)
			{
				M8_1(G8[i], G[k], GA[k]);
			}
			for (int k = 0; k < 16; k++)
			{
				for (int aa = 0; aa < 8; aa++)
				{
					GAObk[k * 8 + aa]=GA[k][aa];
				}
			}
			for (int k = 0; k < 128; k++)
			{
				SIr[k] = GAObk[k] ;
			}
			for (int k = 0; k < 16; k++)
			{
				TypeI_d[i][j][k] = SIr[k * 8 + 0] * 128 + SIr[k * 8 + 1] * 64 + SIr[k * 8 + 2] * 32 + SIr[k * 8 + 3] * 16 + SIr[k * 8 + 4] * 8 + SIr[k * 8 + 5] * 4 + SIr[k * 8 + 6] * 2 + SIr[k * 8 + 7];
			}
		}
	}

}



//White-box encryption
void Wencrypt(u32 X[4], u32 MK[4], u8 wY[16],int s)
{
	
	

	u8 x8[16];//Plaintext stored by byte
	u8 x[16][8];//Plaintext stored by bit
	u32 RK[32]; //Round keys
	u32 K[4]; //Intermediate data
	getRK(MK, K, RK);
	
	u8 states[16];
	u8 state16[16][16];
	u8 state128[16][128];
	u8 states128[128];


	u8 TypeI_c[16][256][16];
	u8 TypeII_c[16][256][16];
	u8 TypeI_a[32][16][256][16];
	u8 TypeII_a[32][16][256][16];
	u8 TypeI_b[31][16][256][16];
	u8 TypeII_b[31][16][256][16];
	u8 TypeI_d[16][256][16];



	u8 S1_f4[32][4][256];
	u8 S2_f4[32][4][256];


	
	//Code
	u8 P[64][128][128];
	u8 P_b[65][17][128];
	u8 P_inv[64][128][128];
	u8 F[128][128];
	u8 G[128][128];

	u8 A_1[128][128];
	u8 A_2[128][128];
	u8 A_3[128][128];
	u8 A_13[128][128];
	u8 A_1_b[128];
	u8 A_2_b[32][128];
	u8 A_3_b[128];
	u8 A_13_b[31][128];

	u8 STypeI_O[32][128][128];
	u8 STypeI_O_b[32][128];
	u8 STypeI_I[32][128][128];
	u8 STypeI_I_b[32][128];
	u8 STypeII_O[32][128][128];
	u8 STypeII_O_b[32][128];
	u8 STypeII_I[32][128][128];
	u8 STypeII_I_b[32][128];

	
	//Coding auxiliary variables
	u8 F8[16][8][8];
	u8 G8[16][8][8];
	u8 STypeI_OP[32][16][8][8];
	u8 STypeI_OP_b[32][16][8];
	u8 STypeI_IP[32][16][8][8];
	u8 STypeI_IP_b[32][16][8];
	u8 STypeII_OP[32][16][8][8];
	u8 STypeII_OP_b[32][16][8];
	u8 STypeII_IP[32][16][8][8];
	u8 STypeII_IP_b[32][16][8];
	u8 S1_f4a[32][4][256];
	u8 S2_f4a[32][4][256];
	u8 S1_f4a_inv[32][4][256];
	u8 S2_f4a_inv[32][4][256];



	
	//Coding auxiliary variable assignment
	getP128(P, P_inv);
	getP_b(P_b);
	if(s==0)
		getP8(F8, G8, STypeI_OP, STypeI_OP, STypeI_IP, STypeII_OP, STypeII_IP);
	else
		getP8w(F8, G8, STypeI_OP, STypeI_OP, STypeI_IP, STypeII_OP, STypeII_IP);
	generateOI(STypeI_OP, STypeI_IP, STypeII_OP, STypeII_IP, STypeI_OP_b, STypeI_IP_b, STypeII_OP_b, STypeII_IP_b);
	getA(A_1, A_2, A_3, A_13);
	getA_b(RK, A_1_b, A_2_b, A_3_b, A_13_b);

	gOI128(STypeI_OP, STypeI_OP_b, STypeI_O, STypeI_O_b);
	gOI128(STypeI_IP, STypeI_IP_b, STypeI_I, STypeI_I_b);
	gOI128(STypeII_OP, STypeII_OP_b, STypeII_O, STypeII_O_b);
	gOI128(STypeII_IP, STypeII_IP_b, STypeII_I, STypeII_I_b);

	gS_4(S1_f4a, S1_f4a_inv, S1_f4);
	gS2_4(S2_f4a, S2_f4a_inv, S2_f4);






	
	//The following is to build lookup tables of white-box SM4

	getTypeI_c(F8, A_1, A_1_b, P, P_b, TypeI_c);
	getTypeII_c(P_inv[0], P_b[0], STypeI_O[0], STypeI_O_b[0], TypeII_c);

	for (int i = 0; i < 31; i++)
	{
		getTypeI_a(S1_f4a_inv[i], P[i * 2 + 1], P_b[i * 2 + 1], A_2, A_2_b[i], STypeI_IP[i], STypeI_IP_b[i], TypeI_a[i]);
		getTypeII_a(P_inv[i * 2 + 1], P_b[i * 2 + 1], STypeII_O[i], STypeII_O_b[i], TypeII_a[i]);
		getTypeI_b(S2_f4a_inv[i], P[i * 2 + 2], P_b[i * 2 + 2], A_13, A_13_b[i], STypeII_IP[i], STypeII_IP_b[i], TypeI_b[i]);
		getTypeII_b(P_inv[i * 2 + 2], P_b[i * 2 + 2], STypeI_O[i + 1], STypeI_O_b[i + 1], TypeII_b[i]);
	}


	getTypeI_a(S1_f4a_inv[31], P[63], P_b[63], A_2, A_2_b[31], STypeI_IP[31], STypeI_IP_b[31], TypeI_a[31]);
	getTypeII_a(P_inv[63], P_b[63], STypeII_O[31], STypeII_O_b[31], TypeII_a[31]);
	getTypeI_d(S2_f4a_inv[31], A_3, A_3_b, STypeII_IP[31], STypeII_IP_b[31], TypeI_d, G8);


	printf("\n\nThe construction of lookup tables is over!");







	
	//The following is a white-box encryption using lookup tables

	getx(X, x8);
	u8 x128[128];
	

	//TypeI_c
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			state16[i][j] = TypeI_c[i][x8[i]][j];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				state128[i][j * 8 + k] = (state16[i][j] >> (7 - k)) & 1;
			}
		}
	}

	for (int i = 0; i < 128; i++)
	{
		states128[i] = 0;
		for (int j = 0; j < 16; j++)
		{
			states128[i] = states128[i] ^ state128[j][i];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		states[i] = states128[i * 8 + 0] * 128 + states128[i * 8 + 1] * 64 + states128[i * 8 + 2] * 32 + states128[i * 8 + 3] * 16 + states128[i * 8 + 4] * 8 + states128[i * 8 + 5] * 4 + states128[i * 8 + 6] * 2 + states128[i * 8 + 7];

	}
	

	//TypeII_C
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			state16[i][j] = TypeII_c[i][states[i]][j];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				state128[i][j * 8 + k] = (state16[i][j] >> (7 - k)) & 1;
			}
		}
	}

	for (int i = 0; i < 128; i++)
	{
		states128[i] = 0;
		for (int j = 0; j < 16; j++)
		{
			states128[i] = states128[i] ^ state128[j][i];
		}
	}

	for (int i = 0; i < 16; i++)
	{
		states[i] = states128[i * 8 + 0] * 128 + states128[i * 8 + 1] * 64 + states128[i * 8 + 2] * 32 + states128[i * 8 + 3] * 16 + states128[i * 8 + 4] * 8 + states128[i * 8 + 5] * 4 + states128[i * 8 + 6] * 2 + states128[i * 8 + 7];

	}

	for (int i = 0; i < 4; i++)
	{

		states[i] = S1_f4[0][i][states[i]];

	}

	
	//31 rounds of table lookup
	for (int i = 0; i < 31; i++)
	{

		//TypeI_a
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				state16[j][k] = TypeI_a[i][j][states[j]][k];
			}
		}

		for (int i1 = 0; i1 < 16; i1++)
		{
			for (int j = 0; j < 16; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
				}
			}
		}
		for (int i1 = 0; i1 < 128; i1++)
		{
			states128[i1] = 0;
			for (int j = 0; j < 16; j++)
			{
				states128[i1] = states128[i1] ^ state128[j][i1];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

		}
		

		//TypeII_a
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				state16[j][k] = TypeII_a[i][j][states[j]][k];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			for (int j = 0; j < 16; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
				}
			}
		}
		for (int i1 = 0; i1 < 128; i1++)
		{
			states128[i1] = 0;
			for (int j = 0; j < 16; j++)
			{
				states128[i1] = states128[i1] ^ state128[j][i1];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

		}
		

		//S2
		for (int j = 0; j < 4; j++)
		{

			states[j] = S2_f4[i][j][states[j]];

		}


		//TypeI_b
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				state16[j][k] = TypeI_b[i][j][states[j]][k];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			for (int j = 0; j < 16; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
				}
			}
		}
		for (int i1 = 0; i1 < 128; i1++)
		{
			states128[i1] = 0;
			for (int j = 0; j < 16; j++)
			{
				states128[i1] = states128[i1] ^ state128[j][i1];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

		}


		//TypeII_b
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				state16[j][k] = TypeII_b[i][j][states[j]][k];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			for (int j = 0; j < 16; j++)
			{
				for (int k = 0; k < 8; k++)
				{
					state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
				}
			}
		}
		for (int i1 = 0; i1 < 128; i1++)
		{
			states128[i1] = 0;
			for (int j = 0; j < 16; j++)
			{
				states128[i1] = states128[i1] ^ state128[j][i1];
			}
		}
		for (int i1 = 0; i1 < 16; i1++)
		{
			states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

		}


		//S1
		for (int j = 0; j < 4; j++)
		{
			states[j] = S1_f4[i + 1][j][states[j]];
		}
		

	}


	//TypeI_a
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			state16[i][j] = TypeI_a[31][i][states[i]][j];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
			}
		}
	}
	for (int i1 = 0; i1 < 128; i1++)
	{
		states128[i1] = 0;
		for (int j = 0; j < 16; j++)
		{
			states128[i1] = states128[i1] ^ state128[j][i1];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

	}


	//TypeII_a
	for (int j = 0; j < 16; j++)
	{
		for (int k = 0; k < 16; k++)
		{
			state16[j][k] = TypeII_a[31][j][states[j]][k];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
			}
		}
	}
	for (int i1 = 0; i1 < 128; i1++)
	{
		states128[i1] = 0;
		for (int j = 0; j < 16; j++)
		{
			states128[i1] = states128[i1] ^ state128[j][i1];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

	}


	//S2
	for (int i = 0; i < 4; i++)
	{

		states[i] = S2_f4[31][i][states[i]];

	}
	

	//TypeI_d
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			state16[i][j] = TypeI_d[i][states[i]][j];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				state128[i1][j * 8 + k] = (state16[i1][j] >> (7 - k)) & 1;
			}
		}
	}
	for (int i1 = 0; i1 < 128; i1++)
	{
		states128[i1] = 0;
		for (int j = 0; j < 16; j++)
		{
			states128[i1] = states128[i1] ^ state128[j][i1];
		}
	}
	for (int i1 = 0; i1 < 16; i1++)
	{
		states[i1] = states128[i1 * 8 + 0] * 128 + states128[i1 * 8 + 1] * 64 + states128[i1 * 8 + 2] * 32 + states128[i1 * 8 + 3] * 16 + states128[i1 * 8 + 4] * 8 + states128[i1 * 8 + 5] * 4 + states128[i1 * 8 + 6] * 2 + states128[i1 * 8 + 7];

	}
	

	//Reverse
	for (int i = 0; i < 4; i++)
	{
		wY[i] = states[i + 12];
		wY[i + 4] = states[i + 8];
		wY[i + 8] = states[i + 4];
		wY[i + 12] = states[i];
	}


}








