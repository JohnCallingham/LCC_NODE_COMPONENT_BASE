#ifndef LCC_NODE_COMPONENT_BASE_H
#define LCC_NODE_COMPONENT_BASE_H

#include <Arduino.h>

/**
 * The base class for the following classes;-
 * - Servo_LCC (in component LCC_SERVO)
 * - Crossover (in component LCC_CROSSOVER)
 * - Frog (in component LCC_FROG)
 * - TOTI (in component LCC_TOTI)
 * - ToFSensorBase (in component LCC_TOF_SENSOR)
 */

 class LCC_Node_Component_Base {
  public:
    void setSendEventCallbackFunction(void (*sendEvent)(uint16_t eventIndexToSend)) { this->sendEvent = sendEvent; }
    void setLogMessageCallbackFunction(void (*logMessage)(String message)) { this->logMessage = logMessage; }

    void setTestStartEventIndex(uint16_t index) { testStartEventIndex = index; }
    void setTestStopEventIndex(uint16_t index) { testStopEventIndex = index; }

    /**
     * Pure virtual functions to force them to be overridden in derived classes.
     */

    // Used when an event is received to determine if it is for this component.
    virtual bool eventIndexMatches(uint16_t index) = 0;

    // Used when JMRI queries the state of an event index.
    virtual bool eventIndexMatchesCurrentState(uint16_t index) = 0;

    // Used when a JMRI hub connection is made so that JMRI knows the state of this component.
    virtual void sendEventsForCurrentState() = 0;

  protected:
    // Callback function to send events.
    void (*sendEvent) (uint16_t eventIndexToSend);

    // Callback function for logging.
    void (*logMessage) (String message);

    // The event indexes which will start and stop the test cycle.
    uint16_t testStartEventIndex;
    uint16_t testStopEventIndex;

    /**
     * The following are used for controlling the board testing cycle.
     */
    bool testing = false;
    unsigned long testingTimer; // Contains the value of millis() for the next change in the testing cycle.

  private:

 };

 #endif
