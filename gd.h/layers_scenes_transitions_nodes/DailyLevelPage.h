#ifndef __DAILYLEVELPAGE_H__
#define __DAILYLEVELPAGE_H__

#include <gd.h>

namespace gd {

    class GJSearchObject;

    class DailyLevelPage : public gd::FLAlertLayer {
    public:
        PAD(493 - sizeof(gd::FLAlertLayer));
        bool isWeekly;
    };

}

#endif
