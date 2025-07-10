
#include "esphome.h"
#include "modbus/modbus.h"
#include "modbus_controller.h"

using namespace esphome;

class ModbusBatchReader : public PollingComponent, public modbus_controller::ModbusDevice {
 public:
  Sensor *l1_l1voltage = new Sensor();
  Sensor *l2_l2voltage = new Sensor();
  Sensor *l1_totalvoltage_l1plusl2 = new Sensor();
  Sensor *current_l1_l1_ch1 = new Sensor();
  Sensor *current_l1_l1_ch2 = new Sensor();
  Sensor *current_l1_l1_ch3 = new Sensor();
  Sensor *current_l1_l1_ch4 = new Sensor();
  Sensor *current_l1_l1_ch5 = new Sensor();
  Sensor *current_l1_l1_ch6 = new Sensor();
  Sensor *current_l1_l1total = new Sensor();
  Sensor *current_l2_l2_ch1 = new Sensor();
  Sensor *current_l2_l2_ch2 = new Sensor();
  Sensor *current_l2_l2_ch3 = new Sensor();
  Sensor *current_l2_l2_ch4 = new Sensor();
  Sensor *current_l2_l2_ch5 = new Sensor();
  Sensor *current_l2_l2_ch6 = new Sensor();
  Sensor *current_l2_l2total = new Sensor();
  Sensor *current_l1_l1plusl2total = new Sensor();
  Sensor *power_l1_l1_ch1 = new Sensor();
  Sensor *power_l1_l1_ch2 = new Sensor();
  Sensor *power_l1_l1_ch3 = new Sensor();
  Sensor *power_l1_l1_ch4 = new Sensor();
  Sensor *power_l1_l1_ch5 = new Sensor();
  Sensor *power_l1_l1_ch6 = new Sensor();
  Sensor *power_l1_l1total = new Sensor();
  Sensor *power_l2_l2_ch1 = new Sensor();
  Sensor *power_l2_l2_ch2 = new Sensor();
  Sensor *power_l2_l2_ch3 = new Sensor();
  Sensor *power_l2_l2_ch4 = new Sensor();
  Sensor *power_l2_l2_ch5 = new Sensor();
  Sensor *power_l2_l2_ch6 = new Sensor();
  Sensor *power_l2_l2total = new Sensor();
  Sensor *power_total = new Sensor();
  Sensor *energy_l1_l1_ch1 = new Sensor();
  Sensor *energy_l1_l1_ch2 = new Sensor();
  Sensor *energy_l1_l1_ch3 = new Sensor();
  Sensor *energy_l1_l1_ch4 = new Sensor();
  Sensor *energy_l1_l1_ch5 = new Sensor();
  Sensor *energy_l1_l1_ch6 = new Sensor();
  Sensor *energy_l1_l1total = new Sensor();
  Sensor *energy_l2_l2_ch1 = new Sensor();
  Sensor *energy_l2_l2_ch2 = new Sensor();
  Sensor *energy_l2_l2_ch3 = new Sensor();
  Sensor *energy_l2_l2_ch4 = new Sensor();
  Sensor *energy_l2_l2_ch5 = new Sensor();
  Sensor *energy_l2_l2_ch6 = new Sensor();
  Sensor *energy_l2_l2total = new Sensor();
  Sensor *energy_l1_l1plusl2total = new Sensor();
  Sensor *l1_l1pf = new Sensor();
  Sensor *l2_l2pf = new Sensor();
  Sensor *frequency = new Sensor();
  Sensor *temperature = new Sensor();

  ModbusBatchReader() : PollingComponent(500) {}

  void setup() override {
    this->set_address(1);
  }

  void update() override {
    this->send_read_holding_registers(0x00, 67);
  }

