#pragma once

#include <libtorrent/error_code.hpp>

namespace lt
{
    public ref class error_code
    {
    internal:
        error_code(const libtorrent::error_code& ec);

    public:
        ~error_code();

        System::String^ message();
        int value();

    private:
        libtorrent::error_code* error_;
    };
}
