
#include <cstdint>

class Block
{
public:

	Block(void);
	~Block(void);

	uint32_t id;
	uint32_t offset;
	uint64_t hash_value;

private:

};
