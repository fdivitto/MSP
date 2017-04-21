#include <SoftwareSerial.h>

#include "MSP.h"


MSP msp;

// debug
SoftwareSerial debug(10, 11); // 10=RX, 11=TX


void setup()
{
  // debug
  debug.begin(9600);
  
  Serial.begin(115200);
  msp.begin(Serial);

  debug.println("setup ended");
}


void loop()
{
  /*
  msp_rx_map_t rxmap;
  if (msp.request(MSP_RX_MAP, &rxmap, sizeof(rxmap))) {
    for (uint8_t i = 0; i != 4; ++i) {
      debug.print(rxmap.rxmap[i]); debug.write('\t');
    }
  }
  */

  msp_rc_t rcraw;
  if (msp.request(MSP_RC, &rcraw, sizeof(rcraw))) {
    for (uint8_t i = 0; i != 16; ++i) {
      debug.print(rcraw.channelValue[i]); debug.write('\t');
    }
  }

  /*
  msp_decoded_rc_t rc;
  if (msp.getRC(&rc)) {
    debug.print(rc.roll); debug.write('\t');
    debug.print(rc.pitch); debug.write('\t');
    debug.print(rc.yaw); debug.write('\t');
    debug.print(rc.throttle); debug.write('\t');
    for (int i = 0; i < sizeof(rc.aux); ++i) {
      debug.print(rc.aux[i]); debug.write('\t');
    }
  }*/



  debug.println();

  /*
  msp_raw_imu_t rawImu;
  if (msp.request(MSP_RAW_IMU, &rawImu, sizeof(rawImu))) {
    debug.print("acc: ");
    for (int i=0; i<3; ++i) {
      debug.print(rawImu.acc[i]); debug.write(' ');
    }
    debug.print("gyro: ");
    for (int i=0; i<3; ++i) {
      debug.print(rawImu.gyro[i]); debug.write(' ');
    }
    debug.print("mag: ");
    for (int i=0; i<3; ++i) {
      debug.print(rawImu.mag[i]); debug.write(' ');
    }
    debug.println();
  }
  */
}

