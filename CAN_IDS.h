#ifndef CAN_IDS_H
#define CAN_IDS_H

#define CAN_BAUD           250000 // CAN Baud rate in Hz

// Body Control Module

// Electronic Throttle

// Lap Timer
#define LAP_TIME_ID         0x70        // GPS lap timer status and latest laptime
#define GPS_LAT_ID          0x71        // GPS latitude
#define GPS_LONG_ID         0x72        // GPS longitude

// Steering Wheel
#define STEERING_WHEEL_ID   0x00        // Shifting, DRS, TCS, and aux functions
// Telemetry

// Thermocouple
#define THERMOCOUPLE_1_ID   0x1E        // Channels 1-4
#define THERMOCOUPLE_2_ID   0x1F        // Channel 5


#endif // CAN_IDS_H