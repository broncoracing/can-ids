#ifndef CAN_IDS_H
#define CAN_IDS_H

#define CAN_BAUD              250000      // CAN Baud rate in Hz

// Steering wheel
#define STEERING_WHEEL_ID     0x01        // Shifting and DRS

// https://pe-ltd.com/assets/AN400_CAN_Protocol_C.pdf
// Originally on PE ECU some parts implemented on Link ECU for compatibility
//
// #define PE1_ID                0x0CFFF048  // 29 bit extended ID! RPM, TPS
// #define PE6_ID                0x0CFFF548  // 29 bit extended ID! Battery voltage, air temp, coolant temp

// Engine Control Unit
#define ECU1_ID               0x05        // RPM
#define ECU2_ID               0x06        // Oil Temp, Water Temp, IATs
#define ECU3_ID               0x07        // Oil Pressure, Batt Voltage


// Body control module
#define BCM_STATUS_ID         0x14        // Neutral, ETCEnable, fan, and water pump statuses

// Electronic throttle system
#define DBW_SENSORS_ID        0x20        // from Link Fury, APPS and TPS
#define BRAKE_PRESSURE_ID     0x21        // from Link Fury, BSE

// Thermocouple module
#define THERMOCOUPLE1_ID      0x1E        // Channels 1-4
#define THERMOCOUPLE2_ID      0x1F        // Channel 5

// Brake light
#define BRAKE_LIGHT_ID        0x30        // Brake light heartbeat pulse

// Telemetry commands
#define TELEMETRY_CONTROL_ID  0x40        // Override cooling from telemetry/laptop (for accel runs)

// Analog to CAN
#define A2C0_ID               0x50        // Analog to CAN modules (may or may not be installed)
#define A2C1_ID               0x51
#define A2C2_ID               0x52
#define A2C3_ID               0x53
#define A2C4_ID               0x54
#define A2C5_ID               0x55
#define A2C6_ID               0x56
#define A2C7_ID               0x57

// Dyno
#define DYNO_SERVO_ID         0x60        // Water valve control on dyno (for load control)

// Lap timer
#define LAP_TIME_ID           0x70        // GPS lap timer status and latest laptime
#define GPS_LAT_ID            0x71        // GPS latitude
#define GPS_LONG_ID           0x72        // GPS longitude

#endif // CAN_IDS_H