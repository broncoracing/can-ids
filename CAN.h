#ifndef CAN_FORMAT_H
#define CAN_FORMAT_H
#include "main.h"

// CAN Frame definition macro.
// Ensures that the dlc & ID are valid, and defines constants for them
#define FRAME(id, name, dlc) \
   const uint16_t name ## _ID = id;\
   const uint8_t name ## _DLC = dlc;\
   static_assert(0 <= id && id < 0x800, "Invalid CAN ID");\
   static_assert(0<= dlc && dlc <= 8, "Invalid DLC");
    

// Indicates if a field is signed or unsigned
enum field_signed_t {
    UNSIGNED,
    SIGNED
};

// Represents the position in a CAN frame where a field is located,
// as well as the scaling factor for it.
struct can_field_t { 
    const uint8_t start;
    const uint8_t length;
    const uint32_t multiplier;
    const uint32_t divisor;
    const uint32_t offset;
    const enum field_signed_t is_signed;
};

// Macro to define CAN frame field.
#define FIELD(frame, name, _start, _length, _multiplier, _divisor, _offset, _signed) \
    static_assert(_start + _length <= frame ## _DLC * 8, "Field extends beyond end of frame data");\
    const struct can_field_t frame ## _ ## field {\
        .start = _start,\
        .length = _length,\
        .multiplier = _multiplier,\
        .divisor = _divisor,\
        .offset = _offset,\
        .is_signed = _signed\
    };

// Include CAN frame & field definitions
#include "CAN_IDS.h"

// Undefine the macros
#undef FRAME
#undef FIELD

#define MASK_8(length) (0xFF >> (8 - length))
#define MASK_16(length) (0xFFFF >> (16 - length))
#define MASK_32(length) (0xFFFFFFFF >> (32 - length))

#define GET_FIELD_FUNC(type, name, sign_extend) \
    type read_field_ ## name(struct can_field_t* field, uint8_t* data) {    \
        uint64_t data_u64 = *((uint64_t *) data);                           \
        type output = data_u64 >> field -> start;                           \
        output &= MASK_8(field -> length);                                  \
        if(sign_extend) {                                                   \
            type sign_bit = 1 << (field -> length - 1);                     \
            output = (output ^ sign_bit) - sign_bit;                        \
        }                                                                   \
        return output;                                                      \
    }                                                                       \

GET_FIELD_FUNC(uint8_t,  u8,  0);
GET_FIELD_FUNC(uint16_t, u16, 0);
GET_FIELD_FUNC(uint32_t, u32, 0);

GET_FIELD_FUNC(int8_t,  i8,  1);
GET_FIELD_FUNC(int16_t, i16, 1);
GET_FIELD_FUNC(int32_t, i32, 1);

uint32_t read_field_scaled_unsigned(struct can_field_t* field, uint8_t* data) {
    if(field -> is_signed == SIGNED) {
        return (uint32_t)(read_field_i32(field, data) * field->multiplier / field->divisor + field->offset);
    } else {
        return (uint32_t)(read_field_u32(field, data) * field->multiplier / field->divisor + field->offset);
    }
}

int32_t read_field_scaled_signed(struct can_field_t* field, uint8_t* data) {
    if(field -> is_signed == SIGNED) {
        return (int32_t)(read_field_i32(field, data) * field->multiplier / field->divisor + field->offset);
    } else {
        return (int32_t)(read_field_u32(field, data) * field->multiplier / field->divisor + field->offset);
    }
}

float read_field_scaled_float(struct can_field_t* field, uint8_t* data) {
    float raw_val;
    if(field -> is_signed == SIGNED) {
        raw_val = (float)read_field_i32(field, data);
    } else {
        raw_val = (float)read_field_u32(field, data);
    }

    return raw_val * ((float) field -> multiplier) / ((float) field -> divisor) + ((float) field -> offset);
}


#endif

