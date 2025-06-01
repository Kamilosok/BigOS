#include <stdbigos/bitutils.h>
#include <stdbigos/buffer.h>
#include <stdbigos/math.h>
#include <stdbigos/string.h>

bool cbuffer_read_u32_be(cbuffer_t buf, size_t offset, u32* out) {
	bool ok = cbuffer_is_valid(buf) && offset + sizeof(*out) <= buf.size;
	if (ok)
		*out = read_be32((const u8*)buf.data + offset);
	return ok;
}

bool cbuffer_read_u32_le(cbuffer_t buf, size_t offset, u32* out) {
	bool ok = cbuffer_is_valid(buf) && offset + sizeof(*out) <= buf.size;
	if (ok)
		*out = read_le32((const u8*)buf.data + offset);
	return ok;
}
bool cbuffer_read_u64_be(cbuffer_t buf, size_t offset, u64* out) {
	bool ok = cbuffer_is_valid(buf) && offset + sizeof(*out) <= buf.size;
	if (ok)
		*out = read_be64((const u8*)buf.data + offset);
	return ok;
}
bool cbuffer_read_u64_le(cbuffer_t buf, size_t offset, u64* out) {
	bool ok = cbuffer_is_valid(buf) && offset + sizeof(*out) <= buf.size;
	if (ok)
		*out = read_le64((const u8*)buf.data + offset);
	return ok;
}

bool cbuffer_read_cstring(cbuffer_t buf, size_t offset, const char** out_str) {
	if (!cbuffer_is_valid(buf) || !out_str || offset >= buf.size)
		return false;

	const char* beg = (const char*)buf.data + offset;
	const void* end = memchr(beg, '\0', buf.size - offset);

	if (!end)
		return false;

	// found null
	*out_str = beg;
	return true;
}

cbuffer_t cbuffer_sub_cbuffer(cbuffer_t buf, size_t offset, size_t max_size) {
	if (!cbuffer_is_valid(buf) || buf.size < offset)
		return make_cbuffer(nullptr, 0);

	size_t rest = buf.size - offset;
	return make_cbuffer((const u8*)buf.data + offset, min(rest, max_size));
}
