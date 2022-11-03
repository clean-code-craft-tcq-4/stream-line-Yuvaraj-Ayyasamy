/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver;

import java.util.ArrayList;
import java.util.List;

import com.tdd.receiver.exception.InvalidInputException;

/**
 * @author MSP5COB
 */
public class ReceiverHandler {

  /**
   * @param samples array of signals
   * @return List<Double> signals List
   * @throws InvalidInputException when passed invalid numbers
   */
  public List<Double> parseReceivedSignals(final String[] samples) throws InvalidInputException {
    List<Double> signalsList = new ArrayList<>();
    if ((samples != null) && (samples.length > 0)) {
      try {
        for (String sample : samples) {
          signalsList.add(Double.parseDouble(sample));
        }
      }
      catch (Exception e) {
        throw new InvalidInputException(e.getMessage());
      }
    }
    return signalsList;
  }

  public void printSignals(final List<Double> signalValues) {
    System.out.println(signalValues);
  }
}
