#include <cstdint>
#include<vector>
#include <stdio.h>
#include <ctime>

#include "Block.h"

typedef unsigned char byte;


class Blob
{
public:

	Blob(void);
	~Blob(void);
	
	uint64_t id;

	uint32_t get_block_data(uint64_t id_block, uint64_t block_size, byte *data);

	uint64_t save_block_data(uint64_t block_id, const byte * block_data, uint64_t block_size);

	uint32_t get_blocks_count();

protected:

	void init();
	void generate_random_file_name(char* file_name, uint32_t max_file_name_length);

	uint64_t create_new_block(uint64_t block_id, uint64_t block_offset);

	char *file_name;

	uint32_t max_file_name_length = 6;
	
	FILE * pFile;

	std::vector<Block*> blocks;
};
