#define CAN_BAUD              500000      // CAN Baud rate in Hz

// Inverter frames
// inverter temperatures
FRAME(0x0A0, INVERTER_TEMP_1, 8);
FIELD(INVERTER_TEMP_1, IGBT_A_temp, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_1, IGBT_B_temp, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_1, IGBT_C_temp, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_1, gate_driver_temp, 48, 16, 1, 10, 0, SIGNED);


FRAME(0x0A1, INVERTER_TEMP_2, 8);
FIELD(INVERTER_TEMP_2, control_board_temp, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_2, rtd_1_temp, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_2, rtd_2_temp, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_2, rtd_3_temp, 48, 16, 1, 10, 0, SIGNED);


FRAME(0x0A2, INVERTER_TEMP_3, 8);
FIELD(INVERTER_TEMP_3, rtd_4_temp, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_3, rtd_5_temp, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_3, motor_temp, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TEMP_3, torque_shudder, 48, 16, 1, 10, 0, SIGNED);


// inverter analog inputs (Including APPS/TPS)
FRAME(0x0A3, INVERTER_AN_VOLT, 8);
FIELD(INVERTER_AN_VOLT, an_volt_1, 0, 10, 1, 100, 0, SIGNED);
FIELD(INVERTER_AN_VOLT, an_volt_2, 10, 10, 1, 100, 0, SIGNED);
FIELD(INVERTER_AN_VOLT, an_volt_3, 20, 10, 1, 100, 0, SIGNED);
FIELD(INVERTER_AN_VOLT, an_volt_4, 32, 10, 1, 100, 0, SIGNED);
FIELD(INVERTER_AN_VOLT, an_volt_5, 42, 10, 1, 100, 0, SIGNED);
FIELD(INVERTER_AN_VOLT, an_volt_6, 52, 10, 1, 100, 0, SIGNED);


// Inverter digital inputs
FRAME(0x0A4, INVERTER_DIGITAL_IN, 8);
FIELD(INVERTER_DIGITAL_IN, digital_in_1,  0, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_2,  8, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_3, 16, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_4, 24, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_5, 32, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_6, 40, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_7, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_DIGITAL_IN, digital_in_8, 56, 8, 1, 1, 0, UNSIGNED);


FRAME(0x0A5, INVERVER_MOTOR_POSITION, 8);
FIELD(INVERVER_MOTOR_POSITION, motor_angle_electrical, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERVER_MOTOR_POSITION, angular_velocity, 32, 16, 1, 1, 0, SIGNED);
FIELD(INVERVER_MOTOR_POSITION, frequency, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERVER_MOTOR_POSITION, delta_resolver, 48, 16, 1, 10, 0, SIGNED);


FRAME(0x0A6, INVERTER_CURRENT, 8);
FIELD(INVERTER_CURRENT, phase_a, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_CURRENT, phase_b, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_CURRENT, phase_c, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_CURRENT, dc_bus, 48, 16, 1, 10, 0, SIGNED);


FRAME(0x0A7, INVERTER_VOLTAGE, 8);
FIELD(INVERTER_VOLTAGE, dc_bus, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_VOLTAGE, output, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_VOLTAGE, VAB_Vd_Voltage, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_VOLTAGE, VBC_Vq_Voltage, 48, 16, 1, 10, 0, SIGNED);

FRAME(0x0A8, INVERTER_FLUX, 8);
FIELD(INVERTER_FLUX, flux_command, 0, 16, 1, 1000, 0, SIGNED);
FIELD(INVERTER_FLUX, flux_feedback, 16, 16, 1, 1000, 0, SIGNED);
FIELD(INVERTER_FLUX, id_feedback, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_FLUX, iq_feedback, 48, 16, 1, 10, 0, SIGNED);

FRAME(0x0A9, INVERTER_INTERNAL_VOLTAGE, 8);
FIELD(INVERTER_INTERNAL_VOLTAGE, ref_1v5, 0, 16, 1, 100, 0, SIGNED);
FIELD(INVERTER_INTERNAL_VOLTAGE, ref_2v5, 16, 16, 1, 100, 0, SIGNED);
FIELD(INVERTER_INTERNAL_VOLTAGE, ref_5v, 32, 16, 1, 100, 0, SIGNED);
FIELD(INVERTER_INTERNAL_VOLTAGE, glv_voltage, 48, 16, 1, 100, 0, SIGNED);


