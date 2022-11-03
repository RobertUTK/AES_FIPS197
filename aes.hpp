#ifndef AES_HPP
#define AES_HPP

#include <cstdint>

class AES {
	private:
		int Nb; //Number of 32 bit words comprising the state
		int Nk; //Number of 32 bit words comprising the cipher key
		int Nr; //Number of rounds
		unsigned char **state;
		unsigned char *key;
		unsigned int *expandedKey;
		//Functions
		unsigned char xtime(const unsigned char&);
		unsigned char ffMultiply(const unsigned char&, const unsigned char&);
		unsigned char ffAdd(const unsigned char&, const unsigned char&);
		unsigned int subWord(unsigned int);
		unsigned int rotWord(unsigned int);
		unsigned int word(const unsigned char&, const unsigned char&, const unsigned char&, const unsigned char&);
		void subBytes();
		void shiftRows();
		void mixColumns();
		void addRoundKey(const unsigned int *words);
		void freeMemory();
		void keyExpansion();
		void printState();
		void invShiftRows();
		void invSubBytes();
		void invMixColumns();
		void printData(const int &, const int &, const int &);
	public:
		AES(char *, int);
		virtual ~AES() {freeMemory();}
		void cipher(unsigned char *, unsigned char *);
		void invCipher(unsigned char *, unsigned char *);
};



void makeState(unsigned char *, unsigned char **);
void makeOut(unsigned char **, unsigned char *);

#endif