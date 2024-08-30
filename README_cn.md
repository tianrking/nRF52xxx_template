# nRF5 SDK Example Directory Structure Explanation

## 主要目录解释

1. `ble_central`: 包含蓝牙中心设备的示例。
2. `ble_peripheral`: 包含蓝牙外围设备的示例（这是我们最感兴趣的）。
3. `ble_central_and_peripheral`: 包含同时作为中心和外围设备的示例。
4. `ant`: ANT协议相关的示例。
5. `802_15_4`: IEEE 802.15.4协议相关的示例。
6. `crypto`: 加密相关的示例。
7. `dfu`: 设备固件更新相关的示例。
8. `nfc`: NFC（近场通信）相关的示例。
9. `peripheral`: 各种外围设备功能的示例（如GPIO、UART等）。
10. `proprietary_rf`: 专有RF协议的示例。

## BLE开发相关的重要目录

对于BLE开发，我们主要关注`ble_peripheral`目录。以下是一些值得注意的示例：

1. `ble_app_beacon`: 蓝牙信标示例。
2. `ble_app_blinky`: 简单的LED控制示例。
3. `ble_app_hrs`: 心率服务示例。
4. `ble_app_uart`: 通过BLE实现UART功能的示例。
5. `ble_app_template`: 基本的BLE应用模板。

## 推荐参考的示例

根据您的具体需求，我推荐以下几个示例作为起点：

1. 如果您是刚开始学习BLE开发：
   - `ble_app_blinky`: 这是一个简单的示例，展示了如何通过BLE控制LED。

2. 如果您需要实现数据传输：
   - `ble_app_uart`: 这个示例展示了如何通过BLE发送和接收数据。

3. 如果您需要一个通用的起点：
   - `ble_app_template`: 这个模板提供了基本的BLE功能设置。

4. 如果您需要实现特定的BLE服务：
   - 查看其他特定服务的示例，如`ble_app_hrs`（心率服务）或`ble_app_cscs`（骑行速度和步调服务）。

## 使用示例的步骤

1. 选择合适的示例（如`ble_app_blinky`）。
2. 复制该示例到您的工作目录。
3. 修改Makefile以适应您的项目结构和SDK路径。
4. 研究`main.c`文件，了解BLE初始化和服务设置的过程。
5. 根据您的需求修改和扩展代码。

## 其他有用的目录

- `peripheral`: 虽然不是直接与BLE相关，但这里的示例对于理解硬件外围设备的使用很有帮助。
- `dfu`: 如果您计划实现固件更新功能，这个目录的示例会很有用。

