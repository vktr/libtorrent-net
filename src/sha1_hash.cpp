#include "sha1_hash.h"

#include <libtorrent/sha1_hash.hpp>

#include "interop.h"

using namespace lt;

sha1_hash::sha1_hash(const libtorrent::sha1_hash& hash)
{
    hash_ = new libtorrent::sha1_hash(hash);
}

sha1_hash::sha1_hash(System::String^ val)
{
    std::string hex = interop::to_std_string(val);

    hash_ = new libtorrent::sha1_hash();
    libtorrent::from_hex(&hex[0], hex.size(), (char*)&hash_[0]);
}

sha1_hash::~sha1_hash()
{
    delete hash_;
}

libtorrent::sha1_hash& sha1_hash::ptr()
{
    return *hash_;
}

System::String^ sha1_hash::ToString()
{
    std::string hex = libtorrent::to_hex(hash_->to_string());
    return interop::from_std_string(hex);
}
