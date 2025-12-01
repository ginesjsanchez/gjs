package org.gjs.java.test.samples.pojos;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleMaterialized2 extends SampleGeneric<SamplePojo> {

    String texto;

    @Override
    public String toString() {
        return "SampleMaterialized2 [texto=" + texto + ", generic=" + generic + "]";
    }

}
