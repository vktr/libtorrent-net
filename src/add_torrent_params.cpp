#include "add_torrent_params.h"

#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_info.hpp>
#include <msclr/marshal_cppstd.h>

#include "interop.h"
#include "torrent_info.h"

using namespace lt;

add_torrent_params::add_torrent_params()
{
    params_ = new libtorrent::add_torrent_params();
}

add_torrent_params::~add_torrent_params()
{
    delete params_;
}

System::String^ add_torrent_params::name::get()
{
    return interop::from_std_string(params_->name);
}

void add_torrent_params::name::set(System::String^ value)
{
    params_->name = interop::to_std_string(value);
}

System::String^ add_torrent_params::save_path::get()
{
    return interop::from_std_string(params_->save_path);
}

void add_torrent_params::save_path::set(System::String^ value)
{
    params_->save_path = interop::to_std_string(value);
}

torrent_info^ add_torrent_params::ti::get()
{
    if(params_->ti)
    {
        return gcnew torrent_info(*params_->ti.get());
    }

    return nullptr;
}

void add_torrent_params::ti::set(torrent_info^ value)
{
    params_->ti = new libtorrent::torrent_info(*value->ptr());
}

libtorrent::add_torrent_params* add_torrent_params::ptr()
{
    return params_;
}
