
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
	byte input = NULL;
	
	while (true) {

		printf("\n\nIf you want put block, press 0, if you want get block, press 1...\n");

		scanf("%c", &symbol);

		if (symbol == '0' || symbol=='1') {

			printf("Enter BLOCK_ID: ");
			scanf("%d", &block_id);

			if (symbol == '0') {

				printf("Please, enter data: ");
				for (uint32_t i = 0; i < BLOK_SIZE-1 && input != '\0'; i++) {

					scanf("%c", &input);
					block_data[i] = input;
				}
				block_data[BLOK_SIZE - 1] = '\0';

				manager->put_block(block_id, block_data);
			}
			else {

				uint32_t relay = manager->get_block(block_id, block_data);

				if (relay == 0) {

					for (uint32_t i = 0; i < BLOK_SIZE - 1; i++) {

						printf("%c", block_data[i]);
					}
				}
				else {

					printf("Fail by getting data.. :(\n");
				}
			}

		} else {
			// pass
		}

	}
	
	return 0;
}

