#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
block_t *block = NULL;
if (!prev || !data )
return (NULL);
block = (block_t *) malloc(sizeof(block_t));
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(0);
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
if (data_len > BLOCKCHAIN_DATA_MAX)
{
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
block->data.len=BLOCKCHAIN_DATA_MAX;
}
else
{
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
block->data.len=data_len;
}
memset(block->hash, 0, SHA256_DIGEST_LENGTH);
return (block);
}
