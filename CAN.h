#ifndef CAN_H
#define CAN_H
#include "main.h"
#define CAN_BAUD              500000      // CAN Baud rate in Hz

// CAN Frame declaration macro.
// Ensures that the dlc & ID are valid, and defines constants for them
#define FRAME(id, name, dlc) \
   enum{ name ## _ID = id};\
   enum{ name ## _DLC = dlc};\
   _Static_assert(0 <= id && id < 0x800, "Invalid CAN ID");\
   _Static_assert(0<= dlc && dlc <= 8, "Invalid DLC");
    

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

// Macro to declare CAN frame field.
#define FIELD(frame, name, _start, _length, _multiplier, _divisor, _offset, _signed) \
    _Static_assert(_start + _length <= frame ## _DLC * 8, "Field extends beyond end of frame data");\
    extern const struct can_field_t frame ## _ ## name;

// Include CAN IDs and undefine macros
#include "CAN_IDS.inc"
#undef FRAME
#undef FIELD

#define MASK_8(length) (0xFF >> (8 - length))
#define MASK_16(length) (0xFFFF >> (16 - length))
#define MASK_32(length) (0xFFFFFFFF >> (32 - length))

#define GET_FIELD_FUNC(type, name, sign_extend) \
    type read_field_ ## name(struct can_field_t* field, uint8_t* data);

GET_FIELD_FUNC(uint8_t,  u8,  0);
GET_FIELD_FUNC(uint16_t, u16, 0);
GET_FIELD_FUNC(uint32_t, u32, 0);

GET_FIELD_FUNC(int8_t,  i8,  1);
GET_FIELD_FUNC(int16_t, i16, 1);
GET_FIELD_FUNC(int32_t, i32, 1);

#undef GET_FIELD_FUNC

uint32_t read_field_scaled_unsigned(struct can_field_t* field, uint8_t* data);

int32_t read_field_scaled_signed(struct can_field_t* field, uint8_t* data);

float read_field_scaled_float(struct can_field_t* field, uint8_t* data);


#endif

