#pragma once

#include <memory>
#include <vcclr.h>

namespace libtorrent
{
    class alert;
}

namespace lt
{
    ref class alert;

    class session_alert_dispatcher
    {
    public:
        void invoke_callback(std::auto_ptr<libtorrent::alert> alert);

        void set_callback(gcroot<System::Action<alert^>^> callback);

    private:
        gcroot<System::Action<alert^>^> callback_;
    };
}
