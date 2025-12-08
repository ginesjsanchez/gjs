package org.gjs.java.test.samples.pojos;

import java.time.LocalDate;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleLocalDatePojo {

    private LocalDate localDate;

    public SampleLocalDatePojo() {
    }

    public SampleLocalDatePojo(LocalDate localDate) {
        this.localDate = localDate;
    }

    @Override
    public String toString() {
        return "SampleLocalDatePojo [localDate="
                + localDate
                + "]";
    }

}
