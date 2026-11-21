\# Session 2 - First STM32 Firmware



\## Hardware

&#x20;- Stm32 NUCLEO-G474RE

&#x20;- ARM Cortex-M4

&#x20;- Onboard STLINK-V3E debugger



\## Development Environment

&#x20;- STM32CubeIDE

&#x20;- STM32CubeMX

&#x20;- STM32CubeG4 HAL and BSP



\## Verified results

&#x20;- Generated firmware project using CubeMX

&#x20;- Built ARM firmware with zero errors and warnings

&#x20;- Flashed firmware successfully using ST-LINK

&#x20;- Verified USER button toggles LD2

&#x20;- Used a breakpoint to halt the CPU

&#x20;- Inspected BspButtonState: 1 before reset, 0 afterward

&#x20;- Stepped through code and observed hardware response



\## Future Work

&#x20;- GPIO programming

&#x20;- Memory-mapped register fundamentals

&#x20;- LED control and button input

