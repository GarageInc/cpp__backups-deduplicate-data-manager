

typedef unsigned char byte;

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "Blob.h"


class DeduplicateManager
{
public:

	DeduplicateManager(void);
	~DeduplicateManager(void);

	int init(uint64_t block_size, uint32_t blob_size);

	int put_block(uint64_t block_id, const byte* block_data);

	int get_block(uint64_t block_id, byte* block_data);


protected:

	uint64_t block_size;
	uint32_t blob_size;

	// block data hash and blob* as value(where search data)
	std::unordered_map<uint64_t, Blob*> blocks_map;
		
	// block_id as key and blob* as value
	std::unordered_map<uint64_t, Blob*> blocks_ids_map;

	std::vector<Blob*> blobs;

	uint64_t hash(const byte *block_data);
};
