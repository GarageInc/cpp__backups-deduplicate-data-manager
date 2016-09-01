
#include "DeduplicateManager.h"

const uint32_t BLOB_SIZE = 10;
const uint64_t BLOK_SIZE = 10;

int main(int argc, char *argv[])
{
	DeduplicateManager *manager = new DeduplicateManager();
	
	manager->init(BLOK_SIZE, BLOB_SIZE);
	

	char symbol;
	uint64_t block_id;
	byte* block_data = new byte[BLOK_SIZE]();
	byte input = ' ';
	
	while (true) {

		printf("\nPress 0, if you want put block, \npress 1 if you want get block, \npress another for break...\n");
				
		scanf("%c", &symbol);
		
		if (symbol == '0' || symbol=='1') {

			printf("\nEnter BLOCK_ID: ");
			scanf("%ju", &block_id);

			if (symbol == '0') {

				printf("\nPlease, enter data by length %ju: ", BLOK_SIZE);

				scanf("%s", block_data);
				
				// dog-nail for output
				block_data[BLOK_SIZE - 1] = '\0';

				uint32_t relay = manager->put_block(block_id, block_data);
			
				if (relay != 0) {
					printf("failed with code: %d", relay);
				};
			}
			else {

				uint32_t relay = manager->get_block(block_id, block_data);

				if ( relay == 0) {

					for (uint32_t i = 0; i < BLOK_SIZE - 1; i++) {

						printf("%c", block_data[i]);
					}
				}
				else {

					printf("failed with code: %d", relay);
				}
			}

		} else {

			break;
		}

		while ( getchar() != '\n') {

		}

	}
	
	return 0;
}

