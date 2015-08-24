#include "alert.h"

#include <libtorrent/alert.hpp>
#include <libtorrent/alert_types.hpp>

#include "alert_types.h"
#include "interop.h"

#define ALERT_CASE(alert_name) \
    case libtorrent::alert_name::alert_type: \
    { \
        libtorrent::alert_name* tmp = libtorrent::alert_cast<libtorrent::alert_name>(a); \
        return gcnew alert_name(tmp); \
    }

using namespace lt;

alert::alert(libtorrent::alert* al)
{
    alert_ = al;
}

alert::~alert()
{
    delete alert_;
}

alert^ alert::create(std::auto_ptr<libtorrent::alert> al)
{
    libtorrent::alert* a = al.release();

    switch (a->type())
    {
        ALERT_CASE(torrent_added_alert);
        ALERT_CASE(torrent_removed_alert);
    default:
        return gcnew alert(a);
    }

    throw gcnew System::NotImplementedException();
}

System::DateTime alert::timestamp()
{
    // TODO
    return System::DateTime::Now;
}

int alert::type()
{
    return alert_->type();
}

System::String^ alert::what()
{
    return interop::from_std_string(alert_->what());
}

System::String^ alert::message()
{
    return interop::from_std_string(alert_->message());
}

int alert::category()
{
    return alert_->category();
}

bool alert::discardable()
{
    return alert_->discardable();
}
