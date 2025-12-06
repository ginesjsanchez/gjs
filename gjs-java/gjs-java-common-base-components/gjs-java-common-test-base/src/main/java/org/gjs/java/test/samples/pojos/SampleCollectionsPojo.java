package org.gjs.java.test.samples.pojos;

import java.util.List;
import java.util.Map;
import java.util.Set;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleCollectionsPojo {

    private List<Long> ids;
    private Set<String> nombres;
    private Map<String, SamplePojo> objetos;

    public SampleCollectionsPojo() {
    }

}
