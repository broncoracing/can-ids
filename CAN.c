#include "CAN.h"

#define GET_FIELD_FUNC(type, name, sign_extend) \
    type read_field_ ## name(struct can_field_t* field, uint8_t* data) {    \
        uint32_t output = 0;                                                \
        uint8_t start_byte = field->start / 8;                              \
        uint8_t start_bit = field->start % 8;                               \
        uint8_t end = field->start + field->length - 1;                     \
        uint8_t end_byte = end / 8;                                         \
        uint8_t end_bit = 7 - (end % 8);                                    \
        for(uint8_t byte = end_byte; byte > start_byte; --byte){ /* Add all bytes after 1st byte */ \
            uint8_t byte_num = end_byte - byte;                             \
            output |= (data[byte] << byte_num) >> end_bit;                  \
        }                                                                   \
        output |= ((data[start_byte] & (0xFF >> start_bit)) << ((end_byte - start_byte) * 8)) >> end_bit;   /* Add start byte (masked) */ \
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
