#include "session.h"

#include <libtorrent/session.hpp>

#include "alert.h"
#include "add_torrent_params.h"
#include "session_alert_dispatcher.h"

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

void session::async_add_torrent(add_torrent_params^ params)
{
    session_->async_add_torrent(*params->ptr());
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

void session::listen_on(int minPort, int maxPort)
{
    libtorrent::error_code ec;
    session_->listen_on(std::make_pair(minPort, maxPort), ec);

    if (ec)
    {
        throw gcnew System::Exception(gcnew System::String(ec.message().c_str()));
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
