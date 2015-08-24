#include "session_alert_dispatcher.h"

#include <libtorrent/alert.hpp>

#include "alert.h"

using namespace lt;

void session_alert_dispatcher::invoke_callback(std::auto_ptr<libtorrent::alert> al)
{
    // TODO lock
    gcroot<alert^> a = alert::create(al);
    callback_->Invoke(a);
}

void session_alert_dispatcher::set_callback(gcroot<System::Action<alert^>^> callback)
{
    callback_ = callback;
}
