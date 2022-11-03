#include <stdio.h>
#include <cstdint>
#include "aes.hpp"

using std::uint8_t;
using std::uint32_t;

int main(int argc, char **argv)
{	
	unsigned char in[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
	unsigned char key128[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};
	unsigned char out[16];
	
	AES c128((char*)key128, sizeof(key128));
	
	printf("C.1   AES-128 (Nk=4, Nr=10)\n\n");
	printf("PLAINTEXT:          ");
	for(int i = 0; i < (int) sizeof(in); i++) printf("%02x", in[i]);
	printf("\nKEY:                ");
	for(int i = 0; i < (int) sizeof(key128); i++) printf("%02x", key128[i]);
	printf("\n\nCIPHER (ENCRYPT):\n");
	c128.cipher(in, out);
	printf("\nINVERSE CIPHER (DECRYPT):\n");
	c128.invCipher(out, out);
	
	unsigned char key192[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17};
	AES c192((char*)key192, sizeof(key192));
	
	printf("\nC.2   AES-192 (Nk=6, Nr=12)\n");
	printf("\nPLAINTEXT:          ");
	for(int i = 0; i < (int) sizeof(in); i++) printf("%02x", in[i]);
	printf("\nKEY:                ");
	for(int i = 0; i < (int) sizeof(key192); i++) printf("%02x", key192[i]);
	printf("\n\nCIPHER (ENCRYPT):\n");
	c192.cipher(in, out);
	printf("\nINVERSE CIPHER (DECRYPT):\n");
	c192.invCipher(out, out);
	
	unsigned char key256[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
							  0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f};
	AES c256((char*)key256, sizeof(key256));
	
	printf("\nC.3   AES-256 (Nk=8, Nr=14)\n");
	printf("\nPLAINTEXT:          ");
	for(int i = 0; i < (int) sizeof(in); i++) printf("%02x", in[i]);
	printf("\nKEY:                ");
	for(int i = 0; i < (int) sizeof(key256); i++) printf("%02x", key256[i]);
	printf("\n\nCIPHER (ENCRYPT):\n");
	c256.cipher(in, out);
	printf("\nINVERSE CIPHER (DECRYPT):\n");
	c256.invCipher(out, out);
	
	return 0;
}
