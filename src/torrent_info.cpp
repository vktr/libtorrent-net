#include "torrent_info.h"

#include <libtorrent/torrent_info.hpp>
#include <msclr/marshal_cppstd.h>

#include "interop.h"

using namespace lt;

torrent_info::torrent_info(cli::array<System::Byte>^ buffer)
{
    pin_ptr<unsigned char> ptr = &buffer[0];
    const char *pbegin = (const char*)(const unsigned char*)ptr;
    info_ = new libtorrent::torrent_info(pbegin, buffer->Length);
}

torrent_info::torrent_info(System::String^ fileName)
{
    std::string file = interop::to_std_string(fileName);
    info_ = new libtorrent::torrent_info(file);
}

torrent_info::torrent_info(libtorrent::torrent_info& info)
{
    info_ = new libtorrent::torrent_info(info);
}

torrent_info::~torrent_info()
{
    delete info_;
}

System::String^ torrent_info::name()
{
    return lt::interop::from_std_string(info_->name());
}

System::String^ torrent_info::comment()
{
    return lt::interop::from_std_string(info_->comment());
}

System::String^ torrent_info::creator()
{
    return lt::interop::from_std_string(info_->creator());
}

libtorrent::torrent_info* torrent_info::ptr()
{
    return info_;
}