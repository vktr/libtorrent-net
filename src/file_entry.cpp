#include "file_entry.h"

#include <libtorrent/file_storage.hpp>

#include "interop.h"

#define FE_PROP_IMPL(type, name) \
    type file_entry::name::get() \
    { \
        return entry_->name; \
    } \
    void file_entry::name::set(type val) \
    { \
        entry_->name = val; \
    }

using namespace lt;

file_entry::file_entry(const libtorrent::file_entry& entry)
{
    entry_ = new libtorrent::file_entry(entry);
}

file_entry::~file_entry()
{
    delete entry_;
}

libtorrent::file_entry& file_entry::ptr()
{
    return *entry_;
}

System::String^ file_entry::path::get()
{
    return interop::from_std_string(entry_->path);
}

void file_entry::path::set(System::String^ val)
{
    entry_->path = interop::to_std_string(val);
}

System::String^ file_entry::symlink_path::get()
{
    return interop::from_std_string(entry_->symlink_path);
}

void file_entry::symlink_path::set(System::String^ val)
{
    entry_->symlink_path = interop::to_std_string(val);
}

FE_PROP_IMPL(long long, offset);
FE_PROP_IMPL(long long, size);
FE_PROP_IMPL(long long, file_base);
// TODO mtime
// TODO filehash
FE_PROP_IMPL(bool, pad_file);
FE_PROP_IMPL(bool, hidden_attribute);
FE_PROP_IMPL(bool, executable_attribute);
FE_PROP_IMPL(bool, symlink_attribute);
