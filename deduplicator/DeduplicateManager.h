

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


private:

	uint64_t block_size;
	uint32_t blob_size;

	// block data hash and blobs_ids(where search data)
	std::unordered_map<uint64_t, std::vector<uint64_t>> blocks_map;
		
	// id_block and pair<blob_id, block_id>
	std::unordered_map<uint64_t, std::pair<uint32_t, uint32_t>> blocks_ids_map;

	std::vector<Blob> blobs;

	uint64_t hash(const byte *block_data);
};
