package org.gjs.java.test.samples.pojos;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleInterfacePojo implements ISample {

    private long id;
    private String nombre;

    @Override
    public boolean isValid() {
        return (id > 0);
    }

}
