#ifndef STINGRAY_MESSAGES_PINGER_FINDER_H
#define STINGRAY_MESSAGES_PINGER_FINDER_H

#include "stingray_core_communication/messages/common.h"

class PingerFinderMessage : public AbstractMessage {
public:
    PingerFinderMessage();

    const static uint8_t length = 1;

    int8_t angle;

    void pack(std::vector<uint8_t> &container) override; // raspberry_cm4 to STM
    bool parse(std::vector<uint8_t> &input) override; // pult to raspberry_cm4
};

#endif // STINGRAY_MESSAGES_PINGER_FINDER_H