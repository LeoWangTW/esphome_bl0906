
#include "modbus_batch_reader.h"
#include "esphome/core/log.h"

namespace esphome {
namespace modbus_batch_reader {

static const char *const TAG = "modbus_batch_reader";

void ModbusBatchReader::setup() {
  this->set_address(1);
}

void ModbusBatchReader::update() {
  this->send_read_holding_registers(0x00, 67);
}

void ModbusBatchReader::on_modbus_data(const std::vector<uint8_t> &data) {
  if (data.size() < 2 * 67) return;

  auto read_u16 = [&](int index) {
    int i = index * 2;
    return uint16_t(data[i] << 8 | data[i + 1]);
  };

  if (this->current_l1_ch1) this->current_l1_ch1->publish_state(read_u16(3) * 0.01f);
  if (this->current_l1_ch2) this->current_l1_ch2->publish_state(read_u16(4) * 0.01f);
  if (this->current_l1_ch3) this->current_l1_ch3->publish_state(read_u16(5) * 0.01f);
  if (this->current_l1_ch4) this->current_l1_ch4->publish_state(read_u16(6) * 0.01f);
  if (this->current_l1_ch5) this->current_l1_ch5->publish_state(read_u16(7) * 0.01f);
  if (this->current_l1_ch6) this->current_l1_ch6->publish_state(read_u16(8) * 0.01f);
  if (this->current_l1_total) this->current_l1_total->publish_state(read_u16(9) * 0.01f);
}

void ModbusBatchReader::dump_config() {
  ESP_LOGCONFIG(TAG, "Modbus Batch Reader");
}

}  // namespace modbus_batch_reader
}  // namespace esphome
