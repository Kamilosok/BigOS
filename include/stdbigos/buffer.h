#ifndef _STDBIGOS_BUFFER_H
#define _STDBIGOS_BUFFER_H

#include <stdbigos/types.h>

typedef struct cbuffer_t {
	const void* data;
	size_t size;
} cbuffer_t;

// Helpers to create buffers
[[nodiscard]]
static inline cbuffer_t make_cbuffer(const void* data, size_t size) {
	cbuffer_t buf = {.data = data, .size = size};
	return buf;
}

[[nodiscard]]
static inline bool cbuffer_is_valid(cbuffer_t buf) {
	return buf.data != nullptr;
}

[[nodiscard]]
static inline bool cbuffer_is_empty(cbuffer_t buf) {
	return !cbuffer_is_valid(buf) || buf.size == 0;
}

// Read big-endian 32-bit from buffer at given offset
[[nodiscard]]
bool cbuffer_read_u32_be(cbuffer_t buf, size_t offset, u32* out);

// Read big-endian 64-bit from buffer at given offset
[[nodiscard]]
bool cbuffer_read_u64_be(cbuffer_t buf, size_t offset, u64* out);

// Read little-endian 32-bit from buffer at given offset
[[nodiscard]]
bool cbuffer_read_u32_le(cbuffer_t buf, size_t offset, u32* out);

// Read little-endian 64-bit from buffer at given offset
[[nodiscard]]
bool cbuffer_read_u64_le(cbuffer_t buf, size_t offset, u64* out);

// Read a zero-terminated C-string from buf at offset
[[nodiscard]]
bool cbuffer_read_cstring(cbuffer_t buf, size_t offset, const char** out_str);

// Sub buffer
[[nodiscard]]
cbuffer_t cbuffer_sub_cbuffer(cbuffer_t buf, size_t offset, size_t max_size);

#endif
