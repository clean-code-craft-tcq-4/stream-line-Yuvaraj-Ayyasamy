/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver.tests;


import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import java.util.List;

import org.junit.Test;

import com.tdd.receiver.ReceiverHandler;
import com.tdd.receiver.exception.InvalidInputException;


/**
 * @author MSP5COB
 */
public class ReceiverTest {


  /**
   * Positive Test case for Receiver Test, should pass without any error
   *
   * @throws InvalidInputException InvalidInputException
   */
  @Test
  public void testReceiver() throws InvalidInputException {
    String[] input = { "0", "5.6", "6", "15", "34.6" };
    List<Double> signals = new ReceiverHandler().parseReceivedSignals(input);
    assertNotNull(signals);
    assertEquals("Expected value not Received", (Double) 5.6, signals.get(1));
    assertEquals("Expected value not Received", (Double) 6.0, signals.get(2));
  }

  /**
   * Test case for Receiver Test with invalid input
   *
   * @throws InvalidInputException InvalidInputException
   */
  @Test(expected = InvalidInputException.class)
  public void testReceiverInalidInput() throws InvalidInputException {
    String[] invalidInput = { "0", "5.6", "invalid_string", "15", "34.6" };
    new ReceiverHandler().parseReceivedSignals(invalidInput);
  }
}
