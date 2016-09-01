
#include <cstdint>

class Block
{
public:

	Block(uint64_t block_id, uint64_t offset);
	~Block(void);

	uint64_t id;
	uint64_t offset;

protected:

};
