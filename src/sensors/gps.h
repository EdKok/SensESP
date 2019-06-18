#ifndef _gps_H_
#define _gps_H_

#include "sensor.h"
#include "system/nmea_parser.h"

// Support for a GPS module communicating with NMEA-0183
// messages over a serial interface

constexpr int GPS_SERIAL_BITRATE = 115200;

class GPSInput : public Sensor {
 public:
  GPSInput(int reset_pin, String config_path="");
  virtual void enable() override final;
  NMEAData nmea_data;
 private:
  int reset_pin;
  NMEAParser nmea_parser;
};

// must parse the following sentences:
// - GPGGA - Global Positioning System Fix Data
// - GPGLL - Latitude/Longitude
// - GPRMC - The Recommended Minimum
// - GPVTG - Course Over Ground and Ground Speed
// - GPGSA - GNSS DOP and Active Satellites
// - GLGSA - GNSS DOP and Active Satellites
// - GPGSV - GNSS Satellites in View
// - GLGSV - GNSS Satellites in View
// - PSTI,030 - Recommended Minimum 3D GNSS Data
// - PSTI,032 - RTK Baseline Data

#endif
