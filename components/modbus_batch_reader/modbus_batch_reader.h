
#pragma once
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/modbus_controller/modbus_controller.h"

namespace esphome {
namespace modbus_batch_reader {

class ModbusBatchReader : public PollingComponent, public modbus_controller::ModbusDevice {
 public:
  sensor::Sensor *current_l1_ch1{nullptr};
  sensor::Sensor *current_l1_ch2{nullptr};
  sensor::Sensor *current_l1_ch3{nullptr};
  sensor::Sensor *current_l1_ch4{nullptr};
  sensor::Sensor *current_l1_ch5{nullptr};
  sensor::Sensor *current_l1_ch6{nullptr};
  sensor::Sensor *current_l1_total{nullptr};

  ModbusBatchReader() : PollingComponent(500) {}
  void setup() override;
  void update() override;
  void on_modbus_data(const std::vector<uint8_t> &data) override;

  void dump_config() override;
};

}  // namespace modbus_batch_reader
}  // namespace esphome