FRAME(0X0AA, INVERTER_INTERNAL_STATES, 8);
FIELD(INVERTER_INTERNAL_STATES, vsm_state, 0, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, pwm_frequency, 8, 8, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, inverter_state, 16, 8, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, relay_1, 24, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, relay_2, 25, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, relay_3, 26, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, relay_4, 27, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, relay_5, 28, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, relay_6, 29, 1, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, run_mode, 32, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, active_discharge_state, 37, 3, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, command_mode, 40, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, rolling_counter_value, 44, 4, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, enable_state, 48, 1, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, start_active, 54, 1, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, enable_lockout, 55, 1, 1, 1, 0, UNSIGNED);

FIELD(INVERTER_INTERNAL_STATES, direction_command, 56, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, bms_active, 57, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, bms_limiting_torque, 58, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, limit_max_speed, 59, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, limit_hot_spot, 60, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, limit_low_speed, 61, 1, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_INTERNAL_STATES, limit_coolant_temp, 62, 1, 1, 1, 0, UNSIGNED);





FRAME(0X0AB, INVERTER_FAULT_CODES, 8);
FIELD(INVERTER_FAULT_CODES, POST_fault, 0, 32, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_FAULT_CODES, run_fault, 32, 32, 1, 1, 0, UNSIGNED);

FRAME(0X0AC, INVERTER_TORQUE_TIMING_INFO, 8);
FIELD(INVERTER_TORQUE_TIMING_INFO, commanded_torque, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TORQUE_TIMING_INFO, torque_feedback, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_TORQUE_TIMING_INFO, power_on_timer, 32, 32, 3, 1000, 0, SIGNED);

FRAME(0X0AD, INVERTER_MODULATION_IDX_FLUX_WEAKENING_OUTPUT, 8);
FIELD(INVERTER_MODULATION_IDX_FLUX_WEAKENING_OUTPUT, modulation_idx, 0, 16, 1, 100, 0, SIGNED);
FIELD(INVERTER_MODULATION_IDX_FLUX_WEAKENING_OUTPUT, flux_weakening_output, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_MODULATION_IDX_FLUX_WEAKENING_OUTPUT, id_command, 32, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_MODULATION_IDX_FLUX_WEAKENING_OUTPUT, iq_command, 48, 16, 1, 10, 0, SIGNED);


FRAME(0X0AE, INVERTER_FW_INFO, 8);
FIELD(INVERTER_FW_INFO, eeprom_version, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_FW_INFO, software_version, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_FW_INFO, date_mmdd, 32, 16, 1, 1, 0, UNSIGNED);
FIELD(INVERTER_FW_INFO, date_yyyy, 48, 16, 1, 1, 0, UNSIGNED);


// Please refer to the manual, “Download Diagnostic Data” for details about diagnostic data.
FRAME(0X0AF, INVERTER_DIAGNOSTIC_DATA, 8);

//High speed frame is sent every 3ms
FRAME(0X0B0, INVERTER_HIGH_SPEED, 8);
FIELD(INVERTER_HIGH_SPEED, commanded_torque, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_HIGH_SPEED, torque_feedback, 16, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_HIGH_SPEED, motor_speed, 32, 16, 1, 1, 0, SIGNED);
FIELD(INVERTER_HIGH_SPEED, dc_bus_voltage, 48, 16, 1, 10, 0, SIGNED);


// Inverter command message
FRAME(0X0C0, INVERTER_COMMAND, 8);
FIELD(INVERTER_COMMAND, torque_command, 0, 16, 1, 10, 0, SIGNED);
FIELD(INVERTER_COMMAND, speed_command, 16, 16, 1, 1, 0, SIGNED);
FIELD(INVERTER_COMMAND, direction_command, 32, 8, 1, 1, 0, UNSIGNED); // 0=reverse, 1=forward

