//
// Created by Alisia Kazimierek on 04/06/2024.
//

#ifndef ZORK_DERVIEDFUTUREFEATURE_H
#define ZORK_DERVIEDFUTUREFEATURE_H

#include "FutureFeature.h"
class DerviedFutureFeature : public FutureFeature{
public:
    DerviedFutureFeature() = default;
    ~DerviedFutureFeature() override = default;

    void someFutureFeature() override;
};


#endif //ZORK_DERVIEDFUTUREFEATURE_H
