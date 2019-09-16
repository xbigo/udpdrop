#ifndef UDPDROP_VERSION_H
#define UDPDROP_VERSION_H

//  UDPDROP_VERSION % 100 is the patch level
//  UDPDROP_VERSION / 100 % 100 is the minor version
//  UDPDROP_VERSION / 10000 is the major version
#define UDPDROP_VERSION 000100
#define UDPDROP_LIB_VERSION "0_1"

namespace udpdrop{
    inline constexpr int udpdrop_version=100;
}
#endif //end UDPDROP_VERSION_H