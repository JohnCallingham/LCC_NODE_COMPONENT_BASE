#ifndef LCC_NODE_COMPONENT_BASE_H
#define LCC_NODE_COMPONENT_BASE_H

/**
 * The base class for the following LCC node components;-
 * - LCC_SERVO
 * - LCC_CROSSOVER
 * - LCC_FROG
 * - LCC_TOTI
 */

 class LCC_Node_Component_Base {
  public:
    void setSendEventCallbackFunction(void (*sendEvent)(uint16_t eventIndexToSend)) { this->sendEvent = sendEvent; }

    /**
     * Pure virtual functions to force them to be overridden in derived classes.
     */
    // Used when event is received to determine if it is for this component.
    virtual bool eventIndexMatches(uint16_t index) = 0;

    // Used when JMRI queries the state of an event index.
    virtual bool eventIndexMatchesCurrentState(uint16_t index) = 0;

    // Used when a JMRI hub connection is made so that JMRI knows the state of this component.
    virtual void sendEventsForCurrentState() = 0;

  protected:
    // Callback function to send events.
    void (*sendEvent) (uint16_t eventIndexToSend);

  private:

 };

 #endif
