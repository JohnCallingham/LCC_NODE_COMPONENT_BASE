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
    void setSendEventCallbackFunction(void (*sendEvent)(uint16_t eventIndexToSend)) { this->sendEvent = sendEvent; }

    /**
     * Pure virtual functions to force them to be overridden in derived classes.
     */
    virtual bool eventIndexMatches(uint16_t index) = 0;
    virtual bool eventIndexMatchesCurrentState(uint16_t index) = 0;
    virtual void sendEventsForCurrentState() = 0;

  protected:
    // Call back function to send events.
    void (*sendEvent) (uint16_t eventIndexToSend);

  private:

 };

 #endif
