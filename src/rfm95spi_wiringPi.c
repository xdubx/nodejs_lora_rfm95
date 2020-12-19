
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <rfm95spi.h>
#include <stdio.h>


RFM95_status_t RFM95spi_init() {
  // CS0 spi port 0 | clock speed of 250000 hz
  wiringPiSetup()
  if (!wiringPiSPISetup(0, 250000)) {
    return RFM95_ERROR;
  }

  if (!bcm2835_spi_begin()) {
    printf("bcm2835_spi_begin failed. Are you running as root??\n");
    return RFM95_ERROR;
  }
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
  bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default

  return RFM95_OK;
}

void RFM95spi_transfernb(char* tbuf, char* rbuf, uint32_t len) {
  wiringPiSPIDataRW(0, tbuf, len );
}

#endif
