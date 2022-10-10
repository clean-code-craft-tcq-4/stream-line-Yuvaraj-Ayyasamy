/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver.tests;


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
    new ReceiverHandler().parseReceivedSignals(input);
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
