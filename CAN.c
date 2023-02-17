#include "CAN.h"

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
