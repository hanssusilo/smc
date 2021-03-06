# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Hans Susilo\Documents\smc\Frog Leg Jacobian QUADRUPED\Design02.cydsn\Design02.cyprj
# Date: Thu, 19 Feb 2015 01:05:55 GMT
#set_units -time ns
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 19.230769230769234 -waveform {0 9.61538461538462} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 19.230769230769234 -waveform {0 9.61538461538462} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_clock -name {Clock_2(fixed-function)} -period 38.461538461538467 -waveform {0 19.2307692307692} [get_pins {ClockBlock/dclk_glb_ff_1}]
create_generated_clock -name {UART_2_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 15} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 15} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Clock_4} -source [get_pins {ClockBlock/clk_sync}] -edges {1 53 105} -nominal_period 1000 [list [get_pins {ClockBlock/dclk_glb_4}]]
create_clock -name {Clock_4(fixed-function)} -period 980.769230769231 -waveform {0 19.2307692307692} -nominal_period 1000 [get_pins {ClockBlock/dclk_glb_ff_4}]
create_generated_clock -name {Clock_5} -source [get_pins {ClockBlock/clk_sync}] -edges {1 521 1041} -nominal_period 10000 [list [get_pins {ClockBlock/dclk_glb_5}]]
create_clock -name {Clock_5(fixed-function)} -period 9980.7692307692323 -waveform {0 19.2307692307692} -nominal_period 10000 [get_pins {ClockBlock/dclk_glb_ff_5}]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Hans Susilo\Documents\smc\Frog Leg Jacobian QUADRUPED\Design02.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Hans Susilo\Documents\smc\Frog Leg Jacobian QUADRUPED\Design02.cydsn\Design02.cyprj
# Date: Thu, 19 Feb 2015 01:03:53 GMT
