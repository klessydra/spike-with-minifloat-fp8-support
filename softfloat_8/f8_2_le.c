/*============================================================================
Copyright 2023 Sapienza University of Rome

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
=============================================================================*/

#include <stdbool.h>
#include <stdint.h>
#include "platform.h"
#include "internals.h"
#include "softfloat.h"

bool f8_2_le( float8_2_t a, float8_2_t b )
{
    union ui8_f8_2 uA;
    uint_fast8_t uiA;
    union ui8_f8_2 uB;
    uint_fast8_t uiB;
    bool signA, signB;

    uA.f = a;
    uiA = uA.ui;
    uB.f = b;
    uiB = uB.ui;
    if ( isNaNF8_2UI( uiA ) || isNaNF8_2UI( uiB ) ) {
        softfloat_raiseFlags( softfloat_flag_invalid );
        return false;
    }
    signA = signF8_2UI( uiA );
    signB = signF8_2UI( uiB );
    return
        (signA != signB) ? signA || ! (uint8_t) ((uiA | uiB)<<1)
            : (uiA == uiB) || (signA ^ (uiA < uiB));

}