  void on_modbus_data(const std::vector<uint8_t> &data) override {
    if (data.size() < 2 * 67) return;

    auto read_u16 = [&](int index) {
      int i = index * 2;
      return uint16_t(data[i] << 8 | data[i + 1]);
    };

    l1_l1voltage->publish_state(read_u16(0) * 0.1f);
    l2_l2voltage->publish_state(read_u16(1) * 0.1f);
    l1_totalvoltage_l1plusl2->publish_state(read_u16(2) * 0.1f);
    current_l1_l1_ch1->publish_state(read_u16(3) * 0.01f);
    current_l1_l1_ch2->publish_state(read_u16(4) * 0.01f);
    current_l1_l1_ch3->publish_state(read_u16(5) * 0.01f);
    current_l1_l1_ch4->publish_state(read_u16(6) * 0.01f);
    current_l1_l1_ch5->publish_state(read_u16(7) * 0.01f);
    current_l1_l1_ch6->publish_state(read_u16(8) * 0.01f);
    current_l1_l1total->publish_state(read_u16(9) * 0.01f);
    current_l2_l2_ch1->publish_state(read_u16(10) * 0.01f);
    current_l2_l2_ch2->publish_state(read_u16(11) * 0.01f);
    current_l2_l2_ch3->publish_state(read_u16(12) * 0.01f);
    current_l2_l2_ch4->publish_state(read_u16(13) * 0.01f);
    current_l2_l2_ch5->publish_state(read_u16(14) * 0.01f);
    current_l2_l2_ch6->publish_state(read_u16(15) * 0.01f);
    current_l2_l2total->publish_state(read_u16(16) * 0.01f);
    current_l1_l1plusl2total->publish_state(read_u16(17) * 0.01f);
    power_l1_l1_ch1->publish_state(read_u16(19) * 0.1f);
    power_l1_l1_ch2->publish_state(read_u16(21) * 0.1f);
    power_l1_l1_ch3->publish_state(read_u16(23) * 0.1f);
    power_l1_l1_ch4->publish_state(read_u16(25) * 0.1f);
    power_l1_l1_ch5->publish_state(read_u16(27) * 0.1f);
    power_l1_l1_ch6->publish_state(read_u16(29) * 0.1f);
    power_l1_l1total->publish_state(read_u16(31) * 0.1f);
    power_l2_l2_ch1->publish_state(read_u16(33) * 0.1f);
    power_l2_l2_ch2->publish_state(read_u16(35) * 0.1f);
    power_l2_l2_ch3->publish_state(read_u16(37) * 0.1f);
    power_l2_l2_ch4->publish_state(read_u16(39) * 0.1f);
    power_l2_l2_ch5->publish_state(read_u16(41) * 0.1f);
    power_l2_l2_ch6->publish_state(read_u16(43) * 0.1f);
    power_l2_l2total->publish_state(read_u16(45) * 0.1f);
    power_total->publish_state(read_u16(47) * 0.1f);
    energy_l1_l1_ch1->publish_state(read_u16(48) * 0.1f);
    energy_l1_l1_ch2->publish_state(read_u16(49) * 0.1f);
    energy_l1_l1_ch3->publish_state(read_u16(50) * 0.1f);
    energy_l1_l1_ch4->publish_state(read_u16(51) * 0.1f);
    energy_l1_l1_ch5->publish_state(read_u16(52) * 0.1f);
    energy_l1_l1_ch6->publish_state(read_u16(53) * 0.1f);
    energy_l1_l1total->publish_state(read_u16(54) * 0.1f);
    energy_l2_l2_ch1->publish_state(read_u16(55) * 0.1f);
    energy_l2_l2_ch2->publish_state(read_u16(56) * 0.1f);
    energy_l2_l2_ch3->publish_state(read_u16(57) * 0.1f);
    energy_l2_l2_ch4->publish_state(read_u16(58) * 0.1f);
    energy_l2_l2_ch5->publish_state(read_u16(59) * 0.1f);
    energy_l2_l2_ch6->publish_state(read_u16(60) * 0.1f);
    energy_l2_l2total->publish_state(read_u16(61) * 0.1f);
    energy_l1_l1plusl2total->publish_state(read_u16(62) * 0.1f);
    l1_l1pf->publish_state(read_u16(63) * 0.01f);
    l2_l2pf->publish_state(read_u16(64) * 0.01f);
    frequency->publish_state(read_u16(65) * 0.1f);
    temperature->publish_state(read_u16(66) * 0.1f);
  }
};
