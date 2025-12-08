package org.gjs.java.test.samples.pojos;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleMaterialized1 extends SampleGeneric<Long> {

    String texto;

    @Override
    public String toString() {
        return "SampleMaterialized1 [texto=" + texto + ", generic=" + generic + "]";
    }

}
