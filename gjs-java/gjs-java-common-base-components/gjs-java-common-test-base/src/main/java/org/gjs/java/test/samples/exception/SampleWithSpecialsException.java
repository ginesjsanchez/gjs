package org.gjs.java.test.samples.exception;

import org.gjs.java.test.samples.pojos.SamplePojo;

public class SampleWithSpecialsException extends Exception {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public SampleWithSpecialsException() {
        super("Default message");
    }

    public SampleWithSpecialsException(String message) {
        super(message);
    }

    public SampleWithSpecialsException(String message, Throwable e) {
        super(message, e);
    }

    public SampleWithSpecialsException(Throwable e) {
        super(e.getMessage(), e);
    }

    public SampleWithSpecialsException(SamplePojo sample) {
        super(String.format("Sample error for the object %s", (sample != null) ? sample.getNombre() : "<unknown>"));
    }

}
