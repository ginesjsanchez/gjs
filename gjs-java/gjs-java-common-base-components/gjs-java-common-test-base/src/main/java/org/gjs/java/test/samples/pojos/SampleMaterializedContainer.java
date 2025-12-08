package org.gjs.java.test.samples.pojos;

import java.util.Date;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleMaterializedContainer {

    SampleMaterialized2 materialized;
    Date inicio;

    @Override
    public String toString() {
        return "SampleMaterializedContainer [materialized=" + materialized + ", inicio=" + inicio + "]";
    }

}
