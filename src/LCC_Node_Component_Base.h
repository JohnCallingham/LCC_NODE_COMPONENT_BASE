#ifndef LCC_NODE_COMPONENT_BASE_H
#define LCC_NODE_COMPONENT_BASE_H

/**
 * The base class for the following LCC node components;-
 * - LCC_Servo
 * - Frog
 * - TOTI
 */

 class LCC_Node_Component_Base {
  public:


  protected:
    void setSendEventCallbackFunction(void (*sendEvent)(uint16_t eventIndexToSend)) { this->sendEvent = sendEvent; }

  private:
    // Call back function to send events.
    void (*sendEvent) (uint16_t eventIndexToSend);

 };

 #endif
