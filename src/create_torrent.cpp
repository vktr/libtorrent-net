#include "create_torrent.h"

#include <libtorrent/create_torrent.hpp>

#include "entry.h"
#include "file_storage.h"
#include "interop.h"
#include "sha1_hash.h"

using namespace lt;

create_torrent::create_torrent(file_storage^ fs)
    : create_torrent(fs, 0, -1, libtorrent::create_torrent::optimize, -1)
{
}

create_torrent::create_torrent(file_storage^ fs, int piece_size)
    : create_torrent(fs, piece_size, -1, libtorrent::create_torrent::optimize, -1)
{
}

create_torrent::create_torrent(file_storage^ fs, int piece_size, int pad_file_limit)
    : create_torrent(fs, piece_size, pad_file_limit, libtorrent::create_torrent::optimize, -1)
{
}

create_torrent::create_torrent(file_storage^ fs, int piece_size, int pad_file_limit, int flags)
    : create_torrent(fs, piece_size, pad_file_limit, flags, -1)
{
}

create_torrent::create_torrent(file_storage^ fs, int piece_size, int pad_file_limit, int flags, int alignment)
{
    create_ = new libtorrent::create_torrent(fs->ptr(), piece_size, pad_file_limit, flags, alignment);
}

create_torrent::~create_torrent()
{
    delete create_;
}

libtorrent::create_torrent& create_torrent::ptr()
{
    return *create_;
}

void create_torrent::add_files(file_storage^ fs, System::String^ path)
{
    add_files(fs, path, 0U);
}

void create_torrent::add_files(file_storage^ fs, System::String^ path, unsigned int flags)
{
    libtorrent::add_files(fs->ptr(), interop::to_std_string(path), flags);
}

void create_torrent::set_piece_hashes(create_torrent^ ct, System::String^ path)
{
    libtorrent::set_piece_hashes(ct->ptr(), interop::to_std_string(path));
}

entry^ create_torrent::generate()
{
    return gcnew entry(create_->generate());
}

file_storage^ create_torrent::files()
{
    return gcnew file_storage(create_->files());
}

void create_torrent::set_comment(System::String^ str)
{
    create_->set_comment(interop::to_std_string(str).c_str());
}

void create_torrent::set_creator(System::String^ str)
{
    create_->set_creator(interop::to_std_string(str).c_str());
}

void create_torrent::set_hash(int index, sha1_hash^ hash)
{
    create_->set_hash(index, hash->ptr());
}

void create_torrent::set_file_hash(int index, sha1_hash^ hash)
{
    create_->set_file_hash(index, hash->ptr());
}

void create_torrent::add_url_seed(System::String^ url)
{
    create_->add_url_seed(interop::to_std_string(url));
}

void create_torrent::add_http_seed(System::String^ url)
{
    create_->add_http_seed(interop::to_std_string(url));
}

void create_torrent::add_node(System::String^ host, int port)
{
    create_->add_node(std::make_pair(interop::to_std_string(host), port));
}

void create_torrent::add_tracker(System::String^ url)
{
    add_tracker(url, 0);
}

void create_torrent::add_tracker(System::String^ url, int tier)
{
    create_->add_tracker(interop::to_std_string(url), tier);
}

void create_torrent::set_root_cert(System::String^ pem)
{
    create_->set_root_cert(interop::to_std_string(pem));
}

bool create_torrent::priv()
{
    return create_->priv();
}

void create_torrent::set_priv(bool p)
{
    create_->set_priv(p);
}

int create_torrent::num_pieces()
{
    return create_->num_pieces();
}

int create_torrent::piece_length()
{
    return create_->piece_length();
}

int create_torrent::piece_size(int n)
{
    return create_->piece_size(n);
}
