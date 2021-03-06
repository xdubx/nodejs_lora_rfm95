
#ifndef __rfm95spi_H
#define __rfm95spi_H
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <rfm95.h>


/**
 * 
 */
RFM95_status_t RFM95spi_init(void);

/*
 * Close the spi
 */
RFM95_status_t RFM95spi_close(void);

/**
 * Configure the SPI periferal.
 */
void RFM95spi_begin(void);

/**
 * Return the SPI pins back to their defaults.
 */
void RFM95spi_end(void);

/**
 * Transfers one byte to and from the currently selected SPI slave.
 * Asserts the currently selected CS pins during the transfer.
 * Clocks the 8 bit value out on MOSI, and simultaneously clocks in data from MISO.
 * Returns the read data byte from the slave.
 *   @param[in] value The 8 bit data byte to write to MOSI
 *   @return The 8 bit byte simultaneously read from  MISO
 */
uint8_t RFM95spi_transfer(uint8_t value);

/**
 * Transfers any number of bytes to and from the currently selected SPI slave.
 * Asserts the currently selected CS pins during the transfer.
 * Clocks the len 8 bit bytes out on MOSI, and simultaneously clocks in data from MISO.
 * The data read read from the slave is placed into rbuf. rbuf must be at least len bytes long
 *   @param[in] tbuf Buffer of bytes to send.
 *   @param[out] rbuf Received bytes will by put in this buffer
 *   @param[in] len Number of bytes in the tbuf buffer, and the number of bytes to send/received
 */
 void RFM95spi_transfernb(char* tbuf, char* rbuf, uint32_t len);

#ifdef __cplusplus
}
#endif
#endif /*__rfm95spi_H */
