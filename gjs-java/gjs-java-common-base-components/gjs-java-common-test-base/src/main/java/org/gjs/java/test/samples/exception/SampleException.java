package org.gjs.java.test.samples.exception;

public class SampleException extends Exception {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public SampleException() {
        super("Default message");
    }

    public SampleException(String message) {
        super(message);
    }

    public SampleException(String message, Throwable e) {
        super(message, e);
    }

    public SampleException(Throwable e) {
        super(e.getMessage(), e);
    }

}
