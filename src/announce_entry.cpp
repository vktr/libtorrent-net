#include "announce_entry.h"

#include <libtorrent/torrent_info.hpp>

#include "interop.h"

using namespace lt;

announce_entry::announce_entry(libtorrent::announce_entry& entry)
{
    entry_ = new libtorrent::announce_entry(entry);
}

announce_entry::announce_entry(System::String^ url)
{
    entry_ = new libtorrent::announce_entry(interop::to_std_string(url));
}

announce_entry::~announce_entry()
{
    delete entry_;
}

libtorrent::announce_entry* announce_entry::ptr()
{
    return entry_;
}

int announce_entry::next_announce_in()
{
    return entry_->next_announce_in();
}

int announce_entry::min_announce_in()
{
    return entry_->min_announce_in();
}

void announce_entry::reset()
{
    entry_->reset();
}

bool announce_entry::can_announce(System::DateTime now, bool is_seed)
{
    System::DateTime unix(1970, 1, 1);
    int totalSeconds = (now - unix.ToLocalTime()).TotalSeconds;
    return entry_->can_announce(libtorrent::ptime(totalSeconds), is_seed); // TODO: investigate ptime
}

bool announce_entry::is_working()
{
    return entry_->is_working();
}

void announce_entry::trim()
{
    entry_->trim();
}

System::String^ announce_entry::url::get()
{
    return interop::from_std_string(entry_->url);
}

System::String^ announce_entry::trackerid::get()
{
    return interop::from_std_string(entry_->trackerid);
}

System::String^ announce_entry::message::get()
{
    return interop::from_std_string(entry_->message);
}

int announce_entry::scrape_incomplete::get()
{
    return entry_->scrape_incomplete;
}

int announce_entry::scrape_complete::get()
{
    return entry_->scrape_complete;
}

int announce_entry::scrape_downloaded::get()
{
    return entry_->scrape_downloaded;
}

int announce_entry::tier::get()
{
    return entry_->tier;
}

int announce_entry::fail_limit::get()
{
    return entry_->fail_limit;
}

int announce_entry::fails::get()
{
    return entry_->fails;
}

bool announce_entry::updating::get()
{
    return entry_->updating;
}

int announce_entry::source::get()
{
    return entry_->source;
}

bool announce_entry::verified::get()
{
    return entry_->verified;
}

bool announce_entry::start_sent::get()
{
    return entry_->start_sent;
}

bool announce_entry::complete_sent::get()
{
    return entry_->complete_sent;
}

bool announce_entry::send_stats::get()
{
    return entry_->send_stats;
}