FIELD(INVERTER_COMMAND, inverter_enable, 40, 1, 1, 1, 0, UNSIGNED); // 0=off, 1=on
FIELD(INVERTER_COMMAND, inverter_discharge, 41, 1, 1, 1, 0, UNSIGNED); // 0=disable, 1=enable
FIELD(INVERTER_COMMAND, speed_mode_enable, 42, 1, 1, 1, 0, UNSIGNED); // 0=disable, 1=enable - must send a disable command before enable command!
FIELD(INVERTER_COMMAND, torque_limit_override, 48, 16, 1, 10, 0, SIGNED); // if set to 0, EEPROM torque limit is used.


//BCM Command Frames
FRAME(0xD0, BCM_COMMAND, 3); // ECU command to BCM
FIELD(BCM_COMMAND, water_pump_duty, 0, 8, 1, 255, 0, UNSIGNED); // 0=off, 255=full
FIELD(BCM_COMMAND, radiator_fan_duty, 8, 8, 1, 255, 0, UNSIGNED);
FIELD(BCM_COMMAND, upshift, 16, 1, 1, 1, 0, UNSIGNED);
FIELD(BCM_COMMAND, downshift, 17, 1, 1, 1, 0, UNSIGNED);
FIELD(BCM_COMMAND, brake_light, 18, 1, 1, 1, 0, UNSIGNED);

// BCM Status frame(s)
FRAME(0x100, BCM_STATUS1, 8);
FIELD(BCM_STATUS1, upshift_current, 0, 16, 1, 100, 0, UNSIGNED);
FIELD(BCM_STATUS1, downshift_current, 16, 16, 1, 100, 0, UNSIGNED);
FIELD(BCM_STATUS1, mcu_temperature, 32, 16, 1, 10, 0, SIGNED);

// Steering wheel frames
FRAME(0xE0, DASHBOARD_0, 8);
FIELD(DASHBOARD_0, an1,  0, 16, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_0, an2, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_0, an3, 32, 16, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_0, an4, 48, 16, 1, 1, 0, UNSIGNED);

FRAME(0xE1, DASHBOARD_1, 8);

FIELD(DASHBOARD_1, an4,  0, 16, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, an5, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn0, 32, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn1, 33, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn2, 34, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn3, 35, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn4, 36, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, btn5, 37, 1, 1, 1, 0, UNSIGNED);
FIELD(DASHBOARD_1, mcu_temperature, 48, 16, 1, 10, 0, SIGNED);


// AEM Sensor module
FRAME(0x500, AEM_ANALOG_1, 8); // Can switch to 0x600 for lower speed (50hz rather than 100hz)
FIELD(AEM_ANALOG_1, an1, 0, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_1, an2, 16, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_1, an3, 32, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_1, an4, 48, 16, 1, 1000, 0, UNSIGNED);

FRAME(0x501, AEM_ANALOG_2, 8); // Can switch to 0x601 for lower speed (50hz rather than 100hz)
FIELD(AEM_ANALOG_2, an5, 0, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_2, an6, 16, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_2, an7, 32, 16, 1, 1000, 0, UNSIGNED);
FIELD(AEM_ANALOG_2, an8, 48, 16, 1, 1000, 0, UNSIGNED);

FRAME(0x502, AEM_ANALOG_RESISTANCE_1, 8);
FIELD(AEM_ANALOG_RESISTANCE_1, an5_resistance, 0, 16, 1, 1, 0, UNSIGNED); // Units of Ohms
FIELD(AEM_ANALOG_RESISTANCE_1, an6_resistance, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_ANALOG_RESISTANCE_1, an7_resistance, 32, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_ANALOG_RESISTANCE_1, an8_resistance, 48, 16, 1, 1, 0, UNSIGNED);

FRAME(0x503, AEM_ANALOG_RESISTANCE_2, 8);
FIELD(AEM_ANALOG_RESISTANCE_2, an9_resistance, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_ANALOG_RESISTANCE_2, an10_resistance, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_ANALOG_RESISTANCE_2, an11_resistance, 32, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_ANALOG_RESISTANCE_2, an12_resistance, 48, 16, 1, 1, 0, UNSIGNED);


