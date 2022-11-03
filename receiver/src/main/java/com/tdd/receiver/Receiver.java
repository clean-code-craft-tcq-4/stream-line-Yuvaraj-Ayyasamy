/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver;

import java.util.List;

import com.tdd.receiver.exception.InvalidInputException;

/**
 * @author MSP5COB
 */
public class Receiver {

  /**
   * @param args
   * @throws InvalidInputException
   */
  public static void main(final String[] args) throws InvalidInputException {
    ReceiverHandler receiverHandler = new ReceiverHandler();
    List<Double> signals = receiverHandler.parseReceivedSignals(args);
    receiverHandler.printSignals(signals);
  }

}
