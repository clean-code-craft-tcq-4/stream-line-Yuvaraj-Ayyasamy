/*
 * Copyright (c) Robert Bosch GmbH. All rights reserved.
 */
package com.tdd.receiver.exception;


/**
 * @author MSP5COB
 */
public class InvalidInputException extends Exception {

  /**
   *
   */
  private static final long serialVersionUID = 3272386497273115739L;

  /**
   * @param message Exception message
   */
  public InvalidInputException(final String message) {
    super(message);
  }

}
