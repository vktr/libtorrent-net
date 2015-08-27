#include "file_storage.h"

#include <libtorrent/file_storage.hpp>

#include "file_entry.h"
#include "interop.h"

using namespace lt;

file_storage::file_storage(const libtorrent::file_storage& storage)
{
    storage_ = new libtorrent::file_storage(storage);
}

file_storage::file_storage()
{
    storage_ = new libtorrent::file_storage();
}

file_storage::~file_storage()
{
    delete storage_;
}

libtorrent::file_storage& file_storage::ptr()
{
    return *storage_;
}

bool file_storage::is_valid()
{
    return storage_->is_valid();
}

void file_storage::reserve(int num_files)
{
    storage_->reserve(num_files);
}

void file_storage::add_file(System::String^ p, long long size)
{
    storage_->add_file(interop::to_std_string(p), size);
}

void file_storage::add_file(file_entry^ entry)
{
    storage_->add_file(entry->ptr());
}

void file_storage::rename_file(int index, System::String^ new_filename)
{
    storage_->rename_file(index, interop::to_std_string(new_filename));
}

int file_storage::num_files()
{
    return storage_->num_files();
}

file_entry^ file_storage::at(int index)
{
    return gcnew file_entry(storage_->at(index));
}

long long file_storage::total_size()
{
    return storage_->total_size();
}

void file_storage::set_num_pieces(int n)
{
    storage_->set_num_pieces(n);
}

int file_storage::num_pieces()
{
    return storage_->num_pieces();
}

void file_storage::set_piece_length(int l)
{
    storage_->set_piece_length(l);
}

int file_storage::piece_length()
{
    return storage_->piece_length();
}

int file_storage::piece_size(int index)
{
    return storage_->piece_size(index);
}

void file_storage::set_name(System::String^ name)
{
    storage_->set_name(interop::to_std_string(name));
}

System::String^ file_storage::name()
{
    return interop::from_std_string(storage_->name());
}

void file_storage::optimize(int pad_file_limit, int alignment)
{
    storage_->optimize(pad_file_limit, alignment);
}

long long file_storage::file_size(int index)
{
    return storage_->file_size(index);
}

System::String^ file_storage::file_name(int index)
{
    return interop::from_std_string(storage_->file_name(index));
}

long long file_storage::file_offset(int index)
{
    return storage_->file_offset(index);
}

bool file_storage::pad_file_at(int index)
{
    return storage_->pad_file_at(index);
}

System::String^ file_storage::symlink(int index)
{
    return interop::from_std_string(storage_->symlink(index));
}

System::String^ file_storage::file_path(int index, System::String^ save_path)
{
    return interop::from_std_string(storage_->file_path(
        index,
        interop::to_std_string(save_path)));
}

int file_storage::file_flags(int index)
{
    return storage_->file_flags(index);
}

void file_storage::set_file_base(int index, long long offset)
{
    storage_->set_file_base(index, offset);
}

long long file_storage::file_base(int index)
{
    return storage_->file_base(index);
}

int file_storage::file_index_at_offset(long long offset)
{
    return storage_->file_index_at_offset(offset);
}