FRAME(0x504, AEM_VR_TACHO_FUEL_BATTERY, 8);
FIELD(AEM_VR_TACHO_FUEL_BATTERY, vr1, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_VR_TACHO_FUEL_BATTERY, vr2, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_VR_TACHO_FUEL_BATTERY, tacho, 32, 16, 1, 10, 0, UNSIGNED);
FIELD(AEM_VR_TACHO_FUEL_BATTERY, fuel_level, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(AEM_VR_TACHO_FUEL_BATTERY, battery_voltage, 56, 8, 1, 10, 0, UNSIGNED);


FRAME(0x505, AEM_DIGITAL_1, 8);
FIELD(AEM_DIGITAL_1, d1_frequency, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_1, d2_frequency, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_1, d1_duty_cycle, 32, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_1, d2_duty_cycle, 40, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_1, d1_state, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_1, d2_state, 48, 8, 1, 1, 0, UNSIGNED);

FRAME(0x506, AEM_DIGITAL_2, 8);
FIELD(AEM_DIGITAL_2, d3_frequency, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_2, d4_frequency, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_2, d3_duty_cycle, 32, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_2, d4_duty_cycle, 40, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_2, d3_state, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_2, d4_state, 48, 8, 1, 1, 0, UNSIGNED);


FRAME(0x507, AEM_DIGITAL_3, 8);
FIELD(AEM_DIGITAL_3, d5_frequency, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_3, d6_frequency, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_3, d5_duty_cycle, 32, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_3, d6_duty_cycle, 40, 8, 1, 100, 0, UNSIGNED);
FIELD(AEM_DIGITAL_3, d5_state, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(AEM_DIGITAL_3, d6_state, 48, 8, 1, 1, 0, UNSIGNED);


// Engine Control Unit
FRAME(0x400, ECU_1, 8);
FIELD(ECU_1, rpm, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(ECU_1, lamda, 16, 16, 1, 100, 0, UNSIGNED);
FIELD(ECU_1, accel_lat, 32, 16, 1, 100, 0, SIGNED);
FIELD(ECU_1, accel_lon, 48, 16, 1, 100, 0, SIGNED);


FRAME(0x401, ECU_2, 8);
FIELD(ECU_2, oil_temp, 0, 16, 1, 10, 0, SIGNED);
FIELD(ECU_2, water_temp, 16, 16, 1, 10, 0, SIGNED);
FIELD(ECU_2, intake_air_temp, 32, 16, 1, 10, 0, SIGNED);
FIELD(ECU_2, map, 48, 16, 1, 10, 0, SIGNED);

FRAME(0x402, ECU_3, 8);
FIELD(ECU_3, oil_pressure, 0, 16, 1, 10, 0, SIGNED);
FIELD(ECU_3, battery_voltage, 16, 16, 1, 100, 0, SIGNED);
FIELD(ECU_3, gear_sensor_voltage, 32, 16, 1, 100, 0, UNSIGNED);
FIELD(ECU_3, gear_position, 48, 8, 1, 1, 0, UNSIGNED);
FIELD(ECU_3, speedometer, 48, 8, 1, 1, 0, UNSIGNED);

FRAME(0x403, ECU_4, 8);
FIELD(ECU_4, wheel_speed_FR, 0, 16, 1, 1, 0, UNSIGNED);
FIELD(ECU_4, wheel_speed_FL, 16, 16, 1, 1, 0, UNSIGNED);
FIELD(ECU_4, wheel_speed_RR, 32, 16, 1, 1, 0, UNSIGNED);
FIELD(ECU_4, wheel_speed_RL, 48, 16, 1, 1, 0, UNSIGNED);

FRAME(0x404, ECU_DBW, 6);
FIELD(ECU_DBW, apps, 0, 8, 1, 100, 0, UNSIGNED);
FIELD(ECU_DBW, tps, 8, 8, 1, 100, 0, UNSIGNED);
FIELD(ECU_DBW, brake_pressure_front, 16, 16, 1, 10, 0, UNSIGNED);
FIELD(ECU_DBW, brake_pressure_rear, 32, 16, 1, 10, 0, UNSIGNED);


// Bootloader IDs
FRAME(0x700, BOOTLOADER, 8);
FRAME(0x701, BOOTLOADER_RESPONSE, 8);