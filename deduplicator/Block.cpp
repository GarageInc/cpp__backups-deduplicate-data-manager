#include "Block.h"
#include <cstdio>

Block::Block(uint64_t block_id, uint64_t block_offset)
{
	id = block_id;
	offset = block_offset;
}

Block::~Block(void)
{
	printf("\nDeleted block... %d", id);
}