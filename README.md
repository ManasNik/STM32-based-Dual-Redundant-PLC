# Overview 
This is a work-in-progress project that I am developing under the guidance of my college faculty member and a consultancy firm. The objective is to build a cost-effective prototype of a Programmable Logic Controller 
(PLC) with dual redundancy, based on the STM32F103C8T6 microcontroller.

The system consists of individual input/output interface modules - namely Digital Input (DI), Digital Output (DO), Analog Input (AI), and Analog Output (AO) - all connected to a main control module, making the design 
modular. This modular approach simplifies maintenance, allows quick replacement of faulty circuits, and provides flexibility and scalability while keeping costs to a minimum.

The system is being designed with dual redundancy, meaning it will have two PLCs: one serving as the main or primary controller and the other as a standby controller. Both will monitor each other’s operating status, with the 
standby unit taking over if the main controller fails. This ensures that the industrial process continues without interruption, even in the event of a controller fault.

# Design 
The whole system circuitry is currently being tested on breadboards. Each module is set up on separate breadboards each containing a STM32F103C8T6 development board. The modules are currently connected via I2C 
communication protocol, making use of the STM32's I2C peripherals. The main controller's I2C1 peripheral is being used to communicate with the input modules (DI and AI) and the I2C2 is being used to communicate with
the output modules (DO and AO). We chose I2C as it is simpler communication protocol having just two lines, leaving more pins for other uses. 

# Circuit schmatic and the breadboard prototype
<img width="1156" height="818" alt="Screenshot 2025-10-05 222447" src="https://github.com/user-attachments/assets/428a79a2-8b27-4195-9a0f-1a91e9b6649c" />

The above circuit schematic shows the connections we made between the individual modules. The same connection is replicated on the standby controller. The main controller in each controller acts as the 'Master device' in I2C communication on both the buses - I2C1 and I2C2, while the I/O modules act as the 'Slave devices'.

![WhatsApp Image 2025-10-04 at 16 51 43_01130a7d](https://github.com/user-attachments/assets/78d0c47f-54f8-4ace-8df3-316d50b740d9)
We made the connections on the breadboard for the primary controller(top row) and the secondary controller(bottom row). Each breadboard consists of the circuit for a specific module with the leftmost being the main control module followed by Digital Input(DI), Digital Output(DO), Analog Input(AI) and Analog Output(AO). Same order is followed on the secondary controller. Observe that we used LED indicators on both the digital input and output pins for testing. Also we used a potentiometer for analog input and an OLED screen for viewing the analog output. The final prototype will be in the form of a system using backplane PCB design.

# Testing
For testing the digital I/O modules, we supplied a simple 3.3V signal to the digital input pins(D0 to D7). Each pin represents one bit and we package the eight individual bits into one byte which is then fetched by the main controller via I2C. The main controller will transfer the same to the digital output module. The same indicator LEDs turn on/off on the digital input and output modules. This is to verify that we have a reliable communication between the modules. In actual application, the byte can then be unpacked at the main controller to check the state of each digital input and execute the necessary logic based on it which may also include turning any of the digital output pins high/low. 

Similary, the analog modules are tested by sampling a potentiometer output at the analog input module and transferring it to the main control module as two bytes, since ADC output(12-bit resolution) is stored in an unsigned 16-bit and since I2C can only send 1 byte(8 bits) at a time. The received analog-to-digital value at the main controller is then tranferred to the analog output module which is displayed on an OLED screen. We observed whether the changes in the potentiometer at the analog input module changed the received value at the analog output value displayed on the screen.
