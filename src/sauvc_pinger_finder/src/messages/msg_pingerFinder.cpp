#include "sauvc_pinger_finder/messages/msg_pingerFinder.h"


PingerFinderMessage::PingerFinderMessage() : AbstractMessage() {
    angle = 0;
}

// form byte-vector (raspberry_cm4 to STM) // TODO
void PingerFinderMessage::pack(std::vector<uint8_t> &container) {
    pushToVector(container, angle);
}

// pull message from byte-vector (pult to raspberry_cm4)
bool PingerFinderMessage::parse(std::vector<uint8_t> &input) {
    popFromVector(input, angle);

    return true;
}