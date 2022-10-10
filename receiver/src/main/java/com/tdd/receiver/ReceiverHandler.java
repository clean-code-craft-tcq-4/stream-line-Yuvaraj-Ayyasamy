/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver;

import com.tdd.receiver.exception.InvalidInputException;

/**
 * @author MSP5COB
 */
public class ReceiverHandler {

  /**
   * @param samples array of signals
   * @throws InvalidInputException when passed invalid numbers
   */
  public void parseReceivedSignals(final String[] samples) throws InvalidInputException {
    if ((samples != null) && (samples.length > 0)) {
      try {
        for (String sample : samples) {
          printSignals(Double.parseDouble(sample));
        }
      }
      catch (Exception e) {
        throw new InvalidInputException(e.getMessage());
      }
    }

  }

  private void printSignals(final double signalValue) {
    System.out.println(signalValue);
  }
}
