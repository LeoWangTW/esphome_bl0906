# Modbus Batch Reader (ESPHome Component)

This ESPHome external component performs a batch read of 67 Modbus registers, and publishes current values for L1 current channels (CH1~CH6) and total.

## Usage

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/LeoWangTW/esphome_bl0906
      ref: main
    components: [modbus_batch_reader]

modbus:
  id: modbus1
  uart_id: uart_modbus

modbus_batch_reader:
  - id: reader
    current_l1_ch1:
      name: "L1電流 CH1"
    ...
```
