#include <cstdint>
#include<vector>
#include <stdio.h>
#include <ctime>

#include "Block.h"

typedef unsigned char byte;

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int string_length = sizeof(alphanum) - 1;

char genRandom()
{

	return alphanum[rand() % string_length];
}

class Blob
{
public:

	Blob(void);
	~Blob(void);
	
	uint32_t id;

	uint32_t get_block_data(uint64_t id_block, uint64_t block_size, byte *data);

	uint32_t save(uint64_t block_id, const byte * block_data, uint64_t block_size);

	uint32_t get_blocks_count();
private:

	
	char *file_name;

	uint32_t max_file_name_length = 20;
	
	FILE * pFile;

	// save id_block and offset in file
	std::vector<Block> blocks;
};
