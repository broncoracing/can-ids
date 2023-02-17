#include "CAN.h"

// Frames don't need to be defined, they're constant enum values
#define FRAME(id, name, dlc)

// Macro to define CAN frame field.
#define FIELD(frame, name, _start, _length, _multiplier, _divisor, _offset, _signed) \
    const struct can_field_t frame ## _ ## name = {\
        .start = _start,\
        .length = _length,\
        .multiplier = _multiplier,\
        .divisor = _divisor,\
        .offset = _offset,\
        .is_signed = _signed\
    };

#include "CAN_IDS.inc"