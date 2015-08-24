#include "interop.h"

#include <windows.h>

using namespace lt;

System::String^ interop::from_std_string(const std::string& value)
{
    int bufferSize = MultiByteToWideChar(CP_UTF8, 0, value.c_str(), -1, NULL, 0);
    wchar_t* wstr = new wchar_t[bufferSize];
    MultiByteToWideChar(CP_UTF8, 0, value.c_str(), -1, wstr, bufferSize);
    System::String^ result = gcnew System::String(wstr);
    delete[] wstr;
    return result;
}

std::string interop::to_std_string(System::String^ value)
{
    // First, convert to a managed array of the bytes you want.
    array<System::Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(value);

    // Then, copy those bytes from the managed byte array to an unmanaged string.
    std::string str;
    str.resize(bytes->Length);
    System::Runtime::InteropServices::Marshal::Copy(bytes, 0, System::IntPtr((int)str.data()), bytes->Length);
    return str;
}
