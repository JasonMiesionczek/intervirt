#include <drivers/hyperv/HypervDriverLegacy.h>

HypervDriverLegacy::HypervDriverLegacy(Connection::ConnectionPtr conn) 
    : HypervCommon(conn)
{
    auto result = this->enumerate<v1::Win32OperatingSystem>();
}