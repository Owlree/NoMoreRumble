# NoMoreRumble
Simple C++ program that sets ruble parameters to 0 on all connected controllers.

When I do work on games that use the rumble feature on controllers, it is often the case that a breakpoint, an assert, or a crash happens while the controller is rumbling, leaving it stuck like that. This is a C++ program that sets rumble parameters to 0 using Xinput.

Compile it with `cl /EHsc main.cpp /link /out:NoMoreRumble.exe`.
