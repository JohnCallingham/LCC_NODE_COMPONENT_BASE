# LCC_NODE_COMPONENT_BASE

This component is part of a suite of components which can be used as part of a program which implements an OpenLCB/LCC node. It has been developed using PlatformIO and has been tested on an Arduino Nano ESP32.

The file LCC_Node_Component_Base.h contains a single class which is designed to be an abstract base class which derived classes will inherit. This base class enforces an interface for the derived classes and also provides a callback function which is used to send LCC events.
