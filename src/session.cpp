#include "session.h"

#include <libtorrent/session.hpp>

#include "alert.h"
#include "add_torrent_params.h"
#include "entry.h"
#include "interop.h"
#include "lazy_entry.h"
#include "session_alert_dispatcher.h"
#include "torrent_handle.h"

using namespace lt;

session::session()
{
    dispatcher_ = new session_alert_dispatcher();
    session_ = new libtorrent::session();
}

session::~session()
{
    delete dispatcher_;
    delete session_;
}

void session::load_state(lazy_entry^ e)
{
    session_->load_state(*e->ptr());
}

entry^ session::save_state(unsigned int flags)
{
    libtorrent::entry e;
    session_->save_state(e, flags);

    return gcnew entry(e);
}

void session::post_torrent_updates()
{
    session_->post_torrent_updates();
}

void session::async_add_torrent(add_torrent_params^ params)
{
    session_->async_add_torrent(*params->ptr());
}

torrent_handle^ session::add_torrent(add_torrent_params^ params)
{
    libtorrent::error_code ec;
    libtorrent::torrent_handle h = session_->add_torrent(*params->ptr(), ec);

    if (ec)
    {
        throw gcnew System::Exception(interop::from_std_string(ec.message()));
    }

    return gcnew torrent_handle(h);
}

void session::pause()
{
    session_->pause();
}

void session::resume()
{
    session_->resume();
}

bool session::is_paused()
{
    return session_->is_paused();
}

bool session::is_dht_running()
{
    return session_->is_dht_running();
}

void session::start_dht()
{
    session_->start_dht();
}

void session::stop_dht()
{
    session_->stop_dht();
}

void session::load_country_db(System::String^ file)
{
    session_->load_country_db(interop::to_std_string(file).c_str());
}

void session::load_asnum_db(System::String^ file)
{
    session_->load_asnum_db(interop::to_std_string(file).c_str());
}

void session::set_key(int key)
{
    session_->set_key(key);
}

void session::listen_on(int minPort, int maxPort)
{
    libtorrent::error_code ec;
    session_->listen_on(std::make_pair(minPort, maxPort), ec);

    if (ec)
    {
        throw gcnew System::Exception(interop::from_std_string(ec.message()));
    }
}

bool session::is_listening()
{
    return session_->is_listening();
}

int session::listen_port()
{
    return session_->listen_port();
}

int session::ssl_listen_port()
{
    return session_->ssl_listen_port();
}

void session::remove_torrent(torrent_handle^ handle, int options)
{
    session_->remove_torrent(*handle->ptr(), options);
}

void session::set_alert_mask(unsigned int mask)
{
    // TODO
    session_->set_alert_mask(libtorrent::alert::all_categories);
}

void session::set_alert_dispatch(System::Action<alert^>^ dispatch)
{
    dispatcher_->set_callback(dispatch);
    session_->set_alert_dispatch(std::bind(&session_alert_dispatcher::invoke_callback, *dispatcher_, std::placeholders::_1));
}

void session::clear_alert_dispatch()
{
    typedef boost::function<void(std::auto_ptr<libtorrent::alert>)> dispatch_func_t;
    session_->set_alert_dispatch(dispatch_func_t());
}

void session::stop_lsd()
{
    session_->stop_lsd();
}

void session::start_lsd()
{
    session_->start_lsd();
}

void session::stop_upnp()
{
    session_->stop_upnp();
}

void session::start_upnp()
{
    session_->start_upnp();
}

void session::delete_port_mapping(int handle)
{
    session_->delete_port_mapping(handle);
}

void session::stop_natpmp()
{
    session_->stop_natpmp();
}

void session::start_natpmp()
{
    session_->start_natpmp();
}
