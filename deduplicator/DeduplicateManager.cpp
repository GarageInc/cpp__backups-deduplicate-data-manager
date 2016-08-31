#include "DeduplicateManager.h"

uint32_t blob_id_counter = 0;

DeduplicateManager::DeduplicateManager(void)
{

}

DeduplicateManager::~DeduplicateManager(void)
{

}

int DeduplicateManager::init(uint64_t i_block_size, uint32_t i_blob_size) {
	block_size = i_block_size;
	blob_size = i_blob_size;

	return 0;
}

int DeduplicateManager::put_block(uint64_t block_id, const byte* block_data) {

	// check blocks - is such block exist?
	uint64_t data_hash = hash(block_data);

	if ( blocks_map.find(data_hash) == blocks_map.end()) {
		
		return 0;// success;
	}
	else {

		uint64_t saved_block_id;
		
		for ( auto blob : blobs) {
			
			saved_block_id = blob.save( block_id, block_data, block_size);

			if ( saved_block_id != 0) {

				blocks_map[ data_hash].push_back(blob.id);	

				return 0;// success;
			} // pass
		}

		Blob new_blob;
		new_blob.id = ++blob_id_counter;
		new_blob.save(block_id, block_data, block_size);

		blocks_map[data_hash].push_back(new_blob.id);

		blobs.push_back(new_blob);

		return 0;
	}

	return 1;
}

int  DeduplicateManager::get_block( uint64_t block_id, byte* block_data) {

	auto blob_block_ids = blocks_ids_map.find( block_id);

	if ( blob_block_ids != blocks_ids_map.end()) {


		return 0;
	}
	else {
		return 1;
	}
}

// this algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c. another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33 (why it works better than many other constants, prime or not) has never been adequately explained.
uint64_t DeduplicateManager::hash(const byte *block_data) {
	
	uint64_t hash = 5381;
	
	int c;

	while (c = *block_data++) {
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return hash;
}